#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/CmsSignature.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

CmsSignature::CmsSignature() noexcept = default;
CmsSignature::~CmsSignature() noexcept = default;

pkcs11::enums::Mechanism CmsSignature::getType() const noexcept
{
	return pkcs11::enums::Mechanism::CMS_SIG;
}

}}} // namespace flame_ide::soft_pkcs11::mechanisms

