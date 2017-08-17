/*
 * file:       IntializerList.hpp
 *
 * created:    21.07.2017
 * author:     kachsheev
 */
#ifndef INTIALIZERLIST_HPP
#define INTIALIZERLIST_HPP

#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief Alternative initializer list implementation
 */
template<typename T, SizeTraits::SizeType SIZE = 64>
class InitializerList
{
public:
	using Type = typename DefaultTraits<T>::Type;
	using Pointer = typename DefaultTraits<T>::Pointer;
	using Iterator = typename DefaultTraits<T>::PointerToConst;
	using SizeType = typename SizeTraits::SizeType;

	template<typename ...Args>
	InitializerList(Args &&...args);

	~InitializerList();

	constexpr SizeType size() const noexcept;

	constexpr Iterator begin() const noexcept;

	/**
	 * @brief Return an iterator pointing to the first element of the initializer_list.
	 *
	 * @param list
	 * Initializer list.
	 */
	template<typename U, SizeTraits::SizeType SIZE1>
	typename InitializerList<U, SIZE1>::Iterator begin(
			InitializerList<U, SIZE1> list) noexcept;

	constexpr Iterator end() const noexcept;

	/**
	 * @brief Return an iterator pointing to the last element of the initializer_list.
	 *
	 * @param list
	 * Initializer list.
	 */
	template<typename U, SizeTraits::SizeType SIZE1>
	typename InitializerList<U, SIZE1>::Iterator end(
			InitializerList<U, SIZE1> list) noexcept;

private:
	template<typename U, typename ... Args>
	struct Helper;

	template<typename U, typename ArgHead, typename... Args>
	struct Helper<U, ArgHead, Args...>: public NonCreational
	{
		static inline void init(typename DefaultTraits<U>::Pointer iterator
				, ArgHead &&argHead, Args &&...args)
		{
			*iterator = static_cast<Type &&>(argHead);
			Helper<U, Args...>::init(++iterator, forward(args)...);
		}
	};

	template<typename U>
	struct Helper<U>: public NonCreational
	{
		static inline void init(Pointer)
		{}
	};

	SizeType listSize;

	Type list[SIZE];
};

}}

namespace flame_ide
{namespace templates
{

template<typename T, SizeTraits::SizeType SIZE>
template<typename ...Args>
InitializerList<T, SIZE>::InitializerList(Args &&...args) : listSize(sizeof...(Args))
{
	static_assert(SIZE >= sizeof...(Args), "ERROR: Illegal count of arguments");
	Helper<T, Args...>::init(list, forward(args)...);
}

template<typename T, SizeTraits::SizeType SIZE> constexpr
typename InitializerList<T, SIZE>::SizeType InitializerList<T, SIZE>::size() const noexcept
{
	return listSize;
}

template<typename T, SizeTraits::SizeType SIZE> constexpr
typename InitializerList<T, SIZE>::Iterator InitializerList<T, SIZE>::begin() const noexcept
{
	return list;
}

template<typename T, SizeTraits::SizeType SIZE>
template<typename U, SizeTraits::SizeType SIZE1>
typename InitializerList<U, SIZE1>::Iterator InitializerList<T, SIZE>::begin(
		InitializerList<U, SIZE1> list) noexcept
{
	return list.begin();
}

template<typename T, SizeTraits::SizeType SIZE> constexpr
typename InitializerList<T, SIZE>::Iterator InitializerList<T, SIZE>::end() const noexcept
{
	return begin() + size();
}

template<typename T, SizeTraits::SizeType SIZE>
template<typename U, SizeTraits::SizeType SIZE1>
typename InitializerList<U, SIZE1>::Iterator InitializerList<T, SIZE>::end(
		InitializerList<U, SIZE1> list) noexcept
{
	return list.end();
}

template<typename T, SizeTraits::SizeType SIZE>
InitializerList<T, SIZE>::~InitializerList()
{
	for (auto &it : *this)
	{
		it.~T();
	}
}

}}

#endif // INTIALIZERLIST_HPP
