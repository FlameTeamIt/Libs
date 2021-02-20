#ifndef FLAMEIDE_CRYPTO_PKCS11_MECHANISM_HPP
#define FLAMEIDE_CRYPTO_PKCS11_MECHANISM_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Common/Traits/Numbers.hpp>
#include <FlameIDE/Templates/Bits.hpp>
#include <FlameIDE/Templates/Range.hpp>

namespace flame_ide
{
namespace pkcs11
{

class Mechanism : private structs::Mechanism
{
	using Parent = structs::Mechanism;

public:
	using Type = value_types::Mechanism;
	using EnumType = enums::Mechanism;

	using ParameterPtr = value_types::ValuePtr;
	using ParameterPtrToConst = const void *;
	using ParameterSize = value_types::Ulong;

	using ParameterRange = templates::Range<byte_t *>;
	using ConstParameterRange = templates::Range<const byte_t *>;

	using CryptokiParameterRange = templates::Range<value_types::Byte *>;

	Mechanism() noexcept : Parent{ enums::value(EnumType::VENDOR_DEFINED), nullptr, 0 }
	{}

	Mechanism(const Mechanism &) noexcept = default;
	Mechanism(Mechanism &&) noexcept = default;

	/// @brief Mechanism
	/// @param cryptokiMechanism
	Mechanism(const Parent &cryptokiMechanism) : Parent{ cryptokiMechanism }
	{}

	/// @brief Mechanism
	/// @param type
	/// @param paramterPtr
	/// @param paramterSize
	Mechanism(EnumType type, ParameterPtr paramterPtr
			, ParameterSize paramterSize) noexcept;

	/// @brief Attribute
	/// @param initType
	/// @param range
	Mechanism(EnumType initType, ParameterRange range) noexcept
			: Mechanism(
					initType
					, static_cast<ParameterPtr>(&*range.begin())
					, static_cast<ParameterSize>(range.end() - range.begin())
			)
	{}

	/// @brief Attribute
	/// @param initType
	/// @param range
	Mechanism(EnumType initType, CryptokiParameterRange range) noexcept
			: Mechanism(
					initType
					, static_cast<ParameterPtr>(&*range.begin())
					, static_cast<ParameterSize>(range.end() - range.begin())
			)
	{}

	/// @brief getType
	/// @return
	EnumType &getType() noexcept;

	/// @brief getType
	/// @return
	EnumType getType() const noexcept;

	/// @brief getParameterPointer
	/// @return
	ParameterPtr &getParameterPointer() noexcept;

	/// @brief getParameterPointer
	/// @return
	ParameterPtrToConst getParameterPointer() const noexcept;

	/// @brief getParameterSize
	/// @return
	ParameterSize &getParameterSize() noexcept;

	/// @brief getParameterSize
	/// @return
	ParameterSize getParameterSize() const noexcept;

	/// @brief getParameterReange
	/// @return
	ParameterRange getParameterReange() noexcept;

	/// @brief getParameterReange
	/// @return
	ConstParameterRange getParameterReange() const noexcept;

	void set(EnumType type, ParameterPtr paramterPtr , ParameterSize paramterSize) noexcept;

private:
	using Parent::mechanism;
	using Parent::pParameter;
	using Parent::ulParameterLen;
};

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_MECHANISM_HPP
