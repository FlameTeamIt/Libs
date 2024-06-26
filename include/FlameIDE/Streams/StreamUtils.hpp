#ifndef FLAMEIDE_STREAMS_STREAMUTILS_HPP
#define FLAMEIDE_STREAMS_STREAMUTILS_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Byte.hpp>

#include <FlameIDE/Os/Types.hpp>
#include <FlameIDE/Os/Constants.hpp>

#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstCircularIterator.hpp>
#include <FlameIDE/Templates/Array.hpp>

namespace flame_ide
{namespace streams
{namespace stream_utils
{

using Byte = byte_t;

constexpr flame_ide::Types::size_t COUNT_CONTINUOUS_RANGES = 2; ///<
constexpr flame_ide::SizeTraits::SsizeType INVALID_COUNT_BYTES = -1; ///<

///
/// @brief The AbstractByteStreamReader struct
///
struct AbstractByteStreamReader
{
	///
	using ByteIterator = templates::Iterator<
		Byte *, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	///
	using CircularByteIterator = templates::CircularIterator<
		ByteIterator, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	///
	using OutputByteRange = templates::Range<ByteIterator>;

	///
	using OutputCircularByteRange = templates::Range<CircularByteIterator>;

	using ContiniousOutputRanges = templates::Array<
		OutputByteRange, COUNT_CONTINUOUS_RANGES
	>;

	virtual ~AbstractByteStreamReader() noexcept = default;

	///
	/// @brief read
	/// @param range
	/// @return
	///
	virtual SizeTraits::SsizeType read(OutputByteRange range) noexcept = 0;

	///
	/// @brief read
	/// @param range
	/// @return
	///
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) noexcept = 0;

	///
	/// @brief getReaderStatus
	/// @return
	///
	os::Status getReaderStatus() const noexcept
	{
		return readerStatus;
	}

	///
	/// @brief getContinuousOutputRanges
	/// @param range
	/// @return
	///
	// TODO: тестирование
	static ContiniousOutputRanges
	getContinuousOutputRanges(OutputCircularByteRange range) noexcept;

protected:
	///
	/// @brief setReaderStatus
	/// @param status
	///
	void setReaderStatus(os::Status status) noexcept
	{
		readerStatus = status;
	}

private:
	os::Status readerStatus = os::STATUS_SUCCESS;
};

struct AbstractByteStreamWriter
{
	using ConstByteIterator = templates::ConstIterator<
		const Byte *, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using ConstCircularByteIterator = templates::ConstCircularIterator<
		ConstByteIterator, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using InputByteRange = templates::Range<ConstByteIterator>;
	using InputCircularByteRange = templates::Range<ConstCircularByteIterator>;

	using ContiniousInputRanges = templates::Array<
		InputByteRange, COUNT_CONTINUOUS_RANGES
	>;

	virtual ~AbstractByteStreamWriter() noexcept = default;

	///
	/// @brief write
	/// @param range
	/// @return
	///
	virtual SizeTraits::SsizeType write(InputByteRange range) noexcept = 0;

	///
	/// @brief write
	/// @param range
	/// @return
	///
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) noexcept = 0;

	///
	/// @brief flush
	///
	virtual void flush() noexcept = 0;

	///
	/// @brief getWriterStatus
	/// @return
	///
	os::Status getWriterStatus() const noexcept
	{
		return writerStatus;
	}

	///
	/// @brief getContinuousInputRanges
	/// @param range
	/// @return
	///
	// TODO: тестирование
	static ContiniousInputRanges
	getContinuousInputRanges(InputCircularByteRange range) noexcept;

protected:
	void setWriterStatus(os::Status status) noexcept
	{
		writerStatus = status;
	}

private:
	os::Status writerStatus = os::STATUS_SUCCESS;
};

class AbstractByteStream: public AbstractByteStreamReader
		, public AbstractByteStreamWriter
{
public:
	virtual ~AbstractByteStream() noexcept = default;

	///
	/// @brief getReader
	/// @return
	///
	AbstractByteStreamReader &getReader() noexcept
	{
		return *this;
	}

	///
	/// @brief getWriter
	/// @return
	///
	AbstractByteStreamWriter &getWriter() noexcept
	{
		return *this;
	}
};

}}}

#endif // FLAMEIDE_STREAMS_STREAMUTILS_HPP
