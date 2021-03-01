#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/XorBaseAndData.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

XorBaseAndData::XorBaseAndData() noexcept = default;
XorBaseAndData::~XorBaseAndData() noexcept = default;

pkcs11::enums::Mechanism XorBaseAndData::getType() const noexcept
{
	return pkcs11::enums::Mechanism::XOR_BASE_AND_DATA;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

