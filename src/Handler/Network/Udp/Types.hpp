#ifndef HANDLERINTERNALUDPTYPES_HPP
#define HANDLERINTERNALUDPTYPES_HPP

#include <FlameIDE/Common/Traits/Numbers.hpp>

#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/Os/Threads/Spin.hpp>
#include <FlameIDE/Os/Threads/Utils.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

enum class MessageState
{
	EMPTY
	, PROCESSING
	, READY
};

struct Message
{
	::flame_ide::templates::StaticArray<
		::flame_ide::byte_t, Constants::MESSAGE_SIZE
	> bytes;
	::flame_ide::Types::ssize_t size = 0;
	MessageState state = MessageState::EMPTY;

	mutable os::threads::Spin spin;
};

template<typename MessageType, Types::size_t SIZE>
struct ActualData
{
public:
	using Messages = flame_ide::templates::StaticArray<
		flame_ide::templates::UniquePointer<MessageType>, SIZE
	>;
	using MessagesCircularIterator =
			flame_ide::templates::defaults::CircularForwardIterator<
				typename Messages::Iterator
			>;

	MessageType *getEmptyMessage() noexcept;

	MessageType *getFilledMessage() noexcept;

private:
	::flame_ide::Types::size_t amount = 0;
	Messages messages;
	MessagesCircularIterator first = MessagesCircularIterator{
			messages.begin()
			, templates::makeRange(messages.begin(), messages.end())
	};
	MessagesCircularIterator last = first;
	mutable os::threads::Spin spin;
};

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
class Endpoint
{
public:
	using Data = EndpointData;
	using Optional = flame_ide::templates::Optional<Data>;
	using ActualInput = ActualData<MessageType, INPUT_SIZE>;
	using ActualOutput = ActualData<MessageType, OUTPUT_SIZE>;

	bool empty() const noexcept;
	void attach(EndpointData &&data) noexcept;
	EndpointData detach() noexcept;

	Optional &endpoint() noexcept;
	const Optional &endpoint() const noexcept;

	ActualInput &input() noexcept;
	ActualOutput &output() noexcept;

protected:
	Optional osEndpoint;
	ActualInput actualInput;
	ActualOutput actualOutput;
};

}}}} // namespace flame_ide::handler::network::udp

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

// ActualData

template<typename MessageType, Types::size_t SIZE>
MessageType *ActualData<MessageType, SIZE>::getEmptyMessage() noexcept
{
	os::threads::Locker lock{ spin };

	if (amount == SIZE)
		return nullptr;

	auto result = last;
	++amount;
	++last;
	return result->pointer();
}

template<typename MessageType, Types::size_t SIZE>
MessageType *ActualData<MessageType, SIZE>::getFilledMessage() noexcept
{
	os::threads::Locker lock{ spin };

	if ((first == last) && (amount == 0))
		return nullptr;

	auto result = first;
	--amount;
	++first;
	return result->pointer();
}

// Endpoint

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
bool Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::empty() const noexcept
{
	return !(osEndpoint);
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
void Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::attach(
		EndpointData &&data
) noexcept
{
	if (!empty())
		return;

	osEndpoint.set(flame_ide::move(data));
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
EndpointData
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::detach() noexcept
{
	if (empty())
		return {};

	Data data = flame_ide::move(osEndpoint.pull());
	return data;
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
typename Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::Optional &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::endpoint() noexcept
{
	return osEndpoint;
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
const typename Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::Optional &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::endpoint() const noexcept
{
	return osEndpoint;
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
typename Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::ActualInput &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::input() noexcept
{
	return actualInput;
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
typename Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::ActualOutput &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::output() noexcept
{
	return actualOutput;
}

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLERINTERNALUDPTYPES_HPP
