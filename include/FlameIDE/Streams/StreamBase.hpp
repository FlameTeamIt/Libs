#ifndef STREAMS_STREAMBASE_HPP
#define STREAMS_STREAMBASE_HPP

#include <FlameIDE/Common/PrimitiveTypes.hpp>

namespace flame_ide
{namespace streams
{

template<typename Accumulator>
class StreamOutputBase
{
public:
	StreamOutputBase() = default;
	StreamOutputBase(const StreamOutputBase &stream) = default;
	StreamOutputBase(StreamOutputBase &&stream) = default;
	StreamOutputBase(const Accumulator &accum);
	StreamOutputBase(Accumulator &&accum);
	~StreamOutputBase() = default;
	StreamOutputBase &operator=(const StreamOutputBase &stream) = default;
	StreamOutputBase &operator=(StreamOutputBase &&stream) = default;

	StreamOutputBase &operator<<(ichar_t value);
	StreamOutputBase &operator<<(uichar_t value);

	StreamOutputBase &operator<<(short_t value);
	StreamOutputBase &operator<<(ushort_t value);

	StreamOutputBase &operator<<(int_t value);
	StreamOutputBase &operator<<(uint_t value);

	StreamOutputBase &operator<<(long_t value);
	StreamOutputBase &operator<<(ulong_t value);

	StreamOutputBase &operator<<(float_t value);
	StreamOutputBase &operator<<(double_t value);

	StreamOutputBase &operator<<(char *value);

	ssize_t write(const char_t *buffer, ssize_t size);

private:
	Accumulator accum;
};

template<typename Accumulator>
class StreamInputBase
{
public:
	struct ReadStringSetting
	{
		char_t delimer;
		char *value;
	};

	StreamInputBase() = default;
	StreamInputBase(const StreamInputBase &stream) = default;
	StreamInputBase(StreamInputBase &&stream) = default;
	StreamInputBase(const Accumulator &initAccum);
	StreamInputBase(Accumulator &&initAccum);
	~StreamInputBase() = default;
	StreamInputBase &operator=(const StreamInputBase &stream) = default;
	StreamInputBase &operator=(StreamInputBase &&stream) = default;

	StreamInputBase &operator>>(ichar_t value);
	StreamInputBase &operator>>(uichar_t value);

	StreamInputBase &operator>>(short_t value);
	StreamInputBase &operator>>(ushort_t value);

	StreamInputBase &operator>>(int_t value);
	StreamInputBase &operator>>(uint_t value);

	StreamInputBase &operator>>(long_t value);
	StreamInputBase &operator>>(ulong_t value);

	StreamInputBase &operator>>(float_t value);
	StreamInputBase &operator>>(double_t value);

	StreamInputBase &operator>>(ReadStringSetting &value);

	ssize_t read(char_t *buffer, ssize_t size);

private:
	Accumulator accum;
};

}}

#endif // STREAMS_STREAMBASE_HPP
