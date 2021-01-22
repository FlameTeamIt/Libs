#ifndef FLAMEIDE_TEMPLATES_BUILDER_HPP
#define FLAMEIDE_TEMPLATES_BUILDER_HPP

#include <FlameIDE/Templates/Tuple.hpp>

namespace flame_ide
{namespace templates
{

namespace builder_utils
{

template<typename DerivedStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE = ErrorType{}
>
class Substep
{
public:
	using Me = Substep<
		DerivedStep, ResultType, ErrorType, SUCCESS_VALUE
	>;

	Substep() noexcept = default;

	/// @brief Substep
	/// @param arg
	/// @param args
	template<typename Arg, typename ...Args>
	Substep(Arg &&arg, Args &&...args) noexcept;

	Substep(const Me &) noexcept = default;
	Substep(Me &&) noexcept = default;
	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	/// @brief operator()
	/// @details
	void operator()() noexcept;

	/// @brief operator bool
	/// @details
	operator bool() const noexcept;

	/// @brief getResult
	/// @details
	/// @return
	ResultType &getResult() noexcept;

	/// @brief getResult
	/// @details
	/// @return
	const ResultType &getResult() const noexcept;

protected:
	ResultType resultValue; ///<
	ErrorType error; ///<

private:
	inline DerivedStep *getDeliveredStep() noexcept
	{
		return static_cast<DerivedStep *>(this);
	}
	inline const DerivedStep *getDeliveredStep() const noexcept
	{
		return static_cast<const DerivedStep *>(this);
	}
};

/// @brief The Steps class
template<typename ...Substeps>
class Steps : protected Tuple<Substeps...>
{
public:

private:
};

}

/// @brief The Builder class
template<typename ResultType
	, template <typename ...> class Steps
	, typename ErrorType
>
class Builder
{
public:

protected:
	ResultType resultOject; ///<
};

}}

namespace flame_ide
{namespace templates
{

namespace builder_utils
{

template<typename DeliveredStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE
>
template<typename Arg, typename ...Args>
Substep<
	DeliveredStep, ResultType, ErrorType, SUCCESS_VALUE
>::Substep(Arg &&arg, Args &&...args) noexcept
{
	getDeliveredStep()->initImpl(arg, args...);
}

template<typename DeliveredStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE
>
void Substep<
	DeliveredStep, ResultType, ErrorType, SUCCESS_VALUE
>::operator()() noexcept
{
	getDeliveredStep()->doImpl();
}

template<typename DeliveredStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE
>
Substep<
	DeliveredStep, ResultType, ErrorType, SUCCESS_VALUE
>::operator bool() const noexcept
{
	return SUCCESS_VALUE != error;
}

template<typename DeliveredStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE
>
ResultType &Substep<
	DeliveredStep, ResultType, ErrorType, SUCCESS_VALUE
>::getResult() noexcept
{
	return resultValue;
}

template<typename DeliveredStep
	, typename ResultType
	, typename ErrorType
	, ErrorType SUCCESS_VALUE
>
const ResultType &Substep<
	DeliveredStep, ResultType, ErrorType, SUCCESS_VALUE
>::getResult() const noexcept
{
	return resultValue;
}


}

}}

#endif // FLAMEIDE_TEMPLATES_BUILDER_HPP
