#ifndef FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP
#define FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{
namespace templates
{

namespace maybemonad_utils
{

enum class State : Types::uint_t
{
};

} // namespace maybemonad_utils

template<typename Context, typename Traits = DefaultTraits<Context>>
class MaybeMonad: public Traits
{
public:
	using typename Traits::Type;
	using typename Traits::ConstType;
	using typename Traits::Reference;
	using typename Traits::MoveReference;
	using typename Traits::ConstReference;
	using typename Traits::Pointer;
	using typename Traits::PointerToConst;
	using typename Traits::ConstPointer;

	using State = maybemonad_utils::State;


private:

};

} // namespace templates
} // namespace flame_ide

#endif // FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP
