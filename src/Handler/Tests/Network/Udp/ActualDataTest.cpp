#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ActualDataTest.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/ActualData.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

#include <FlameIDE/Os/Threads/Thread.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

using ResultType = ::AbstractTest::ResultType;

//

using TestActualData = ActualData<Message, 3>;

//

static ::AbstractTest::ResultType init()
{
	TestActualData actualData;
	::flame_ide::unused(actualData);

	return ResultType::SUCCESS;
}

// getEmptyMessage() test cases

static ::AbstractTest::ResultType getEmptyMessage_One()
{
	TestActualData actualData;

	flame_ide::ReferenceWrapper<Message> emptyOneMessage = actualData.getEmptyMessage();
	IN_CASE_CHECK(emptyOneMessage.operator->() != nullptr);
	IN_CASE_CHECK(emptyOneMessage->spin.tryLock() == true);
	IN_CASE_CHECK(emptyOneMessage->state == MessageState::PROCESSING);
	IN_CASE_CHECK(emptyOneMessage->size == 0);

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType getEmptyMessage_All()
{
	TestActualData actualData;

	flame_ide::ReferenceWrapper<Message> firstEmptyMessage = actualData.getEmptyMessage();
	flame_ide::unused(firstEmptyMessage);

	for (
			RemoveAllTrait<decltype(TestActualData::Messages::CAPACITY)>::Type i = 1;
			i < TestActualData::Messages::CAPACITY;
			++i
	)
	{
		flame_ide::ReferenceWrapper<Message> nextEmptyMessage
				= actualData.getEmptyMessage();
		IN_CASE_CHECK(nextEmptyMessage.operator->() != nullptr);
		IN_CASE_CHECK(nextEmptyMessage->spin.tryLock() == true);
		IN_CASE_CHECK(nextEmptyMessage->state == MessageState::PROCESSING);
		IN_CASE_CHECK(nextEmptyMessage->size == 0);
	}

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType getEmptyMessage_AllOne()
{
	TestActualData actualData;
	for (
			RemoveAllTrait<decltype(TestActualData::Messages::CAPACITY)>::Type i = 0;
			i < TestActualData::Messages::CAPACITY;
			++i
	)
	{
		flame_ide::ReferenceWrapper<Message> emptyMessage
				= actualData.getEmptyMessage();
		flame_ide::unused(emptyMessage);
	}

	flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
	IN_CASE_CHECK(emptyMessage.operator->() == nullptr);

	return ResultType::SUCCESS;
}

// getFilledMessage()

static ::AbstractTest::ResultType getFilledMessage_NoMessages()
{
	using ResultType = ::AbstractTest::ResultType;

	TestActualData actualData;
	flame_ide::ReferenceWrapper<Message> filledMessage = actualData.getFilledMessage();
	IN_CASE_CHECK(filledMessage.operator->() == nullptr);

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType getFilledMessage_OneMessage()
{
	using ResultType = ::AbstractTest::ResultType;

	const char TEST_DATA[] = "some test data";

	TestActualData actualData;
	// Fill message
	{

		flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
		emptyMessage->write(TEST_DATA, sizeof(TEST_DATA));
		flame_ide::unused(emptyMessage);
	}
	flame_ide::ReferenceWrapper<Message> filledMessage = actualData.getFilledMessage();
	IN_CASE_CHECK(filledMessage.operator->() != nullptr);
	IN_CASE_CHECK(filledMessage->size == sizeof(TEST_DATA));
	IN_CASE_CHECK(filledMessage->state == MessageState::PROCESSING);
	IN_CASE_CHECK(filledMessage->spin.tryLock());

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType getFilledMessage_AllMessages()
{
	using ResultType = ::AbstractTest::ResultType;

	const char TEST_DATA0[] = "some test data 0";
	const char TEST_DATA1[] = "some test data 1";
	const char TEST_DATA2[] = "some test data 2";
	constexpr flame_ide::SizeTraits::SizeType TEST_DATA_SIZE = size(TEST_DATA0);

	const char *const TEST_DATA[] = { TEST_DATA0, TEST_DATA1, TEST_DATA2 };
	static_assert(
			flame_ide::size(TEST_DATA) == TestActualData::Messages::CAPACITY
			, "Invalid size"
	);

	TestActualData actualData;
	// Fill messages
	{
		for (auto i = flame_ide::size(TEST_DATA); i != 0; --i)
		{
			flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
			emptyMessage->write(TEST_DATA[i - 1], TEST_DATA_SIZE);
			flame_ide::unused(emptyMessage);
		}
	}

	for (
			RemoveAllTrait<decltype(TestActualData::Messages::CAPACITY)>::Type i = 0;
			i < TestActualData::Messages::CAPACITY;
			++i
	)
	{
		flame_ide::ReferenceWrapper<Message> filledMessage = actualData.getFilledMessage();
		IN_CASE_CHECK(filledMessage.operator->() != nullptr);
		IN_CASE_CHECK(filledMessage->size == TEST_DATA_SIZE);
		IN_CASE_CHECK(filledMessage->state == MessageState::PROCESSING);
		IN_CASE_CHECK(filledMessage->spin.tryLock());
	}

	return ResultType::SUCCESS;
}


// getFilledMessageSize()

static ::AbstractTest::ResultType getFilledMessageSize()
{
	using ResultType = ::AbstractTest::ResultType;

	TestActualData actualData;
	// no messages
	{
		constexpr SizeTraits::SizeType EXPECTED_SIZE = 0;
		IN_CASE_CHECK(EXPECTED_SIZE == actualData.getFilledMessageSize());
	}
	// 1 message
	{
		const char TEST_DATA0[] = "some test data 0";
		constexpr SizeTraits::SizeType EXPECTED_SIZE = flame_ide::size(TEST_DATA0);

		flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
		emptyMessage->write(TEST_DATA0, flame_ide::size(TEST_DATA0));
		emptyMessage->state = MessageState::READY;

		IN_CASE_CHECK(EXPECTED_SIZE == actualData.getFilledMessageSize());
	}

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType pingPong()
{
	// TODO: Два потока: читающий и пишущий; нужна консистентность на множестве циклов

	using ResultType = ::AbstractTest::ResultType;

	TestActualData actualData;
	::flame_ide::unused(actualData);

	return ResultType::SUCCESS;
}

//

ActualDataTest::ActualDataTest() : ::AbstractTest("udp::ActualData")
{}

ActualDataTest::~ActualDataTest() = default;

int ActualDataTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"Initialization"
			, []() { return init(); }
	));

	// udp::ActualData::getEmptyMessage()
	CHECK_RESULT_SUCCESS(doTestCase(
			"getEmptyMessage(): get one message"
			, []() { return getEmptyMessage_One(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"getEmptyMessage(): get all messages"
			, []() { return getEmptyMessage_All(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"getEmptyMessage(): get all messages and one"
			, []() { return getEmptyMessage_AllOne(); }
	));

	// udp::ActualData::getFilledMessage()
	CHECK_RESULT_SUCCESS(doTestCase(
			"getFilledMessage(): no messages"
			, []() { return getFilledMessage_NoMessages(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"getFilledMessage(): get one message"
			, []() { return getFilledMessage_OneMessage(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"getFilledMessage(): get all filled messages"
			, []() { return getFilledMessage_AllMessages(); }
	));

	CHECK_RESULT_SUCCESS(doTestCase(
			"getFilledMessageSize()"
			, []() { return getFilledMessageSize(); }
	));

	//
	CHECK_RESULT_SUCCESS(doTestCase(
			"Multithread ping & pong"
			, []() { return pingPong(); }
	));
	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
