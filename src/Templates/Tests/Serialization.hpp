#ifndef TEST_SERIALIZATION_HPP
#define TEST_SERIALIZATION_HPP

#include <tests/Test.hpp>

#include <Templates/Traits.hpp>
#include <Templates/Serialization.hpp>

namespace flame_ide
{namespace test
{

class Serialization: public AbstractTest
{
public:
	Serialization() : AbstractTest("Serialization")
	{}
	virtual ~Serialization() = default;

private:
	using Types = templates::Types;
	using SerializerLe = templates::SerializerLe;
	using SerializerBe = templates::SerializerBe;
	using DeserializerLe = templates::DeserializerLe;
	using DeserializerBe = templates::DeserializerBe;

	virtual int vStart();

	bool le();
	bool le16();
	bool le32();
	bool le64();

	bool be();
	bool be16();
	bool be32();
	bool be64();

	bool leSpec();
	bool leSpec32();
	bool leSpec64();

	bool beSpec();
	bool beSpec32();
	bool beSpec64();

	static constexpr Types::uichar_t BYTES[] = {
		0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5, 0x6A, 0x7B
	};
};

}}

#endif // TEST_SERIALIZATION_HPP
