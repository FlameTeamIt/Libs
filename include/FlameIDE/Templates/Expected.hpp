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

	Expected() noexcept = default;
	Expected(const Expected<Result, Error> &expected) noexcept = default;
	Expected(Expected<Result, Error> &&expected) noexcept = default;

	Expected(const Result &result) noexcept;
	Expected(Result &&result) noexcept;

	Expected(const Error &error) noexcept;
	Expected(Error &&error) noexcept;

	/// @brief ifResult
	/// @tparam Function
	/// @param function
	/// @return
	template<typename Function>
	Expected<Result, Error> &ifResult(Function &&function);

	/// @brief ifError
	/// @tparam Function
	/// @param function
	/// @return
	template<typename Function>
	Expected<Result, Error> &ifError(Function &&function);

	void done();

private:
	Variant<Result, Error> variant;
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
void Expected<Result, Error>::done()
{
	variant.reset();
}

} // namespace templates
} // namespace flame_ide

#endif // FLAMEIDE_TEMPLATES_EXPECTED_HPP
