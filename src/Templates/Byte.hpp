#ifndef TEMPLATES_BYTE_HPP
#define TEMPLATES_BYTE_HPP

#include <Templates/Bits.hpp>

namespace flame_ide
{namespace templates
{namespace bits
{

namespace byte_utils
{

template<typename ByteStructType> static inline
void initBits(ByteStructType &byte) noexcept;

template<typename ByteStructType> static inline
void revertBits(ByteStructType &byte) noexcept;

template<typename ByteStructType1, typename ByteStructType2> static inline
void assignBits(ByteStructType1 &biteOut, const ByteStructType2 &byteIn) noexcept;

template<typename ByteStructType> static inline
bool getByIndex(ByteStructType byte, Types::size_t index) noexcept;

template<typename ByteStructType>
class BitHandler
{
public:
	BitHandler(ByteStructType &byteInit, Types::size_t bitNumberInit) :
			byte(byteInit), bitNumber(bitNumberInit)
	{}

	BitHandler &operator=(bool bitValue)
	{
		setByIndex(byte, bitNumber, bitValue);
		return *this;
	}

	operator bool() const
	{
		return getByIndex(byte, bitNumber);
	}

private:
	ByteStructType &byte;
	Types::size_t bitNumber;
};

template<typename ByteStructType> static inline
void initBits(ByteStructType &byte) noexcept
{
	byte.bit0 = 0; byte.bit1 = 0; byte.bit2 = 0; byte.bit3 = 0;
	byte.bit4 = 0; byte.bit5 = 0; byte.bit6 = 0; byte.bit7 = 0;
}

template<typename ByteStructType> static inline
void revertBits(ByteStructType &byte) noexcept
{
	bool tmp;
	tmp = byte.bit0; byte.bit0 = byte.bit7; byte.bit7 = tmp;
	tmp = byte.bit1; byte.bit1 = byte.bit6; byte.bit6 = tmp;
	tmp = byte.bit2; byte.bit2 = byte.bit5; byte.bit5 = tmp;
	tmp = byte.bit3; byte.bit3 = byte.bit4; byte.bit4 = tmp;
}

template<typename ByteStructType1, typename ByteStructType2> static inline
void assignBits(ByteStructType1 &biteOut, const ByteStructType2 &byteIn) noexcept
{
	biteOut.bit0 = byteIn.bit0; biteOut.bit1 = byteIn.bit1;
	biteOut.bit2 = byteIn.bit2; biteOut.bit3 = byteIn.bit3;
	biteOut.bit4 = byteIn.bit4; biteOut.bit5 = byteIn.bit5;
	biteOut.bit6 = byteIn.bit6; biteOut.bit7 = byteIn.bit7;
}

template<typename ByteStructType> static inline
bool getByIndex(ByteStructType byte, Types::size_t index) noexcept
{
	switch (index)
	{
		case 0:
			return byte.bit0;
		case 1:
			return byte.bit1;
		case 2:
			return byte.bit2;
		case 3:
			return byte.bit3;
		case 4:
			return byte.bit4;
		case 5:
			return byte.bit5;
		case 6:
			return byte.bit6;
		case 7:
			return byte.bit7;
		default:
			return bool();
	}
}

template<typename ByteStructType> static inline
BitHandler<ByteStructType> getHandlerByIndex(ByteStructType &byte, Types::size_t index) noexcept
{
	return BitHandler<ByteStructType>(byte, index);
}


template<typename ByteStructType> static inline
void setByIndex(ByteStructType &byte, Types::size_t index, bool value) noexcept
{
	switch (index)
	{
		case 0:
			byte.bit0 = value;
			break;
		case 1:
			byte.bit1 = value;
			break;
		case 2:
			byte.bit2 = value;
			break;
		case 3:
			byte.bit3 = value;
			break;
		case 4:
			byte.bit4 = value;
			break;
		case 5:
			byte.bit5 = value;
			break;
		case 6:
			byte.bit6 = value;
			break;
		case 7:
			byte.bit7 = value;
			break;
		default:
			return;
	}
}

}

struct ReversedByte;
struct Byte
{
	inline Byte() noexcept
	{
		byte_utils::initBits(*this);
	}

	inline Byte(const Byte &byte) noexcept
	{
		byte_utils::assignBits(*this, byte);
	}

	Byte& operator=(const Byte &byte) noexcept
	{
		byte_utils::assignBits(*this, byte);
		return *this;
	}

	byte_utils::BitHandler<Byte> operator[](Types::size_t index)
	{
		return byte_utils::getHandlerByIndex(*this, index);
	}

//	byte_utils::BitHandler<Byte> operator[](Types::size_t index) const
//	{
//		return byte_utils::getHandlerByIndex(*this, index);
//	}

	operator ReversedByte() const noexcept;

	void revert() noexcept
	{
		byte_utils::revertBits(*this);
	}

	void set(Types::size_t index, bool value)
	{
		byte_utils::setByIndex(*this, index, value);
	}

	bool bit0:1; bool bit1:1; bool bit2:1; bool bit3:1;
	bool bit4:1; bool bit6:1; bool bit5:1; bool bit7:1;
};

struct ReversedByte
{
	inline ReversedByte() noexcept
	{
		byte_utils::initBits(*this);
	}

	inline ReversedByte(const Byte &byte)
	{
		byte_utils::assignBits(*this, byte);
	}

	ReversedByte& operator=(const ReversedByte &byte)
	{
		byte_utils::assignBits(*this, byte);
		return *this;
	}

	bool operator[](Types::size_t index) const
	{
		return byte_utils::getByIndex(*this, index);
	}

	operator Byte() const noexcept;

	void revert()
	{
		byte_utils::revertBits(*this);
	}

	void set(Types::size_t index, bool value)
	{
		byte_utils::setByIndex(*this, index, value);
	}

	bool bit7:1; bool bit6:1; bool bit5:1; bool bit4:1;
	bool bit3:1; bool bit2:1; bool bit1:1; bool bit0:1;
};

inline Byte::operator ReversedByte() const noexcept
{
	ReversedByte reversed;
	byte_utils::assignBits(reversed, *this);
	return reversed;
}

inline ReversedByte::operator Byte() const noexcept
{
	Byte byte;
	byte_utils::assignBits(byte, *this);
	return byte;
}

} // bits
} // templates
} // flame_ide

#endif // TEMPLATES_BYTE_HPP
