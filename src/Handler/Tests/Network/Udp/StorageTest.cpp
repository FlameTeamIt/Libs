#include <FlameIDE/../../src/Handler/Tests/Network/Udp/StorageTest.hpp>
#include <FlameIDE/../../src/Handler/Network/Udp/Storage.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

StorageTest::StorageTest() : ::AbstractTest("udp::Storage")
{}

StorageTest::~StorageTest() = default;

int StorageTest::vStart()
{
	CHECK_RESULT_SUCCESS(doTestCase(
			"initialization"
			, [this]() { return init(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"server push-pop"
			, [this]() { return serverPushPop(); }
	));
	return ResultType::SUCCESS;
}

int StorageTest::init()
{
	udp::Storage storage;
	return ResultType::SUCCESS;
}

int StorageTest::serverPushPop()
{
	udp::Storage storage;
	os::network::UdpServer server{ 65001 };

	const os::Socket expectedSocket = server.native();

	auto handle = storage.push(flame_ide::move(server));
	IN_CASE_CHECK(handle.operator->() != nullptr);

	auto resultServer = storage.pop(handle);
	IN_CASE_CHECK(expectedSocket.descriptor == resultServer.native().descriptor);

	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
