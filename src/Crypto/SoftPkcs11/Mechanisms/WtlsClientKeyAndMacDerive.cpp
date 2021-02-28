#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsClientKeyAndMacDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsClientKeyAndMacDerive::WtlsClientKeyAndMacDerive() noexcept = default;
WtlsClientKeyAndMacDerive::~WtlsClientKeyAndMacDerive() noexcept = default;

pkcs11::enums::Mechanism WtlsClientKeyAndMacDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_CLIENT_KEY_AND_MAC_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

