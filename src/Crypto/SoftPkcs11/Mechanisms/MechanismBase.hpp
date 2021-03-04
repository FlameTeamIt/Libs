#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Templates/Expected.hpp>
#include <FlameIDE/Templates/Variant.hpp>

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

	using Parameter = templates::Variant<
		pkcs11::structs::RsaPkcsOaepParams
		, pkcs11::structs::RsaPkcsPssParams
		, pkcs11::structs::EcDh1DeriveParams
		, pkcs11::structs::EcDh2DeriveParams
		, pkcs11::structs::EcMqvDeriveParams
		, pkcs11::structs::X9Dh1DeriveParams
		, pkcs11::structs::X9Dh2DeriveParams
		, pkcs11::structs::X9MqvDeriveParams
		, pkcs11::structs::KeaDeriveParams
		, pkcs11::structs::Rc2CbcParams
		, pkcs11::structs::Rc2MacGeneralParams
		, pkcs11::structs::Rc5Params
		, pkcs11::structs::Rc5CbcParams
		, pkcs11::structs::Rc5MacGeneralParams
		, pkcs11::structs::DesCbcEncryptDataParams
		, pkcs11::structs::AesCbcEncryptDataParams
		, pkcs11::structs::SkipjackPrivateWrapParams
		, pkcs11::structs::SkipjackRelayxParams
		, pkcs11::structs::PbeParams
		, pkcs11::structs::KeyWrapSetOaepParams
		, pkcs11::structs::Ssl3MasterKeyDeriveParams
		, pkcs11::structs::Ssl3KeyMatParams
		, pkcs11::structs::TlsPrfParams
		, pkcs11::structs::WtlsMasterKeyDeriveParams
		, pkcs11::structs::WtlsPrfParams
		, pkcs11::structs::WtlsKeyMatParams
		, pkcs11::structs::CmsSigParams
		, pkcs11::structs::Pkcs5Pbkd2Params
		, pkcs11::structs::Pkcs5Pbkd2Params2
		, pkcs11::structs::OtpParam
		, pkcs11::structs::OtpParams
		, pkcs11::structs::KipParams
		, pkcs11::structs::AesCtrParams
		, pkcs11::structs::GcmParams
		, pkcs11::structs::CcmParams
		, pkcs11::structs::CamelliaCtrParams
		, pkcs11::structs::CamelliaCbcEncryptDataParams
		, pkcs11::structs::AriaCbcEncryptDataParams
		, pkcs11::structs::DsaParameterGenParam
		, pkcs11::structs::EcdhAesKeyWrapParams
		, pkcs11::structs::RsaAesKeyWrapParams
		, pkcs11::structs::Tls12MasterKeyDeriveParams
		, pkcs11::structs::Tls12KeyMatParams
		, pkcs11::structs::TlsKdfParams
		, pkcs11::structs::TlsMacParams
		, pkcs11::structs::Gostr3410DeriveParams
		, pkcs11::structs::Gostr3410KeyWrapParams
		, pkcs11::structs::SeedCbcEncryptDataParams
	>;

	MechanismBase() noexcept;

	virtual ~MechanismBase() noexcept;

	virtual pkcs11::enums::Mechanism getType() const noexcept;

	virtual pkcs11::structs::MechanismInfo getInfo() const noexcept;

	virtual ExpectedEncryptor getEncryptor() noexcept;

	virtual ExpectedDecryptor getDecryptor() noexcept;

	virtual ExpectedSigner getSigner() noexcept;

	virtual ExpectedVerifier getVerifier() noexcept;

	virtual pkcs11::enums::ReturnType
	processParameter(const Parameter &paramter) noexcept;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMBASE_HPP
