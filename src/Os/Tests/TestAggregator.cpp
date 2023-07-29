#include <FlameIDE/../../src/Os/Tests/TestAggregator.hpp>

#include <FlameIDE/../../src/Os/Tests/LibraryTest.hpp>

#include <FlameIDE/../../src/Os/Tests/Network/Ipv4Test.hpp>
#include <FlameIDE/../../src/Os/Tests/Network/UdpFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Network/UdpTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Network/TcpFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Network/TcpTest.hpp>

#include <FlameIDE/../../src/Os/Tests/Network/HandlerTest.hpp>

#include <FlameIDE/../../src/Os/Tests/Threads/MutexFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/MutexTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/SemaphoreFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/SemaphoreTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/SpinFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/SpinTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/ThreadFunctionsTest.hpp>
#include <FlameIDE/../../src/Os/Tests/Threads/ThreadTest.hpp>

namespace flame_ide
{namespace os
{namespace tests
{

TestAggregator::TestAggregator() : ::TestAggregator("Os")
{
	pushBackTest(std::make_shared<LibraryTest>());

	pushBackTest(std::make_shared<network::tests::Ipv4Test>());
	pushBackTest(std::make_shared<network::tests::UdpFunctionsTest>());
	pushBackTest(std::make_shared<network::tests::UdpTest>());
	pushBackTest(std::make_shared<network::tests::TcpFunctionsTest>());
	pushBackTest(std::make_shared<network::tests::TcpTest>());
	pushBackTest(std::make_shared<network::tests::HandlerTest>());

	pushBackTest(std::make_shared<threads::tests::MutexFunctionsTest>());
	pushBackTest(std::make_shared<threads::tests::MutexTest>());
	pushBackTest(std::make_shared<threads::tests::SemaphoreFunctionsTest>());
	pushBackTest(std::make_shared<threads::tests::SemaphoreTest>());
	pushBackTest(std::make_shared<threads::tests::SpinFunctionsTest>());
	pushBackTest(std::make_shared<threads::tests::SpinTest>());
	pushBackTest(std::make_shared<threads::tests::ThreadFunctionsTest>());
	pushBackTest(std::make_shared<threads::tests::ThreadTest>());
}

}}} // namespace flame_ide::os::tests
