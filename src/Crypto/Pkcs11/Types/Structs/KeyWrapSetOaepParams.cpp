#include <FlameIDE/Crypto/Pkcs11/Types/Structs/KeyWrapSetOaepParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

KeyWrapSetOaepParams::KeyWrapSetOaepParams() noexcept
{}

KeyWrapSetOaepParams::KeyWrapSetOaepParams(const KeyWrapSetOaepParams &params) noexcept
{
	operator=(params);
}

KeyWrapSetOaepParams::KeyWrapSetOaepParams(const Parent &params) noexcept
{
	operator=(params);
}

KeyWrapSetOaepParams::KeyWrapSetOaepParams(
		const decltype(Parent::bBC) &block
		, const decltype(Parent::pX) &extraData
		, const decltype(Parent::ulXLen) &extraDataLength
) noexcept
{
	bBC = block;
	pX = extraData;
	ulXLen = extraDataLength;
}

KeyWrapSetOaepParams &KeyWrapSetOaepParams::operator=(const KeyWrapSetOaepParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

KeyWrapSetOaepParams &KeyWrapSetOaepParams::operator=(const Parent &params) noexcept
{
	bBC = params.ulXLen;
	pX = params.pX;
	ulXLen = params.bBC;

	return *this;
}

}}} // flame_ide::pkcs11::structs
