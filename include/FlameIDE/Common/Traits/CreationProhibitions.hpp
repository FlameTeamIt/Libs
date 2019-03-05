#ifndef FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP
#define FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP

namespace flame_ide
{

///
/// @brief A variable of this struct cannot be create with constructor.
///
struct NonDefault
{
	NonDefault() = delete;
};

///
/// @brief A variable of this struct cannot be move.
///
struct NonMove
{
	NonMove(NonMove &&) = delete;
};

///
/// @brief A variable of this struct cannot be copy.
///
struct NonCopy
{
	NonCopy(const NonCopy &) = delete;
};

///
/// @brief A variable of this struct cannot be define.
///
struct NonCreational: public NonDefault, public NonMove, public NonCopy
{};

}

#endif // FLAMEIDE_COMMON_TRAITS_CREATIONPROHIBITIONS_HPP
