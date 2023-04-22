#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20ChaCha20Poly1305Params.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Salsa20ChaCha20Poly1305Params::Salsa20ChaCha20Poly1305Params() noexcept
{}

Salsa20ChaCha20Poly1305Params::Salsa20ChaCha20Poly1305Params(
		const Salsa20ChaCha20Poly1305Params &params
) noexcept
{
	operator=(params);
}

Salsa20ChaCha20Poly1305Params::Salsa20ChaCha20Poly1305Params(const Parent &params) noexcept
{
	operator=(params);
}

Salsa20ChaCha20Poly1305Params::Salsa20ChaCha20Poly1305Params(
		const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceLen) &nonceLength
		, const decltype(Parent::pAAD) &aad
		, const decltype(Parent::ulAADLen) &aadLength
) noexcept
{
	pNonce = nonce;
	ulNonceLen = nonceLength;
	pAAD = aad;
	ulAADLen = aadLength;
}

Salsa20ChaCha20Poly1305Params &Salsa20ChaCha20Poly1305Params::operator=(
		const Salsa20ChaCha20Poly1305Params &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Salsa20ChaCha20Poly1305Params &Salsa20ChaCha20Poly1305Params::operator=(
		const Parent &params
) noexcept
{
	pNonce = params.pNonce;
	ulNonceLen = params.ulNonceLen;
	pAAD = params.pAAD;
	ulAADLen = params.ulAADLen;

	return *this;
}


}}} // flame_ide::pkcs11::structs
