#include <FlameIDE/Crypto/Pkcs11/Types/Structs/TlsKdfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

TlsKdfParams::TlsKdfParams() noexcept
{}

TlsKdfParams::TlsKdfParams(const TlsKdfParams &params) noexcept
{
	operator=(params);
}

TlsKdfParams::TlsKdfParams(const Parent &params) noexcept
{
	operator=(params);
}

TlsKdfParams::TlsKdfParams(
		const decltype(Parent::prfMechanism) &prfMechanism
		, const decltype(Parent::pLabel) &label
		, const decltype(Parent::ulLabelLength) &labelLength
		, const decltype(Parent::RandomInfo) &randomInfo
		, const decltype(Parent::pContextData) &contextData
		, const decltype(Parent::ulContextDataLength) &contextDataLength
) noexcept
{
	this->prfMechanism = prfMechanism;
	pLabel = label;
	ulLabelLength = labelLength;
	RandomInfo = randomInfo;
	pContextData = contextData;
	ulContextDataLength = contextDataLength;
}

TlsKdfParams &TlsKdfParams::operator=(const TlsKdfParams &params) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

TlsKdfParams &TlsKdfParams::operator=(const Parent &params) noexcept
{
	prfMechanism = params.prfMechanism;
	pLabel = params.pLabel;
	ulLabelLength = params.ulLabelLength;
	RandomInfo = params.RandomInfo;
	pContextData = params.pContextData;
	ulContextDataLength = params.ulContextDataLength;

	return *this;
}

}}} // flame_ide::pkcs11::structs
