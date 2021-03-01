#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Md5.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Md5::Md5() noexcept = default;
Md5::~Md5() noexcept = default;

pkcs11::enums::Mechanism Md5::getType() const noexcept
{
	return pkcs11::enums::Mechanism::MD5;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

