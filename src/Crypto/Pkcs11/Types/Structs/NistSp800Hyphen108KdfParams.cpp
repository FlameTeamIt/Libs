#include <FlameIDE/Crypto/Pkcs11/Types/Structs/NistSp800Hyphen108KdfParams.hpp>

namespace flame_ide
{namespace pkcs11
{namespace structs
{

NistSp800Hyphen108KdfParams::NistSp800Hyphen108KdfParams() noexcept
{}

NistSp800Hyphen108KdfParams::NistSp800Hyphen108KdfParams(
		const NistSp800Hyphen108KdfParams &params
) noexcept
{
	operator=(params);
}

NistSp800Hyphen108KdfParams::NistSp800Hyphen108KdfParams(const Parent &params) noexcept
{
	operator=(params);
}

NistSp800Hyphen108KdfParams::NistSp800Hyphen108KdfParams(
		const decltype(Parent::pAdditionalDerivedKeys) &additionalDerivedKeys
		, const decltype(Parent::ulAdditionalDerivedKeys) &additionalDerivedKeysCount
		, const decltype(Parent::pDataParams) &dataParams
		, const decltype(Parent::ulNumberOfDataParams) &dataParamsCount
) noexcept
{
	pAdditionalDerivedKeys = additionalDerivedKeys;
	ulAdditionalDerivedKeys = additionalDerivedKeysCount;
	pDataParams = dataParams;
	ulNumberOfDataParams = dataParamsCount;
}

NistSp800Hyphen108KdfParams &NistSp800Hyphen108KdfParams::operator=(
		const NistSp800Hyphen108KdfParams &params
) noexcept
{
	return operator=(static_cast<const Parent &>(params));
}

NistSp800Hyphen108KdfParams &NistSp800Hyphen108KdfParams::operator=(
		const Parent &params
) noexcept
{
	ulNumberOfDataParams = params.ulNumberOfDataParams;
	pDataParams = params.pDataParams;
	ulAdditionalDerivedKeys = params.ulAdditionalDerivedKeys;
	pAdditionalDerivedKeys = params.pAdditionalDerivedKeys;

	return *this;
}


}}} // flame_ide::pkcs11::structs
