#ifndef FLAMEIDE_TEMPLATES_VARIANT_HPP
#define FLAMEIDE_TEMPLATES_VARIANT_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

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
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer get();

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst get() const;

	template<typename T>
	bool set(const T &object);

	template<typename T>
	bool set(T &&object);

	bool assign(Types::ssize_t index, const Me &me);

	bool assign(Types::ssize_t index, Me &&me);

	bool reset(Types::ssize_t index);

	bool equal(const Me &varianStruct, Types::ssize_t index);
};

template<typename Arg, typename ...Args>
struct VariantStruct<Arg, Args...>
{
	using Me = VariantStruct<Arg, Args...>;

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer get();

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst get() const;

	template<typename T>
	Types::ssize_t set(const T &object);

	template<typename T>
	Types::ssize_t set(T &&object);

	bool assign(Types::ssize_t index, const Me &me);

	bool assign(Types::ssize_t index, Me &&me);

	bool reset(Types::ssize_t index);

	bool equal(const Me &varianStruct, Types::ssize_t index);

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
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer get();

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst get() const;

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

	bool equal(const Me &, Types::ssize_t)
	{
		return false;
	}
};

template<bool IS_SAME_TYPES>
struct VariantStructGetterSetter
{
	template<typename T, typename Arg, typename ...Args> static inline
	Types::ssize_t set(VariantStruct<Arg, Args...> &me, const T &object);

	template<typename T, typename Arg, typename ...Args> static inline
	Types::ssize_t set(VariantStruct<Arg, Args...> &me, T &&object);

	template<typename T, typename Arg, typename ...Args> static inline
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
	get(VariantStruct<Arg, Args...> &me);

	template<typename T, typename Arg, typename ...Args> static inline
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
	getConst(const VariantStruct<Arg, Args...> &me);
};

template<>
struct VariantStructGetterSetter<false>
{
	template<typename T, typename Arg, typename ...Args> static inline
	Types::ssize_t set(VariantStruct<Arg, Args...> &me, const T &object);

	template<typename T, typename Arg, typename ...Args> static inline
	Types::ssize_t set(VariantStruct<Arg, Args...> &me, T &&object);

	template<typename T, typename Arg, typename ...Args> static inline
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
	get(VariantStruct<Arg, Args...> &me);

	template<typename T, typename Arg, typename ...Args> static inline
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
	getConst(const VariantStruct<Arg, Args...> &me);
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
	using GetTypeByIndex = flame_ide::GetTypeByIndex<INDEX, Arg, Args...>;

	Variant() noexcept;

	Variant(const Me &variant) noexcept;

	Variant(Me &&variant) noexcept;

	template<typename T>
	Variant(const T &initObject) noexcept;

	template<typename T>
	Variant(T &&initObject) noexcept;

	~Variant() noexcept;

	Me &operator=(const Me &me) noexcept;
	Me &operator=(Me &&me) noexcept;

	bool operator==(const Me &) noexcept;
	bool operator!=(const Me &) noexcept;

	operator bool() const noexcept;

	bool isSet() const noexcept;

	void reset() noexcept;

	template<Types::size_t INDEX>
	typename GetTypeByIndex<INDEX>::Type *get();

	template<Types::size_t INDEX>
	const typename GetTypeByIndex<INDEX>::Type *get() const;

	template<typename T>
	Types::ssize_t set(T &&object);

	template<typename T>
	Types::ssize_t set(const T &object);

	Types::ssize_t getCurrentIndex() const;

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer get();

	template<typename T>
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst get() const;

	template<typename T>
	bool get(T &object) const;

private:
	template<typename TT, bool IS_SAME>
	struct InitStruct: public flame_ide::NonCreational
	{};

	template<typename TT>
	struct InitStruct<TT, false>: public flame_ide::NonCreational
	{
		static void exec(Me &me, const TT &initObject)
		{
			me.currentIndex = me.value.set(initObject);
		}
		static void execMove(Me &me, TT &&initObject)
		{
			me.currentIndex = me.value.set(move(initObject));
		}
	};

	template<typename TT>
	struct InitStruct<TT, true>: public flame_ide::NonCreational
	{
		static void exec(Me &itsMe, const Me &me)
		{
			if (me.getCurrentIndex() >= 0)
			{
				itsMe.value.assign(me.getCurrentIndex(), me.value);
				itsMe.currentIndex = me.getCurrentIndex();
			}
		}
		static void execMove(Me &itsMe, Me &&me)
		{
			if (me.getCurrentIndex() >= 0)
			{
				itsMe.value.assign(me.getCurrentIndex(), move(me.value));
				itsMe.currentIndex = me.getCurrentIndex();
			}
		}
	};

	static_assert(IsUniqueParameterPack<Arg, Args...>::VALUE
			, "Paramter pack is not unique.");

	VariantStruct value;
	Types::ssize_t currentIndex;
};

}}

namespace flame_ide
{namespace templates
{

namespace variant_utils
{

template<typename Arg, typename ...Args> template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
VariantStruct<Arg, Args...>::get()
{
	return VariantStructGetterSetter<isSameTypes<T, Arg>()>::template get<T>(*this);
}

template<typename Arg, typename ...Args> template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
VariantStruct<Arg, Args...>::get() const
{
	return VariantStructGetterSetter<isSameTypes<T, Arg>()>
			::template getConst<T>(*this);
}

template<typename Arg, typename ...Args> template<typename T>
Types::ssize_t VariantStruct<Arg, Args...>::set(const T &object)
{
	return VariantStructGetterSetter<isSameTypes<T,Arg>()>::set(*this, object);
}

template<typename Arg, typename ...Args> template<typename T>
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
		placementNew<Arg>(&data.arg, me.data.arg);
	}
	else
	{
		result = data.pack.assign(index - 1, me.data.pack);
	}
	return result;
}

template<typename Arg, typename ...Args>
bool VariantStruct<Arg, Args...>::assign(Types::ssize_t index, Me &&me)
{
	bool result = true;
	if (!index)
	{
		placementNew<Arg>(&data.arg, move(me.data.arg));
	}
	else
	{
		result = data.pack.assign(index - 1, move(me.data.pack));
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
		result = data.pack.reset(index - 1);
	}
	return result;
}

template<typename Arg, typename ...Args>
bool VariantStruct<Arg, Args...>::equal(const Me &variantStruct, Types::ssize_t index)
{
	if (index == 0)
	{
		return data.arg == variantStruct.data.arg;
	}
	else
	{
		return data.pack.equal(variantStruct.data.pack, --index);
	}
}

template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
VariantStruct<>::get()
{
	return nullptr;
}

template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
VariantStruct<>::get() const
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

template<bool IS_SAME_TYPES> template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<IS_SAME_TYPES>::set(
		VariantStruct<Arg, Args...> &me, T &&object)
{
	placementNew<T>(&me.data.arg, move(object));
	return Types::ssize_t(0);
}

template<bool IS_SAME_TYPES> template<typename T, typename Arg, typename ...Args> inline
typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
VariantStructGetterSetter<IS_SAME_TYPES>::get(VariantStruct<Arg, Args...> &me)
{
	return &me.data.arg;
}

template<bool IS_SAME_TYPES> template<typename T, typename Arg, typename ...Args> inline
typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
VariantStructGetterSetter<IS_SAME_TYPES>::getConst(const VariantStruct<Arg, Args...> &me)
{
	return &me.data.arg;
}

template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<false>::set(
		VariantStruct<Arg, Args...> &me, const T &object)
{
	Types::ssize_t result = me.data.pack.set(object);
	return (result < 0) ? result : ++result;
}

template<typename T, typename Arg, typename ...Args> inline
Types::ssize_t VariantStructGetterSetter<false>::set(
		VariantStruct<Arg, Args...> &me, T &&object)
{
	Types::ssize_t result = me.data.pack.set(move(object));
	return (result < 0) ? result : ++result;
}

template<typename T, typename Arg, typename ...Args> inline
typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
VariantStructGetterSetter<false>::get(VariantStruct<Arg, Args...> &me)
{
	return me.data.pack.template get<T>();
}

template<typename T, typename Arg, typename ...Args> inline
typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
VariantStructGetterSetter<false>::getConst(const VariantStruct<Arg, Args...> &me)
{
	return me.data.pack.template get<T>();
}

} // namespace variant_utils

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant() noexcept : currentIndex(-1)
{}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(const Me &variant) noexcept
{
	value.assign(variant.getCurrentIndex(), variant.value);
	currentIndex = variant.getCurrentIndex();
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::Variant(Me &&variant) noexcept
{
	value.assign(variant.getCurrentIndex(), move(variant.value));
	currentIndex = variant.getCurrentIndex();
}

template<typename Arg, typename ...Args> template<typename T>
Variant<Arg, Args...>::Variant(const T &initObject) noexcept
{
	InitStruct<
		typename RemoveAll<T>::Type
		, ComparingTypes<Me, typename RemoveAll<T>::Type>::VALUE
	>::exec(*this, initObject);
}

template<typename Arg, typename ...Args> template<typename T>
Variant<Arg, Args...>::Variant(T &&initObject) noexcept
{
	InitStruct<
		typename RemoveAll<T>::Type
		, ComparingTypes<Me, typename RemoveAll<T>::Type>::VALUE
	>::execMove(*this, move(initObject));
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...>::~Variant() noexcept
{
	reset();
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(const Me &variant) noexcept
{
	if (&variant != this && variant.isSet())
	{
		reset();
		value.assign(variant.getCurrentIndex(), variant.value);
		currentIndex = variant.getCurrentIndex();
	}
	return *this;
}

template<typename Arg, typename ...Args>
Variant<Arg, Args...> &Variant<Arg, Args...>::operator=(Me &&variant) noexcept
{
	if (&variant != this && variant.isSet())
	{
		reset();
		value.assign(variant.getCurrentIndex(), move(variant.value));
		currentIndex = variant.getCurrentIndex();
	}
	return *this;
}

template<typename Arg, typename ...Args>
bool Variant<Arg, Args...>::operator==(const Me &variant) noexcept
{
	if (isSet() && variant.isSet() && getCurrentIndex() == variant.getCurrentIndex())
	{
		return value.equal(variant.value, getCurrentIndex());
	}
	return false;
}

template<typename Arg, typename ...Args>
bool Variant<Arg, Args...>::operator!=(const Me &variant) noexcept
{
	return !(*this == variant);
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
{
	if (isSet())
	{
		value.reset(getCurrentIndex());
		currentIndex = -1;
	}
}

template<typename Arg, typename ...Args> template<Types::size_t INDEX>
typename GetTypeByIndex<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get()
{
	using Type = typename GetTypeByIndex<INDEX>::Type;
	return value.template get<Type>();
}

template<typename Arg, typename ...Args> template<Types::size_t INDEX>
const typename GetTypeByIndex<INDEX, Arg, Args...>::Type *Variant<Arg, Args...>::get() const
{
	using Type = typename GetTypeByIndex<INDEX>::Type;
	if (isSet())
	{
		return value.template get<Type>();
	}
	else
	{
		return nullptr;
	}
}

template<typename Arg, typename ...Args> template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(T &&object)
{
	reset();
	currentIndex = value.set(move(object));
	return getCurrentIndex();
}

template<typename Arg, typename ...Args> template<typename T>
Types::ssize_t Variant<Arg, Args...>::set(const T &object)
{
	reset();
	currentIndex = value.set(object);
	return getCurrentIndex();
}

template<typename Arg, typename ...Args>
Types::ssize_t Variant<Arg, Args...>::getCurrentIndex() const
{
	return currentIndex;
}

template<typename Arg, typename ...Args> template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::Pointer
Variant<Arg, Args...>::get()
{
	constexpr Types::ssize_t TYPE_INDEX = GetIndexOfType<T, Arg, Args...>::INDEX;
	if (TYPE_INDEX == getCurrentIndex() && isSet())
	{
		return value.template get<T>();
	}
	else
	{
		return nullptr;
	}
}

template<typename Arg, typename ...Args> template<typename T>
typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst
Variant<Arg, Args...>::get() const
{
	constexpr Types::ssize_t TYPE_INDEX = GetIndexOfType<T, Arg, Args...>::INDEX;
	if (TYPE_INDEX == getCurrentIndex() && isSet())
	{
		return value.template get<T>();
	}
	else
	{
		return nullptr;
	}
}

template<typename Arg, typename ...Args> template<typename T>
bool Variant<Arg, Args...>::get(T &object) const
{
	typename DefaultTraits<typename RemoveAll<T>::Type>::PointerToConst obj = get();
	if (obj)
	{
		object = *obj;
		return true;
	}
	return false;
}

}}

#endif // FLAMEIDE_TEMPLATES_VARIANT_HPP
