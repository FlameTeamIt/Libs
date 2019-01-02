#ifndef FLAMEIDE_STREAMS_STREAMBASE_HPP
#define FLAMEIDE_STREAMS_STREAMBASE_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>
#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Byte.hpp>
#include <FlameIDE/Templates/View.hpp>
#include <FlameIDE/Templates/Iterator.hpp>

namespace flame_ide
{namespace streams
{

namespace stream_utils
{

template<typename IteratorType>
constexpr void checkIterator(IteratorType)
{
	using namespace templates::iterator_utils;
	using templates::IteratorAccess;
	using templates::IteratorCategory;
	static_assert (
		GetIteratorInfo<IteratorType>::CATEGORY >= IteratorCategory::FORWARD
		, "Invalid iterator type"
	);
}


}

template<typename Accumulator, typename Traits = SizeTraits>
class StreamOutputBase
{
public:
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;
	using Byte = typename Traits::ByteType;
	using DataIterator = templates::ConstIterator<
		const Byte*, templates::IteratorCategory::FORWARD
	>;
	using WritebleData = templates::Range<DataIterator>;

	StreamOutputBase() = default;
	StreamOutputBase(const StreamOutputBase &stream) = default;
	StreamOutputBase(StreamOutputBase &&stream) = default;
	StreamOutputBase(const Accumulator &accum);
	StreamOutputBase(Accumulator &&accum);
	~StreamOutputBase() = default;
	StreamOutputBase &operator=(const StreamOutputBase &stream) = default;
	StreamOutputBase &operator=(StreamOutputBase &&stream) = default;

	SsizeType write(const WritebleData &data) noexcept;

protected:
	Accumulator &getOutputDataAccumulator();

private:
	Accumulator accum;
};

template<typename Accumulator, typename Traits = SizeTraits>
class StreamInputBase
{
public:
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;
	using Byte = typename Traits::ByteType;
	using DataIterator = templates::ConstIterator<
		const Byte*, templates::IteratorCategory::FORWARD
	>;
	using RidableData = templates::Range<DataIterator>;

	StreamInputBase() = default;
	StreamInputBase(const StreamInputBase &stream) = default;
	StreamInputBase(StreamInputBase &&stream) = default;
	StreamInputBase(const Accumulator &initAccum);
	StreamInputBase(Accumulator &&initAccum);
	~StreamInputBase() = default;
	StreamInputBase &operator=(const StreamInputBase &stream) = default;
	StreamInputBase &operator=(StreamInputBase &&stream) = default;

	SsizeType read(RidableData &data) noexcept;

protected:
	Accumulator &getInputDataAccumulator();

private:
	Accumulator accum;
};

}}

#endif // FLAMEIDE_STREAMS_STREAMBASE_HPP
