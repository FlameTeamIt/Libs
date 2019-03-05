#include "ByteOrderTest.hpp"

namespace flame_ide
{namespace test
{

using flame_ide::templates::ToNeedOrder;
using flame_ide::Types;
using flame_ide::templates::ByteOrder;

int ByteOrderTest::vStart()
{
	constexpr Types::ushort_t VALUE16 = 0xA1B2;
	constexpr Types::uint_t VALUE32 = 0xA1B2C3D4;
	constexpr Types::ulong_t VALUE64 = 0xA1B2C3D4E5F6A9BA;

	constexpr Types::ushort_t VALUE_OTHER16 = 0xB2A1;
	constexpr Types::uint_t VALUE_OTHER32 = 0xD4C3B2A1;
	constexpr Types::ulong_t VALUE_OTHER64 = 0xBAA9F6E5D4C3B2A1;

	Types::ushort_t valueResult16 =
			ToNeedOrder<
				ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER
			>::convert(VALUE16);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from LE to BE byte ordering 16bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER16 == valueResult16);
		}
	));

	valueResult16 =
			ToNeedOrder<
				ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER
			>::convert(VALUE16);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from BE to LE byte ordering 16bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER16 == valueResult16);
		}
	));

	Types::uint_t valueResult32 =
			ToNeedOrder<
				ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER
			>::convert(VALUE32);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from LE to BE byte ordering 32bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER32 == valueResult32);
		}
	));

	valueResult32 =
				ToNeedOrder<
					ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER
				>::convert(VALUE32);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from BE to LE byte ordering 32bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER32 == valueResult32);
		}
	));

	Types::ulong_t valueResult64 =
			ToNeedOrder<
				ByteOrder::LITTLE_ENDIAN_ORDER, ByteOrder::BIG_ENDIAN_ORDER
			>::convert(VALUE64);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from LE to BE byte ordering 64bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER64 == valueResult64);
		}
	));

	valueResult64 =
			ToNeedOrder<
				ByteOrder::BIG_ENDIAN_ORDER, ByteOrder::LITTLE_ENDIAN_ORDER
			>::convert(VALUE64);
	CHECK_RESULT_SUCCESS(doTestCase(
		"convert from BE to LE byte ordering 64bit"
		, [&]()
		{
			IN_CASE_CHECK_END(VALUE_OTHER64 == valueResult64);
		}
	));

	return 0;
}

}}
