#include "SerializationTest.hpp"

#include <FlameIDE/Templates/Vector.hpp>

namespace flame_ide
{namespace test
{

using templates::CompileTimeReverseBytes;

int SerializationTest::vStart()
{
	CHECK_RESULT_SUCCESS(le());
	CHECK_RESULT_SUCCESS(be());
	CHECK_RESULT_SUCCESS(leSpec());
	CHECK_RESULT_SUCCESS_END(beSpec());
}

// LITTLE_ENDIAN_ORDER

SerializationTest::ResultType SerializationTest::le()
{
	IN_CASE_CHECK(le16());
	IN_CASE_CHECK(le32());
	IN_CASE_CHECK_END(le64());
}

bool SerializationTest::le16()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ushort_t VALUE = (Types::ushort_t(BYTES[0]) << 8)
			| Types::ushort_t(BYTES[1]);

	CHECK_RESULT_SUCCESS(doTestCase(
			"le16 serialize"
			, [&]
			{
				auto serializerLe = SerializerLe(&vector[0]);
				serializerLe(VALUE);
				IN_CASE_CHECK_END(vector[0] == BYTES[1] && vector[1] == BYTES[0]);
			}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"le16 deserialize"
			, [&]
			{
				Types::ushort_t value16;
				auto deserializerLe = DeserializerLe(&vector[0]);
				deserializerLe(value16);
				IN_CASE_CHECK_END(value16 == VALUE);
			}
	));

	vector[0] = vector[1] = 0;

	return true;
}

bool SerializationTest::le32()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	CHECK_RESULT_SUCCESS(doTestCase(
		"le32 serialize"
		, [&]
		{
			auto serializerLe = SerializerLe(&vector[0]);
			serializerLe(VALUE);
			IN_CASE_CHECK_END(
					vector[0] == BYTES[3]
					&& vector[1] == BYTES[2]
					&& vector[2] == BYTES[1]
					&& vector[3] == BYTES[0]
			);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"le32 deserialize"
		, [&]
		{
			Types::uint_t value;
			auto deserializerLe = DeserializerLe(&vector[0]);
			deserializerLe(value);

			vector[0] = vector[1] = vector[2] = vector[3] = 0;

			IN_CASE_CHECK_END(value == VALUE);
		}
	));


	return true;
}

bool SerializationTest::le64()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	CHECK_RESULT_SUCCESS(doTestCase(
		"le64 serialize"
		, [&]
		{
			auto serializerLe = SerializerLe(&vector[0]);
			serializerLe(VALUE);
			IN_CASE_CHECK_END(vector[0] == BYTES[7]
					&& vector[1] == BYTES[6]
					&& vector[2] == BYTES[5]
					&& vector[3] == BYTES[4]
					&& vector[4] == BYTES[3]
					&& vector[5] == BYTES[2]
					&& vector[6] == BYTES[1]
					&& vector[7] == BYTES[0]);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"le64 deserialize"
		, [&]
		{
			Types::ulong_t value;
			auto deserializerLe = DeserializerLe(&vector[0]);
			deserializerLe(value);

			vector[0] = vector[1] = vector[2] = vector[3]
					= vector[4] = vector[5] = vector[6] = vector[7] = 0;

			IN_CASE_CHECK_END(value == VALUE);
		}
	));

	vector[0] = vector[1] = vector[2] = vector[3]
			= vector[4] = vector[5] = vector[6] = vector[7] = 0;

	return true;
}

// BIG_ENDIAN_ORDER

SerializationTest::ResultType SerializationTest::be()
{
	IN_CASE_CHECK(be16());
	IN_CASE_CHECK(be32());
	IN_CASE_CHECK_END(be64());
}

bool SerializationTest::be16()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ushort_t VALUE = (Types::ushort_t(BYTES[0]) << 8)
			| Types::ushort_t(BYTES[1]);

	CHECK_RESULT_SUCCESS(doTestCase(
		"be16 serialize"
		, [&]
		{
			auto serializerBe = SerializerBe(&vector[0]);
			serializerBe(VALUE);
			IN_CASE_CHECK_END(vector[0] == BYTES[0]
					&& vector[1] == BYTES[1]);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be16 deserialize"
		, [&]
		{
			Types::ushort_t value;
			auto deserializerBe = DeserializerBe(&vector[0]);
			deserializerBe(value);

			vector[0] = vector[1] = 0;

			IN_CASE_CHECK_END(value == VALUE);
		}
	));

	return true;
}

bool SerializationTest::be32()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	CHECK_RESULT_SUCCESS(doTestCase(
		"be32 serialize"
		, [&]
		{
			auto serializerBe = SerializerBe(&vector[0]);
			serializerBe(VALUE);
			IN_CASE_CHECK_END(vector[0] == BYTES[0]
					&& vector[1] == BYTES[1]
					&& vector[2] == BYTES[2]
					&& vector[3] == BYTES[3]);
		 }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be32 deserialize"
		, [&]
		{
			Types::uint_t value;
			auto deserializerBe = DeserializerBe(&vector[0]);
			deserializerBe(value);

			vector[0] = vector[1] = vector[2] = vector[3] = 0;

			IN_CASE_CHECK_END(value == VALUE);
		}
	));

	return true;
}

bool SerializationTest::be64()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be64 serialize"
		, [&]
		{
			auto serializerBe = SerializerBe(&vector[0]);
			serializerBe(VALUE);
			IN_CASE_CHECK_END(vector[0] == BYTES[0]
					&& vector[1] == BYTES[1]
					&& vector[2] == BYTES[2]
					&& vector[3] == BYTES[3]
					&& vector[4] == BYTES[4]
					&& vector[5] == BYTES[5]
					&& vector[6] == BYTES[6]
					&& vector[7] == BYTES[7]);
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be64 deserialize"
		, [&]
		{
			Types::ulong_t value;
			auto deserializerBe = DeserializerBe(&vector[0]);
			deserializerBe(value);

			vector[0] = vector[1] = vector[2] = vector[3]
					= vector[4] = vector[5] = vector[6] = vector[7] = 0;

			IN_CASE_CHECK_END(value == VALUE);
		}
	));


	return true;
}

// LITTLE_ENDIAN_ORDER spetialized

SerializationTest::ResultType SerializationTest::leSpec()
{
	IN_CASE_CHECK(leSpec32());
	IN_CASE_CHECK_END(leSpec64());
}

bool SerializationTest::leSpec32()
{
	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	CHECK_RESULT_SUCCESS(doTestCase(
		"le32 spec (LE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue32Le = templates::makeSpecializedValueLe(VALUE, 3, 1);
			auto resultValue32Le = templates::makeSpecializedValueEmptyLe<Types::uint_t>(3, 1);

			auto serializer = templates::SerializerLe(&vector[0]);
			serializer(specValue32Le);
			IN_CASE_CHECK(vector[0] == BYTES[3]
					&& vector[1] == BYTES[2]
					&& vector[2] == BYTES[1]);

			auto deserializer = templates::DeserializerLe(&vector[0]);
			deserializer(resultValue32Le);

			auto range1 = templates::makeRange(specValue32Le.begin(), specValue32Le.end());
			auto range2 = templates::makeRange(resultValue32Le.begin(), resultValue32Le.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"le32 spec (BE numbers) serialize/deserialize"
		, [&]()
	{
		auto specValue32Be = templates::makeSpecializedValueBe(VALUE, 3, 1);
		auto resultValue32Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(3, 1);

		auto serializer = templates::SerializerLe(&vector[0]);
		serializer(specValue32Be);
		IN_CASE_CHECK(vector[0] == BYTES[3]
				&& vector[1] == BYTES[2]
				&& vector[2] == BYTES[1]);

		auto deserializer = templates::DeserializerLe(&vector[0]);
		deserializer(resultValue32Be);

		auto range1 = templates::makeRange(specValue32Be.begin(), specValue32Be.end());
		auto range2 = templates::makeRange(resultValue32Be.begin(), resultValue32Be.end());
		IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
	}
	));

	return true;
}

bool SerializationTest::leSpec64()
{
	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	CHECK_RESULT_SUCCESS(doTestCase(
		"le64 spec (LE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue64Le = templates::makeSpecializedValueLe(VALUE, 5, 2);
			auto resultValue64Le = templates::makeSpecializedValueEmptyLe<Types::ulong_t>(5, 2);

			auto serializer = templates::SerializerLe(&vector[0]);
			serializer(specValue64Le);
			IN_CASE_CHECK(vector[0] == BYTES[6]
					&& vector[1] == BYTES[5]
					&& vector[2] == BYTES[4]
					&& vector[3] == BYTES[3]
					&& vector[4] == BYTES[2]);

			auto deserializer = templates::DeserializerLe(&vector[0]);
			deserializer(resultValue64Le);

			auto range1 = templates::makeRange(specValue64Le.begin(), specValue64Le.end());
			auto range2 = templates::makeRange(resultValue64Le.begin(), resultValue64Le.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"le64 spec (BE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue64Be = templates::makeSpecializedValueBe(VALUE, 5, 2);
			auto resultValue64Be = templates::makeSpecializedValueEmptyBe<Types::ulong_t>(5, 2);

			auto serializer = templates::SerializerLe(&vector[0]);
			serializer(specValue64Be);
			IN_CASE_CHECK(vector[0] == BYTES[6]
					&& vector[1] == BYTES[5]
					&& vector[2] == BYTES[4]
					&& vector[3] == BYTES[3]
					&& vector[4] == BYTES[2]);

			auto deserializer = templates::DeserializerLe(&vector[0]);
			deserializer(resultValue64Be);

			auto range1 = templates::makeRange(specValue64Be.begin(), specValue64Be.end());
			auto range2 = templates::makeRange(resultValue64Be.begin(), resultValue64Be.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	return true;
}

// BIG_ENDIAN_ORDER spetialized

SerializationTest::ResultType SerializationTest::beSpec()
{
	IN_CASE_CHECK(beSpec32());
	IN_CASE_CHECK_END(beSpec64());
}

bool SerializationTest::beSpec32()
{
	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	CHECK_RESULT_SUCCESS(doTestCase(
		"be32 spec (LE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue32Le = templates::makeSpecializedValueLe(VALUE, 3, 1);
			auto resultValue32Le = templates::makeSpecializedValueEmptyLe<Types::uint_t>(3, 1);

			auto serializer = templates::SerializerBe(&vector[0]);
			serializer(specValue32Le);
			IN_CASE_CHECK(vector[0] == BYTES[1]
					&& vector[1] == BYTES[2]
					&& vector[2] == BYTES[3]);

			auto deserializer = templates::DeserializerBe(&vector[0]);
			deserializer(resultValue32Le);

			auto range1 = templates::makeRange(specValue32Le.begin(), specValue32Le.end());
			auto range2 = templates::makeRange(resultValue32Le.begin(), resultValue32Le.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be32 spec (BE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue32Be = templates::makeSpecializedValueBe(VALUE, 3, 1);
			auto resultValue32Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(3, 1);

			auto serializer = templates::SerializerBe(&vector[0]);
			serializer(specValue32Be);
			IN_CASE_CHECK(vector[0] == BYTES[1]
					|| vector[1] == BYTES[2]
					|| vector[2] == BYTES[3]);

			auto deserializer = templates::DeserializerBe(&vector[0]);
			deserializer(resultValue32Be);

			auto range1 = templates::makeRange(specValue32Be.begin(), specValue32Be.end());
			auto range2 = templates::makeRange(resultValue32Be.begin(), resultValue32Be.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	return true;
}

bool SerializationTest::beSpec64()
{
	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	CHECK_RESULT_SUCCESS(doTestCase(
		"be64 spec (LE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue64Le = templates::makeSpecializedValueLe(VALUE, 5, 2);
			auto resultValue64Le = templates::makeSpecializedValueEmptyLe<Types::ulong_t>(5, 2);

			auto serializer = templates::SerializerBe(&vector[0]);
			serializer(specValue64Le);

			IN_CASE_CHECK(vector[0] == BYTES[2]
					&& vector[1] == BYTES[3]
					&& vector[2] == BYTES[4]
					&& vector[3] == BYTES[5]
					&& vector[4] == BYTES[6]);

			auto deserializer = templates::DeserializerBe(&vector[0]);
			deserializer(resultValue64Le);

			auto range1 = templates::makeRange(specValue64Le.begin(), specValue64Le.end());
			auto range2 = templates::makeRange(resultValue64Le.begin(), resultValue64Le.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	CHECK_RESULT_SUCCESS(doTestCase(
		"be64 spec (BE numbers) serialize/deserialize"
		, [&]()
		{
			auto specValue64Be = templates::makeSpecializedValueBe(VALUE, 5, 2);
			auto resultValue64Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(5, 2);

			auto serializer = templates::SerializerBe(&vector[0]);
			serializer(specValue64Be);

			IN_CASE_CHECK(vector[0] == BYTES[2]
					&& vector[1] == BYTES[3]
					&& vector[2] == BYTES[4]
					&& vector[3] == BYTES[5]
					&& vector[4] == BYTES[6]);

			auto deserializer = templates::DeserializerBe(&vector[0]);
			deserializer(resultValue64Be);

			auto range1 = templates::makeRange(specValue64Be.begin(), specValue64Be.end());
			auto range2 = templates::makeRange(resultValue64Be.begin(), resultValue64Be.end());
			IN_CASE_CHECK_END(ResultType::SUCCESS == compareContainers(range1, range2));
		}
	));

	return true;
}

}}
