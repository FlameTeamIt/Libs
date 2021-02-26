#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Templates/Expected.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/EncryptorBase.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DecryptorBase.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/SignerBase.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/VerifierBase.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class MechanismBase
{
public:
	using ExpectedEncryptor = templates::Expected<
		EncryptorBase *, pkcs11::enums::ReturnType
	>;
	using ExpectedDecryptor = templates::Expected<
		DecryptorBase *, pkcs11::enums::ReturnType
	>;
	using ExpectedSigner = templates::Expected<
		SignerBase *, pkcs11::enums::ReturnType
	>;
	using ExpectedVerifier = templates::Expected<
		VerifierBase *, pkcs11::enums::ReturnType
	>;

	MechanismBase() noexcept;

	virtual ~MechanismBase() noexcept;

	virtual pkcs11::enums::Mechanism getType() const noexcept;

	virtual pkcs11::structs::Mechanism getNative() const noexcept;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept;

	virtual ExpectedEncryptor getEncryptor() noexcept;

	virtual ExpectedDecryptor getDecryptor() noexcept;

	virtual ExpectedSigner getSigner() noexcept;

	virtual ExpectedVerifier getVerifier() noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP
