#ifndef FLAMEIDE_COMMON_EXPECTED_HPP
#define FLAMEIDE_COMMON_EXPECTED_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{

template<typename ResultType, typename ErrorType>
class Expected
{
public:
	using Me = Expected<ResultType, ErrorType>;
	using Result = ResultType;
	using Error = ErrorType;

	Expected() noexcept = default;
	Expected(const Me &expected) noexcept;
	Expected(Me &&expected) noexcept;
	Expected(const ResultType &expected) noexcept;
	Expected(ResultType &&expected) noexcept;
	Expected(const ErrorType &expected) noexcept;
	Expected(ErrorType &&expected) noexcept;
	~Expected() noexcept;

	Me &operator=(const Me &expected) noexcept;
	Me &operator=(Me &&expected) noexcept;
	Me &operator=(const ResultType &expected) noexcept;
	Me &operator=(ResultType &&expected) noexcept;
	Me &operator=(const ErrorType &expected) noexcept;
	Me &operator=(ErrorType &&expected) noexcept;

	template<typename Functor>
	Me &ifResult(Functor &&functor) noexcept;
	template<typename Functor>
	const Me &ifResult(Functor &&functor) const noexcept;

	template<typename Functor>
	Me &ifError(Functor &&functor) noexcept;
	template<typename Functor>
	const Me &ifError(Functor &&functor) const noexcept;

	void done() noexcept;
	void done() const noexcept;

private:
	void destroy() noexcept;

private:
	enum class State: Types::ichar_t
	{
		UNKNOWN = -1
		, RESULT = 0
		, ERROR = 1
	};

	union Data
	{
		Data() noexcept { state = State::UNKNOWN; }
		~Data() {}

		State state;
		struct
		{
			State state;
			ErrorType value;
		} error;

		struct
		{
			State state;
			ResultType value;
		} result;
	};

private:
	Data data;
};

} // namespace flame_ide

namespace flame_ide
{

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(const Me &expected) noexcept
{
	operator=(expected);
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(Me &&expected) noexcept
{
	operator=(move(expected));
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(const ResultType &expected) noexcept
{
	operator=(expected);
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(ResultType &&expected) noexcept
{
	operator=(move(expected));
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(const ErrorType &expected) noexcept
{
	operator=(expected);
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::Expected(ErrorType &&expected) noexcept
{
	operator=(move(expected));
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType>::~Expected() noexcept
{
	destroy();
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(const Me &expected) noexcept
{
	destroy();
	expected.ifResult([this](const ResultType &result)
			{
				operator=(result);
			}).ifError([this](const ErrorType &error)
					{
						operator=(error);
					}).done();
	return *this;
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(Me &&expected) noexcept
{
	expected.ifResult([this](ResultType &&result)
			{
				this->operator=(move(result));
			}).ifError([this](ErrorType &&error)
					{
						this->operator=(move(error));
					}).done();
	return *this;
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(const ResultType &result) noexcept
{
	destroy();
	flame_ide::placementNew(&data.result.value, result);
	data.state = State::RESULT;
	return *this;
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(ResultType &&result) noexcept
{
	destroy();
	flame_ide::placementNew(&data.result.value, move(result));
	data.state = State::RESULT;
	return *this;
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(const ErrorType &error) noexcept
{
	destroy();
	flame_ide::placementNew(&data.error.value, error);
	data.state = State::ERROR;
	return *this;
}

template<typename ResultType, typename ErrorType>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::operator=(ErrorType &&error) noexcept
{
	destroy();
	flame_ide::placementNew(&data.error.value, move(error));
	data.state = State::ERROR;
	return *this;
}

template<typename ResultType, typename ErrorType>
template<typename Functor>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::ifResult(Functor &&functor) noexcept
{
	if (State::RESULT != data.state)
		return *this;

	functor(move(data.result.value));
	data.state = State::UNKNOWN;

	return *this;
}

template<typename ResultType, typename ErrorType>
template<typename Functor>
const Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::ifResult(Functor &&functor) const noexcept
{
	if (State::RESULT != data.state)
		return *this;

	functor(data.result.value);

	return *this;
}

template<typename ResultType, typename ErrorType>
template<typename Functor>
Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::ifError(Functor &&functor) noexcept
{
	if (State::ERROR != data.state)
		return *this;

	functor(move(data.error.value));
	data.state = State::UNKNOWN;

	return *this;
}

template<typename ResultType, typename ErrorType>
template<typename Functor>
const Expected<ResultType, ErrorType> &
Expected<ResultType, ErrorType>::ifError(Functor &&functor) const noexcept
{
	if (State::ERROR != data.state)
		return *this;

	functor(data.error.value);

	return *this;
}

template<typename ResultType, typename ErrorType>
inline void Expected<ResultType, ErrorType>::done() noexcept
{}

template<typename ResultType, typename ErrorType>
inline void Expected<ResultType, ErrorType>::done() const noexcept
{}

// private

template<typename ResultType, typename ErrorType>
void Expected<ResultType, ErrorType>::destroy() noexcept
{
	switch (data.state)
	{
		case State::RESULT:
			data.result.value.~ResultType();
			return;

		case State::ERROR:
			data.error.value.~ErrorType();
			return;

		case State::UNKNOWN:
		default:
			return;
	}
}

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_EXPECTED_HPP
