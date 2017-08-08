#ifndef TEMPLATES_FOR_ALL
#define TEMPLATES_FOR_ALL

#include <Others/PrimitiveTypes.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief A variable of this struct cannot be create with constructor.
 */
struct NonDefault
{
	NonDefault() = delete;
};

/**
 * @brief A variable of this struct cannot be move.
 */
struct NonMove
{
	NonMove(NonMove &&) = delete;
};

/**
 * @brief A variable of this struct cannot be copy.
 */
struct NonCopy
{
	NonCopy(const NonCopy &) = delete;
};

/**
 * @brief A variable of this struct cannot be define.
 */
struct NonCreational
{
	NonCreational() = delete;
	NonCreational(const NonCreational &) = delete;
	NonCreational(NonCreational &&) = delete;
	~NonCreational() = delete;
};

/**
 * @brief Aliases to primitive fixed size types.
 */
struct Types: public NonCreational
{
	using char_t = flame_ide::types::primitive::char_t;
	using short_t = flame_ide::types::primitive::short_t;
	using int_t = flame_ide::types::primitive::int_t;
	using long_t = flame_ide::types::primitive::long_t;
	using llong_t = flame_ide::types::primitive::llong_t;

	using byte_t = flame_ide::types::primitive::uchar_t;

	using uchar_t = flame_ide::types::primitive::uchar_t;
	using ushort_t = flame_ide::types::primitive::ushort_t;
	using uint_t = flame_ide::types::primitive::uint_t;
	using ulong_t = flame_ide::types::primitive::ulong_t;
	using ullong_t = flame_ide::types::primitive::ullong_t;

	using float_t = flame_ide::types::primitive::float_t;
	using double_t = flame_ide::types::primitive::double_t;
	using ldouble_t = flame_ide::types::primitive::ldouble_t;

	using size_t = flame_ide::types::primitive::size_t;
	using ssize_t = flame_ide::types::primitive::ssize_t;
	using diff_t = flame_ide::types::primitive::diff_t;
};

/**
 * @brief Removing pointer from type.
 * @tparam Raw type.
 */
template<typename T>
struct RemovePointer: public NonCreational
{
	using Type = T;
};

/**
 * @brief View RemovePointer
 */
template<typename T>
struct RemovePointer<T *>: public NonCreational
{
	using Type = T;
};

/**
 * @brief Removing reference from type.
 * @tparam Raw type.
 */
template<typename T>
struct RemoveReference: public NonCreational
{
	using Type = T;
};

/**
 * @brief View RemoveReference
 */
template<typename T>
struct RemoveReference<T &>: public NonCreational
{
	using Type = T;
};

/**
 * @brief View RemoveReference
 */
template<typename T>
struct RemoveReference<T &&>: public NonCreational
{
	using Type = T;
};

/**
 * @brief Default type traits
 * @tparam Raw type.
 */
template<typename T>
struct DefaultTraits: public NonCreational
{
	using Type = T;
	using ConstType = Type const;

	using Reference = Type &;
	using MoveReference =  Type &&;
	using ConstReference = Type const&;

	using Pointer = Type *;
	using PointerToConst = Type const*;
	using ConstPointer = Type *const;

	using VoidPointer = void *;
};

/**
 * @brief Default size, diff  traits.
 */
struct SizeTraits: public NonCreational
{
	using SizeType = Types::size_t ;
	using SsizeType = Types::ssize_t;
	using DiffType = Types::diff_t;
};

/**
 * @brief Default traits for containers such as Array, Vector, etc.
 * @tparam Raw type.
 */
template<typename T>
struct ContainerTraits: public DefaultTraits<T>, public SizeTraits
{};

/**
 * @brief Template compile time constant.
 * @tparam Raw type.
 * @tparam Raw type value.
 */
template<typename T, T v>
struct IntegralConstant: public NonCreational
{
	using Type = T;
	static constexpr Type VALUE = v;
};

/**
 * @brief Compile time true constant.
 */
struct TrueType: public IntegralConstant<bool, true>
{};

/**
 * @brief Compile time false constant.
 */
struct FalseType: public IntegralConstant<bool, false>
{
	static constexpr bool VALUE = false;
};

/**
 * @brief Comparing different types.
 * @tparam First type.
 * @tparam Second type.
 */
template<typename T, typename U>
struct ComparingTypes: public FalseType
{};

/**
 * @brief Comparing equal types.
 * @tparam Type.
 */
template<typename T>
struct ComparingTypes<T, T>: public TrueType
{};

/**
 * @brief Get info is type pointer.
 * @tparam Type.
 */
template<typename T>
struct IsPointer: public FalseType
{};

/**
 * @brief Get info is type pointer.
 * @tparam Type.
 */
template<typename T>
struct IsPointer<T *>: public TrueType
{};

/**
 * @brief Get info is type pointer.
 * @tparam Type.
 */
template<typename T>
struct IsPointer<const T *>: public TrueType
{};

/**
 * @brief Get info is type pointer.
 * @tparam Type.
 */
template<typename T>
struct IsPointer<T *const>: public TrueType
{};

/**
 * @brief Get info is type reference.
 * @tparam Type.
 */
template<typename T>
struct IsReference: public FalseType
{};

/**
 * @brief Get info is type reference.
 * @tparam Type.
 */
template<typename T>
struct IsReference<T &>: public TrueType
{};

/**
 * @brief Get info is type reference.
 * @tparam Type.
 */
template<typename T>
struct IsReference<T const &>: public TrueType
{};

/**
 * @brief Get info is type reference.
 * @tparam Type.
 */
template<typename T>
struct IsReference<T &&>: public TrueType
{};

}}

#endif // TEMPLATES_FOR_ALL
