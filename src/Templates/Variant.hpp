#ifndef TEMPLATES_VARIANT_HPP
#define TEMPLATES_VARIANT_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

namespace variant_utils
{

template<typename ...Args>
struct VariantStruct
{
	using Me = VariantStruct<Args...>;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	bool set(const T &object);

	template<typename T>
	bool set(T &&object);

	bool assign(Types::ssize_t index, const Me &me);

	bool assign(Types::ssize_t index, Me &&me);

	bool reset(Types::ssize_t index);
};

template<typename Arg, typename ...Args>
struct VariantStruct<Arg, Args...>
{
	using Me = VariantStruct<Arg, Args...>;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	Types::ssize_t set(const T &object);

	template<typename T>
	Types::ssize_t set(T &&object);

	bool assign(Types::ssize_t index, const Me &me);

	bool assign(Types::ssize_t index, Me &&me);

	bool reset(Types::ssize_t index);

	union VariantUnion
	{
		VariantUnion()
		{}
		~VariantUnion()
		{}

		Arg arg;
		VariantStruct<Args...> pack;
	} data;
};

template<>
struct VariantStruct<>
{
	using Me = VariantStruct<>;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	Types::ssize_t set(const T &object);

	template<typename T>
	Types::ssize_t set(T &&object);

	inline bool assign(Types::ssize_t, const Me &)
	{
		return false;
	}

	inline bool assign(Types::ssize_t, Me &&)
	{
		return false;
	}

	inline bool reset(Types::ssize_t)
	{
		return false;
	}
};

template<bool IS_SAME_TYPES>
struct VariantStructGetterSetter
{
	template<typename T, typename Arg, typename ...Args>
	static Types::ssize_t set(VariantStruct<Arg, Args...> &me, const T &object);

	template<typename T, typename Arg, typename ...Args>
	static Types::ssize_t set(VariantStruct<Arg, Args...> &me, T &&object);

	template<typename T, typename Arg, typename ...Args>
	static T *get(VariantStruct<Arg, Args...> &me);

	template<typename T, typename Arg, typename ...Args>
	static const T *getConst(const VariantStruct<Arg, Args...> &me);
};

template<>
struct VariantStructGetterSetter<false>
{
	template<typename T, typename Arg, typename ...Args>
	static Types::ssize_t set(VariantStruct<Arg, Args...> &me, const T &object);

	template<typename T, typename Arg, typename ...Args>
	static Types::ssize_t set(VariantStruct<Arg, Args...> &me, T &&object);

	template<typename T, typename Arg, typename ...Args>
	static T *get(VariantStruct<Arg, Args...> &me);

	template<typename T, typename Arg, typename ...Args>
	static const T *getConst(const VariantStruct<Arg, Args...> &me);
};

}

template<typename ...Args>
class Variant
{};

template<typename Arg, typename ...Args>
class Variant<Arg, Args...>
{
public:
	using Me = Variant<Arg, Args...>;
	using VariantStruct = variant_utils::VariantStruct<Arg, Args...>;

	template<Types::size_t INDEX>
	using TypeGetter = flame_ide::templates::TypeGetter<INDEX, Arg, Args...>;

	Variant() noexcept;
	Variant(const Me &me) noexcept;
	Variant(Me &&me) noexcept;

	template<typename T>
	explicit Variant(const T &initObject) noexcept;

	template<typename T>
	explicit Variant(T &&initObject);

	Me &operator=(const Me &me);
	Me &operator=(Me &&me) noexcept;

	operator bool() const noexcept;

	bool isSet() const noexcept;

	void reset() noexcept;

	template<Types::size_t INDEX>
	typename TypeGetter<INDEX>::Type *get();

	template<Types::size_t INDEX>
	const typename TypeGetter<INDEX>::Type *get() const;

	template<typename T>
	Types::ssize_t set(T &&object);

	template<typename T>
	Types::ssize_t set(const T &object);

	Types::ssize_t getCurrentIndex() const;

	template<typename T>
	T *get();

	template<typename T>
	const T *get() const;

	template<typename T>
	bool get(T &object) const;

private:
	static constexpr bool VALUE = IsUniqueParameterPack<Arg, Args...>::VALUE;
	static_assert(VALUE, "Paramter pack is not unique.");

	VariantStruct value;
	Types::ssize_t currentIndex;
};

}}

namespace flame_ide
{namespace templates
{

namespace variant_utils
{

template<typename Arg, typename ...Args>
template<typename T>
T *VariantStruct<Arg, Args...>::get()
{
	return VariantStructGetterSetter<isSameTypes<T, Arg>()>::get(*this);
}

template<typename Arg, typename ...Args>
template<typename T>
const T *VariantStruct<Arg, Args...>::get() const
{
	return VariantStructGetterSetter<isSameTypes<T, Arg>()>::getConst(*this);
}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t VariantStruct<Arg, Args...>::set(const T &object)
{
	return VariantStructGetterSetter<isSameTypes<T,Arg>()>::set(*this, object);
}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t VariantStruct<Arg, Args...>::set(T &&object)
{
	return VariantStructGetterSetter<isSameTypes<T,Arg>()>::set(*this, move(object));
}


template<typename Arg, typename ...Args>
bool VariantStruct<Arg, Args...>::assign(Types::ssize_t index, const Me &me)
{
	bool result = true;
	if (!index)
	{
		data.arg = me.data.arg;
	}
	else
	{
		result = data.template pack.assign(index - 1, me.pack);
	}
	return result;
}

template<typename Arg, typename ...Args>
bool VariantStruct<Arg, Args...>::assign(Types::ssize_t index, Me &&me)
{
	bool result = true;
	if (!index)
	{
		data.arg = move(me.data.arg);
	}
	else
	{
		result = data.template pack.assign(index - 1, move(me.pack));
	}
	return result;
}

template<typename Arg, typename ...Args>
bool VariantStruct<Arg, Args...>::reset(Types::ssize_t index)
{
	bool result = true;
	if (!index)
	{
		data.arg.~Arg();
	}
	else
	{
		result = data.template pack.reset(index - 1);
	}
	return result;
}

template<typename T>
T *VariantStruct<>::get()
{
	return nullptr;
}

template<typename T>
const T *VariantStruct<>::get() const
{
	return nullptr;
}

template<typename T>
Types::ssize_t VariantStruct<>::set(const T &)
{
	return -1;
}

template<typename T>
Types::ssize_t VariantStruct<>::set(T &&)
{
	return -1;
}

template<bool IS_SAME_TYPES>
template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<IS_SAME_TYPES>::set(
		VariantStruct<Arg, Args...> &me , const T &object)
{
	placementNew<T>(&me.data.arg, object);
	return Types::ssize_t(0);
}

template<bool IS_SAME_TYPES>
template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<IS_SAME_TYPES>::set(
		VariantStruct<Arg, Args...> &me, T &&object)
{
	placementNew<T>(&me.data.arg, move(object));
	return Types::ssize_t(0);
}

template<bool IS_SAME_TYPES>
template<typename T, typename Arg, typename ...Args> inline
T *VariantStructGetterSetter<IS_SAME_TYPES>::get(VariantStruct<Arg, Args...> &me)
{
	return &me.data.arg;
}

template<bool IS_SAME_TYPES>
template<typename T, typename Arg, typename ...Args> inline
const T *VariantStructGetterSetter<IS_SAME_TYPES>::getConst(
		const VariantStruct<Arg, Args...> &me)
{
	return &me.data.arg;
}

template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<false>::set(
		VariantStruct<Arg, Args...> &me, const T &object)
{
	Types::ssize_t result = me.data.pack.template set(object);
	return (result < 0) ? result : ++result;
}

template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<false>::set(
		VariantStruct<Arg, Args...> &me, T &&object)
{
	Types::ssize_t result = me.data.pack.template set(move(object));
	return (result < 0) ? result : ++result;
}

template<typename T, typename Arg, typename ...Args> inline
T *VariantStructGetterSetter<false>::get(VariantStruct<Arg, Args...> &me)
{
	return me.data.pack.template get<T>();
}

template<typename T, typename Arg, typename ...Args> inline
const T *VariantStructGetterSetter<false>::getConst(
		const VariantStruct<Arg, Args...> &me)
{
	return me.data.pack.template get<T>();
}

}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant() noexcept : currentIndex(-1)
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(const Me &me) noexcept
{
	// надо рекурсивно спуститься к нужно типу по индексу
	// и присвоить
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(Me &&me) noexcept
{
	// надо рекурсивно спуститься к нужно типу по индексу
	// и присвоить
}

template<typename Arg, typename ...Args>
template<typename T>
Variant<Arg, Args...>::Variant(const T &initObject) noexcept
{
	// надо рекурсивно спуститься к нужно типу по индексу
	// и присвоить
}

template<typename Arg, typename ...Args>
template<typename T>
Variant<Arg, Args...>::Variant(T &&initObject)
{
	// надо рекурсивно спуститься к нужно типу по индексу
	// и присвоить
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(const Me &me)
{
	if (&me != this && me.currentIndex > 0)
	{

	}
	return *this;
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(Me &&me) noexcept
{
	if (&me != this && me.currentIndex > 0)
	{

	}
	return *this;
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::operator bool() const noexcept
{
	return isSet();
}

template<typename Arg, typename ...Args>
bool Variant<Arg, Args...>::isSet() const noexcept
{
	return currentIndex >= 0;
}

template<typename Arg, typename ...Args>
void Variant<Arg, Args...>::reset() noexcept
{}

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
typename TypeGetter<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get()
{}

template<typename Arg, typename ...Args>
template<Types::size_t INDEX>
const typename TypeGetter<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get() const
{}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(T &&object)
{}

template<typename Arg, typename ...Args>
template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(const T &object)
{}

template<typename Arg, typename ...Args>
Types::ssize_t Variant<Arg, Args...>::getCurrentIndex() const
{}

template<typename Arg, typename ...Args>
template<typename T>
T *Variant<Arg, Args...>::get()
{}

template<typename Arg, typename ...Args>
template<typename T>
const T *Variant<Arg, Args...>::get() const
{}

template<typename Arg, typename ...Args>
template<typename T>
bool Variant<Arg, Args...>::get(T &object) const
{}

}}

#endif // TEMPLATES_VARIANT_HPP
