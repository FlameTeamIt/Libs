#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/PbeSha1Rc4dot128.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

PbeSha1Rc4dot128::PbeSha1Rc4dot128() noexcept = default;
PbeSha1Rc4dot128::~PbeSha1Rc4dot128() noexcept = default;

pkcs11::enums::Mechanism PbeSha1Rc4dot128::getType() const noexcept
{
	return pkcs11::enums::Mechanism::PBE_SHA1_RC4_128;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

