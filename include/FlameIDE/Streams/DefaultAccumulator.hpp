#ifndef FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP
#define FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{namespace streams
{

class DefaultAccumulator
{
public:
	using Traits = SizeTraits;
	using SsizeType = typename Traits::SsizeType;
	using Byte = typename Traits::ByteType;
	using DataIterator = templates::ConstIterator<
		Byte*, templates::IteratorCategory::FORWARD
	>;
	using ConstDataIterator = templates::ConstIterator<
		const Byte*, templates::IteratorCategory::FORWARD
	>;
	using WritebleData = templates::Range<ConstDataIterator>;
	using ReadableData = templates::Range<DataIterator>;

	static constexpr SizeTraits::SizeType BUFFER_SIZE = 1024;

	DefaultAccumulator();
	~DefaultAccumulator();

	SsizeType push(const WritebleData &data);
	void flush()
	{
	}

	SsizeType pull(ReadableData &data);
	SsizeType peek(ReadableData &data);

private:
	templates::Array<Byte, BUFFER_SIZE, false, ContainerTraits<Byte>> buffer;
};

}}

#endif // FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP
