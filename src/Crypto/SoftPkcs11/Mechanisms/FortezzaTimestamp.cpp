#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/FortezzaTimestamp.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

FortezzaTimestamp::FortezzaTimestamp() noexcept = default;
FortezzaTimestamp::~FortezzaTimestamp() noexcept = default;

pkcs11::enums::Mechanism FortezzaTimestamp::getType() const noexcept
{
	return pkcs11::enums::Mechanism::FORTEZZA_TIMESTAMP;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

