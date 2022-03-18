#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108DkmLengthFormat.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

NistSp800Hyphen108DkmLengthFormat::NistSp800Hyphen108DkmLengthFormat() noexcept
{}

NistSp800Hyphen108DkmLengthFormat::NistSp800Hyphen108DkmLengthFormat(
		const NistSp800Hyphen108DkmLengthFormat &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108DkmLengthFormat::NistSp800Hyphen108DkmLengthFormat(
		const Parent &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108DkmLengthFormat::NistSp800Hyphen108DkmLengthFormat(
		const decltype(Parent::ulWidthInBits) &widthInBits
		, const decltype(Parent::bLittleEndian) &isLittleEndian
		, const decltype(Parent::dkmLengthMethod) &dkmLengthMethod
) noexcept
{
	ulWidthInBits = widthInBits;
	bLittleEndian = isLittleEndian;
	this->dkmLengthMethod = dkmLengthMethod;
}

NistSp800Hyphen108DkmLengthFormat &NistSp800Hyphen108DkmLengthFormat::operator=(
		const NistSp800Hyphen108DkmLengthFormat &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

NistSp800Hyphen108DkmLengthFormat &NistSp800Hyphen108DkmLengthFormat::operator=(
		const Parent &params
) noexcept
{
	dkmLengthMethod = params.dkmLengthMethod;
	bLittleEndian = params.bLittleEndian;
	ulWidthInBits = params.ulWidthInBits;

	return *this;
}

}}} // flame_ide::pkcs11::structs
