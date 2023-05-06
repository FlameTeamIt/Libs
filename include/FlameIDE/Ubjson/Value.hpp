#ifndef FLAMEIDE_UBJSON_VALUE_HPP
#define FLAMEIDE_UBJSON_VALUE_HPP

#include <FlameIDE/Ubjson/Types.hpp>
#include <FlameIDE/Ubjson/Traits.hpp>
#include <FlameIDE/Ubjson/BaseValue.hpp>
#include <FlameIDE/Ubjson/ValueSpecializations.hpp>
#include <FlameIDE/Ubjson/Array.hpp>
#include <FlameIDE/Ubjson/Object.hpp>
#include <FlameIDE/Ubjson/String.hpp>

namespace flame_ide
{namespace ubjson
{

template<bool IS_ALLOCATED>
using ValueVariant = templates::Variant<
	BaseValue<EnumeratedValueType::NULLVAL, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::NOOP, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::TRUE, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::FALSE, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::INT8, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::UINT8, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::INT16, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::INT32, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::INT64, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::FLOAT32, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::FLOAT64, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::HUGE_NUM, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::CHAR, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::STRING, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::ARRAY, IS_ALLOCATED>
	, BaseValue<EnumeratedValueType::OBJECT, IS_ALLOCATED>
>;

class Value
{
public:
	Value();
	Value(const Value &value) = default;
	Value(Value &&value) = default;
	Value &operator=(const Value &value) = default;
	Value &operator=(Value &&value) = default;

	template<typename T>
	Value &operator=(const T &ubjsonValue);

	inline operator bool() const
	{
		return valueVariant;
	}

	EnumeratedValueType getType() const
	{
		if (valueVariant.getCurrentIndex() < 0)
		{
			return EnumeratedValueType::ERROR;
		}
		else
		{
			return static_cast<EnumeratedValueType>(valueVariant.getCurrentIndex());
		}
	}

private:
	ValueVariant<TrueType::VALUE> valueVariant;
};

}}

#endif // FLAMEIDE_UBJSON_VALUE_HPP
