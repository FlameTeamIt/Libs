#ifndef TEMPLATES_VARIANT_HPP
#define TEMPLATES_VARIANT_HPP

#include <Templates/Traits.hpp>

namespace flame_ide
{namespace templates
{

namespace variant_utils
{

template<typename Arg, typename ...Args>
struct VariantStruct
{
	union
	{
		Arg arg;
		VariantStruct<Args...> pack;
	} data;
};

}

template<typename Arg, typename ...Args>
class Variant
{
public:
	using Me = Variant<Arg, Args...>;
	using Struct = variant_utils::VariantStruct<Arg, Args...>;

	template<Types::size_t INDEX>
	using TypeGetter = flame_ide::templates::TypeGetter<INDEX, Arg, Args...>;

	Variant()
	{}

	Variant(const Me&);
	Variant(Me &&);

	template<typename T>
	Variant(const T &value);

	template<typename T>
	Variant(T &&value);

	template<Types::size_t INDEX>
	typename TypeGetter<INDEX>::Type &get();

	template<Types::size_t INDEX>
	const typename TypeGetter<INDEX>::Type &get() const;

	template<typename T>
	Types::size_t set(T &&);

	template<typename T>
	Types::size_t set(const T &);

	Types::size_t getCurrentIndex() const;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	bool get(T& object) const;

private:
	struct Getter
	{
		template<Types::size_t INDEX>
		typename TypeGetter<INDEX>::Type &operator()(Me &me);
	};

	struct GetterConst
	{
		template<Types::size_t INDEX>
		typename TypeGetter<INDEX>::Type &operator()(const Me &me);
	};

	struct Setter
	{
		template<typename T>
		void operator()(Me &me, T&&);

		template<Types::size_t INDEX, typename T>
		void operator()(Me &me, const T&);
	};

	struct GetterConst
	{
		template<Types::size_t INDEX>
		typename TypeGetter<INDEX>::Type &operator()(const Me &me);
	};

	constexpr static bool VALUE = IsUniqueParameterPack<Arg, Args...>::VALUE;
	static_assert(VALUE, "Paramter pack is not unique.");

	Struct value;
	Types::size_t currentIndex;
};

template<typename Arg>
class Variant<Arg>
{
public:
	template<typename T>
	T &get();

	template<typename T>
	const T &get() const;

	template<typename T>
	T &get();

	template<typename T>
	size_t set(const T &);
private:
	Arg value;
};

}}

#endif // TEMPLATES_VARIANT_HPP
