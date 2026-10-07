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

///
/// @brief The ActualData class
///
template<typename MessageType, ::flame_ide::Types::size_t ACTUAL_DATA_CAPACITY>
struct ActualData
{
public:
	static constexpr ::flame_ide::Types::size_t CAPACITY = ACTUAL_DATA_CAPACITY;

	using Messages = flame_ide::templates::StaticArray<
		flame_ide::templates::UniquePointer<MessageType>, ACTUAL_DATA_CAPACITY
	>;
	using MessagesCircularIterator =
			::flame_ide::templates::defaults::CircularForwardIterator<
				typename Messages::Iterator
			>;

	/// @brief Get empty message
	/// @note Message object has "PROCESSING" state
	::flame_ide::ReferenceWrapper<MessageType> getEmptyMessage() noexcept;

	/// @brief
	/// @note Message object has "PROCESSING" state
	::flame_ide::ReferenceWrapper<MessageType> getFilledMessage() noexcept;

	/// @brief
	::flame_ide::Types::ssize_t getFilledMessageSize() const noexcept;

	/// @brief
	::flame_ide::Types::size_t amountOfMessages() const noexcept;

private:
	::flame_ide::Types::size_t amount = 0;

	Messages messages;
	MessagesCircularIterator first = MessagesCircularIterator{
			messages.begin(), templates::makeRange(messages)
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

	{
		os::threads::Locker lockMessage{ first->pointer()->spin };
		if (last->pointer()->state == MessageState::PROCESSING)
			return nullptr;
	}

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

	{
		os::threads::Locker lockMessage{ first->pointer()->spin };
		if (
				first->pointer()->state == MessageState::PROCESSING
				|| first->pointer()->state == MessageState::EMPTY
		)
			return nullptr;
	}

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

template<typename MessageType, Types::size_t SIZE>
::flame_ide::Types::size_t
ActualData<MessageType, SIZE>::amountOfMessages() const noexcept
{
	os::threads::Locker lock{ spin };

	return amount;
}

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_ACTUAL_DATA_HPP
