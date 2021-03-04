#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeMd2DesCbc.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeMd2DesCbc::PbeMd2DesCbc() noexcept = default;
PbeMd2DesCbc::~PbeMd2DesCbc() noexcept = default;

pkcs11::enums::Mechanism PbeMd2DesCbc::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_MD2_DES_CBC;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

