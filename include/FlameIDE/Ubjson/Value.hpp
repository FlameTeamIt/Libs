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
	BaseValue<EnumeratedType::NULLVAL, IS_ALLOCATED>
	, BaseValue<EnumeratedType::NOOP, IS_ALLOCATED>
	, BaseValue<EnumeratedType::TRUE, IS_ALLOCATED>
	, BaseValue<EnumeratedType::FALSE, IS_ALLOCATED>
	, BaseValue<EnumeratedType::INT8, IS_ALLOCATED>
	, BaseValue<EnumeratedType::UINT8, IS_ALLOCATED>
	, BaseValue<EnumeratedType::INT16, IS_ALLOCATED>
	, BaseValue<EnumeratedType::INT32, IS_ALLOCATED>
	, BaseValue<EnumeratedType::INT64, IS_ALLOCATED>
	, BaseValue<EnumeratedType::FLOAT32, IS_ALLOCATED>
	, BaseValue<EnumeratedType::FLOAT64, IS_ALLOCATED>
	, BaseValue<EnumeratedType::HUGE_NUM, IS_ALLOCATED>
	, BaseValue<EnumeratedType::CHAR, IS_ALLOCATED>
	, BaseValue<EnumeratedType::STRING, IS_ALLOCATED>
	, BaseValue<EnumeratedType::ARRAY, IS_ALLOCATED>
	, BaseValue<EnumeratedType::OBJECT, IS_ALLOCATED>
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

	EnumeratedType getType() const
	{
		if (valueVariant.getCurrentIndex() < 0)
		{
			return EnumeratedType::ERROR;
		}
		else
		{
			return static_cast<EnumeratedType>(valueVariant.getCurrentIndex());
		}
	}

private:
	ValueVariant<TrueType::VALUE> valueVariant;
};

}}

#endif // FLAMEIDE_UBJSON_VALUE_HPP
