#include <FlameIDE/Crypto/Pkcs11/Types/Structs/AesCtrParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

AesCtrParams::AesCtrParams() noexcept
{}

AesCtrParams::AesCtrParams(const AesCtrParams &params) noexcept
{
	operator=(params);
}

AesCtrParams::AesCtrParams(const Parent &params) noexcept
{
	operator=(params);
}

AesCtrParams::AesCtrParams(
		const decltype(Parent::ulCounterBits) &counterBits
		, const decltype(Parent::cb) &counterBlock
) noexcept
{
	ulCounterBits = counterBits;
	copy(cb, counterBlock);
}

AesCtrParams &AesCtrParams::operator=(const AesCtrParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

AesCtrParams &AesCtrParams::operator=(const Parent &params) noexcept
{
	ulCounterBits = params.ulCounterBits;
	copy(cb, params.cb);

	return *this;
}

}}} // flame_ide::pkcs11::structs
