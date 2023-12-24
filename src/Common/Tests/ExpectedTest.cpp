#include <FlameIDE/../../src/Common/Tests/ExpectedTest.hpp>

#include <FlameIDE/Common/Expected.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <FlameIDE/Templates/Pointers.hpp>

namespace flame_ide
{namespace common
{namespace tests
{

template<typename ValueType>
class TestClass
{
public:
	using Me = TestClass<ValueType>;

public:
	TestClass() noexcept = default;
	TestClass(const TestClass &object) noexcept { operator=(object); }
	TestClass(TestClass &&object) noexcept { operator=(flame_ide::move(object)); }
	TestClass(const ValueType &initValue) noexcept { operator=(initValue); }
	~TestClass() noexcept
	{
		if (value)
			templates::allocator::ObjectAllocator<ValueType>{}.destroy(value);
	}

	Me &operator=(const TestClass &object) noexcept
	{
		if (!object)
			return *this;
		return operator=(*object.value);
	}

	Me &operator=(TestClass &&object) noexcept
	{
		if (!object)
			return *this;

		value = object.value;
		object.value = nullptr;

		return *this;
	}

	Me &operator=(const ValueType &initValue) noexcept
	{
		if (!value)
			value = templates::allocator::ObjectAllocator<ValueType>{}.construct();
		*value = initValue;
		return *this;
	}

	Me &operator=(ValueType &&initValue) noexcept
	{
		if (!value)
			value = templates::allocator::ObjectAllocator<ValueType>{}.construct();
		*value = flame_ide::move(initValue);
		return *this;
	}

	bool operator==(const Me &object) const noexcept
	{
		if (operator bool() && object.operator bool())
			return *value == *object.value;
		return false;
	}

	operator bool() const noexcept
	{
		return value;
	}

private:
	ValueType *value = nullptr;
};

}}}

namespace flame_ide
{namespace common
{namespace tests
{

using ExpectedPrimitive = Expected<Types::size_t, int>;
using ExpectedNonPrimitive = Expected<TestClass<Types::size_t>, int>;

ExpectedTest::ExpectedTest() noexcept : ::AbstractTest("Expected")
{}

ExpectedTest::~ExpectedTest() noexcept = default;

// private

int ExpectedTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get data without value"
			, [this] { return noValue(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get copied value of primitive error"
			, [this] { return errorPrimitiveCopy(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get copied value of primitive result"
			, [this] { return resultPrimitiveCopy(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get moved value of primitive error"
			, [this] { return errorPrimitiveMove(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get moved value of primitive result"
			, [this] { return resultPrimitiveMove(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get copied value of non-primitive error"
			, [this] { return errorNonPrimitiveCopy(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get copied value of non-primitive result" // crash
			, [this] { return resultNonPrimitiveCopy(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get moved value of non-primitive error"
			, [this] { return errorNonPrimitiveMove(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Set/get moved value of non-primitive result" // crash
			, [this] { return resultNonPrimitiveMove(); }
	));

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::noValue() noexcept
{
	bool resultExists = false;
	bool errorExists = false;

	ExpectedPrimitive primitive;
	primitive.ifResult([&resultExists](auto &&)
			{
				resultExists = true;
			}).ifError([&errorExists](auto &&)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == false);

	ExpectedNonPrimitive nonPrimitive;
	nonPrimitive.ifResult([&resultExists](auto &&)
			{
				resultExists = true;
			}).ifError([&errorExists](auto &&)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == false);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::errorPrimitiveCopy() noexcept
{
	const ExpectedPrimitive::Error expectedErrorValue = -15;

	ExpectedPrimitive expected = decltype(expected)::Error{ expectedErrorValue };
	DefaultTraits<decltype(expected)>::ConstReference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists](auto &)
			{
				resultExists = true;
			}).ifError([&errorExists, &expectedErrorValue](auto &errorValue)
					{
						if (expectedErrorValue == errorValue)
							errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == true);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::resultPrimitiveCopy() noexcept
{
	const ExpectedPrimitive::Result expectedResultValue{ 100500 };

	ExpectedPrimitive expected = decltype(expected)::Result{ expectedResultValue };
	DefaultTraits<ExpectedPrimitive>::ConstReference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists, &expectedResultValue](auto &resultValue)
			{
				if (expectedResultValue == resultValue)
					resultExists = true;
			}).ifError([&errorExists](auto &)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == true);
	IN_CASE_CHECK(errorExists == false);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::errorPrimitiveMove() noexcept
{
	const ExpectedPrimitive::Error expectedErrorValue = -15;

	ExpectedPrimitive expected = decltype(expected)::Error{ expectedErrorValue };
	DefaultTraits<decltype(expected)>::Reference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists](auto &&)
			{
				resultExists = true;
			}).ifError([&errorExists, &expectedErrorValue](auto &&errorValue)
					{
						if (expectedErrorValue == errorValue)
							errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == true);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::resultPrimitiveMove() noexcept
{
	const ExpectedPrimitive::Result expectedResultValue{ 100500 };

	ExpectedPrimitive expected = decltype(expected)::Result{ expectedResultValue };
	DefaultTraits<decltype(expected)>::Reference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists, &expectedResultValue](auto &&resultValue)
			{
				if (expectedResultValue == resultValue)
					resultExists = true;
			}).ifError([&errorExists](auto &&)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == true);
	IN_CASE_CHECK(errorExists == false);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::errorNonPrimitiveCopy() noexcept
{
	const ExpectedNonPrimitive::Error expectedErrorValue = -15;

	ExpectedNonPrimitive expected = decltype(expected)::Error{ expectedErrorValue };
	DefaultTraits<decltype(expected)>::ConstReference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists](auto &)
			{
				resultExists = true;
			}).ifError([&errorExists, &expectedErrorValue](auto &errorValue)
					{
						if (expectedErrorValue == errorValue)
							errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == true);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::resultNonPrimitiveCopy() noexcept
{
	const ExpectedNonPrimitive::Result expectedResultValue = 100500;

	ExpectedNonPrimitive expected = expectedResultValue;
	DefaultTraits<decltype(expected)>::ConstReference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists, &expectedResultValue](const auto &resultValue)
			{
				if (expectedResultValue == resultValue)
					resultExists = true;
			}).ifError([&errorExists](const auto &)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == true);
	IN_CASE_CHECK(errorExists == false);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::errorNonPrimitiveMove() noexcept
{
	const ExpectedNonPrimitive::Error expectedErrorValue = -15;

	ExpectedNonPrimitive expected = decltype(expected)::Error{ expectedErrorValue };
	DefaultTraits<decltype(expected)>::Reference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists](auto &&)
			{
				resultExists = true;
			}).ifError([&errorExists, &expectedErrorValue](auto &&errorValue)
					{
						if (expectedErrorValue == errorValue)
							errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == false);
	IN_CASE_CHECK(errorExists == true);

	return ::AbstractTest::ResultType::SUCCESS;
}

int ExpectedTest::resultNonPrimitiveMove() noexcept
{
	const ExpectedNonPrimitive::Result expectedResultValue = 100500;

	ExpectedNonPrimitive expected = expectedResultValue;
	DefaultTraits<decltype(expected)>::Reference reference = expected;
	bool resultExists = false;
	bool errorExists = false;
	reference.ifResult([&resultExists, &expectedResultValue](auto &&resultValue)
			{
				if (expectedResultValue == resultValue)
					resultExists = true;
				auto value = flame_ide::move(resultValue);
			}).ifError([&errorExists](auto &&)
					{
						errorExists = true;
					}).done();
	IN_CASE_CHECK(resultExists == true);
	IN_CASE_CHECK(errorExists == false);

	return ::AbstractTest::ResultType::SUCCESS;
}

}}} // namespace flame_ide::common::tests

