#ifndef ANALYSERS_UBJSON_VALUE_HPP
#define ANALYSERS_UBJSON_VALUE_HPP

#include <Analysers/Ubjson/Types.hpp>

#include <Analysers/Ubjson/Traits.hpp>

#include <Analysers/Ubjson/Array.hpp>
#include <Analysers/Ubjson/Object.hpp>
#include <Analysers/Ubjson/String.hpp>

namespace flame_ide
{namespace ubjson
{

using ValueVariant = templates::Variant<
	ValueTraits<EnumeratedType::NULLVAL>
	, ValueTraits<EnumeratedType::NOOP>
	, ValueTraits<EnumeratedType::TRUE>
	, ValueTraits<EnumeratedType::FALSE>
	, ValueTraits<EnumeratedType::INT8>
	, ValueTraits<EnumeratedType::UINT8>
	, ValueTraits<EnumeratedType::INT16>
	, ValueTraits<EnumeratedType::INT32>
	, ValueTraits<EnumeratedType::INT64>
	, ValueTraits<EnumeratedType::FLOAT32>
	, ValueTraits<EnumeratedType::FLOAT64>
	, ValueTraits<EnumeratedType::HUGE_NUM>
	, ValueTraits<EnumeratedType::CHAR>
	, ValueTraits<EnumeratedType::STRING>
	, ValueTraits<EnumeratedType::ARRAY>
	, ValueTraits<EnumeratedType::OBJECT>
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
	ValueVariant valueVariant;
};

}}

#endif // ANALYSERS_UBJSON_VALUE_HPP
