#ifndef HANDLER_INTERNAL_UDP_ENDPOINT_HPP
#define HANDLER_INTERNAL_UDP_ENDPOINT_HPP

#include <FlameIDE/Common/Traits/Functional.hpp>
#include <FlameIDE/Templates/Optional.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/ActualData.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

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
	const ActualInput &input() const noexcept;

	ActualOutput &output() noexcept;
	const ActualOutput &output() const noexcept;

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
const typename Endpoint<
	EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE
>::ActualInput &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::input() const noexcept
{
	return actualInput;
}

template<
		typename EndpointData
		, typename MessageType
		, ::flame_ide::Types::size_t INPUT_SIZE
		, ::flame_ide::Types::size_t OUTPUT_SIZE
		>
typename Endpoint<
EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE
>::ActualOutput &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::output() noexcept
{
	return actualOutput;
}

template<
	typename EndpointData
	, typename MessageType
	, ::flame_ide::Types::size_t INPUT_SIZE
	, ::flame_ide::Types::size_t OUTPUT_SIZE
>
const typename Endpoint<
	EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE
>::ActualOutput &
Endpoint<EndpointData, MessageType, INPUT_SIZE, OUTPUT_SIZE>::output() const noexcept
{
	return actualOutput;
}

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_ENDPOINT_HPP
