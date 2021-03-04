#ifndef FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMLIST_HPP
#define FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMLIST_HPP

#include <FlameIDE/Templates/Pointers.hpp>

#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>
#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/VendorDefined.hpp>

namespace flame_ide
{namespace soft_pkcs11
{namespace mechanisms
{

class MechanismList
{
public:
	MechanismList() noexcept;
	~MechanismList() noexcept;

	MechanismBase &get(pkcs11::enums::Mechanism mechanismType) noexcept;

private:
	struct List;

private:
	VendorDefined vendorDefined;
	templates::allocator::MallocAllocator<SizeTraits> allocator;
	ContainerTraits<List>::Pointer list;
};

}}} // namespace flame_ide::soft_pkcs11::mechanisms

#endif // FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_MECHANISMLIST_HPP
