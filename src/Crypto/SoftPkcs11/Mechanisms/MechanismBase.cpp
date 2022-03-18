#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

// callbacks

static pkcs11::enums::Mechanism getType(const MechanismBase *);
static pkcs11::structs::MechanismInfo getInfo(const MechanismBase *);
static MechanismBase::ExpectedEncryptor getEncryptor(MechanismBase *);
static MechanismBase::ExpectedDecryptor getDecryptor(MechanismBase *);
static MechanismBase::ExpectedSigner getSigner(MechanismBase *);
static MechanismBase::ExpectedVerifier getVerifier(MechanismBase *);
static pkcs11::enums::ReturnType processParameter(MechanismBase *
		, const MechanismBase::Parameter &);

//

MechanismBase::MechanismBase() noexcept :
		MechanismBase(
				flame_ide::soft_pkcs11::mechanisms::getType
				, flame_ide::soft_pkcs11::mechanisms::getInfo
				, flame_ide::soft_pkcs11::mechanisms::getEncryptor
				, flame_ide::soft_pkcs11::mechanisms::getDecryptor
				, flame_ide::soft_pkcs11::mechanisms::getSigner
				, flame_ide::soft_pkcs11::mechanisms::getVerifier
				, flame_ide::soft_pkcs11::mechanisms::processParameter
		)
{}

MechanismBase::~MechanismBase() noexcept
{}

pkcs11::enums::Mechanism MechanismBase::getType() const noexcept
{
	return getTypeCallback(this);
}

pkcs11::structs::MechanismInfo MechanismBase::getInfo() const noexcept
{
	return getInfoCallback(this);
}

MechanismBase::ExpectedEncryptor MechanismBase::getEncryptor() noexcept
{
	return getEncryptorCallback(this);
}

MechanismBase::ExpectedDecryptor MechanismBase::getDecryptor() noexcept
{
	return getDecryptorCallback(this);
}

MechanismBase::ExpectedSigner MechanismBase::getSigner() noexcept
{
	return getSignerCallback(this);
}

MechanismBase::ExpectedVerifier MechanismBase::getVerifier() noexcept
{
	return getVerifierCallback(this);
}

pkcs11::enums::ReturnType MechanismBase::processParameter(const Parameter &parameter) noexcept
{
	return processParameterCallback(this, parameter);
}

//

MechanismBase::MechanismBase(
		GetTypeCallback getTypeCallback
		, GetInfoCallback getInfoCallback
		, GetEncryptorCallback getEncryptorCallback
		, GetDecryptorCallback getDecryptorCallback
		, GetSignerCallback getSignerCallback
		, GetVerifierCallback getVerifierCallback
		, ProcessParameterCallback processParameterCallback
) noexcept
{
	this->getTypeCallback = getTypeCallback
	, this->getInfoCallback = getInfoCallback
	, this->getEncryptorCallback = getEncryptorCallback
	, this->getDecryptorCallback = getDecryptorCallback
	, this->getSignerCallback = getSignerCallback
	, this->getVerifierCallback = getVerifierCallback
	, this->processParameterCallback = processParameterCallback;
}

//

static pkcs11::enums::Mechanism getType(const MechanismBase *)
{
	return pkcs11::enums::Mechanism::VENDOR_DEFINED;
}

static pkcs11::structs::MechanismInfo getInfo(const MechanismBase *)
{
	return pkcs11::structs::MechanismInfo {
		pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Flags{}
	};
}

static MechanismBase::ExpectedEncryptor getEncryptor(MechanismBase *)
{
	return MechanismBase::ExpectedEncryptor {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static MechanismBase::ExpectedDecryptor getDecryptor(MechanismBase *)
{
	return MechanismBase::ExpectedDecryptor {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static MechanismBase::ExpectedSigner getSigner(MechanismBase *)
{
	return MechanismBase::ExpectedSigner {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static MechanismBase::ExpectedVerifier getVerifier(MechanismBase *)
{
	return MechanismBase::ExpectedVerifier {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static pkcs11::enums::ReturnType processParameter(MechanismBase *
		, const MechanismBase::Parameter &)
{
	return pkcs11::enums::ReturnType::ARGUMENTS_BAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
