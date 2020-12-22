#ifndef FLAMEIDE_STREAMS_RAMSTREAM_HPP
#define FLAMEIDE_STREAMS_RAMSTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Templates/Vector.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The RamStream class
///
class RamStream: public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	RamStream() noexcept;
	virtual ~RamStream() noexcept;

	virtual SizeTraits::SsizeType read(Parent::OutputByteRange range) noexcept;
	virtual SizeTraits::SsizeType read(Parent::OutputCircularByteRange range) noexcept;

	virtual SizeTraits::SsizeType write(Parent::InputByteRange range) noexcept;
	virtual SizeTraits::SsizeType write(Parent::InputCircularByteRange range) noexcept;

	virtual void flush() noexcept;

private:
	templates::Vector<stream_utils::Byte> buffer; ///<
};

}}

#endif // FLAMEIDE_STREAMS_RAMSTREAM_HPP
