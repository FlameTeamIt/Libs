#ifndef FLAMEIDE_STREAMS_STREAMBASE_HPP
#define FLAMEIDE_STREAMS_STREAMBASE_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/CircularArray.hpp>

namespace flame_ide
{namespace streams
{

namespace stream_utils
{

constexpr SizeTraits::SizeType DEFAULT_CIRCULAR_BUFFER_SIZE = 1023;

class AbstractByteStream
{
public:
	using Byte = byte_t;
	using InputByteRange = templates::Range<const Byte *>;
	using OutputByteRange = templates::Range<Byte *>;
	using SsizeType = SizeTraits::SsizeType;

	virtual ~AbstractByteStream() = default;

	virtual SizeTraits::SsizeType write(InputByteRange range) = 0;
	virtual SizeTraits::SsizeType read(OutputByteRange range) = 0;
};

using DefaultCircularByteBuffer = templates::CircularArray<
	byte_t, DEFAULT_CIRCULAR_BUFFER_SIZE
>;

}

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

#endif // FLAMEIDE_STREAMS_STREAMBASE_HPP
