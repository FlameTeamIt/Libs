#include <Analysers/Bson/DefaultAccumulator.hpp>

namespace flame_ide
{namespace bson
{

DefaultAccumulator::DefaultAccumulator() noexcept
		: bytes(DefaultAccumulator::MIN_SIZE), offset(0)
{}

DefaultAccumulator::SizeType DefaultAccumulator::size() const noexcept
{
	return bytes.size();
}

DefaultAccumulator::SizeType DefaultAccumulator::dataOffset() const noexcept
{
	return offset;
}

void DefaultAccumulator::resetOffset() noexcept
{
	offset = 0;
}

DefaultAccumulator::Range DefaultAccumulator::data() noexcept
{
	return templates::makeRange(bytes.data(), bytes.data() + bytes.size());
}

DefaultAccumulator::ConstRange DefaultAccumulator::data() const noexcept
{
	return templates::makeRange(bytes.data(), bytes.data() + bytes.size());

}

void DefaultAccumulator::putData(DefaultAccumulator::ConstRange &data)
{

}

}}
