#include <Analysers/Ubjson/DefaultAccumulator.hpp>

namespace flame_ide
{namespace ubjson
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
	offset += SizeType(data.end() - data.begin());
	bytes.insert(bytes.end(), data.begin(), data.end());
}

}}
