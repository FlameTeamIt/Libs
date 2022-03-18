#include <FlameIDE/Crypto/Pkcs11/Types/Structs/CamelliaCtrParams.hpp>
#include <FlameIDE/Common/Utils.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

CamelliaCtrParams::CamelliaCtrParams() noexcept
{}

CamelliaCtrParams::CamelliaCtrParams(const CamelliaCtrParams &params) noexcept
{
	operator=(params);
}

CamelliaCtrParams::CamelliaCtrParams(const Parent &params) noexcept
{
	operator=(params);
}

CamelliaCtrParams::CamelliaCtrParams(
		const decltype(Parent::ulCounterBits) &counterBits
		, const decltype(Parent::cb) &counterBlock
) noexcept
{
	ulCounterBits = counterBits;
	copy(cb, counterBlock);
}

CamelliaCtrParams &CamelliaCtrParams::operator=(const CamelliaCtrParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

CamelliaCtrParams &CamelliaCtrParams::operator=(const Parent &params) noexcept
{
	ulCounterBits = params.ulCounterBits;
	copy(cb, params.cb);

	return *this;
}

//using Parent::ulCounterBits;
//using Parent::cb; // [16]

}}} // flame_ide::pkcs11::structs
