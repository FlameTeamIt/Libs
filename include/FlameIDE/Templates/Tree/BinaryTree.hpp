#ifndef FLAMEIDE_TEMPLATES_TREE_BINARYTREE_HPP
#define FLAMEIDE_TEMPLATES_TREE_BINARYTREE_HPP

#include <FlameIDE/Templates/Tree/BinaryTreeImpl.hpp>
#include <FlameIDE/Templates/Tree/BinaryTreeIterator.hpp>
#include <FlameIDE/Templates/Tree/TreeStrategy.hpp>

namespace flame_ide
{namespace templates
{namespace tree
{

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
>
using BinaryTree = base::TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator
	, iterator::BinaryTreeIterator
	, impl::BinaryTreeImpl<TreeNode<T>, TreeComparator<T>>
>;

}}} // namespace flame_ide::templates::tree

#endif // FLAMEIDE_TEMPLATES_TREE_BINARYTREE_HPP
