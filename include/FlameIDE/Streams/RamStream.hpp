#ifndef FLAMEIDE_STREAMS_RAMSTREAM_HPP
#define FLAMEIDE_STREAMS_RAMSTREAM_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>
#include <FlameIDE/Templates/Vector.hpp>

namespace flame_ide
{namespace streams
{

class RamStream : public stream_utils::AbstractByteStream
{
public:
	using Parent = stream_utils::AbstractByteStream;

	RamStream();
	virtual ~RamStream();

	virtual SizeTraits::SsizeType write(Parent::InputByteRange range);
	virtual SizeTraits::SsizeType write(Parent::InputCircularByteRange range);

	virtual SizeTraits::SsizeType read(Parent::OutputByteRange range);
	virtual SizeTraits::SsizeType read(Parent::OutputCircularByteRange range);

private:
	templates::Vector<stream_utils::Byte> buffer;
};

}}

#endif // FLAMEIDE_STREAMS_RAMSTREAM_HPP
