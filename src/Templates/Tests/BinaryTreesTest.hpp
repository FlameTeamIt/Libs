#ifndef FLAMEIDE_TEMPLATES_TESTS_BINARYTREESTEST_HPP
#define FLAMEIDE_TEMPLATES_TESTS_BINARYTREESTEST_HPP

#include <tests/Test.hpp>

namespace flame_ide
{namespace templates
{namespace test
{

class BinaryTreesTest: public AbstractTest
{
public:
	BinaryTreesTest();
	virtual ~BinaryTreesTest();

private:
	virtual int vStart();

private:
	int defaultInitialization();

	int pushCopyInitialization();
	int pushEmplaceInitialization();
};


}}} // namespace flame_ide::templates::test

#endif // FLAMEIDE_TEMPLATES_TESTS_BINARYTREESTEST_HPP
