#ifndef FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP
#define FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP

namespace flame_ide
{

///
/// @brief A variable of this struct cannot be create with default constructor
///
struct NonDefault
{
	NonDefault() noexcept = delete;
	NonDefault(const NonDefault &) noexcept = default;
	NonDefault(NonDefault &&) noexcept = default;

	NonDefault& operator=(const NonDefault &) noexcept = default;
	NonDefault& operator=(NonDefault &&) noexcept = default;
};

///
/// @brief A variable of this struct cannot be move
///
struct NonMove
{
	NonMove() noexcept = default;
	NonMove(NonMove &&) = delete;

	NonMove &operator=(NonMove &&) = delete;
};

///
/// @brief A variable of this struct cannot be copy
///
struct NonCopy
{
	NonCopy() noexcept = default;
	NonCopy(const NonCopy &) = delete;

	NonCopy &operator=(const NonCopy &) = delete;
};

///
/// @brief A variable of this struct cannot be assign
///
struct NonAssignable: public NonMove, public NonCopy
{
	NonAssignable() noexcept = default;
};

///
/// @brief A variable of this struct cannot be create.
///
struct NonCreational: public NonDefault, public NonMove, public NonCopy
{};

}

#endif // FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP
