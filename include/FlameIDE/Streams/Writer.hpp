#ifndef FLAMEIDE_STREAMS_WRITER_HPP
#define FLAMEIDE_STREAMS_WRITER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

namespace flame_ide
{namespace streams
{

template<typename CircularByteBuffer, typename RealByteStream>
class Writer
{
public:
	using InputByteRange = stream_utils::AbstractByteStream::InputByteRange;
	using SsizeType = stream_utils::AbstractByteStream::SsizeType;

	///
	/// @brief putData
	/// @param range
	/// @return
	///
	SsizeType putData(const InputByteRange &range) noexcept;

	///
	/// @brief flush
	/// @return
	///
	bool flush() noexcept;

protected:
	CircularByteBuffer buffer;
};

}}

#endif // FLAMEIDE_STREAMS_WRITER_HPP
