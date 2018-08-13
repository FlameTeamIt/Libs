#include "Serialization.hpp"

#include <Templates/Vector.hpp>

namespace flame_ide
{namespace test
{

using templates::CompileTimeReverseBytes;

int Serialization::vStart()
{
	if(!le() || !be() || !leSpec() || !beSpec())
	{
		return -1;
	}

	return 0;
}

// LITTLE_ENDIAN

bool Serialization::le()
{
	return le16() && le32() && le64();
}

bool Serialization::le16()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ushort_t VALUE = (Types::ushort_t(BYTES[0]) << 8)
			| Types::ushort_t(BYTES[1]);

	auto serializerLe = SerializerLe(&vector[0]);
	serializerLe(VALUE);
	if (vector[0] != BYTES[1] || vector[1] != BYTES[0])
	{
		log << std::hex << int(vector[0]) << ' ' << int(vector[1]) << std::endl;
		return false;
	}

	Types::ushort_t value16;
	auto deserializerLe = DeserializerLe(&vector[0]);
	deserializerLe(value16);
	if (value16 != VALUE)
	{
		log << std::hex << value16 << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = 0;

	return true;
}

bool Serialization::le32()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	auto serializerLe = SerializerLe(&vector[0]);
	serializerLe(VALUE);
	if (vector[0] != BYTES[3] || vector[1] != BYTES[2]
			|| vector[2] != BYTES[1] || vector[3] != BYTES[0])
	{
		log << std::hex
				<< int(vector[0]) << ' ' << int(vector[1]) << ' '
				<< int(vector[2]) << ' ' << int(vector[3]) << std::endl;
		return false;
	}

	Types::uint_t value;
	auto deserializerLe = DeserializerLe(&vector[0]);
	deserializerLe(value);
	if (value != VALUE)
	{
		log << std::hex << value << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = vector[2] = vector[3] = 0;

	return true;
}

bool Serialization::le64()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	auto serializerLe = SerializerLe(&vector[0]);
	serializerLe(VALUE);
	if (vector[0] != BYTES[7] || vector[1] != BYTES[6]
			|| vector[2] != BYTES[5] || vector[3] != BYTES[4]
			|| vector[4] != BYTES[3] || vector[5] != BYTES[2]
			|| vector[6] != BYTES[1] || vector[7] != BYTES[0])
	{
		log << std::hex
				<< int(vector[0]) << ' ' << int(vector[1]) << ' '
				<< int(vector[2]) << ' ' << int(vector[3]) << ' '
				<< int(vector[4]) << ' ' << int(vector[5]) << ' '
				<< int(vector[6]) << ' ' << int(vector[7]) << std::endl;
		return false;
	}

	Types::ulong_t value;
	auto deserializerLe = DeserializerLe(&vector[0]);
	deserializerLe(value);
	if (value != VALUE)
	{
		log << std::hex << value << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = vector[2] = vector[3]
			= vector[4] = vector[5] = vector[6] = vector[7] = 0;

	return true;
}

// BIG_ENDIAN

bool Serialization::be()
{
	return be16() && be32() && be64();
}

bool Serialization::be16()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ushort_t VALUE = (Types::ushort_t(BYTES[0]) << 8)
			| Types::ushort_t(BYTES[1]);

	auto serializerBe = SerializerBe(&vector[0]);
	serializerBe(VALUE);
	if (vector[0] != BYTES[0] || vector[1] != BYTES[1])
	{
		log << std::hex << int(vector[0]) << ' ' << int(vector[1]) << std::endl;
		return false;
	}

	Types::ushort_t value16;
	auto deserializerBe = DeserializerBe(&vector[0]);
	deserializerBe(value16);
	if (value16 != VALUE)
	{
		log << std::hex << value16 << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = 0;

	return true;
}

bool Serialization::be32()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	auto serializerBe = SerializerBe(&vector[0]);
	serializerBe(VALUE);
	if (vector[0] != BYTES[0] || vector[1] != BYTES[1]
			|| vector[2] != BYTES[2] || vector[3] != BYTES[3])
	{
		log << std::hex
				<< int(vector[0]) << ' ' << int(vector[1]) << ' '
				<< int(vector[2]) << ' ' << int(vector[3]) << std::endl;
		return false;
	}

	Types::uint_t value;
	auto deserializerBe = DeserializerBe(&vector[0]);
	deserializerBe(value);
	if (value != VALUE)
	{
		log << std::hex << value << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = vector[2] = vector[3] = 0;

	return true;
}

bool Serialization::be64()
{
	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	auto serializerBe = SerializerBe(&vector[0]);
	serializerBe(VALUE);
	if (vector[0] != BYTES[0] || vector[1] != BYTES[1]
			|| vector[2] != BYTES[2] || vector[3] != BYTES[3]
			|| vector[4] != BYTES[4] || vector[5] != BYTES[5]
			|| vector[6] != BYTES[6] || vector[7] != BYTES[7])
	{
		log << std::hex
				<< int(vector[0]) << ' ' << int(vector[1]) << ' '
				<< int(vector[2]) << ' ' << int(vector[3]) << ' '
				<< int(vector[4]) << ' ' << int(vector[5]) << ' '
				<< int(vector[6]) << ' ' << int(vector[7]) << std::endl;
		return false;
	}

	Types::ulong_t value;
	auto deserializerBe = DeserializerBe(&vector[0]);
	deserializerBe(value);
	if (value != VALUE)
	{
		log << std::hex << value << ' ' << VALUE << std::endl;
		return false;
	}

	vector[0] = vector[1] = vector[2] = vector[3]
			= vector[4] = vector[5] = vector[6] = vector[7] = 0;

	return true;
}


// LITTLE_ENDIAN spetialized

bool Serialization::leSpec()
{
	return leSpec32() && leSpec64();
}

bool Serialization::leSpec32()
{
	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	templates::Vector<flame_ide::Types::uichar_t> vector(8);


	{
		auto specValue32Le = templates::makeSpecializedValueLe(VALUE, 3, 1);
		auto resultValue32Le = templates::makeSpecializedValueEmptyLe<Types::uint_t>(3, 1);

		auto serializer = templates::SerializerLe(&vector[0]);
		serializer(specValue32Le);
		if (vector[0] != BYTES[3] || vector[1] != BYTES[2]
				|| vector[2] != BYTES[1])
		{
			log << std::hex
					<< int(vector[0]) << ' '
					<< int(vector[1]) << ' '
					<< int(vector[2]) << ' '
					<< std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerLe(&vector[0]);
		deserializer(resultValue32Le);

		using Iterator = decltype(specValue32Le.begin());
		for (Iterator itValue = specValue32Le.begin(), itResult = resultValue32Le.begin();
				itValue != specValue32Le.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
			}
		}
	}

	{
		auto specValue32Be = templates::makeSpecializedValueBe(VALUE, 3, 1);
		auto resultValue32Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(3, 1);

		auto serializer = templates::SerializerLe(&vector[0]);
		serializer(specValue32Be);
		if (vector[0] != BYTES[3] || vector[1] != BYTES[2]
				|| vector[2] != BYTES[1])
		{
			log << std::hex
					<< int(vector[0]) << ' '
					<< int(vector[1]) << ' '
					<< int(vector[2]) << ' '
					<< std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerLe(&vector[0]);
		deserializer(resultValue32Be);

		using Iterator = decltype(specValue32Be.begin());
		for (Iterator itValue = specValue32Be.begin(), itResult = resultValue32Be.begin();
				itValue != specValue32Be.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
			}
		}
	}

	return true;
}

bool Serialization::leSpec64()
{
	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	{
		auto specValue64Le = templates::makeSpecializedValueLe(VALUE, 5, 2);
		auto resultValue64Le = templates::makeSpecializedValueEmptyLe<Types::ulong_t>(5, 2);

		auto serializer = templates::SerializerLe(&vector[0]);
		serializer(specValue64Le);

		if (vector[0] != BYTES[6] && vector[1] != BYTES[5] && vector[2] != BYTES[4]
				&& vector[3] != BYTES[3] && vector[4] != BYTES[2])
		{
			log;
			auto range = templates::makeRange(&vector[0], &vector[5]);
			for (auto i : range)
			{
				std::cout << (int(i) & 0xFF) << ' ';
			}
			std::cout << std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerLe(&vector[0]);
		deserializer(resultValue64Le);

		using Iterator = decltype(specValue64Le.begin());
		for (Iterator itValue = specValue64Le.begin(), itResult = resultValue64Le.begin();
				itValue != specValue64Le.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
				return false;
			}
		}
	}

	{
		auto specValue64Be = templates::makeSpecializedValueBe(VALUE, 5, 2);
		auto resultValue64Be = templates::makeSpecializedValueEmptyBe<Types::ulong_t>(5, 2);

		auto serializer = templates::SerializerLe(&vector[0]);
		serializer(specValue64Be);

		if (vector[0] != BYTES[6] && vector[1] != BYTES[5] && vector[2] != BYTES[4]
				&& vector[3] != BYTES[3] && vector[4] != BYTES[2])
		{
			log;
			auto range = templates::makeRange(&vector[0], &vector[5]);
			for (auto i : range)
			{
				std::cout << (int(i) & 0xFF) << ' ';
			}
			std::cout << std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerLe(&vector[0]);
		deserializer(resultValue64Be);

		using Iterator = decltype(specValue64Be.begin());
		for (Iterator itValue = specValue64Be.begin(), itResult = resultValue64Be.begin();
				itValue != specValue64Be.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
				return false;
			}
		}
	}

	return true;
}

// BIG_ENDIAN spetialized

bool Serialization::beSpec()
{
	return beSpec32() && beSpec64();
}

bool Serialization::beSpec32()
{
	constexpr Types::uint_t VALUE = (Types::uint_t(BYTES[0]) << 24)
			| (Types::uint_t(BYTES[1]) << 16) | (Types::uint_t(BYTES[2]) << 8)
			| Types::uint_t(BYTES[3]);

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	// little-endian serialize/deserialize
	{
		auto specValue32Le = templates::makeSpecializedValueLe(VALUE, 3, 1);
		auto resultValue32Le = templates::makeSpecializedValueEmptyLe<Types::uint_t>(3, 1);

		auto serializer = templates::SerializerBe(&vector[0]);
		serializer(specValue32Le);
		if (vector[0] != BYTES[1]
				|| vector[1] != BYTES[2]
				|| vector[2] != BYTES[3])
		{
			log << std::hex
					<< int(vector[0]) << ' '
					<< int(vector[1]) << ' '
					<< int(vector[2]) << ' '
					<< std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerBe(&vector[0]);
		deserializer(resultValue32Le);

		using Iterator = decltype(specValue32Le.begin());
		for (Iterator itValue = specValue32Le.begin(), itResult = resultValue32Le.begin();
				itValue != specValue32Le.end();
				++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
			}
		}
	}

	// big-endian serialize/deserialize
	{
		auto specValue32Be = templates::makeSpecializedValueBe(VALUE, 3, 1);
		auto resultValue32Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(3, 1);

		auto serializer = templates::SerializerBe(&vector[0]);
		serializer(specValue32Be);
		if (vector[0] != BYTES[1]
				|| vector[1] != BYTES[2]
				|| vector[2] != BYTES[3])
		{
			log << std::hex
					<< int(vector[0]) << ' '
					<< int(vector[1]) << ' '
					<< int(vector[2]) << ' '
					<< std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerBe(&vector[0]);
		deserializer(resultValue32Be);

		using Iterator = decltype(specValue32Be.begin());
		for (Iterator itValue = specValue32Be.begin(), itResult = resultValue32Be.begin();
				itValue != specValue32Be.end();
				++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
			}
		}
	}

	return true;
}

bool Serialization::beSpec64()
{
	constexpr Types::ulong_t VALUE = (Types::ulong_t(BYTES[0]) << 56)
			| (Types::ulong_t(BYTES[1]) << 48) | (Types::ulong_t(BYTES[2]) << 40)
			| (Types::ulong_t(BYTES[3]) << 32) | (Types::ulong_t(BYTES[4]) << 24)
			| (Types::ulong_t(BYTES[5]) << 16) | (Types::ulong_t(BYTES[6]) << 8)
			| (Types::ulong_t(BYTES[7]));

	templates::Vector<flame_ide::Types::uichar_t> vector(8);

	{
		auto specValue64Le = templates::makeSpecializedValueLe(VALUE, 5, 2);
		auto resultValue64Le = templates::makeSpecializedValueEmptyLe<Types::ulong_t>(5, 2);

		auto serializer = templates::SerializerBe(&vector[0]);
		serializer(specValue64Le);

		if (vector[0] != BYTES[2] && vector[1] != BYTES[3] && vector[2] != BYTES[4]
				&& vector[3] != BYTES[5] && vector[4] != BYTES[6])
		{
			log;
			auto range = templates::makeRange(&vector[0], &vector[5]);
			for (auto i : range)
			{
				std::cout << (int(i) & 0xFF) << ' ';
			}
			std::cout << std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerBe(&vector[0]);
		deserializer(resultValue64Le);

		using Iterator = decltype(specValue64Le.begin());
		for (Iterator itValue = specValue64Le.begin(), itResult = resultValue64Le.begin();
				itValue != specValue64Le.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
				return false;
			}
		}
	}

	{
		auto specValue64Be = templates::makeSpecializedValueBe(VALUE, 5, 2);
		auto resultValue64Be = templates::makeSpecializedValueEmptyBe<Types::uint_t>(5, 2);

		auto serializer = templates::SerializerBe(&vector[0]);
		serializer(specValue64Be);

		if (vector[0] != BYTES[2] && vector[1] != BYTES[3] && vector[2] != BYTES[4]
				&& vector[3] != BYTES[5] && vector[4] != BYTES[6])
		{
			log;
			auto range = templates::makeRange(&vector[0], &vector[5]);
			for (auto i : range)
			{
				std::cout << (int(i) & 0xFF) << ' ';
			}
			std::cout << std::endl;
			return false;
		}

		auto deserializer = templates::DeserializerBe(&vector[0]);
		deserializer(resultValue64Be);

		using Iterator = decltype(specValue64Be.begin());
		for (Iterator itValue = specValue64Be.begin(), itResult = resultValue64Be.begin();
				itValue != specValue64Be.end(); ++itValue, ++itResult)
		{
			if (*itValue != *itResult)
			{
				log << "*itValue(" << std::hex << (int(*itValue) & 0xFF)
						<< ") != *itResult(" << (int(*itResult) & 0xFF) << ")"
						<< std::endl;
				return false;
			}
		}
	}

	return true;
}

}}
