#include <FlameIDE/Crypto/Pkcs11/Types/Structs/SkipjackRelayxParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

SkipjackRelayxParams::SkipjackRelayxParams() noexcept
{}

SkipjackRelayxParams::SkipjackRelayxParams(const SkipjackRelayxParams &params) noexcept
{
	operator=(params);
}

SkipjackRelayxParams::SkipjackRelayxParams(const Parent &params) noexcept
{
	operator=(params);
}

SkipjackRelayxParams::SkipjackRelayxParams(
		const decltype(Parent::ulOldWrappedXLen) &oldWrappedLength
		, const decltype(Parent::pOldWrappedX) &oldWrapped
		, const decltype(Parent::ulOldPasswordLen) &oldPasswordLength
		, const decltype(Parent::pOldPassword) &oldPassword
		, const decltype(Parent::ulOldPublicDataLen) &oldPublicDataLength
		, const decltype(Parent::pOldPublicData) &oldPublicData
		, const decltype(Parent::ulOldRandomLen) &oldRandomLength
		, const decltype(Parent::pOldRandomA) &oldRandomA
		, const decltype(Parent::ulNewPasswordLen) &NewPasswordLength
		, const decltype(Parent::pNewPassword) &newPassword
		, const decltype(Parent::ulNewPublicDataLen) &newPublicDataLength
		, const decltype(Parent::pNewPublicData) &newPublicData
		, const decltype(Parent::ulNewRandomLen) &newRandomLength
		, const decltype(Parent::pNewRandomA) &newRandomA
) noexcept
{
	ulOldWrappedXLen = oldWrappedLength;
	pOldWrappedX = oldWrapped;
	ulOldPasswordLen = oldPasswordLength;
	pOldPassword = oldPassword;
	ulOldPublicDataLen = oldPublicDataLength;
	pOldPublicData = oldPublicData;
	ulOldRandomLen = oldRandomLength;
	pOldRandomA = oldRandomA;
	ulNewPasswordLen = NewPasswordLength;
	pNewPassword = newPassword;
	ulNewPublicDataLen = newPublicDataLength;
	pNewPublicData = newPublicData;
	ulNewRandomLen = newRandomLength;
	pNewRandomA = newRandomA;
}

SkipjackRelayxParams &SkipjackRelayxParams::operator=(const SkipjackRelayxParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

SkipjackRelayxParams &SkipjackRelayxParams::operator=(const Parent &params) noexcept
{
	ulOldWrappedXLen = params.ulOldWrappedXLen;
	pOldWrappedX = params.pOldWrappedX;
	ulOldPasswordLen = params.ulOldPasswordLen;
	pOldPassword = params.pOldPassword;
	ulOldPublicDataLen = params.ulOldPublicDataLen;
	pOldPublicData = params.pOldPublicData;
	ulOldRandomLen = params.ulOldRandomLen;
	pOldRandomA = params.pOldRandomA;
	ulNewPasswordLen = params.ulNewPasswordLen;
	pNewPassword = params.pNewPassword;
	ulNewPublicDataLen = params.ulNewPublicDataLen;
	pNewPublicData = params.pNewPublicData;
	ulNewRandomLen = params.ulNewRandomLen;
	pNewRandomA = params.pNewRandomA;

	return *this;
}

}}} // flame_ide::pkcs11::structs
