#ifndef FLAMEIDE_TEMPLATES_TREE_BINARYTREEITERATOR_HPP
#define FLAMEIDE_TEMPLATES_TREE_BINARYTREEITERATOR_HPP

#include <FlameIDE/Templates/Iterator/IteratorTraits.hpp>

namespace flame_ide
{namespace templates
{namespace tree
{namespace iterator
{

template<typename T, template<class> class TreeNode, IteratorAccess ACCESS>
class BinaryTreeIterator
{
private:
	using Node = TreeNode<T>;

public:
	using Me = BinaryTreeIterator<T, TreeNode, ACCESS>;

	using Type = typename Node::Type;

	using Reference = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename Node::Reference
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename Node::ConstReference
			, void
		>::Type
	>::Type;
	using ConstReference = typename Node::ConstReference;

	using Pointer = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename Node::Pointer
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename Node::PointerToConst
			, void
		>::Type
	>::Type;
	using PointerToConst = typename Node::PointerToConst;

	using NodePointer = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename DefaultTraits<Node>::Pointer
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename DefaultTraits<Node>::PointerToConst
			, void
		>
	>::Type;

	BinaryTreeIterator() noexcept = default;
	BinaryTreeIterator(const Me &) noexcept = default;
	BinaryTreeIterator(Me &&) noexcept = default;

	BinaryTreeIterator(
			NodePointer currentInit, NodePointer nextInit, NodePointer previousInit
	) noexcept;

	~BinaryTreeIterator() noexcept = default;

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++() noexcept;
	Me &operator--() noexcept;

	Me operator++(int) noexcept;
	Me operator--(int) noexcept;

	Reference operator*() noexcept;
	Pointer operator->() noexcept;

private:
	mutable NodePointer current = nullptr;
	mutable NodePointer next = nullptr;
	mutable NodePointer previous = nullptr;
};

}}}} // namespace flame_ide::templates::tree::iterator

namespace flame_ide
{namespace templates
{namespace tree
{namespace iterator
{

template<typename T, template<class> class Node, IteratorAccess ACCESS>
BinaryTreeIterator<T, Node, ACCESS>::BinaryTreeIterator(
		NodePointer currentInit, NodePointer nextInit, NodePointer previousInit
) noexcept :
		current{ currentInit }, next{ nextInit }, previous{ previousInit }
{}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
BinaryTreeIterator<T, Node, ACCESS> &
BinaryTreeIterator<T, Node, ACCESS>::operator++() noexcept
{
	return *this;
}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
BinaryTreeIterator<T, Node, ACCESS> &
BinaryTreeIterator<T, Node, ACCESS>::operator--() noexcept
{
	return *this;
}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
BinaryTreeIterator<T, Node, ACCESS>
BinaryTreeIterator<T, Node, ACCESS>::operator++(int) noexcept
{
	Me copy = *this;
	++(*this);
	return copy;
}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
BinaryTreeIterator<T, Node, ACCESS>
BinaryTreeIterator<T, Node, ACCESS>::operator--(int) noexcept
{
	Me copy = *this;
	--(*this);
	return copy;
}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
typename BinaryTreeIterator<T, Node, ACCESS>::Reference
BinaryTreeIterator<T, Node, ACCESS>::operator*() noexcept
{
	return current->object;
}

template<typename T, template<class> class Node, IteratorAccess ACCESS>
typename BinaryTreeIterator<T, Node, ACCESS>::Pointer
BinaryTreeIterator<T, Node, ACCESS>::operator->() noexcept
{
	return current->object;
}

}}}} // namespace flame_ide::templates::tree::iterator

#endif // FLAMEIDE_TEMPLATES_TREE_BINARYTREEITERATOR_HPP
