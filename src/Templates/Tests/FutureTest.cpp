#include "FutureTest.hpp"

namespace flame_ide
{namespace templates
{namespace test
{

FutureTest::FutureTest() : AbstractTest("Future")
{}

FutureTest::~FutureTest() = default;

int FutureTest::vStart()
{
	return SUCCESS;
}

}}}
