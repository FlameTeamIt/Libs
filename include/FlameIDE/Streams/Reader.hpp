#ifndef FLAMEIDE_STREAMS_READER_HPP
#define FLAMEIDE_STREAMS_READER_HPP

#include <FlameIDE/Streams/StreamUtils.hpp>

namespace flame_ide
{namespace streams
{

///
/// @brief The Reader class
/// @tparam CircularByteBuffer
///
template<typename CircularByteBuffer>
class Reader
{
public:
	using OutputByteRange = stream_utils::AbstractByteStreamReader::OutputByteRange;
	using OutputCiruclarByteRange =
			stream_utils::AbstractByteStreamReader::OutputCircularByteRange;

	Reader() noexcept = default;
	Reader(const Reader &reader) noexcept = delete;
	Reader(Reader &&reader) noexcept = default;

	///
	/// @brief Reader
	/// @param baseReaderImpl
	///
	Reader(stream_utils::AbstractByteStreamReader &baseReaderImpl) noexcept;

	~Reader() noexcept = default;

	Reader &operator=(const Reader &reader) noexcept = delete;
	Reader &operator=(Reader &&reader) noexcept = default;

	///
	/// @brief Getting data without popping.
	/// @param[in,out] range
	/// @return
	///
	SizeTraits::SsizeType seeData(OutputByteRange &range) noexcept;
	SizeTraits::SsizeType seeData(OutputCiruclarByteRange &range) noexcept;

	///
	/// @brief Getting data with popping.
	/// @param[in,out] range
	/// @return
	///
	SizeTraits::SsizeType readData(OutputByteRange &range) noexcept;
	SizeTraits::SsizeType readData(OutputCiruclarByteRange &range) noexcept;

	///
	/// @brief setReaderImpl
	/// @param[in] baseReaderImpl
	///
	void setReaderImpl(stream_utils::AbstractByteStreamReader &baseReaderImpl) noexcept;

	///
	/// @brief getReaderImpl
	/// @return
	///
	stream_utils::AbstractByteStreamReader *getReaderImpl();

	///
	/// @brief empty
	/// @return
	///
	bool empty() const noexcept;

protected:
	CircularByteBuffer buffer; ///<
	stream_utils::AbstractByteStreamReader *readerImpl; ///<
};

}}

namespace flame_ide
{namespace streams
{

}}

#endif // FLAMEIDE_STREAMS_READER_HPP
