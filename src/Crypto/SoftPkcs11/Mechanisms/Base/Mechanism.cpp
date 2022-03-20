#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Base/Mechanism.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

// callbacks

static pkcs11::enums::Mechanism getType(const Mechanism *);
static pkcs11::structs::MechanismInfo getInfo(const Mechanism *);
static Mechanism::ExpectedEncryptor getEncryptor(Mechanism *);
static Mechanism::ExpectedDecryptor getDecryptor(Mechanism *);
static Mechanism::ExpectedSigner getSigner(Mechanism *);
static Mechanism::ExpectedVerifier getVerifier(Mechanism *);
static pkcs11::enums::ReturnType processParameter(Mechanism *
		, const Mechanism::Parameter &);

//

Mechanism::Mechanism() noexcept :
		Mechanism(
				flame_ide::soft_pkcs11::mechanisms::getType
				, flame_ide::soft_pkcs11::mechanisms::getInfo
				, flame_ide::soft_pkcs11::mechanisms::getEncryptor
				, flame_ide::soft_pkcs11::mechanisms::getDecryptor
				, flame_ide::soft_pkcs11::mechanisms::getSigner
				, flame_ide::soft_pkcs11::mechanisms::getVerifier
				, flame_ide::soft_pkcs11::mechanisms::processParameter
		)
{}

Mechanism::~Mechanism() noexcept
{}

pkcs11::enums::Mechanism Mechanism::getType() const noexcept
{
	return getTypeCallback(this);
}

pkcs11::structs::MechanismInfo Mechanism::getInfo() const noexcept
{
	return getInfoCallback(this);
}

Mechanism::ExpectedEncryptor Mechanism::getEncryptor() noexcept
{
	return getEncryptorCallback(this);
}

Mechanism::ExpectedDecryptor Mechanism::getDecryptor() noexcept
{
	return getDecryptorCallback(this);
}

Mechanism::ExpectedSigner Mechanism::getSigner() noexcept
{
	return getSignerCallback(this);
}

Mechanism::ExpectedVerifier Mechanism::getVerifier() noexcept
{
	return getVerifierCallback(this);
}

pkcs11::enums::ReturnType Mechanism::processParameter(const Parameter &parameter) noexcept
{
	return processParameterCallback(this, parameter);
}

//

Mechanism::Mechanism(
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

static pkcs11::enums::Mechanism getType(const Mechanism *)
{
	return pkcs11::enums::Mechanism::VENDOR_DEFINED;
}

static pkcs11::structs::MechanismInfo getInfo(const Mechanism *)
{
	return pkcs11::structs::MechanismInfo {
		pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Ulong{}
		, pkcs11::value_types::Flags{}
	};
}

static Mechanism::ExpectedEncryptor getEncryptor(Mechanism *)
{
	return Mechanism::ExpectedEncryptor {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static Mechanism::ExpectedDecryptor getDecryptor(Mechanism *)
{
	return Mechanism::ExpectedDecryptor {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static Mechanism::ExpectedSigner getSigner(Mechanism *)
{
	return Mechanism::ExpectedSigner {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static Mechanism::ExpectedVerifier getVerifier(Mechanism *)
{
	return Mechanism::ExpectedVerifier {
			pkcs11::enums::ReturnType::MECHANISM_INVALID
	};
}

static pkcs11::enums::ReturnType processParameter(Mechanism *
		, const Mechanism::Parameter &)
{
	return pkcs11::enums::ReturnType::ARGUMENTS_BAD;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
