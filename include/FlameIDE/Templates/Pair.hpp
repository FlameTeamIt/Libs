#ifndef FLAMEIDE_TEMPLATES_PAIR_HPP
#define FLAMEIDE_TEMPLATES_PAIR_HPP

#include <FlameIDE/Templates/Tuple.hpp>

namespace flame_ide
{namespace templates
{

template<typename First, typename Second>
class Pair: private Tuple<First, Second>
{
public:
	using Me = Pair<First, Second>;
	using Parent = Tuple<First, Second>;

	Pair() noexcept = default;
	Pair(const Me &pair) noexcept;
	Pair(Me &&pair) noexcept;
	Pair(const First &first, const Second &second) noexcept;
	Pair(First &&first, Second &&second) noexcept;
	~Pair() noexcept = default;

	Me &operator=(const Me &pair) noexcept;
	Me &operator=(Me &&pair) noexcept;

	First &first() noexcept;
	Second &second() noexcept;

	const First &first() const noexcept;
	const Second &second() const noexcept;
};

}} // namespace flame_ide::templates

namespace flame_ide
{namespace templates
{

template<typename First, typename Second>
Pair<First, Second>::Pair(const Me &pair) noexcept : Parent{ pair }
{}

template<typename First, typename Second>
Pair<First, Second>::Pair(Me &&pair) noexcept : Parent{ flame_ide::move(pair) }
{}

template<typename First, typename Second>
Pair<First, Second>::Pair(const First &first, const Second &second) noexcept :
		Parent{ first, second }
{}

template<typename First, typename Second>
Pair<First, Second>::Pair(First &&first, Second &&second) noexcept :
		Parent{ flame_ide::move(first), flame_ide::move(second) }
{}

template<typename First, typename Second>
Pair<First, Second> &Pair<First, Second>::operator=(const Me &pair) noexcept
{
	Parent::operator=(pair);
	return *this;
}

template<typename First, typename Second>
Pair<First, Second> &Pair<First, Second>::operator=(Me &&pair) noexcept
{
	Parent::operator=(flame_ide::move(pair));
	return *this;
}

template<typename First, typename Second>
First &Pair<First, Second>::first() noexcept
{
	return Parent::template get<0>();
}

template<typename First, typename Second>
Second &Pair<First, Second>::second() noexcept
{
	return Parent::template get<1>();
}

template<typename First, typename Second>
const First &Pair<First, Second>::first() const noexcept
{
	return Parent::template get<0>();
}

template<typename First, typename Second>
const Second &Pair<First, Second>::second() const noexcept
{
	return Parent::template get<1>();
}

}} // namespace flame_ide::templates

#endif // FLAMEIDE_TEMPLATES_PAIR_HPP
