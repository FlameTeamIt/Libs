#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Rsa/RsaPkcsOaepTpm11.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

RsaPkcsOaepTpm11::RsaPkcsOaepTpm11() noexcept = default;
RsaPkcsOaepTpm11::~RsaPkcsOaepTpm11() noexcept = default;

pkcs11::enums::Mechanism RsaPkcsOaepTpm11::getType() const noexcept
{
	return pkcs11::enums::Mechanism::RSA_PKCS_OAEP_TPM_1_1;
}

pkcs11::structs::MechanismInfo RsaPkcsOaepTpm11::getInfo() const noexcept
{
	pkcs11::structs::MechanismInfo info;
	info.flags = pkcs11::enums::value(
			pkcs11::enums::MechanismFlags::ENCRYPT
			| pkcs11::enums::MechanismFlags::DECRYPT
			| pkcs11::enums::MechanismFlags::WRAP
			| pkcs11::enums::MechanismFlags::UNWRAP
	);
	return info;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms
