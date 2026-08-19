#ifndef HANDLER_INTERNAL_UDP_ACTUAL_DATA_HPP
#define HANDLER_INTERNAL_UDP_ACTUAL_DATA_HPP

#include <FlameIDE/Common/ReferenceWrapper.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

template<typename MessageType, ::flame_ide::Types::size_t SIZE>
struct ActualData
{
public:
	using Messages = flame_ide::templates::StaticArray<
		flame_ide::templates::UniquePointer<MessageType>, SIZE
	>;
	using MessagesCircularIterator =
			::flame_ide::templates::defaults::CircularForwardIterator<
				typename Messages::Iterator
			>;

	::flame_ide::ReferenceWrapper<MessageType> getEmptyMessage() noexcept;
	::flame_ide::ReferenceWrapper<MessageType> getFilledMessage() noexcept;

	::flame_ide::Types::ssize_t getFilledMessageSize() const noexcept;

private:
	::flame_ide::Types::size_t amount = 0;

	Messages messages;
	MessagesCircularIterator first = MessagesCircularIterator{
			messages.begin(), templates::makeRange(messages.begin(), messages.end())
	};
	MessagesCircularIterator last = first;

	mutable os::threads::Spin spin;
};

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

template<typename MessageType, Types::size_t SIZE>
::flame_ide::ReferenceWrapper<MessageType>
ActualData<MessageType, SIZE>::getEmptyMessage() noexcept
{
	os::threads::Locker lock{ spin };

	if (amount == SIZE)
		return nullptr;

	auto result = last;
	++amount;
	++last;

	{
		os::threads::Locker lockMessage{ result->pointer()->spin };
		result->pointer()->state = MessageState::PROCESSING;
	}

	return result->pointer();
}

template<typename MessageType, Types::size_t SIZE>
::flame_ide::ReferenceWrapper<MessageType>
ActualData<MessageType, SIZE>::getFilledMessage() noexcept
{
	os::threads::Locker lock{ spin };

	if ((first == last) && (amount == 0))
		return nullptr;

	auto result = first;
	--amount;
	++first;

	{
		os::threads::Locker lockMessage{ result->pointer()->spin };
		result->pointer()->state = MessageState::PROCESSING;
	}

	return result->pointer();
}

template<typename MessageType, Types::size_t SIZE>
::flame_ide::Types::ssize_t
ActualData<MessageType, SIZE>::getFilledMessageSize() const noexcept
{
	os::threads::Locker lock{ spin };

	if ((first == last) && (amount == 0))
		return 0;

	{
		const auto &message = *first;
		os::threads::Locker messageLocker{ message->spin };
		if (message->state == MessageState::EMPTY)
			return 0;
		return message->size;
	}
}

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_ACTUAL_DATA_HPP
