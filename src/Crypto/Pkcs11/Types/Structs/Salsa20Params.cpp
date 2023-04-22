#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Salsa20Params.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

Salsa20Params::Salsa20Params() noexcept
{}

Salsa20Params::Salsa20Params(const Salsa20Params &params) noexcept
{
	operator=(params);
}

Salsa20Params::Salsa20Params(const Parent &params) noexcept
{
	operator=(params);
}

Salsa20Params::Salsa20Params(
		const decltype(Parent::pBlockCounter) &blockCounter
		, const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceBits) &nonceBits
) noexcept
{
	pBlockCounter = blockCounter;
	pNonce = nonce;
	ulNonceBits = nonceBits;
}

Salsa20Params &Salsa20Params::operator=(const Salsa20Params &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

Salsa20Params &Salsa20Params::operator=(const Parent &params) noexcept
{
	pBlockCounter = params.pBlockCounter;
	pNonce = params.pNonce;
	ulNonceBits = params.ulNonceBits;

	return *this;
}

}}} // flame_ide::pkcs11::structs
