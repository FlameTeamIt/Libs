#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108FeedbackKdfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

NistSp800Hyphen108FeedbackKdfParams::NistSp800Hyphen108FeedbackKdfParams() noexcept
{}

NistSp800Hyphen108FeedbackKdfParams::NistSp800Hyphen108FeedbackKdfParams(
		const NistSp800Hyphen108FeedbackKdfParams &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108FeedbackKdfParams::NistSp800Hyphen108FeedbackKdfParams(
		const Parent &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108FeedbackKdfParams::NistSp800Hyphen108FeedbackKdfParams(
		const decltype(Parent::prfType) &prfType
		, const decltype(Parent::ulNumberOfDataParams) &dataParamsCount
		, const decltype(Parent::pDataParams) &dataParams
		, const decltype(Parent::ulIVLen) &ivLength
		, const decltype(Parent::pIV) &iv
		, const decltype(Parent::ulAdditionalDerivedKeys) &additionalDerivedKeysCount
		, const decltype(Parent::pAdditionalDerivedKeys) &additionalDerivedKeys
) noexcept
{
	this->prfType = prfType;
	ulNumberOfDataParams = dataParamsCount;
	pDataParams = dataParams;
	ulIVLen = ivLength;
	pIV = iv;
	ulAdditionalDerivedKeys = additionalDerivedKeysCount;
	pAdditionalDerivedKeys = additionalDerivedKeys;
}

NistSp800Hyphen108FeedbackKdfParams &NistSp800Hyphen108FeedbackKdfParams::operator=(
		const NistSp800Hyphen108FeedbackKdfParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

NistSp800Hyphen108FeedbackKdfParams &NistSp800Hyphen108FeedbackKdfParams::operator=(
		const Parent &params
) noexcept
{
	prfType = params.prfType;
	ulNumberOfDataParams = params.ulNumberOfDataParams;
	pDataParams = params.pDataParams;
	ulIVLen = params.ulIVLen;
	pIV = params.pIV;
	ulAdditionalDerivedKeys = params.ulAdditionalDerivedKeys;
	pAdditionalDerivedKeys = params.pAdditionalDerivedKeys;

	return *this;
}


}}} // flame_ide::pkcs11::structs
