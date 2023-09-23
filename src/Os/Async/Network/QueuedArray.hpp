#ifndef ASYNC_NETWORK_QUEUEDARRAY_HPP
#define ASYNC_NETWORK_QUEUEDARRAY_HPP

#include <FlameIDE/../../src/Os/Async/Network/Types.hpp>
#include <FlameIDE/Templates/Expected.hpp>
#include <FlameIDE/Templates/Pointers.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

template<typename Type, Types::size_t SIZE>
class QueuedArray
{
public:
	operator bool() const noexcept;

	bool init(Type initValue = {}) noexcept;

	bool push(Type value) noexcept;
	templates::Expected<Type, bool> pop(Type initValue = {}) noexcept;

private:
	using Array = templates::StaticArray<Type, SIZE>;
	using Pointer = templates::UniquePointer<Array>;
	using Iterator = templates::defaults::CircularForwardIterator<Type *>;

private:
	Pointer pointer = Pointer::makeEmpty();
	Iterator first;
	Iterator last;
	Types::size_t count = 0;
	mutable threads::Spin spin;
};

template<typename Array>
using ConcreteQueueArrayByArray = QueuedArray<typename Array::Type, Array::CAPACITY>;

}}}} // namespace flame_ide::os::async::network

namespace flame_ide
{namespace os
{namespace async
{namespace network
{

template<typename Type, Types::size_t SIZE>
QueuedArray<Type, SIZE>::operator bool() const noexcept
{
	os::threads::Locker locker{ spin };
	return (pointer);
}

template<typename Type, Types::size_t SIZE>
bool QueuedArray<Type, SIZE>::init(Type initValue) noexcept
{
	os::threads::Locker locker{ spin };

	if (!(pointer = Pointer{}))
		return false;

	for (auto &i : *pointer)
		i = initValue;

	const auto data = pointer->data();
	const auto capacity = pointer->capacity();
	first = last = Iterator{ data, templates::makeRange(data, data + capacity) };

	return true;
}

template<typename Type, Types::size_t SIZE>
bool QueuedArray<Type, SIZE>::push(Type value) noexcept
{
	os::threads::Locker locker{ spin };

	if (count == pointer->capacity())
		return false;

	*last = value;
	++last;
	++count;

	return true;
}

template<typename Type, Types::size_t SIZE>
templates::Expected<Type, bool>
QueuedArray<Type, SIZE>::pop(Type initValue) noexcept
{
	os::threads::Locker locker{ spin };

	if (!count)
		return templates::Expected<Type, bool>{ false };

	const Type value = *first;
	*first = initValue;
	++first;
	--count;

	return templates::Expected<Type, bool>{ value };
}

}}}} // namespace flame_ide::os::async::network

#endif // ASYNC_NETWORK_QUEUEDARRAY_HPP
