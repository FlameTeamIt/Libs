#ifndef FLAMEIDE_STREAMS_STREAMBASE_HPP
#define FLAMEIDE_STREAMS_STREAMBASE_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>
#include <FlameIDE/Templates/Iterator/CircularIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstCircularIterator.hpp>

namespace flame_ide
{namespace streams
{namespace stream_utils
{

class AbstractByteStream
{
public:
	using Byte = byte_t;

	using ByteIterator = templates::Iterator<
		Byte *, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;
	using ConstByteIterator = templates::ConstIterator<
		const Byte *, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using CircularByteIterator = templates::CircularIterator<
		ByteIterator, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using ConstCircularByteIterator = templates::ConstCircularIterator<
		ConstByteIterator, templates::IteratorCategory::RANDOM_ACCESS
		, ContainerTraits<Byte>, void
	>;

	using InputByteRange = templates::Range<ConstByteIterator>;
	using InputCircularByteRange = templates::Range<ConstCircularByteIterator>;

	using OutputByteRange = templates::Range<ByteIterator>;
	using OutputCircularByteRange = templates::Range<CircularByteIterator>;

	using SsizeType = SizeTraits::SsizeType;

	virtual ~AbstractByteStream() = default;

	virtual SizeTraits::SsizeType write(InputByteRange range) = 0;
	virtual SizeTraits::SsizeType write(InputCircularByteRange range) = 0;

	virtual SizeTraits::SsizeType read(OutputByteRange range) = 0;
	virtual SizeTraits::SsizeType read(OutputCircularByteRange range) = 0;
};

}}}

#endif // FLAMEIDE_STREAMS_STREAMBASE_HPP
