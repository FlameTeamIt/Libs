#ifndef FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP
#define FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>
#include <FlameIDE/Templates/Optional.hpp>

// defines

namespace flame_ide
{
namespace templates
{

template<typename Context, typename Traits = DefaultTraits<Context>>
class MaybeMonad: public Traits
{
public:
	using Me = MaybeMonad<Context, Traits>;
	using Optional = typename ::flame_ide::templates::Optional<Context, Traits>;

	MaybeMonad() noexcept = default;
	MaybeMonad(const Me &) noexcept = default;
	MaybeMonad(Me &&) noexcept = default;

	MaybeMonad(const Optional &context) noexcept;
	MaybeMonad(Optional &&context) noexcept;

	~MaybeMonad() noexcept = default;

	template<typename Function>
	auto with(Function &&function) -> MaybeMonad< RemoveAllType<decltype(function())> >;

	template<typename Function>
	Me &go(Function &&function);
private:
	Optional context;
};

template<typename Context, typename Traits = ::flame_ide::DefaultTraits<Context>>
MaybeMonad<Context, Traits> maybe(Optional<Context, Traits> context);

} // namespace templates
} // namespace flame_ide

// impl

namespace flame_ide
{
namespace templates
{

template<typename Context, typename Traits>
MaybeMonad<Context, Traits>::MaybeMonad(const Optional &context) noexcept :
		context{ context }
{}

template<typename Context, typename Traits>
MaybeMonad<Context, Traits>::MaybeMonad(Optional &&context) noexcept :
		context{ ::flame_ide::move(context) }
{}

template<typename Context, typename Traits>
template<typename Function>
auto MaybeMonad<Context, Traits>::with(Function &&function)
		-> MaybeMonad< RemoveAllType<decltype(function)> >
{
	static_assert(ComparingTypes<void, decltype(function())>::VALUE, "");
}

template<typename Context, typename Traits>
template<typename Function>
MaybeMonad<Context, Traits>& MaybeMonad<Context, Traits>::go(Function &&function)
{}


} // namespace templates
} // namespace flame_ide

#endif // FLAMEIDE_TEMPLATES_MAYBEMONAD_HPP
