#ifndef FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP
#define FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP

#include <FlameIDE/Common/Traits/Defaults.hpp>
#include <FlameIDE/Templates/Array.hpp>
#include <FlameIDE/Templates/View.hpp>

namespace flame_ide
{namespace streams
{

class DefaultAccumulator
{
public:
	using Traits = SizeTraits;
	using Byte = typename Traits::ByteType;
	using DataIterator = templates::ConstIterator<
		const Byte*, templates::IteratorCategory::FORWARD
	>;
	using WritebleData = templates::Range<DataIterator>;

	static constexpr SizeTraits::SizeType BUFFER_SIZE = 1024;

	DefaultAccumulator();
	~DefaultAccumulator();

private:
	templates::Array<Byte, BUFFER_SIZE, false, ContainerTraits<Byte>> buffer;
};

}}

#endif // FLAMEIDE_STREAMS_DEFAULTACCUMULATOR_HPP
