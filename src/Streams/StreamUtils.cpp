#include <FlameIDE/Common/Utils.hpp>
#include <FlameIDE/Streams/StreamUtils.hpp>

namespace flame_ide
{namespace streams
{namespace stream_utils
{

namespace // anonymous
{

template<typename Range, typename CircularRange> inline
auto getContiniousRanges(CircularRange range) noexcept
{
	using Ranges = templates::Array<Range, CountContiniousRanges>;

	auto iteratorPrev = range.begin();
	auto iteratorNext = iteratorPrev + 1;

	while (getPointer(iteratorPrev) < getPointer(iteratorNext))
	{
		++iteratorPrev;
		++iteratorNext;
	}

	Range range1{
			{ getPointer(range.begin()) }
			, { getPointer(iteratorPrev) + 1 }
	};

	Range range2{
			{ getPointer(iteratorNext) }
			, { getPointer(range.end()) }
	};

	Ranges ranges;
	ranges.emplaceBack(range1);
	ranges.emplaceBack(range2);
	return ranges;
}

} // anonymous

AbstractByteStreamReader::ContiniousOutputRanges
AbstractByteStreamReader::getContiniousOutputRanges(
	AbstractByteStreamReader::OutputCircularByteRange range
) noexcept
{
	return getContiniousRanges<OutputByteRange>(range);
}

AbstractByteStreamWriter::ContiniousInputRanges
AbstractByteStreamWriter::getContiniousInputRanges(
	AbstractByteStreamWriter::InputCircularByteRange range
) noexcept
{
	return getContiniousRanges<InputByteRange>(range);
}

}}}
