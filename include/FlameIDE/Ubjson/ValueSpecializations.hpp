#ifndef FLAMEIDE_UBJSON_VALUESPECIALIZATIONS_HPP
#define FLAMEIDE_UBJSON_VALUESPECIALIZATIONS_HPP

#include <FlameIDE/Ubjson/Traits.hpp>
#include <FlameIDE/Ubjson/BaseValue.hpp>
#include <FlameIDE/Ubjson/SimpleTypeValues.hpp>

namespace flame_ide
{namespace ubjson
{

//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::NULLVAL
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::NOOP
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::TRUE
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE

//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::FALSE
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::INT8
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::UINT8
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::INT16
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::INT32
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::INT64
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::FLOAT32
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::FLOAT64
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE


//#define MACROS_ENUMERATED_TYPE_VALUE EnumeratedType::CHAR
//template<>
//class BaseValue<EnumeratedValueType, true>:
//		public BaseValue<EnumeratedValueType, false>
//{
//public:
//	static constexpr EnumeratedValueType ENUMERATED_TYPE_VALUE = EnumeratedValueType;
//	using Me = BaseValue<ENUMERATED_TYPE_VALUE, true>;
//	using Parent = BaseValue<ENUMERATED_TYPE_VALUE, false>;
//	using typename Parent::ValueType;

//	BaseValue() = default;
//	BaseValue(const Me &) = default;
//	BaseValue(Me &&) = default;

//	BaseValue(const ValueType &initValue) : Parent(initValue)
//	{}

//	BaseValue(ValueType &&initValue) : Parent(flame_ide::move(initValue))
//	{}

//	~BaseValue() = default;

//	Me &operator=(const Me &) = default;
//	Me &operator=(Me &&) = default;

//	using Parent::operator=;
//	using Parent::operator bool;

//	using Parent::getValue;
//};
//#undef MACROS_ENUMERATED_TYPE_VALUE

}}

#endif // FLAMEIDE_UBJSON_VALUESPECIALIZATIONS_HPP
