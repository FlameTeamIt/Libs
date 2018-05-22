#ifndef TEMPLATES_TUPLE_HPP
#define TEMPLATES_TUPLE_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

namespace tuple_utils
{

template<SizeTraits::SizeType INDEX, typename ...Args>
struct Getter;

template<SizeTraits::SizeType INDEX, typename ...Args>
class ConstGetter;

}

template<typename ...Args>
class Tuple;

}}

namespace flame_ide
{namespace templates
{

namespace tuple_utils
{

// Getter

template<SizeTraits::SizeType INDEX, typename ...Args>
struct Getter
{
	static typename GetTypeByIndex<INDEX, Args...>::Type &get();
};

template<SizeTraits::SizeType INDEX, typename Arg, typename ...Args>
struct Getter<INDEX, Arg, Args...>
{
	using Tuple = typename DefaultTraits<
		flame_ide::templates::Tuple<Arg, Args...>
	>::Type;
	using TupleReference = typename DefaultTraits<Tuple>::Reference;
	using Type = typename GetTypeByIndex<INDEX, Arg, Args...>::Type;

	static Type &get(TupleReference tuple) noexcept
	{
		return Getter<INDEX - 1, Args...>::get(tuple);
	}
};

template<typename Arg, typename ...Args>
struct Getter<SizeTraits::SizeType(0), Arg, Args...>
{
	using Tuple = typename DefaultTraits<
		flame_ide::templates::Tuple<Arg, Args...>
	>::Type;
	using TupleReference = typename DefaultTraits<Tuple>::Reference;

	static Arg &get(TupleReference tuple) noexcept
	{
		return tuple.get();
	}
};

template<SizeTraits::SizeType INDEX>
struct Getter<INDEX>
{
	void get()
	{
		static_assert(INDEX, "Invalid INDEX argument.");
	}
};

template<SizeTraits::SizeType INDEX, typename ...Args>
class ConstGetter
{
	using Tuple = flame_ide::templates::Tuple<Args...>;
	using TupleConstReference = typename DefaultTraits<Tuple>::ConstReference;
	using Type = typename GetTypeByIndex<INDEX, Args...>::Type;

	const Type &get(TupleConstReference tuple) const
	{
		return Getter<INDEX - 1, Args...>::get(tuple);
	}
};

template<typename Arg, typename ...Args>
struct ConstGetter<SizeTraits::SizeType(0), Arg, Args...>
{
	using Tuple = flame_ide::templates::Tuple<Arg, Args...>;
	using TupleConstReference = typename DefaultTraits<Tuple>::ConstReference;

	static Arg &get(TupleConstReference tuple) noexcept
	{
		return tuple.get();
	}
};

}

template<typename ...Args>
class Tuple
{};

template<typename Arg, typename ...Args>
class Tuple<Arg, Args...>: public Tuple<Args...>
{
public:
	using Me = Tuple<Arg, Args ...>;
	using Parent = Tuple<Args ...>;

	Tuple() noexcept = default;
	Tuple(const Me &) noexcept = default;
	Tuple(Me &&) noexcept = default;
	Tuple(const Arg &argHead, const Args &...args) noexcept;
	Tuple(Arg &&argHead, Args &&...args) noexcept;
	~Tuple() noexcept = default;
	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	typename DefaultTraits<Arg>::Reference get() noexcept
	{
		return object;
	}
	typename DefaultTraits<Arg>::ConstReference get() const noexcept
	{
		return object;
	}

	template<SizeTraits::SizeType INDEX>
	auto &get() noexcept
	{
		return tuple_utils::Getter<INDEX, Arg, Args...>::get(*this);
	}

	template<SizeTraits::SizeType INDEX>
	auto &get() const noexcept
	{
		return tuple_utils::ConstGetter<INDEX, Arg, Args...>::get(*this);
	}

private:
	Arg object;
};

template<>
class Tuple<>
{
	using Me = Tuple<>;
};

}}

namespace flame_ide
{namespace templates
{

template<typename ArgHead, typename ...Args>
Tuple<ArgHead, Args...>::Tuple(const ArgHead &argHead, const Args &...args) noexcept
		: Parent(args...), object(argHead)
{}

template<typename ArgHead, typename ...Args>
Tuple<ArgHead, Args...>::Tuple(ArgHead &&argHead, Args &&...args) noexcept
	: Parent(move(args)...), object(move(argHead))
{}

}}

#endif // TEMPLATES_TUPLE_HPP
