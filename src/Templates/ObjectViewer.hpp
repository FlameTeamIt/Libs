#ifndef TEMPLATES_OBJECTVIEWER_HPP
#define TEMPLATES_OBJECTVIEWER_HPP

#include <Common/Utils.hpp>

namespace flame_ide
{namespace templates
{

/**
 * @brief View object as byte array.
 */
template<typename T, typename ContainerTraits = flame_ide::templates::ContainerTraits<T>>
struct ObjectViewer: public NonCopy, public NonMove
{
	ObjectViewer();
	ObjectViewer(typename ContainerTraits::Pointer obj);
	ObjectViewer(typename ContainerTraits::Reference obj);

	/**
	 * @brief Clean array (object block).
	 */
	void clean() noexcept;

	/**
	 * @brief Union, whitch helping to view object.
	 */
	union Bytes
	{
		Bytes();
		Bytes(Bytes &&) = delete;
		Bytes(Bytes const &) = delete;
		Bytes(typename ContainerTraits::Pointer obj);

		typename ContainerTraits::Pointer object;
		flame_ide::templates::ContainerTraits<Types::byte_t>::Pointer array;
	} bytes;
	constexpr static SizeTraits::SizeType SIZE = sizeof(ContainerTraits::Type);
};

template<typename T, typename ContainerTraits>
ObjectViewer<T, ContainerTraits>::ObjectViewer() : bytes()
{}

template<typename T, typename ContainerTraits>
ObjectViewer<T, ContainerTraits>::ObjectViewer(typename ContainerTraits::Pointer obj) : bytes(obj)
{}

template<typename T, typename ContainerTraits>
ObjectViewer<T, ContainerTraits>::ObjectViewer(typename ContainerTraits::Reference obj) : bytes(&obj)
{}

template<typename T, typename ContainerTraits>
void ObjectViewer<T, ContainerTraits>::clean() noexcept
{
	decltype(bytes.array) iterator = bytes.array;
	for(typename ContainerTraits::SizeType i = 0; i < SIZE; ++i, ++iterator)
		iterator[i] = 0;
}

template<typename T, typename ContainerTraits>
ObjectViewer<T, ContainerTraits>::Bytes::Bytes() : object(nullptr)
{}

template<typename T, typename ContainerTraits>
ObjectViewer<T, ContainerTraits>::Bytes::Bytes(
		typename ContainerTraits::Pointer obj) : object(obj)
{}

}}

#endif // TEMPLATES_OBJECTVIEWER_HPP
