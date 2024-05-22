#include <FlameIDE/Crypto/Pkcs11/Types/Structs/ChaCha20Params.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

ChaCha20Params::ChaCha20Params() noexcept
{}

ChaCha20Params::ChaCha20Params(const ChaCha20Params &params) noexcept
{
	operator=(params);
}

ChaCha20Params::ChaCha20Params(const Parent &params) noexcept
{
	operator=(params);
}

ChaCha20Params::ChaCha20Params(
		const decltype(Parent::pBlockCounter) &blockCounter
		, const decltype(Parent::blockCounterBits) &blockCounterBits
		, const decltype(Parent::pNonce) &nonce
		, const decltype(Parent::ulNonceBits) &nonceBits
) noexcept
{
	pBlockCounter = blockCounter;
	this->blockCounterBits = blockCounterBits;
	pNonce = nonce;
	ulNonceBits = nonceBits;
}

ChaCha20Params &ChaCha20Params::operator=(const ChaCha20Params &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

ChaCha20Params &ChaCha20Params::operator=(const Parent &params) noexcept
{
	pBlockCounter = params.pBlockCounter;
	blockCounterBits = params.blockCounterBits;
	pNonce = params.pNonce;
	ulNonceBits = params.ulNonceBits;

	return *this;
}


}}} // flame_ide::pkcs11::structs
