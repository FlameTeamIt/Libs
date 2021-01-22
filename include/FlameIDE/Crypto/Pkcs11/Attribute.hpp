#ifndef FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP
#define FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP

#include <FlameIDE/Crypto/Pkcs11/Types/Structs.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>

#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/Iterator.hpp>

namespace flame_ide
{
namespace pkcs11
{

/// @brief The Attribute class
class Attribute : public structs::Attribute
{
	using Parent = structs::Attribute;

public:
	using Type = value_types::Attribute;
	using EnumType = enums::Attribute;
	using ValuePtr = value_types::ValuePtr;
	using ValueSize = value_types::Ulong;

	using ValueRange = templates::Range<byte_t *>;
	using ConstValueRange = templates::Range<const byte_t *>;

	Attribute() noexcept : Parent{ enums::value(EnumType::VENDOR_DEFINED), nullptr, 0 }
	{}

	Attribute(const Attribute &) noexcept = default;
	Attribute(Attribute &&) noexcept = default;

	/// @brief Attribute
	/// @param cyptokiAttribute
	Attribute(const Parent &cyptokiAttribute) : Parent{ cyptokiAttribute }
	{}

	/// @brief Attribute
	/// @param initType
	/// @param initPtr
	/// @param initSize
	Attribute(EnumType initType, ValuePtr initPtr, ValueSize initSize) noexcept;

	/// @brief Attribute
	/// @param initType
	/// @param range
	Attribute(EnumType initType, ValueRange range) noexcept
			: Attribute(
					initType
					, static_cast<ValuePtr>(&*range.begin())
					, static_cast<ValueSize>(range.end() - range.begin())
			)
	{}

	Attribute &operator=(const Attribute &) noexcept = default;
	Attribute &operator=(Attribute &&) noexcept = default;

	/// @brief typeValue
	/// @return
	EnumType &getType() noexcept;

	/// @brief typeValue
	/// @return
	const EnumType &getType() const noexcept;

	/// @brief valuePointer
	/// @return
	ValuePtr &getValuePointer() noexcept;

	/// @brief valuePointer
	/// @return
	const ValuePtr &getValuePointer() const noexcept;

	/// @brief valueSize
	/// @return
	ValueSize &getValueSize() noexcept;

	/// @brief valueSize
	/// @return
	const ValueSize &getValueSize() const noexcept;

	/// @brief valueRange
	/// @return
	ValueRange getValueRange() noexcept;

	/// @brief valueRange
	/// @return
	ConstValueRange getValueRange() const noexcept;

	/// @brief set
	/// @param newValue
	/// @param newValuePointer
	/// @param newValueSize
	void set(EnumType newValue, ValuePtr newValuePointer
			, ValueSize newValueSize) noexcept;

private:
	using Parent::type;
	using Parent::pValue;
	using Parent::ulValueLen;
};
using AttributeRange = templates::Range<Attribute *>;
using CryptokiAttributeRange = templates::Range<CK_ATTRIBUTE *>;

} // namespace pkcs11
} // namespace flame_ide

#endif // FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP
