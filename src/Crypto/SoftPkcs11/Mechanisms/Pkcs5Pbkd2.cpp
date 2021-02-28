#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/Pkcs5Pbkd2.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

Pkcs5Pbkd2::Pkcs5Pbkd2() noexcept = default;
Pkcs5Pbkd2::~Pkcs5Pbkd2() noexcept = default;

pkcs11::enums::Mechanism Pkcs5Pbkd2::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PKCS5_PBKD2;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

