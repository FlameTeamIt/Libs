declare -r list=(\
	RSA_PKCS_KEY_PAIR_GEN \
	RSA_PKCS \
	RSA_9796 \
	RSA_X_509 \
#\
	MD2_RSA_PKCS \
	MD5_RSA_PKCS \
	SHA1_RSA_PKCS \
\
	RIPEMD128_RSA_PKCS \
	RIPEMD160_RSA_PKCS \
	RSA_PKCS_OAEP \
\
	RSA_X9_31_KEY_PAIR_GEN \
	RSA_X9_31 \
	SHA1_RSA_X9_31 \
	RSA_PKCS_PSS \
	SHA1_RSA_PKCS_PSS \
\
	DSA_KEY_PAIR_GEN \
	DSA \
	DSA_SHA1 \
	DSA_SHA224 \
	DSA_SHA256 \
	DSA_SHA384 \
	DSA_SHA512 \
\
	DH_PKCS_KEY_PAIR_GEN \
	DH_PKCS_DERIVE \
\
	X9_42_DH_KEY_PAIR_GEN \
	X9_42_DH_DERIVE \
	X9_42_DH_HYBRID_DERIVE \
	X9_42_MQV_DERIVE \
\
	SHA256_RSA_PKCS \
	SHA384_RSA_PKCS \
	SHA512_RSA_PKCS \
	SHA256_RSA_PKCS_PSS \
	SHA384_RSA_PKCS_PSS \
	SHA512_RSA_PKCS_PSS \
\
	SHA224_RSA_PKCS \
	SHA224_RSA_PKCS_PSS \
\
	SHA512_224 \
	SHA512_224_HMAC \
	SHA512_224_HMAC_GENERAL \
	SHA512_224_KEY_DERIVATION \
	SHA512_256 \
	SHA512_256_HMAC \
	SHA512_256_HMAC_GENERAL \
	SHA512_256_KEY_DERIVATION \
\
	SHA512_T \
	SHA512_T_HMAC \
	SHA512_T_HMAC_GENERAL \
	SHA512_T_KEY_DERIVATION \
\
	RC2_KEY_GEN \
	RC2_ECB \
	RC2_CBC \
	RC2_MAC \
\
	RC2_MAC_GENERAL \
	RC2_CBC_PAD \
\
	RC4_KEY_GEN \
	RC4 \
\
	DES_KEY_GEN \
	DES_ECB \
	DES_CBC \
	DES_MAC \
\
	DES_MAC_GENERAL \
	DES_CBC_PAD \
\
	DES2_KEY_GEN \
	DES3_KEY_GEN \
	DES3_ECB \
	DES3_CBC \
	DES3_MAC \
\
	DES3_MAC_GENERAL \
	DES3_CBC_PAD \
	DES3_CMAC_GENERAL \
	DES3_CMAC \
\
	CDMF_KEY_GEN \
	CDMF_ECB \
	CDMF_CBC \
	CDMF_MAC \
	CDMF_MAC_GENERAL \
	CDMF_CBC_PAD \
\
	DES_OFB64 \
	DES_OFB8 \
	DES_CFB64 \
	DES_CFB8 \
\
	MD2 \
	MD2_HMAC \
	MD2_HMAC_GENERAL \
\
	MD5 \
	MD5_HMAC \
	MD5_HMAC_GENERAL \
\
	SHA_1 \
	SHA_1_HMAC \
	SHA_1_HMAC_GENERAL \
\
	RIPEMD128 \
	RIPEMD128_HMAC \
	RIPEMD128_HMAC_GENERAL \
	RIPEMD160 \
	RIPEMD160_HMAC \
	RIPEMD160_HMAC_GENERAL \
\
	SHA256 \
	SHA256_HMAC \
	SHA256_HMAC_GENERAL \
	SHA224 \
	SHA224_HMAC \
	SHA224_HMAC_GENERAL \
	SHA384 \
	SHA384_HMAC \
	SHA384_HMAC_GENERAL \
	SHA512 \
	SHA512_HMAC \
	SHA512_HMAC_GENERAL \
\
	SECURID_KEY_GEN \
	SECURID \
\
	HOTP_KEY_GEN \
	HOTP \
\
	ACTI \
	ACTI_KEY_GEN \
\
	CAST_KEY_GEN \
	CAST_ECB \
	CAST_CBC \
	CAST_MAC \
	CAST_MAC_GENERAL \
	CAST_CBC_PAD \
\
	CAST3_KEY_GEN \
	CAST3_ECB \
	CAST3_CBC \
	CAST3_MAC \
	CAST3_MAC_GENERAL \
	CAST3_CBC_PAD \
\
	CAST5_KEY_GEN \
	CAST128_KEY_GEN \
	CAST5_ECB \
	CAST128_ECB \
	CAST5_CBC \
	CAST128_CBC \
	CAST5_MAC \
	CAST128_MAC \
	CAST5_MAC_GENERAL \
	CAST128_MAC_GENERAL \
	CAST5_CBC_PAD \
	CAST128_CBC_PAD \
\
	RC5_KEY_GEN \
	RC5_ECB \
	RC5_CBC \
	RC5_MAC \
	RC5_MAC_GENERAL \
	RC5_CBC_PAD \
\
	IDEA_KEY_GEN \
	IDEA_ECB \
	IDEA_CBC \
	IDEA_MAC \
	IDEA_MAC_GENERAL \
	IDEA_CBC_PAD \
\
	GENERIC_SECRET_KEY_GEN \
\
	CONCATENATE_BASE_AND_KEY \
	CONCATENATE_BASE_AND_DATA \
	CONCATENATE_DATA_AND_BASE \
\
	XOR_BASE_AND_DATA \
\
	EXTRACT_KEY_FROM_KEY \
\
	SSL3_PRE_MASTER_KEY_GEN \
	SSL3_MASTER_KEY_DERIVE \
	SSL3_KEY_AND_MAC_DERIVE \
	SSL3_MASTER_KEY_DERIVE_DH \
\
	TLS_PRE_MASTER_KEY_GEN \
	TLS_MASTER_KEY_DERIVE \
	TLS_KEY_AND_MAC_DERIVE \
	TLS_MASTER_KEY_DERIVE_DH \
	TLS_PRF \
\
	SSL3_MD5_MAC \
	SSL3_SHA1_MAC \
\
	MD5_KEY_DERIVATION \
	MD2_KEY_DERIVATION \
	SHA1_KEY_DERIVATION \
\
	SHA256_KEY_DERIVATION \
	SHA384_KEY_DERIVATION \
	SHA512_KEY_DERIVATION \
	SHA224_KEY_DERIVATION \
\
	PBE_MD2_DES_CBC \
	PBE_MD5_DES_CBC \
	PBE_MD5_CAST_CBC \
	PBE_MD5_CAST3_CBC \
	PBE_MD5_CAST5_CBC \
	PBE_MD5_CAST128_CBC \
	PBE_SHA1_CAST5_CBC \
	PBE_SHA1_CAST128_CBC \
	PBE_SHA1_RC4_128 \
	PBE_SHA1_RC4_40 \
	PBE_SHA1_DES3_EDE_CBC \
	PBE_SHA1_DES2_EDE_CBC \
	PBE_SHA1_RC2_128_CBC \
	PBE_SHA1_RC2_40_CBC \
\
	PKCS5_PBKD2 \
\
	PBA_SHA1_WITH_SHA1_HMAC \
\
	WTLS_PRE_MASTER_KEY_GEN \
	WTLS_MASTER_KEY_DERIVE \
	WTLS_MASTER_KEY_DERIVE_DH_ECC \
	WTLS_PRF \
	WTLS_SERVER_KEY_AND_MAC_DERIVE \
	WTLS_CLIENT_KEY_AND_MAC_DERIVE \
\
	TLS10_MAC_SERVER \
	TLS10_MAC_CLIENT \
	TLS12_MAC \
	TLS12_KDF \
	TLS12_MASTER_KEY_DERIVE \
	TLS12_KEY_AND_MAC_DERIVE \
	TLS12_MASTER_KEY_DERIVE_DH \
	TLS12_KEY_SAFE_DERIVE \
	TLS_MAC \
	TLS_KDF \
\
	KEY_WRAP_LYNKS \
	KEY_WRAP_SET_OAEP \
\
	CMS_SIG \
\
	KIP_DERIVE \
	KIP_WRAP \
	KIP_MAC \
\
	CAMELLIA_KEY_GEN \
	CAMELLIA_ECB \
	CAMELLIA_CBC \
	CAMELLIA_MAC \
	CAMELLIA_MAC_GENERAL \
	CAMELLIA_CBC_PAD \
	CAMELLIA_ECB_ENCRYPT_DATA \
	CAMELLIA_CBC_ENCRYPT_DATA \
	CAMELLIA_CTR \
\
	ARIA_KEY_GEN \
	ARIA_ECB \
	ARIA_CBC \
	ARIA_MAC \
	ARIA_MAC_GENERAL \
	ARIA_CBC_PAD \
	ARIA_ECB_ENCRYPT_DATA \
	ARIA_CBC_ENCRYPT_DATA \
\
	SEED_KEY_GEN \
	SEED_ECB \
	SEED_CBC \
	SEED_MAC \
	SEED_MAC_GENERAL \
	SEED_CBC_PAD \
	SEED_ECB_ENCRYPT_DATA \
	SEED_CBC_ENCRYPT_DATA \
\
	SKIPJACK_KEY_GEN \
	SKIPJACK_ECB64 \
	SKIPJACK_CBC64 \
	SKIPJACK_OFB64 \
	SKIPJACK_CFB64 \
	SKIPJACK_CFB32 \
	SKIPJACK_CFB16 \
	SKIPJACK_CFB8 \
	SKIPJACK_WRAP \
	SKIPJACK_PRIVATE_WRAP \
	SKIPJACK_RELAYX \
\
	KEA_KEY_PAIR_GEN \
	KEA_KEY_DERIVE \
	KEA_DERIVE \
\
	FORTEZZA_TIMESTAMP \
\
	BATON_KEY_GEN \
	BATON_ECB128 \
	BATON_ECB96 \
	BATON_CBC128 \
	BATON_COUNTER \
	BATON_SHUFFLE \
	BATON_WRAP \
\
	ECDSA_KEY_PAIR_GEN \
\
	EC_KEY_PAIR_GEN \
\
	ECDSA \
	ECDSA_SHA1 \
	ECDSA_SHA224 \
	ECDSA_SHA256 \
	ECDSA_SHA384 \
	ECDSA_SHA512 \
\
	ECDH1_DERIVE \
	ECDH1_COFACTOR_DERIVE \
	ECMQV_DERIVE \
\
	ECDH_AES_KEY_WRAP \
	RSA_AES_KEY_WRAP \
\
	JUNIPER_KEY_GEN \
	JUNIPER_ECB128 \
	JUNIPER_CBC128 \
	JUNIPER_COUNTER \
	JUNIPER_SHUFFLE \
	JUNIPER_WRAP \
\
	FASTHASH \
\
	AES_KEY_GEN \
	AES_ECB \
	AES_CBC \
	AES_MAC \
	AES_MAC_GENERAL \
	AES_CBC_PAD \
	AES_CTR \
	AES_GCM \
	AES_CCM \
	AES_CTS \
	AES_CMAC \
	AES_CMAC_GENERAL \
\
	AES_XCBC_MAC \
	AES_XCBC_MAC_96 \
	AES_GMAC \
\
	BLOWFISH_KEY_GEN \
	BLOWFISH_CBC \
\
	TWOFISH_KEY_GEN \
	TWOFISH_CBC \
\
	BLOWFISH_CBC_PAD \
\
	TWOFISH_CBC_PAD \
\
	DES_ECB_ENCRYPT_DATA \
	DES_CBC_ENCRYPT_DATA \
	DES3_ECB_ENCRYPT_DATA \
	DES3_CBC_ENCRYPT_DATA \
\
	AES_ECB_ENCRYPT_DATA \
	AES_CBC_ENCRYPT_DATA \
\
	GOSTR3410_KEY_PAIR_GEN \
	GOSTR3410 \
	GOSTR3410_WITH_GOSTR3411 \
	GOSTR3410_KEY_WRAP \
	GOSTR3410_DERIVE \
\
	GOSTR3411 \
	GOSTR3411_HMAC \
	GOST28147_KEY_GEN \
	GOST28147_ECB \
	GOST28147 \
	GOST28147_MAC \
	GOST28147_KEY_WRAP \
\
	DSA_PARAMETER_GEN \
\
	DH_PKCS_PARAMETER_GEN \
\
	X9_42_DH_PARAMETER_GEN \
\
	DSA_PROBABLISTIC_PARAMETER_GEN \
	DSA_SHAWE_TAYLOR_PARAMETER_GEN \
\
	AES_OFB \
	AES_CFB64 \
	AES_CFB8 \
	AES_CFB128 \
	AES_CFB1 \
	AES_KEY_WRAP \
	AES_KEY_WRAP_PAD \
\
	RSA_PKCS_TPM_1_1 \
	RSA_PKCS_OAEP_TPM_1_1 \
\
	VENDOR_DEFINED \
)

macro_name_gen()
{
	local macrname_prefix="FLAMEIDE_SRC_CRYPTO_SOFTPKCS11_MECHANISMS_"
	local macrname_suffix="_HPP"
	local mechanism_name="$1"
	echo "${macrname_prefix}${mechanism_name}${macrname_suffix}"
}

head_header1_gen()
{
	local macro_name="$1"
	echo "#ifndef ${macro_name}"
}

head_header2_gen()
{
	local macro_name=$1
	echo -e "#define ${macro_name}\n"
}

tail_header2_gen()
{
	local macro_name=$1
	echo "#endif // ${macro_name}"
}

header_list_gen()
{
	printf "%s\n\n" "#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/MechanismBase.hpp>"
}

class_name_gen()
{
	local mechanism_name="$1"
	local class_name=$(\
		echo "${mechanism_name}" |\
			sed -e 's/PKCS/Pkcs/g' |\
			sed -e 's/RSA/Rsa/g' |\
			sed -e 's/KEY/Key/g' |\
			sed -e 's/PAIR/Pair/g' |\
			sed -e 's/GENERIC/Generic/g' |\
			sed -e 's/GENERAL/General/g' |\
			sed -e 's/GEN/Generator/g' |\
			sed -e 's/X_509/Xdot509/g' |\
			sed -e 's/MD/Md/g' |\
			sed -e 's/MD/Md/g' |\
			sed -e 's/SHAWE/Shawe/g' |\
			sed -e 's/SHA/Sha/g' |\
			sed -e 's/RIPE/Ripe/g' |\
			sed -e 's/OAEP/Oaep/g' |\
			sed -e 's/X9_/X9dot/g' |\
			sed -e 's/PSS/Pss/g' |\
			sed -e 's/DSA/Dsa/g' |\
			sed -e 's/DH_/DiffieHellman/g' |\
			sed -e 's/_DH/DiffieHellman/g' |\
			sed -e 's/DERIVE/Derive/g' |\
			sed -e 's/HYBRID/Hybrid/g' |\
			sed -e 's/MQV/Mqv/g' |\
			sed -e 's/HMAC/Hmac/g' |\
			sed -e 's/DERIVATION/Derivation/g' |\
			sed -e 's/_224/dot224/g' |\
			sed -e 's/_256/dot256/g' |\
			sed -e 's/_T/t/g' |\
			sed -e 's/tIMESTAMP/Timestamp/g' |\
			sed -e 's/RC2_128/Rc2dot128/g' |\
			sed -e 's/RC2_40/Rc2dot40/g' |\
			sed -e 's/RC2/Rc2/g' |\
			sed -e 's/RC4_128/Rc4dot128/g' |\
			sed -e 's/RC4_40/Rc4dot40/g' |\
			sed -e 's/RC4/Rc4/g' |\
			sed -e 's/RC5/Rc5/g' |\
			sed -e 's/XCBC/Xcbc/g' |\
			sed -e 's/CBC/Cbc/g' |\
			sed -e 's/PAD/Pad/g' |\
			sed -e 's/GMAC/Gmac/g' |\
			sed -e 's/CMAC/Cmac/g' |\
			sed -e 's/MAC/Mac/g' |\
			sed -e 's/ECB/Ecb/g' |\
			sed -e 's/DES/Des/g' |\
			sed -e 's/CDMF/Cdmf/g' |\
			sed -e 's/CDMF/Cdmf/g' |\
			sed -e 's/OFB/Ofb/g' |\
			sed -e 's/CFB/Cfb/g' |\
			sed -e 's/SECURID/SecurId/g' |\
			sed -e 's/HOTP/Hotp/g' |\
			sed -e 's/ACTI/Acti/g' |\
			sed -e 's/CAST/Cast/g' |\
			sed -e 's/IDEA/Idea/g' |\
			sed -e 's/SECRET/Secret/g' |\
			sed -e 's/CONCATENATE/Concatenate/g' |\
			sed -e 's/BASE/Base/g' |\
			sed -e 's/DATA/Data/g' |\
			sed -e 's/AND/And/g' |\
			sed -e 's/XOR/Xor/g' |\
			sed -e 's/FROM/From/g' |\
			sed -e 's/EXTRACT/Extract/g' |\
			sed -e 's/SSL/Ssl/g' |\
			sed -e 's/WTLS/Wtls/g' |\
			sed -e 's/TLS/Tls/g' |\
			sed -e 's/PRE/Pre/g' |\
			sed -e 's/MASTER/Master/g' |\
			sed -e 's/PRF/Prf/g' |\
			sed -e 's/PBE/Pbe/g' |\
			sed -e 's/PBA/Pba/g' |\
			sed -e 's/EDE/Ede/g' |\
			sed -e 's/PBKD/Pbkd/g' |\
			sed -e 's/SERVER/Server/g' |\
			sed -e 's/CLIENT/Client/g' |\
			sed -e 's/ECC/Ecc/g' |\
			sed -e 's/WITH/With/g' |\
			sed -e 's/KDF/Kdf/g' |\
			sed -e 's/SAFE/Safe/g' |\
			sed -e 's/WRAP/Wrap/g' |\
			sed -e 's/LYNKS/Lynks/g' |\
			sed -e 's/SET/Set/g' |\
			sed -e 's/CMS/Cms/g' |\
			sed -e 's/SIG/Signature/g' |\
			sed -e 's/SKIPJACK/Skipjack/g' |\
			sed -e 's/KIP/Kip/g' |\
			sed -e 's/CAMELLIA/Camellia/g' |\
			sed -e 's/CTR/Ctr/g' |\
			sed -e 's/ARIA/Aria/g' |\
			sed -e 's/ENCRYPT/Encrypt/g' |\
			sed -e 's/SEED/Seed/g' |\
			sed -e 's/PRIVATE/Private/g' |\
			sed -e 's/RELAYX/Relayx/g' |\
			sed -e 's/KEA/Kea/g' |\
			sed -e 's/FORTEZZA/Fortezza/g' |\
			sed -e 's/BATON/Baton/g' |\
			sed -e 's/COUNTER/Counter/g' |\
			sed -e 's/SHUFFLE/Shuffle/g' |\
			sed -e 's/EC/ElipticCurve/g' |\
			sed -e 's/AES/Aes/g' |\
			sed -e 's/FASTHASH/Fasthash/g' |\
			sed -e 's/JUNIPER/Juniper/g' |\
			sed -e 's/GCM/Gcm/g' |\
			sed -e 's/CCM/Ccm/g' |\
			sed -e 's/CTS/Cts/g' |\
			sed -e 's/COFACTOR/Cofactor/g' |\
			sed -e 's/BLOWFISH/Blowfish/g' |\
			sed -e 's/TWOFISH/Twofish/g' |\
			sed -e 's/GOSTR/Gostr/g' |\
			sed -e 's/GOST/Gost/g' |\
			sed -e 's/PARAMETER/Parameter/g' |\
			sed -e 's/tPM_1_1/Tpm11/g' |\
			sed -e 's/VENDOR_DEFINED/VendorDefined/g' |\
			sed -e 's/tAYLOR/Taylor/g' |\
			sed -e 's/PROBABLISTIC/Probablistic/g' |\
			sed -e 's/_//g' #|\
			# sed -e 's///g' |\
	)
# 	local format="%-40s%s\n"
# 	printf "$format" "$mechanism_name" "$class_name" 
	echo "$class_name"
}

namespace_header_gen()
{
	printf "%s\n{%s\n{%s\n{\n\n" "namespace flame_ide" "namespace soft_pkcs11" "namespace mechanisms"
}

class_define_gen()
{
	printf "class %s: public MechanismBase\n" "$1"
	printf "{\n" "$1"
	printf "\t%s() noexcept;\n" "$1"
	printf "\n" "$1"
	printf "\tvirtual ~%s() noexcept override;\n" "$1"
	printf "\n" "$1"
	printf "\tvirtual pkcs11::enums::Mechanism getType() const noexcept override;\n" "$1"
	printf "};\n\n" "$1"
}

class_src_gen()
{
	printf "#include <FlameIDE/../../src/Crypto/SoftPkcs11/Mechanisms/$1.hpp>\n"
	printf "\n"
	namespace_header_gen
	printf "%s::%s() noexcept = default;\n" "$1" "$1"
	printf "\n"
	printf "%s::~%s() noexcept = default;\n" "$1" "$1"
	printf "\n"
	printf "pkcs11::enums::Mechanism\n"
	printf "%s::getType() const noexcept\n" "$1"
	printf "{\n"
	printf "\treturn pkcs11::enums::Mechanism::$2;\n"
	printf "}\n"
	printf "\n"
	namespace_tail_gen
}

namespace_tail_gen()
{
	echo -e "}}} // namespace flame_ide::soft_pkcs11::mechanisms\n"
}

# echo ${list[@]}
for mech in ${list[@]}; do
	echo $mech:
	echo HEADER
	macro_name=$(macro_name_gen $mech)
	head_header1_gen "$macro_name"
	head_header2_gen "$macro_name"

	header_list_gen
	namespace_header_gen

	class_name=$(class_name_gen $mech)
	class_define_gen "$class_name"
	
	namespace_tail_gen
	tail_header2_gen "$macro_name"
	
	head_header1_gen "$macro_name" > src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	head_header2_gen "$macro_name" >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	header_list_gen                >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	namespace_header_gen           >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	class_define_gen "$class_name" >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	namespace_tail_gen             >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	tail_header2_gen "$macro_name" >>src/Crypto/SoftPkcs11/Mechanisms/${class_name}.hpp
	
	echo SOURCE
	class_src_gen "$class_name" "$mech"
	class_src_gen "$class_name" "$mech" > src/Crypto/SoftPkcs11/Mechanisms/${class_name}.cpp
done
