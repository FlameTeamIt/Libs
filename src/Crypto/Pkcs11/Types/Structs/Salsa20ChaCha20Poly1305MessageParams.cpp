#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20ChaCha20Poly1305MessageParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Salsa20ChaCha20Poly1305MessageParams::Salsa20ChaCha20Poly1305MessageParams() noexcept
{}

Salsa20ChaCha20Poly1305MessageParams::Salsa20ChaCha20Poly1305MessageParams(
		const Salsa20ChaCha20Poly1305MessageParams &params
) noexcept
{
	operator=(params);
}

Salsa20ChaCha20Poly1305MessageParams::Salsa20ChaCha20Poly1305MessageParams(const Parent &params) noexcept
{
	operator=(params);
}

Salsa20ChaCha20Poly1305MessageParams::Salsa20ChaCha20Poly1305MessageParams(
		const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceLen) &nonceLength
		, const decltype(Parent::pTag) &tag
) noexcept
{
	pNonce = nonce;
	ulNonceLen = nonceLength;
	pTag = tag;
}

Salsa20ChaCha20Poly1305MessageParams &Salsa20ChaCha20Poly1305MessageParams::operator=(
		const Salsa20ChaCha20Poly1305MessageParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Salsa20ChaCha20Poly1305MessageParams &Salsa20ChaCha20Poly1305MessageParams::operator=(
		const Parent &params
) noexcept
{
	pNonce = params.pNonce;
	ulNonceLen = params.ulNonceLen;
	pTag = params.pTag;

	return *this;
}


}}} // flame_ide::pkcs11::structs
