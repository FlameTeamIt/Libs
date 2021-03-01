#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesOfb64.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesOfb64::DesOfb64() noexcept = default;
DesOfb64::~DesOfb64() noexcept = default;

pkcs11::enums::Mechanism DesOfb64::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_OFB64;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

