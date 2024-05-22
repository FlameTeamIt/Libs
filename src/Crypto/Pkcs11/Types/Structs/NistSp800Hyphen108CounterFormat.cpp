#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108CounterFormat.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

NistSp800Hyphen108CounterFormat::NistSp800Hyphen108CounterFormat() noexcept
{}

NistSp800Hyphen108CounterFormat::NistSp800Hyphen108CounterFormat(
		const NistSp800Hyphen108CounterFormat &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108CounterFormat::NistSp800Hyphen108CounterFormat(const Parent &params) noexcept
{
	operator=(params);
}

NistSp800Hyphen108CounterFormat::NistSp800Hyphen108CounterFormat(
		const decltype(Parent::bLittleEndian) isLittleEndian
		, const decltype(Parent::ulWidthInBits) &widthInBits
) noexcept
{
	bLittleEndian = isLittleEndian;
	ulWidthInBits = widthInBits;
}

NistSp800Hyphen108CounterFormat &NistSp800Hyphen108CounterFormat::operator=(
		const NistSp800Hyphen108CounterFormat &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

NistSp800Hyphen108CounterFormat &NistSp800Hyphen108CounterFormat::operator=(const Parent &params) noexcept
{
	bLittleEndian = params.bLittleEndian;
	ulWidthInBits = params.ulWidthInBits;

	return *this;
}

}}} // flame_ide::pkcs11::structs
