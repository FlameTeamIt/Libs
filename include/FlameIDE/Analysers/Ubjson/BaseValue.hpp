#ifndef ANALYSERS_UBJSON_BASEVALUE_HPP
#define ANALYSERS_UBJSON_BASEVALUE_HPP

#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Analysers/Ubjson/Traits.hpp>

namespace flame_ide
{namespace ubjson
{

namespace utils
{

template<EnumeratedType UBJSON_TYPE>
struct TraitValues
{
	using Me = TraitValues<UBJSON_TYPE>;
	using Traits = ValueTraits<UBJSON_TYPE>;

	using ValueType = typename Traits::ValueType;

	EnumeratedType getType() const
	{
		return Traits::VALUE_TYPE;
	}

	Type getTypeClose() const
	{
		return Traits::VALUE_TYPE_CLOSE;
	}

	bool isDataPayload() const
	{
		return Traits::DATA_PAYLOAD;
	}
};

}

template<EnumeratedType UBJSON_TYPE, bool IS_ALLOCATED = FalseType::VALUE>
class BaseValue: public utils::TraitValues<UBJSON_TYPE>
{
public:
	using Me = BaseValue<UBJSON_TYPE, IS_ALLOCATED>;
	using Parent = utils::TraitValues<UBJSON_TYPE>;
	using typename Parent::ValueType;

	BaseValue() = default;
	BaseValue(const Me &) = default;
	BaseValue(Me &&) = default;

	BaseValue(const ValueType &initValue) : value(initValue)
	{}

	BaseValue(ValueType &&initValue) : value(flame_ide::move(initValue))
	{}

	~BaseValue() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator=(const ValueType &assigninigValue)
	{
		value = assigninigValue;
	}

	Me &operator=(ValueType &&assigninigValue)
	{
		value = flame_ide::move(assigninigValue);
	}

	operator bool()
	{
		return true;
	}

	ValueType &getValue()
	{
		return value;
	}

	const ValueType &getValue() const
	{
		return value;
	}

private:
	ValueType value;
};

template<EnumeratedType UBJSON_TYPE>
class BaseValue<UBJSON_TYPE, TrueType::VALUE>: public utils::TraitValues<UBJSON_TYPE>
{
public:
	using Me = BaseValue<UBJSON_TYPE, TrueType::VALUE>;
	using Parent = utils::TraitValues<UBJSON_TYPE>;
	using typename Parent::ValueType;

	BaseValue() = default;
	BaseValue(const Me &) = default;
	BaseValue(Me &&) = default;

	BaseValue(const ValueType &initValue) :
			value(templates::makeShared<ValueType>(initValue))
	{}

	BaseValue(ValueType &&initValue) :
			value(
					templates::makeShared<ValueType>(flame_ide::move(initValue))
			)
	{}

	~BaseValue() = default;

	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator=(const ValueType &assigninigValue)
	{
		if (!value)
		{
			value = templates::makeShared<ValueType>(assigninigValue);
		}
		else
		{
			*value = assigninigValue;
		}
	}

	Me &operator=(ValueType &&assigninigValue)
	{
		if (!value)
		{
			value = templates::makeShared<ValueType>(flame_ide::move(assigninigValue));
		}
		else
		{
			*value = flame_ide::move(assigninigValue);
		}
	}

	operator bool()
	{
		return value;
	}

	ValueType &getValue()
	{
		return *value;
	}

	const ValueType &getValue() const
	{
		return *value;
	}

private:
	templates::SharedPointer<ValueType> value;
};

}}

#endif // ANALYSERS_UBJSON_BASEVALUE_HPP
