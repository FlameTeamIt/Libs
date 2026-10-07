#include <FlameIDE/../../src/Handler/Tests/Network/Udp/ActualDataTest.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/ActualData.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Config.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Message.hpp>

#include <FlameIDE/Os/Threads/Thread.hpp>
#include <FlameIDE/Templates/Expected.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

using ResultType = ::AbstractTest::ResultType;

//

using TestActualData = ActualData<Message, 3>;
using RealActualData = ActualData<Message, Constants::CLIENT_INPUT_QUEUE_SIZE>;

//

struct MessageIo: MessageWriter, MessageReader
{
	template<Types::size_t TEST_DATA_SIZE>
	MessageIo(const char (&inputTestData)[TEST_DATA_SIZE]) :
			MessageIo(inputTestData, TEST_DATA_SIZE)
	{}

	MessageIo(const char *inputTestData, Types::size_t inputTestDataSize) :
			testData{ inputTestData }
			, testDataSize{ inputTestDataSize }
	{}

	// MessageWriter
	void operator()(MessageData &messageData) const noexcept override
	{
		::flame_ide::copy(
				messageData.bytes.data(), testData, testDataSize
		);
		messageData.size = testDataSize;
	}

	// MessageReader
	virtual void operator()(const MessageData &messageData) noexcept override
	{
		if (messageData.size != static_cast<decltype(messageData.size)>(testDataSize))
			result = decltype(result)::FAILED;

		auto testDataRange = templates::makeRange(
				reinterpret_cast<const byte_t *const>(testData), testDataSize
		);
		auto messageRange = templates::makeRange(
				reinterpret_cast<const byte_t *const>(messageData.bytes.data())
				, messageData.size
		);

		for (auto testDataIt = testDataRange.begin(), messageIt = messageRange.begin();
				testDataIt != testDataRange.end() && messageIt != messageRange.end();
				++testDataIt, ++messageIt
		)
		{
			if (*testDataIt == *messageIt)
				continue;

			result = decltype(result)::FAILED;
			break;
		}
	}

	ResultType result = ResultType::SUCCESS;
	const char *const testData;
	const Types::size_t testDataSize;
};

//

class PingPongBase: public flame_ide::os::threads::ThreadBase
{
public:
	using flame_ide::os::threads::ThreadBase::ThreadBase;

	struct ErrorData
	{
		const char string[128];
		const Types::size_t iteratrion;
		const Types::size_t actualDataSize;
	};

	PingPongBase(
			SizeTraits::SizeType amountOfIterations
			, SizeTraits::SizeType amountOfTries
			, RealActualData &sharedActualData
			, MessageIo &messageIo
	) noexcept :
			flame_ide::os::threads::ThreadBase()
			, internalActualData{ sharedActualData }
			, internalIterations{ amountOfIterations }
			, internalTries{ amountOfTries }
			, internalMessageIo{ messageIo }
	{}

	const templates::Expected<bool, ErrorData> &result() noexcept
	{
		return internalResult;
	}

protected:
	virtual void ping(SizeTraits::SizeType iteration) noexcept
	{ flame_ide::unused(iteration); };
	virtual void pong(SizeTraits::SizeType iteration) noexcept
	{ flame_ide::unused(iteration); };

	SizeTraits::SizeType amountOfTries() const noexcept
	{
		return internalTries;
	}

	SizeTraits::SizeType amountOfIterations() const noexcept
	{
		return internalIterations;
	}

	RealActualData &actualData() noexcept
	{
		return internalActualData;
	}

	MessageIo &messageIo() noexcept
	{
		return internalMessageIo;
	}

private:
	virtual void vRun() noexcept override
	{
		for (decltype(amountOfIterations()) i = 0; i < amountOfIterations(); ++i)
		{
			ping(i);
			pong(i);

			const auto &result = internalResult;
			result.ifError(
					[&i, this](const auto &)
					{
						i = amountOfIterations();
					}
			);
		}
	}

protected:
	templates::Expected<bool, ErrorData> internalResult;

private:
	RealActualData &internalActualData;
	const SizeTraits::SizeType internalIterations = 0;
	const SizeTraits::SizeType internalTries = 0;
	MessageIo &internalMessageIo;
};

struct Ping: public PingPongBase
{
	using PingPongBase::PingPongBase;

private:
	virtual void ping(SizeTraits::SizeType iteration) noexcept override
	{
		std::cout << "Ping: " << iteration << std::endl;
		// заполняем пустое сообщение

		RemoveAllType<decltype(actualData().getEmptyMessage())> messageRef{ nullptr };
		// decltype(amountOfTries()) tries = {};
		Types::size_t amountOfMessages = {};
		while (!messageRef /*&& tries < amountOfTries()*/)
		{
			amountOfMessages = actualData().amountOfMessages();
			if (amountOfMessages < actualData().CAPACITY)
			{
				messageRef = actualData().getEmptyMessage();
			}
			// ++tries;
		}

		if (!messageRef)
		{
			internalResult = ErrorData{
					"Ping thread: Can't get empty message"
					, iteration
					, amountOfMessages
			};
			return;
		}

		messageRef->onWrite(messageIo());

		internalResult = true;
	}
};

struct Pong: public PingPongBase
{
	using PingPongBase::PingPongBase;

private:
	virtual void pong(SizeTraits::SizeType iteration) noexcept override
	{
		//std::cout << "Pong: " << iteration << std::endl;
		// читаем заполненное сообщение

		RemoveAllType<decltype(actualData().getFilledMessage())> messageRef{ nullptr };
		// decltype(amountOfTries()) tries = {};
		Types::size_t amountOfMessages = {};
		while (!messageRef /*&& tries < amountOfTries()*/)
		{
			amountOfMessages = actualData().amountOfMessages();
			if (amountOfMessages)
			{
				messageRef = actualData().getFilledMessage();
			}
			// ++tries;
		}

		if (!messageRef)
		{
			internalResult = ErrorData{
					"Pong thread: Can't get filled message"
					, iteration
					, amountOfMessages
			};
			return;
		}

		messageRef->onRead(messageIo());
		if (messageIo().result == ResultType::FAILED)
		{
			internalResult = ErrorData{
					"Pong thread: Invalid message read"
					, iteration
					, amountOfMessages
			};
			return;
		}
	}
};

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
	using TestDataTraits = decltype(makeArrayTraits(TEST_DATA));

	TestActualData actualData;
	// Fill message
	{
		struct Writer: MessageWriter
		{
			Writer(TestDataTraits::ConstReference inputTestData) :
					testData{ inputTestData }
			{}

			void operator()(MessageData &messageData) const noexcept override
			{
				::flame_ide::copy(
						messageData.bytes.data(), testData, TestDataTraits::SIZE
				);
				messageData.size = TestDataTraits::SIZE;
			}

			TestDataTraits::ConstReference testData;
		} writer{ TEST_DATA };

		flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
		emptyMessage->onWrite(writer);
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

	const char *TEST_DATA[] = {
		TEST_DATA0, TEST_DATA1, TEST_DATA2
	};
	static_assert(
			flame_ide::size(TEST_DATA) == TestActualData::Messages::CAPACITY
			, "Invalid size"
	);

	TestActualData actualData;
	// Fill messages
	{
		for (auto i = flame_ide::size(TEST_DATA); i != 0; --i)
		{
			auto writer = MessageIo{ TEST_DATA[i - 1], TEST_DATA_SIZE };
			flame_ide::ReferenceWrapper<Message> emptyMessage = actualData.getEmptyMessage();
			emptyMessage->onWrite(writer);
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
		auto writer = MessageIo{ TEST_DATA0 };
		emptyMessage->onWrite(writer);
		emptyMessage->state = MessageState::READY;

		IN_CASE_CHECK(EXPECTED_SIZE == actualData.getFilledMessageSize());
	}

	return ResultType::SUCCESS;
}

static ::AbstractTest::ResultType pingPong()
{
	// TODO: Два потока: читающий и пишущий; нужна консистентность на множестве циклов

	using ResultType = ::AbstractTest::ResultType;
	constexpr auto AMOUNT_OF_ITERATIONS = (SizeTraits::SizeType{1} << 16) - 1u;
	constexpr auto AMOUNT_OF_TRIES = (SizeTraits::SizeType{1} << 10) - 1u;

	const char TEST_DATA[] = "some ping & pong test data";
	MessageIo messageIo{ TEST_DATA };

	RealActualData actualData;
	Ping ping{ AMOUNT_OF_ITERATIONS, AMOUNT_OF_TRIES, actualData, messageIo };
	Pong pong{ AMOUNT_OF_ITERATIONS, AMOUNT_OF_TRIES, actualData, messageIo };

	ping.run();
	pong.run();

	ping.join();
	pong.join();

	auto pingResult = ResultType::SUCCESS;
	ping.result().ifResult(
			[](auto) {}
	).ifError(
			[&pingResult](const Ping::ErrorData &internalErrorData)
			{
				pingResult = ResultType::FAILED;
				std::cout << "Error: " << internalErrorData.string
						<< "; iteration = " << internalErrorData.iteratrion
						<< "; amount of messages = " << internalErrorData.actualDataSize
						<< std::endl;
			}
	).done();

	auto pongResult = ResultType::SUCCESS;
	pong.result().ifResult(
			[](auto) {}
	).ifError(
			[&pongResult](const Pong::ErrorData &internalErrorData)
			{
				pongResult = ResultType::FAILED;
				std::cout << "Error: " << internalErrorData.string
						<< "; iteration = " << internalErrorData.iteratrion
						<< "; amount of messages = " << internalErrorData.actualDataSize
						<< std::endl;
			}
	).done();

	IN_CASE_CHECK(
			pingResult == ResultType::SUCCESS && pongResult == ResultType::SUCCESS
	);

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
