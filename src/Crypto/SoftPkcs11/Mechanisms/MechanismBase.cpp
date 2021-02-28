#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

MechanismBase::MechanismBase() noexcept = default;

MechanismBase::~MechanismBase() noexcept = default;

pkcs11::enums::Mechanism
MechanismBase::getType() const noexcept
{
	return pkcs11::enums::Mechanism::VENDOR_DEFINED;
}

pkcs11::structs::Mechanism
MechanismBase::getNative() const noexcept
{
	return pkcs11::structs::Mechanism {
		pkcs11::enums::value(getType())
		, nullptr
		, 0
	};
}

pkcs11::structs::MechanismInfo
MechanismBase::getInfo() const noexcept
{
	return pkcs11::structs::MechanismInfo{
		pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Flags{}
	};
}

MechanismBase::ExpectedEncryptor
MechanismBase::getEncryptor() noexcept
{
	return ExpectedEncryptor{ pkcs11::enums::ReturnType::MECHANISM_INVALID };
}

MechanismBase::ExpectedDecryptor
MechanismBase::getDecryptor() noexcept
{
	return ExpectedDecryptor{ pkcs11::enums::ReturnType::MECHANISM_INVALID };
}

MechanismBase::ExpectedSigner
MechanismBase::getSigner() noexcept
{
	return ExpectedSigner{ pkcs11::enums::ReturnType::MECHANISM_INVALID };
}

MechanismBase::ExpectedVerifier
MechanismBase::getVerifier() noexcept
{
	return ExpectedVerifier{ pkcs11::enums::ReturnType::MECHANISM_INVALID };
}


}}}
