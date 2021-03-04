#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/KipWrap.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

KipWrap::KipWrap() noexcept = default;
KipWrap::~KipWrap() noexcept = default;

pkcs11::enums::Mechanism KipWrap::getType() const noexcept
{
	return pkcs11::enums::Mechanism::KIP_WRAP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

