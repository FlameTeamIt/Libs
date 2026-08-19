#include <FlameIDE/../../src/Handler/Tests/Network/Udp/TypeMappingTest.hpp>

#include <FlameIDE/../../src/Handler/Network/Udp/TypeMapping.hpp>

namespace flame_ide
{namespace handler
{namespace network
{namespace udp
{namespace tests
{

// EndpointTypeMapper

static ::AbstractTest::ResultType serverEndpointTypeMapper() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	IN_CASE_CHECK((
			"Server -> os::network::UdpServer"
			, ComparingTypes<
				os::network::UdpServer
				, EndpointTypeMapper<Server>::Type
			>::VALUE
	));

	IN_CASE_CHECK_END((
			"os::network::UdpServer -> Server"
			, ComparingTypes<
				Server
				, EndpointTypeMapper<os::network::UdpServer>::Type
			>::VALUE
	));
}

static ::AbstractTest::ResultType clientEndpointTypeMapper() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	IN_CASE_CHECK((
			"Client -> os::network::UdpClient"
			, ComparingTypes<
				os::network::UdpClient
				, EndpointTypeMapper<Client>::Type
			>::VALUE
	));
	IN_CASE_CHECK_END((
			"os::network::UdpClient -> Client"
			, ComparingTypes<
				Client
				, EndpointTypeMapper<os::network::UdpClient>::Type
			>::VALUE
	));
}

// HandlerEndpointDataMapper

static ::AbstractTest::ResultType serverHandlerEndpointDataMapper() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	IN_CASE_CHECK((
			"Server -> HandlerEndpointUdpData<Servers>"
			, ComparingTypes<
				HandlerEndpointUdpData<Servers>
				, HandlerEndpointDataMapper<Server>::Type
			>::VALUE
	));
	IN_CASE_CHECK_END((
			"ServerProcessor -> HandlerEndpointUdpData<Servers>"
			, ComparingTypes<
				HandlerEndpointUdpData<Servers>
				, HandlerEndpointDataMapper<ServerProcessor>::Type
			>::VALUE
	));
}

static ::AbstractTest::ResultType clientHandlerEndpointDataMapper() noexcept
{
	using ResultType = ::AbstractTest::ResultType;

	IN_CASE_CHECK((
			"Client -> HandlerEndpointUdpData<Clients>"
			, ComparingTypes<
				HandlerEndpointUdpData<Clients>
				, HandlerEndpointDataMapper<Client>::Type
			>::VALUE
	));
	IN_CASE_CHECK_END((
			"ClientProcessor -> HandlerEndpointUdpData<Clients>"
			, ComparingTypes<
				HandlerEndpointUdpData<Clients>
				, HandlerEndpointDataMapper<ClientProcessor>::Type
			>::VALUE
	));
}

//

TypeMappingTest::TypeMappingTest() : ::AbstractTest("udp::TypeMapping")
{}

TypeMappingTest::~TypeMappingTest() = default;

int TypeMappingTest::vStart()
{
	//
	CHECK_RESULT_SUCCESS(doTestCase(
			"Server <--> os::network::UdpServer"
			, []() { return serverEndpointTypeMapper(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Client <--> os::network::UdpClient"
			, []() { return clientEndpointTypeMapper(); }
	));

	//
	CHECK_RESULT_SUCCESS(doTestCase(
			"Server, ServerProcessor --> HandlerEndpointUdpData<Servers>"
			, []() { return serverHandlerEndpointDataMapper(); }
	));
	CHECK_RESULT_SUCCESS(doTestCase(
			"Client, ClientProcessor --> HandlerEndpointUdpData<Clients>"
			, []() { return clientHandlerEndpointDataMapper(); }
	));

	return ResultType::SUCCESS;
}

}}}}} // namespace flame_ide::handler::network::udp::tests
