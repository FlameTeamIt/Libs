#ifndef FLAMEIDE_TEMPLATES_EXPECTED_HPP
#define FLAMEIDE_TEMPLATES_EXPECTED_HPP

#include <FlameIDE/Templates/Variant.hpp>
#include <FlameIDE/Common/Utils.hpp>

// defines

namespace flame_ide
{namespace templates
{

template<typename Result, typename Error>
class Expected
{
public:
	static_assert (!ComparingTypes<Result, Error>::VALUE, "Types can be different");

	using Me = Expected<Result, Error>;

	Expected() noexcept = default;
	Expected(const Expected<Result, Error> &expected) noexcept = default;
	Expected(Expected<Result, Error> &&expected) noexcept = default;

	Expected(const Result &result) noexcept;
	Expected(Result &&result) noexcept;

	Expected(const Error &error) noexcept;
	Expected(Error &&error) noexcept;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator=(const Result &) noexcept;
	Me &operator=(Result &&) noexcept;

	Me &operator=(const Error &) noexcept;
	Me &operator=(Error &&) noexcept;

	/// @brief ifResult
	/// @tparam Function functional object, labda or function pointer.
	/// Need type - 'void(Result&&)' or 'void(Result)'
	/// @param function
	/// @return
	template<typename Function>
	Me &ifResult(Function &&function);

	/// @brief ifResult
	/// @tparam Function functional object, labda or function pointer.
	/// Need type - 'void(const Result &)' or 'void(Result)'
	/// @param function
	/// @return
	template<typename Function>
	const Me &ifResult(Function &&function) const;

	/// @brief ifError
	/// @tparam Function
	/// @param function
	/// @return
	template<typename Function>
	Me &ifError(Function &&function);

	template<typename Function>
	const Me &ifError(Function &&function) const;

	void done() const;

private:
	mutable Variant<Result, Error> variant;
};

} // namespace templates
} // namespace flame_ide

// implementation

namespace flame_ide
{namespace templates
{

template<typename Result, typename Error>
Expected<Result, Error>::Expected(const Result &result) noexcept : variant{ result }
{}

template<typename Result, typename Error>
Expected<Result, Error>::Expected(Result &&result) noexcept : variant{ move(result) }
{}

template<typename Result, typename Error>
Expected<Result, Error>::Expected(const Error &error) noexcept : variant{ error }
{}

template<typename Result, typename Error>
Expected<Result, Error>::Expected(Error &&error) noexcept : variant{ move(error) }
{}

template<typename Result, typename Error>
Expected<Result, Error> &
Expected<Result, Error>::operator=(const Result &result) noexcept
{
	variant.set(result);
	return *this;
}

template<typename Result, typename Error>
Expected<Result, Error> &
Expected<Result, Error>::operator=(Result &&result) noexcept
{
	variant.set(move(result));
	return *this;
}

template<typename Result, typename Error>
Expected<Result, Error> &
Expected<Result, Error>::operator=(const Error &error) noexcept
{
	variant.set(move(error));
	return *this;
}

template<typename Result, typename Error>
Expected<Result, Error> &
Expected<Result, Error>::operator=(Error &&error) noexcept
{
	variant.set(move(error));
	return *this;
}

template<typename Result, typename Error>
template<typename Function>
Expected<Result, Error> &
Expected<Result, Error>::ifResult(Function &&function)
{
	Result* result = variant.template get<Result>();
	if (result)
	{
		function(move(*result));
	}
	return *this;
}

template<typename Result, typename Error>
template<typename Function>
const Expected<Result, Error> &
Expected<Result, Error>::ifResult(Function &&function) const
{
	const Result* result = variant.template get<Result>();
	if (result)
	{
		function(*result);
	}
	return *this;
}

template<typename Result, typename Error>
template<typename Function>
Expected<Result, Error> &
Expected<Result, Error>::ifError(Function &&function)
{
	Error* error = variant.template get<Error>();
	if (error)
	{
		function(move(*error));
	}
	return *this;
}

template<typename Result, typename Error>
template<typename Function>
const Expected<Result, Error> &
Expected<Result, Error>::ifError(Function &&function) const
{
	const Error* error = variant.template get<Error>();
	if (error)
	{
		function(*error);
	}
	return *this;
}

template<typename Result, typename Error>
void Expected<Result, Error>::done() const
{
	variant.reset();
}

} // namespace templates
} // namespace flame_ide

#endif // FLAMEIDE_TEMPLATES_EXPECTED_HPP
