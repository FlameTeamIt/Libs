#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/WtlsServerKeyAndMacDerive.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

WtlsServerKeyAndMacDerive::WtlsServerKeyAndMacDerive() noexcept = default;
WtlsServerKeyAndMacDerive::~WtlsServerKeyAndMacDerive() noexcept = default;

pkcs11::enums::Mechanism WtlsServerKeyAndMacDerive::getType() const noexcept
{
	return pkcs11::enums::Mechanism::WTLS_SERVER_KEY_AND_MAC_DERIVE;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

