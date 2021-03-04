#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/DesOfb8.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

DesOfb8::DesOfb8() noexcept = default;
DesOfb8::~DesOfb8() noexcept = default;

pkcs11::enums::Mechanism DesOfb8::getType() const noexcept
{
	return pkcs11::enums::Mechanism::DES_OFB8;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

