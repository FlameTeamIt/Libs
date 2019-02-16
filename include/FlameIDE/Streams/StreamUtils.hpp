#ifndef FLAMEIDE_STREAMS_STREAMBASE_HPP
#define FLAMEIDE_STREAMS_STREAMBASE_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Byte.hpp>
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

constexpr flame_ide::Types::size_t COUNT_CONTINUOUS_RANGES = 2;
constexpr flame_ide::SizeTraits::SsizeType INVALID_COUNT_BYTES = -1;

struct AbstractByteStreamReader
{
	using ByteIterator = templates::Iterator<
		Byte *, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using CircularByteIterator = templates::CircularIterator<
		ByteIterator, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using OutputByteRange = templates::Range<ByteIterator>;
	using OutputCircularByteRange = templates::Range<CircularByteIterator>;

	using ContiniousOutputRanges = templates::Array<
		OutputByteRange, COUNT_CONTINUOUS_RANGES
	>;

	virtual ~AbstractByteStreamReader() = default;

	virtual SizeTraits::SsizeType read(OutputByteRange range) = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) = 0;

	 // TODO: тестирование
	static ContiniousOutputRanges
	getContiniousOutputRanges(OutputCircularByteRange range) noexcept;
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

	virtual ~AbstractByteStreamWriter() = default;

	virtual SizeTraits::SsizeType write(InputByteRange range) = 0;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) = 0;

	 // TODO: тестирование
	static ContiniousInputRanges
	getContiniousInputRanges(InputCircularByteRange range) noexcept;
};

class AbstractByteStream : public AbstractByteStreamReader
		, public AbstractByteStreamWriter
{
public:
	AbstractByteStreamReader &getReader()
	{
		return *this;
	}

	AbstractByteStreamWriter &getWriter()
	{
		return *this;
	}
};

}}}

#endif // FLAMEIDE_STREAMS_STREAMBASE_HPP
