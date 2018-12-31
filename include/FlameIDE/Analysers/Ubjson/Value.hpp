#ifndef ANALYSERS_UBJSON_VALUE_HPP
#define ANALYSERS_UBJSON_VALUE_HPP

#include <FlameIDE/Analysers/Ubjson/Types.hpp>
#include <FlameIDE/Analysers/Ubjson/Traits.hpp>
#include <FlameIDE/Analysers/Ubjson/BaseValue.hpp>
#include <FlameIDE/Analysers/Ubjson/ValueSpecializations.hpp>
#include <FlameIDE/Analysers/Ubjson/Array.hpp>
#include <FlameIDE/Analysers/Ubjson/Object.hpp>
#include <FlameIDE/Analysers/Ubjson/String.hpp>

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

#endif // ANALYSERS_UBJSON_VALUE_HPP
