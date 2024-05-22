#ifndef FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP
#define FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP

#include "FlameIDE/Crypto/Pkcs11/Types/Structs/Date.hpp"
#include <FlameIDE/Common/Traits/CreationProhibitions.hpp>
#include <FlameIDE/Common/Traits/Fuctional.hpp>

#include <FlameIDE/Crypto/Pkcs11/Types/Enums.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/Structs/Attribute.hpp>
#include <FlameIDE/Crypto/Pkcs11/Types/ValueTypes.hpp>

#include <FlameIDE/Templates/Array.hpp>

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{namespace attribute_traits
{

namespace meta_tags
{
struct Clock : public NonCreational {};
struct MonotonicCounter : public NonCreational {};
struct Certificate : public NonCreational {};
struct X509PublicKeyCertificateObjects : public NonCreational {};
} // namespace meta_tags

///
template<pkcs11::enums::Attribute, typename Meta = void> struct Trait;

// # Common attributes

/// \brief
/// \note Object class (type)
template<>
struct Trait<pkcs11::enums::Attribute::CLASS> : public NonCreational
{
	using Type = pkcs11::enums::ObjectClass;
};

// ------------------------------------------------------------------------------------------------
// # Hardware Feature Objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Overview
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note Hardware feature (type)
///
template<>
struct Trait<pkcs11::enums::Attribute::HW_FEATURE_TYPE> : public NonCreational
{
	using Type = pkcs11::enums::HardwareFeature;
};

// ------------------------------------------------------------------------------------------------
// ## Clock
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note Current time as a character-string of length 16, represented in the format
/// YYYYMMDDhhmmssxx (4 characters for the year;
/// 2 characters each for the month, the day, the hour, the minute, and the second;
/// and 2 additional reserved ‘0’ characters).
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE, meta_tags::Clock> : public NonCreational
{
	using Type = flame_ide::templates::Array<pkcs11::value_types::Char, 16>; // Byte Array
};
using ClockTrait = Trait<pkcs11::enums::Attribute::VALUE, meta_tags::Clock>;

// ------------------------------------------------------------------------------------------------
// ## Monotonic Counter Objects
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note The value of the counter will reset to a previously returned value if the token is
/// initialized using C_InitToken.
///
template<>
struct Trait<pkcs11::enums::Attribute::RESET_ON_INIT> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note The value of the counter has been reset at least once at some point in time.
///
template<>
struct Trait<pkcs11::enums::Attribute::HAS_RESET> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note The current version of the monotonic counter. The value is returned in big endian order.
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE, meta_tags::MonotonicCounter> : public NonCreational
{
	using Type = void; // Byte Array
};
using MonotonicCounterTrait = Trait<pkcs11::enums::Attribute::VALUE, meta_tags::MonotonicCounter>;

// ------------------------------------------------------------------------------------------------
// ## User Interface Objects
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note Screen resolution (in pixels) in X-axis (e.g. 1280)
///
template<>
struct Trait<pkcs11::enums::Attribute::PIXEL_X> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note Screen resolution (in pixels) in Y-axis (e.g. 1024)
///
template<>
struct Trait<pkcs11::enums::Attribute::PIXEL_Y> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note DPI, pixels per inch
///
template<>
struct Trait<pkcs11::enums::Attribute::RESOLUTION> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note For character-oriented displays; number of character rows (e.g. 24)
///
template<>
struct Trait<pkcs11::enums::Attribute::CHAR_ROWS> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note For character-oriented displays: number of character columns (e.g. 80).
/// If display is of proportional-font type, this is the width of the display
/// in “em”-s (letter “M”), see CC/PP Struct.
///
template<>
struct Trait<pkcs11::enums::Attribute::CHAR_COLUMNS> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note Color support
///
template<>
struct Trait<pkcs11::enums::Attribute::COLOR> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note The number of bits of color or grayscale information per pixel.
///
template<>
struct Trait<pkcs11::enums::Attribute::BITS_PER_PIXEL> : public NonCreational
{
	using Type = pkcs11::value_types::Ulong;
};

///
/// \brief The Trait class
/// \note String indicating supported character sets, as defined by IANA MIBenum
/// sets (www.iana.org).
/// Supported character sets are separated with “;”.
/// E.g. a token supporting iso-8859-1 and US-ASCII would set the attribute value to “4;3”.
///
template<>
struct Trait<pkcs11::enums::Attribute::CHAR_SETS> : public NonCreational
{
	using Type = void; // UTF-8 string
};

///
/// \brief The Trait class
/// \note String indicating supported content transfer encoding methods, as defined by
/// IANA (www.iana.org).
/// Supported methods are separated with “;”.
/// E.g. a token supporting 7bit, 8bit and base64 could set the attribute value
/// to “7bit;8bit;base64”.
///
template<>
struct Trait<pkcs11::enums::Attribute::ENCODING_METHODS> : public NonCreational
{
	using Type = void; // UTF-8 string
};

///
/// \brief The Trait class
/// \note String indicating supported (presentable) MIME-types, as defined by IANA (www.iana.org).
/// Supported types are separated with “;”.
/// E.g. a token supporting MIME types "a/b", "a/c" and "a/d" would set the attribute value
/// to “a/b;a/c;a/d”.
///
template<>
struct Trait<pkcs11::enums::Attribute::MIME_TYPES> : public NonCreational
{
	using Type = void; // UTF-8 string
};

// ------------------------------------------------------------------------------------------------
// ## Storage Objects
// ------------------------------------------------------------------------------------------------

///
/// \brief
/// \note CK_TRUE if object is a token object; CK_FALSE if object is a session object.
/// Default is CK_FALSE.
///
template<>
struct Trait<pkcs11::enums::Attribute::TOKEN> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note CK_TRUE if object is a private object; CK_FALSE if object is a public object.
/// Default value is token-specific, and may depend on the values of other attributes of the object.
///
template<>
struct Trait<pkcs11::enums::Attribute::PRIVATE> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note CK_TRUE if object can be modified.
/// Default is CK_TRUE.
///
template<>
struct Trait<pkcs11::enums::Attribute::MODIFIABLE> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note Description of the object (default empty).
///
template<>
struct Trait<pkcs11::enums::Attribute::LABEL> : public NonCreational
{
	using Type = void; // UTF-8 string
};

///
/// \brief The Trait class
/// \note CK_TRUE if object can be copied using C_CopyObject.
/// Defaults to CK_TRUE.
/// Can’t be set to TRUE once it is set to FALSE.
///
template<>
struct Trait<pkcs11::enums::Attribute::COPYABLE> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note CK_TRUE if the object can be destroyed using C_DestroyObject.
/// Default is CK_TRUE.
///
template<>
struct Trait<pkcs11::enums::Attribute::DESTROYABLE> : public NonCreational
{
	using Type = void;
};

// v3.0
///
/// \brief The Trait class
/// \note The unique identifier assigned to the object.
///
template<>
struct Trait<pkcs11::enums::Attribute::UNIQUE_ID> : public NonCreational
{
	using Type = void; // UTF-8 string
};

// ------------------------------------------------------------------------------------------------
// ## Data objects
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note Description of the application that manages the object (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::APPLICATION> : public NonCreational
{
	using Type = void; // UTF-8 string
};

///
/// \brief The Trait class
/// \note DER-encoding of the object identifier indicating the data object type (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::OBJECT_ID> : public NonCreational
{
	using Type = void; //
};

///
/// \brief The Trait class
/// \note Value of the object (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE> : public NonCreational
{
	using Type = void; // Byte Array
};

// ------------------------------------------------------------------------------------------------
// ## Certificate objects
// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// ### Overview
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note Type of certificate
///
template<>
struct Trait<pkcs11::enums::Attribute::CERTIFICATE_TYPE> : public NonCreational
{
	using Type = pkcs11::enums::Certificate;
};

///
/// \brief The Trait class
/// \note The certificate can be trusted for the application that it was created.
///
template<>
struct Trait<pkcs11::enums::Attribute::TRUSTED> : public NonCreational
{
	using Type = pkcs11::enums::Bool;
};

///
/// \brief The Trait class
/// \note (default CK_CERTIFICATE_CATEGORY_UNSPECIFIED)
///
template<>
struct Trait<pkcs11::enums::Attribute::CERTIFICATE_CATEGORY> : public NonCreational
{
	using Type = pkcs11::enums::CertificateCategory;
};

///
/// \brief The Trait class
/// \note Checksum
///
template<>
struct Trait<pkcs11::enums::Attribute::CHECK_VALUE> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note Start date for the certificate (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::START_DATE> : public NonCreational
{
	using Type = pkcs11::structs::Date;
};

///
/// \brief The Trait class
/// \note End date for the certificate (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::END_DATE> : public NonCreational
{
	using Type = pkcs11::structs::Date;
};

///
/// \brief The Trait class
/// \note DER-encoding of the SubjectPublicKeyInfo for the public key contained
/// in this certificate (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::PUBLIC_KEY_INFO> : public NonCreational
{
	using Type = void;
};

// ------------------------------------------------------------------------------------------------
// ### X.509 public key certificate objects
// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note DER-encoding of the certificate subject name
///
template<>
struct Trait<pkcs11::enums::Attribute::SUBJECT> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note Key identifier for public/private key pair (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::ID> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note DER-encoding of the certificate issuer name (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::ISSUER> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note DER-encoding of the certificate serial number (default empty)
///
template<>
struct Trait<pkcs11::enums::Attribute::SERIAL_NUMBER> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note BER-encoding of the certificate
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE, meta_tags::X509PublicKeyCertificateObjects>
		: public NonCreational
{
	using Type = void; // Byte Array
};
using X509PublicKeyCertificateObjectTrait = Trait<
	pkcs11::enums::Attribute::VALUE
	, meta_tags::X509PublicKeyCertificateObjects
>;

///
/// \brief The Trait class
/// \note If not empty this attribute gives the URL where the complete certificate can be obtained.
/// Default empty.
///
template<>
struct Trait<pkcs11::enums::Attribute::URL> : public NonCreational
{
	using Type = void; // UTF-8 string
};

///
/// \brief The Trait class
/// \note Hash of the subject public key (default empty).
/// Hash algorithm is defined by pkcs11::enums::Attribute::NAME_HASH_ALGORITHM
///
template<>
struct Trait<pkcs11::enums::Attribute::HASH_OF_SUBJECT_PUBLIC_KEY> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note Hash of the issuer public key (default empty).
/// Hash algorithm is defined by pkcs11::enums::Attribute::NAME_HASH_ALGORITHM
///
template<>
struct Trait<pkcs11::enums::Attribute::HASH_OF_ISSUER_PUBLIC_KEY> : public NonCreational
{
	using Type = void; // Byte array
};

///
/// \brief The Trait class
/// \note Java MIDP security domain.
/// Default SecurityDomain::UNSPECIFIED
///
template<>
struct Trait<pkcs11::enums::Attribute::JAVA_MIDP_SECURITY_DOMAIN> : public NonCreational
{
	using Type = pkcs11::enums::SecurityDomain;
};

///
/// \brief The Trait class
/// \note Defines the mechanism used to calculate CKA_HASH_OF_SUBJECT_PUBLIC_KEY and
/// CKA_HASH_OF_ISSUER_PUBLIC_KEY.
/// If the attribute is not present then the type defaults to SHA-1.
///
template<>
struct Trait<pkcs11::enums::Attribute::NAME_HASH_ALGORITHM> : public NonCreational
{
	using Type = pkcs11::enums::Mechanism;
};

// ------------------------------------------------------------------------------------------------
// ### WTLS public key certificate objects
// ------------------------------------------------------------------------------------------------

/*
CKA_SUBJECT                    Byte array        WTLS-encoding (Identifier type) of the certificate subject
CKA_ISSUER                     Byte array        WTLS-encoding (Identifier type) of the certificate issuer (default empty)
CKA_VALUE                      Byte array        WTLS-encoding of the certificate
CKA_URL                        RFC2279 string    If not empty this attribute gives the URL where the complete certificate can be obtained
CKA_HASH_OF_SUBJECT_PUBLIC_KEY Byte array        SHA-1 hash of the subject public key (default empty). Hash algorithm is defined by CKA_NAME_HASH_ALGORITHM
CKA_HASH_OF_ISSUER_PUBLIC_KEY  Byte array        SHA-1 hash of the issuer public key (default empty). Hash algorithm is defined by CKA_NAME_HASH_ALGORITHM
CKA_NAME_HASH_ALGORITHM        CK_MECHANISM_TYPE Defines the mechanism used to calculate CKA_HASH_OF_SUBJECT_PUBLIC_KEY and CKA_HASH_OF_ISSUER_PUBLIC_KEY. If the attribute is not present then the type defaults to SHA-1.
*/

// ------------------------------------------------------------------------------------------------
// ### X.509 attribute certificate objects
// ------------------------------------------------------------------------------------------------

/*
CKA_OWNER         Byte Array DER-encoding of the attribute certificate's subject field. This is distinct from the CKA_SUBJECT attribute contained in CKC_X_509 certificates because the ASN.1 syntax and encoding are different.
CKA_AC_ISSUER     Byte Array DER-encoding of the attribute certificate's issuer field. This is distinct from the CKA_ISSUER attribute contained in CKC_X_509 certificates because the ASN.1 syntax and encoding are different. (default empty)
CKA_SERIAL_NUMBER Byte Array DER-encoding of the certificate serial number. (default empty)
CKA_ATTR_TYPES    Byte Array BER-encoding of a sequence of object identifier values corresponding to the attribute types contained in the certificate. When present, this field offers an opportunity for applications to search for a particular attribute certificate without fetching and parsing the certificate itself. (default empty)
CKA_VALUE         Byte Array BER-encoding of the certificate.
*/

// ------------------------------------------------------------------------------------------------
// ## Key objects
// ------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------
// ## Public key objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Private key objects
// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// ### Overview
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ### RSA private key objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Secret key objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Domain parameter objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Mechanism objects
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// ## Profile objects
// ------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::AC_ISSUER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OWNER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::ATTR_TYPES> : public NonCreational
{
	using Type = void;
};





//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::KEY_TYPE> : public NonCreational
{
	using Type = void;
};



///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::SENSITIVE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::ENCRYPT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::DECRYPT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::WRAP> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::UNWRAP> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::SIGN> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::SIGN_RECOVER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::VERIFY> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::VERIFY_RECOVER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::DERIVE> : public NonCreational
{
	using Type = void;
};


///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::MODULUS> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::MODULUS_BITS> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PUBLIC_EXPONENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PRIVATE_EXPONENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PRIME_1> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PRIME_2> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::EXPONENT_1> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::EXPONENT_2> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::COEFFICIENT> : public NonCreational
{
	using Type = void;
};


///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PRIME> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::SUBPRIME> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::BASE> : public NonCreational
{
	using Type = void;
};

//

template<>
struct Trait<pkcs11::enums::Attribute::PRIME_BITS> : public NonCreational
{
	using Type = void;
};

template<>
struct Trait<pkcs11::enums::Attribute::SUBPRIME_BITS> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE_BITS> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::VALUE_LEN> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::EXTRACTABLE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::LOCAL> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::NEVER_EXTRACTABLE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::ALWAYS_SENSITIVE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::KEY_GEN_MECHANISM> : public NonCreational
{
	using Type = void;
};

//


//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::EC_PARAMS> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::EC_POINT> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::ALWAYS_AUTHENTICATE> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::WRAP_WITH_TRUSTED> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::WRAP_TEMPLATE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::UNWRAP_TEMPLATE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::DERIVE_TEMPLATE> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_FORMAT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_LENGTH> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_TIME_INTERVAL> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_USER_FRIENDLY_MODE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_CHALLENGE_REQUIREMENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_TIME_REQUIREMENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_COUNTER_REQUIREMENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_PIN_REQUIREMENT> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_COUNTER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_TIME> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_USER_IDENTIFIER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_SERVICE_IDENTIFIER> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_SERVICE_LOGO> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::OTP_SERVICE_LOGO_TYPE> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::GOSTR3410_PARAMS> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::GOSTR3411_PARAMS> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::GOST28147_PARAMS> : public NonCreational
{
	using Type = void;
};

//


//


///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::MECHANISM_TYPE> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::REQUIRED_CMS_ATTRIBUTES> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::DEFAULT_CMS_ATTRIBUTES> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::SUPPORTED_CMS_ATTRIBUTES> : public NonCreational
{
	using Type = void;
};

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::ALLOWED_MECHANISMS> : public NonCreational
{
	using Type = void;
};

//

// v3.0
///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::PROFILE_ID> : public NonCreational
{
	using Type = void;
};

//

///
/// \brief The Trait class
/// \note
///
template<>
struct Trait<pkcs11::enums::Attribute::VENDOR_DEFINED> : public NonCreational
{
	using Type = void;
};

}}}} // namespace flame_ide::pkcs11::wrapper::attribute_traits

namespace flame_ide
{namespace pkcs11
{namespace wrapper
{

template<pkcs11::enums::Attribute ATTRIBUTE>
class Attribute : private pkcs11::structs::Attribute
{
public:
	static constexpr auto TYPE = ATTRIBUTE;

	using ValueType = typename attribute_traits::Trait<ATTRIBUTE>::Type;
	static_assert(ComparingTypes<ValueType, void>::VALUE, "Need type");

public:
	Attribute() noexcept
			: pkcs11::structs::Attribute(
					pkcs11::enums::value(ATTRIBUTE)
					, nullptr
					, pkcs11::value_types::Ulong{0}
			)
	{}



private:
	ValueType value;
};

}}} // namespace flame_ide::pkcs11::wrapper

#endif // FLAMEIDE_CRYPTO_PKCS11_ATTRIBUTE_HPP
