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
class Getter;

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
{};

template<SizeTraits::SizeType INDEX, typename ArgsHead, typename ...Args>
struct Getter<INDEX, ArgsHead, Args...>
{
	using Tuple = typename DefaultTraits<
		flame_ide::templates::Tuple<ArgsHead, Args...>
	>::Type;
	using TupleReference = typename DefaultTraits<Tuple>::Reference;

	static auto &get(TupleReference tuple) noexcept
	{
		return Getter<INDEX - 1, Args...>::get(tuple);
	}
};

template<typename ArgsHead, typename ...Args>
struct Getter<SizeTraits::SizeType(0), ArgsHead, Args...>
{
	using Tuple = typename DefaultTraits<
		flame_ide::templates::Tuple<ArgsHead, Args...>
	>::Type;
	using TupleReference = typename DefaultTraits<Tuple>::Reference;

	static auto &get(TupleReference tuple) noexcept
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
	using TupleConstReference = typename DefaultTraits<
		flame_ide::templates::Tuple<Args...>
	>::ConstReference;

	template<SizeTraits::SizeType index>
	const auto &get(TupleConstReference tuple) const
	{
		return Getter<INDEX - 1, Args...>::get(tuple);
	}
};

template<typename ArgsHead, typename ...Args>
struct ConstGetter<SizeTraits::SizeType(0), ArgsHead, Args...>
{
	using Tuple = typename DefaultTraits<
		flame_ide::templates::Tuple<ArgsHead, Args...>
	>::Type;
	using TupleReference = typename DefaultTraits<Tuple>::ConstReference;

	static auto &get(TupleReference tuple) noexcept
	{
		return tuple.get();
	}
};

}

template<typename ...Args>
class Tuple
{};

template<typename ArgHead, typename ...Args>
class Tuple<ArgHead, Args...>: public Tuple<Args...>
{
public:
	using Me = Tuple<ArgHead, Args ...>;
	using Parent = Tuple<Args ...>;

	Tuple() noexcept = default;
	Tuple(const Me &) noexcept = default;
	Tuple(Me &&) noexcept = default;
	Tuple(const ArgHead &argHead, const Args &...args) noexcept;
	Tuple(ArgHead &&argHead, Args &&...args) noexcept;
	~Tuple() noexcept = default;
	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	typename ContainerTraits<ArgHead>::Reference get() noexcept
	{
		return object;
	}
	typename ContainerTraits<ArgHead>::ConstReference get() const noexcept
	{
		return object;
	}

	template<SizeTraits::SizeType index>
	auto &get() noexcept
	{
		return tuple_utils::Getter<index, ArgHead, Args...>::get(*this);
	}

	template<SizeTraits::SizeType index>
	auto &get() const noexcept
	{
		return tuple_utils::ConstGetter<index, ArgHead, Args...>::get(*this);
	}

private:
	ArgHead object;
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
