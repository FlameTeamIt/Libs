#ifndef FLAMEIDE_CRYPTO_PKCS11_OBJECTHANDLE_HPP
#define FLAMEIDE_CRYPTO_PKCS11_OBJECTHANDLE_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Templates/Bits.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{
namespace pkcs11
{

/// @brief The Handle class
class ObjectHandle
{
public:
	using Value = value_types::ObjectHandle;
	static constexpr Value INVALID_VALUE = NumberLimit<
		templates::bits::MinimalType<sizeof(Value) * 8>::Type
	>::MAX_VALUE;

	ObjectHandle() noexcept;
	ObjectHandle(ObjectHandle &&handle) noexcept;

	/// @brief Handle
	/// @param initValue
	explicit ObjectHandle(Value initValue) noexcept;

	ObjectHandle &operator=(ObjectHandle &&handle) noexcept;

	/// @brief operator Value
	explicit operator Value() noexcept;

private:
	Value value = INVALID_VALUE;
};
using ObjectHandleRange = templates::Range<ObjectHandle *>;
using CryptokiObjectHandleRange = templates::Range<ObjectHandle::Value *>;

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_OBJECTHANDLE_HPP
