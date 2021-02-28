#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md2RsaPkcs.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md2RsaPkcs::Md2RsaPkcs() noexcept = default;
Md2RsaPkcs::~Md2RsaPkcs() noexcept = default;

pkcs11::enums::Mechanism Md2RsaPkcs::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD2_RSA_PKCS;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

