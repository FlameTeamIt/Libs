#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesCbc::DesCbc() noexcept = default;
DesCbc::~DesCbc() noexcept = default;

pkcs11::enums::Mechanism DesCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

