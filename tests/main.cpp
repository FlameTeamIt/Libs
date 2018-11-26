#include <Templates/Tests/TestAggregator.hpp>
#include <Common/Tests/TestAggregator.hpp>

int main()
{
	flame_ide::templates::tests::TestAggregator().start();
	flame_ide::tests::TestAggregator().start();
	return 0;
}
