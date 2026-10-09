#ifndef HANDLER_INTERNAL_UDP_MESSAGE_HPP
#define HANDLER_INTERNAL_UDP_MESSAGE_HPP

#include <FlameIDE/Common/FunctorBase.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Os/Threads/Spin.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Types.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{

struct MessageData
{
	::flame_ide::templates::StaticArray<
		::flame_ide::byte_t, Constants::MESSAGE_SIZE
	> bytes;
	::flame_ide::Types::ssize_t size = 0;
};

struct MessageReader: public ::flame_ide::FunctorBase<void, const MessageData &>
{
	virtual ~MessageReader() noexcept override = default;
	virtual void operator()(const MessageData &) noexcept override = 0;
};

struct MessageWriter: public ::flame_ide::FunctorConstBase<void, MessageData &>
{
	virtual ~MessageWriter() noexcept override = default;
	virtual void operator()(MessageData &) const noexcept override = 0;
};

struct Message: public MessageData
{
	using MessageData::bytes;
	using MessageData::size;

	mutable MessageState state = MessageState::EMPTY;
	mutable os::threads::Spin spin;

	void onWrite(MessageWriter &writer) noexcept;
	void onRead(MessageReader &reader) noexcept;

protected:
	::flame_ide::templates::Range<flame_ide::byte_t *> range() noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_MESSAGE_HPP
