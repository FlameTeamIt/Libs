#ifndef FLAMEIDE_STREAMS_READER_HPP
#define FLAMEIDE_STREAMS_READER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

namespace flame_ide
{namespace streams
{

template<typename CircularByteBuffer, typename RealByteStream>
class Reader
{
public:
	using OutputByteRange = stream_utils::AbstractByteStream::OutputByteRange;
	using SsizeType = stream_utils::AbstractByteStream::SsizeType;

	///
	/// @brief Getting data without popping.
	/// @param range
	/// @return
	///
	SsizeType seeData(OutputByteRange &range) noexcept;

	///
	/// @brief Getting data with popping.
	/// @param range
	/// @return
	///
	SsizeType readData(OutputByteRange &range) noexcept;

	///
	/// @brief empty
	/// @return
	///
	bool empty() const noexcept;

protected:
	CircularByteBuffer buffer;
};

}}

#endif // FLAMEIDE_STREAMS_READER_HPP
