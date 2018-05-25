#ifndef ANALYSERS_BSON_DEFAULTACCUMULATOR_HPP
#define ANALYSERS_BSON_DEFAULTACCUMULATOR_HPP

#include <Templates/Vector.hpp>
#include <Templates/View.hpp>

namespace flame_ide
{namespace bson
{

class DefaultAccumulator
{
public:
	using Container = templates::Vector<templates::Types::uchar_t>;
	using Range = templates::Range<templates::Types::uchar_t *>;
	using ConstRange = templates::Range<const templates::Types::uchar_t *>;

	using SizeType = templates::Types::size_t;

	// need

	static constexpr SizeType MAX_SIZE = INT64_MAX;
	static constexpr SizeType MIN_SIZE = SizeType(1024);

	DefaultAccumulator() noexcept;
	DefaultAccumulator(DefaultAccumulator &&) = default;
	DefaultAccumulator(const DefaultAccumulator &) = default;
	~DefaultAccumulator() = default;
	DefaultAccumulator &operator=(DefaultAccumulator &&) = default;
	DefaultAccumulator &operator=(const DefaultAccumulator &) = default;

	SizeType size() const noexcept;
	constexpr SizeType max() const noexcept
	{
		return MAX_SIZE;
	}

	SizeType dataOffset() const noexcept;
	void resetOffset() noexcept;
	Range data() noexcept;
	ConstRange data() const noexcept;

	void putData(ConstRange &data);

private:
	Container bytes;
	SizeType offset;
};


}}

#endif // ANALYSERS_BSON_DEFAULTACCUMULATOR_HPP
