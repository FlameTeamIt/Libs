#ifndef HANDLERINTERNALUDPTYPES_HPP
#define HANDLERINTERNALUDPTYPES_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>

namespace flame_ide
{namespace os
{namespace network
{namespace udp
{

enum class MessageState
{
	EMPTY
	, PROCESSING
	, READY
};

template<typename MessageType, Types::size_t SIZE>
struct ActualData
{
	using Messages = ::flame_ide::templates::StaticArray<
		templates::UniquePointer<MessageType>, SIZE
	>;
	using MessagesCircularIterator =
			templates::defaults::CircularForwardIterator<
				typename Messages::Iterator
			>;

	Messages messages;
	MessagesCircularIterator first = MessagesCircularIterator{
			messages.begin()
			, templates::makeRange(messages.begin(), messages.end())
	};
	MessagesCircularIterator last = first;
	mutable threads::Spin spin;
};

}}}} // namespace flame_ide::os::network::udp

#endif // HANDLERINTERNALUDPTYPES_HPP
