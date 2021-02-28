#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/VendorDefined.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

VendorDefined::VendorDefined() noexcept = default;
VendorDefined::~VendorDefined() noexcept = default;

pkcs11::enums::Mechanism VendorDefined::getType() const noexcept
{
	return pkcs11::enums::Mechanism::VENDOR_DEFINED;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

