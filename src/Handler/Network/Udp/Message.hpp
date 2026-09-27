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
	MessageState state = MessageState::EMPTY;
};

class MessageVisitor:
		public ::flame_ide::FunctorBase<void, MessageData &>
		, public ::flame_ide::FunctorConstBase<void, const MessageData &>
{
public:
	virtual ~MessageVisitor() override = default;
	virtual void operator()(MessageData &) noexcept override = 0;
	virtual void operator()(const MessageData &) const noexcept override = 0;
};

struct Message: public MessageData
{
	using MessageData::bytes;
	using MessageData::size;
	using MessageData::state;

	mutable os::threads::Spin spin;

	void modify(MessageVisitor &visitor) noexcept;

	void write(
			::flame_ide::VoidTraits::PointerToConst data
			, ::flame_ide::Types::size_t size
	) noexcept;

	void read(
			::flame_ide::VoidTraits::Pointer data
			, ::flame_ide::Types::size_t size
	) noexcept;

protected:
	::flame_ide::templates::Range<flame_ide::byte_t *> range() noexcept;
};

}}}} // namespace flame_ide::handler::network::udp

#endif // HANDLER_INTERNAL_UDP_MESSAGE_HPP
