#ifndef FLAMEIDE_STREAMS_WRITER_HPP
#define FLAMEIDE_STREAMS_WRITER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

#include <FlameIDE/Templates/CircularArray.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The Writer class
/// @tparam CircularByteBuffer
///
template<typename CircularByteBuffer>
class Writer
{
public:
	using InputByteRange = stream_utils::AbstractByteStreamWriter::InputByteRange;
	using InputCircularByteRange =
			stream_utils::AbstractByteStreamWriter::InputCircularByteRange;

	Writer() noexcept = default;
	Writer(const Writer &) noexcept = delete;
	Writer(Writer &&) noexcept = default;

	///
	/// @brief Writer
	/// @param byteWriter
	///
	Writer(stream_utils::AbstractByteStreamWriter &baseWriterImpl) noexcept;

	~Writer() noexcept = default;

	Writer &operator=(const Writer &) noexcept = delete;
	Writer &operator=(Writer &&) noexcept = default;

	///
	/// @brief getWriter
	/// @return
	///
	stream_utils::AbstractByteStreamWriter *getWriterImpl() noexcept;

	///
	/// @brief setWriter
	/// @param[in] byteWriter
	///
	void setWriterImpl(stream_utils::AbstractByteStreamWriter &baseWriterImpl) noexcept;

	///
	/// @brief putData
	/// @param[in,out] range
	/// @return
	///
	SizeTraits::SsizeType putData(InputByteRange &range) noexcept;

	///
	/// @brief flush
	/// @return
	///
	bool flush() noexcept;

protected:
	CircularByteBuffer buffer; ///<
	stream_utils::AbstractByteStreamWriter *writerImpl; ///<

};

}}

namespace flame_ide
{namespace streams
{

template<typename CircularByteBuffer>
SizeTraits::SsizeType
Writer<CircularByteBuffer>::putData(InputByteRange &range) noexcept
{
	SizeTraits::SsizeType countData = 0;
	auto it = range.begin();
	while (buffer.size() != buffer.capacity() && it != range.end())
	{
		buffer.pushBack(*it);
		++it;
		++countData;
	}
	return countData;
}

template<typename CircularByteBuffer>
bool Writer<CircularByteBuffer>::flush() noexcept
{
	return true;
}

}}

#endif // FLAMEIDE_STREAMS_WRITER_HPP
