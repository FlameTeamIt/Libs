#ifndef FLAMEIDE_TEMPLATES_BINARYTREES_HPP
#define FLAMEIDE_TEMPLATES_BINARYTREES_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <FlameIDE/Templates/Allocator.hpp>
#include <FlameIDE/Templates/Comparators.hpp>
#include <FlameIDE/Templates/Pair.hpp>

#include <FlameIDE/Templates/Iterator/ConstIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstReverseIterator.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>
#include <FlameIDE/Templates/Iterator/ReverseIterator.hpp>

// Difinition

// Utils
namespace flame_ide
{namespace templates
{namespace tree_utils
{

// Nodes

template<typename T, typename Traits = DefaultTraits<T>>
struct Node
{
	using Me = Node<T, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;

	Node() noexcept = default;
	Node(Me &&node) noexcept = default;
	Node(const Me &node) noexcept = default;

	template<typename ...Args>
	Node(Args &&...args) noexcept;

	~Node() = default;

	Me *left = nullptr;
	Me *right = nullptr;
	Me *previous = nullptr;
	Type object;
};
template<typename T, typename Traits>
inline void update(Node<T, Traits> *node) noexcept { flame_ide::unused(node); }

template<typename T, typename Options, typename Traits = DefaultTraits<T>>
struct CustomNode: public Node<T, Traits>
{
	using Me = CustomNode<T, Options, Traits>;
	using Parent = Node<T, Traits>;

	using typename Parent::Type;
	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	CustomNode() noexcept = default;
	CustomNode(const Me &node) noexcept = default;
	CustomNode(Me &&node) noexcept = default;

	template<typename ...Args>
	CustomNode(Args &&...args) noexcept;

	~CustomNode() = default;

	using Parent::left;
	using Parent::right;
	using Parent::previous;
	using Parent::object;

	Options options;
};

struct AdelsonVelskyLandisOptions
{
	Types::ushort_t height = 0;
};
template<typename T, typename Traits = DefaultTraits<T>>
using AdelsonVelskyLandisNode = CustomNode<T, AdelsonVelskyLandisOptions, Traits>;
template<typename T, typename Traits>
void update(AdelsonVelskyLandisNode<T, Traits> *node) noexcept;

enum class Colour: Types::uichar_t
{
	BLACK = 0
	, RED = 1
};
struct RedBlackOptions
{
	Colour colour = Colour::BLACK;
};
template<typename T, typename Traits = DefaultTraits<T>>
using RedBlackNode = CustomNode<T, RedBlackOptions, Traits>;
template<typename T, typename Traits>
void update(RedBlackNode<T, Traits> *node) noexcept;

// WrappedIterator

template<
	typename T
	, typename TreeNode = Node<T, DefaultTraits<T>>
	, IteratorAccess ACCESS = IteratorAccess::NON_CONSTANT
>
class WrappedIterator
{
public:
	using Me = WrappedIterator<T, TreeNode, ACCESS>;

	using Type = typename TreeNode::Type;

	using Reference = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename TreeNode::Reference
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename TreeNode::ConstReference
			, void
		>::Type
	>::Type;
	using ConstReference = typename TreeNode::ConstReference;

	using Pointer = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename TreeNode::Pointer
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename TreeNode::PointerToConst
			, void
		>::Type
	>::Type;
	using PointerToConst = typename TreeNode::PointerToConst;

	using NodePointer = typename flame_ide::ChooseType<
		ACCESS == IteratorAccess::NON_CONSTANT
		, typename DefaultTraits<TreeNode>::Pointer
		, typename flame_ide::ChooseType<
			ACCESS == IteratorAccess::CONSTANT
			, typename DefaultTraits<TreeNode>::PointerToConst
			, void
		>
	>::Type;

	WrappedIterator() noexcept = default;
	WrappedIterator(const Me &) noexcept = default;
	WrappedIterator(Me &&) noexcept = default;

	WrappedIterator(
			NodePointer currentInit, NodePointer nextInit, NodePointer previousInit
	) noexcept;

	~WrappedIterator() noexcept = default;

	Me &operator=(const Me &) noexcept = default;
	Me &operator=(Me &&) noexcept = default;

	Me &operator++() noexcept;
	Me &operator--() noexcept;

	Me operator++(int) noexcept;
	Me operator--(int) noexcept;

	Reference operator*() noexcept;
	ConstReference operator*() const noexcept;

	Pointer operator->() noexcept;
	PointerToConst operator->() const noexcept;

private:
	mutable NodePointer *current;
	mutable NodePointer *next;
	mutable NodePointer *previous;
};

template<typename TreeNode>
struct Data
{
	TreeNode *root = nullptr;
	TreeNode *first = nullptr;
	TreeNode *last = nullptr;
};

// Pair comparators

template<typename Pair, typename Traits = DefaultTraits<Pair>>
struct PairMore
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft.first() > dataRight.first();
	}
};

template<typename Pair, typename Traits = DefaultTraits<Pair>>
struct PairLess
{
	using ConstReference = typename Traits::ConstReference;

	bool operator()(ConstReference dataLeft, ConstReference dataRight) const noexcept
	{
		return dataLeft.first() < dataRight.first();
	}
};

}}} // namespace flame_ide::templates::tree_utils

namespace flame_ide
{namespace templates
{

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, template<class> class Comparator = Less
	, template<class> class TreeNode = tree_utils::Node
	, template<class> class Allocator = allocator::ObjectAllocator
>
class BinaryTree
{
	using Node = TreeNode<T>;

public:
	using Type = typename Traits::Type;

	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	using Me = BinaryTree<T, Traits, Comparator, TreeNode, Allocator>;

	using Iterator = templates::Iterator<
		tree_utils::WrappedIterator<T, Node, IteratorAccess::NON_CONSTANT>
		, IteratorCategory::BIDIRECTIONAL, Traits, Me
	>;
	using ConstIterator = templates::ConstIterator<
		tree_utils::WrappedIterator<T, Node, IteratorAccess::CONSTANT>
		, IteratorCategory::BIDIRECTIONAL, Traits, Me
	>;
	using ReverseIterator = templates::ReverseIterator<
		Iterator, IteratorCategory::BIDIRECTIONAL, Traits, Me
	>;
	using ConstReverseIterator = templates::ConstReverseIterator<
		ConstIterator, IteratorCategory::BIDIRECTIONAL, Traits, Me
	>;

public:
	BinaryTree() noexcept = default;
	BinaryTree(const Me &tree) noexcept;
	BinaryTree(Me &&tree) noexcept;

	template<typename ValueType, SizeTraits::SizeType SIZE>
	BinaryTree(const ValueType (&a)[SIZE]) noexcept;

	template<typename ValueType, SizeTraits::SizeType SIZE>
	BinaryTree(ValueType (&&a)[SIZE]) noexcept;

	~BinaryTree() noexcept;

	Me &operator=(const Me &tree) noexcept;
	Me &operator=(Me &&tree) noexcept;

	void push(ConstReference value) noexcept;
	void push(MoveReference value) noexcept;

	template<typename ...Args>
	void emplace(Args &&...args) noexcept;

	void erase(Iterator it) noexcept;
	void erase(ConstIterator it) noexcept;
	void erase(ReverseIterator it) noexcept;
	void erase(ConstReverseIterator it) noexcept;

	void clear() noexcept;

	Iterator begin() noexcept;
	Iterator end() noexcept;

	ConstIterator begin() const noexcept;
	ConstIterator end() const noexcept;

	ConstIterator cbegin() const noexcept;
	ConstIterator cend() const noexcept;

	ReverseIterator rbegin() noexcept;
	ReverseIterator rend() noexcept;

	ConstReverseIterator rbegin() const noexcept;
	ConstReverseIterator rend() const noexcept;

	ConstReverseIterator crbegin() const noexcept;
	ConstReverseIterator crend() const noexcept;

	Iterator find() noexcept;
	ConstIterator find() const noexcept;
	ConstIterator cfind() const noexcept;

	ReverseIterator rfind() noexcept;
	ConstReverseIterator rfind() const noexcept;
	ConstReverseIterator crfind() const noexcept;

	///
	/// @brief traverseInfix
	/// @param function
	/// @note [left_subtree, root, right_subtree]
	///
	template<typename Function>
	void traverseInfix(Function &&function) noexcept;

	///
	/// @brief traverseInfix
	/// @param function
	/// @note [left_subtree, root, right_subtree]
	///
	template<typename Function>
	void traverseInfix(Function &&function) const noexcept;

	///
	/// @brief traversePrefix
	/// @param function
	/// @note [root, left_subtree, right_subtree]
	///
	template<typename Function>
	void traversePrefix(Function &&function) noexcept;

	///
	/// @brief traversePrefix
	/// @param function
	/// @note [root, left_subtree, right_subtree]
	///
	template<typename Function>
	void traversePrefix(Function &&function) const noexcept;

	///
	/// @brief traversePostfix
	/// @param function
	/// @note [left_subtree, right_subtree, root]
	///
	template<typename Function>
	void traversePostfix(Function &&function) noexcept;

	///
	/// @brief traversePostfix
	/// @param function
	/// @note [left_subtree, right_subtree, root]
	///
	template<typename Function>
	void traversePostfix(Function &&function) const noexcept;

private:
	void rotateLeft(Node *node) noexcept;

	void rotateRight(Node *node) noexcept;

	template<typename Function>
	void traverseInfix(Node* node, Function &&function) noexcept;
	template<typename Function>
	void traverseInfix(const Node* node, Function &&function) const noexcept;

	template<typename Function>
	void traversePrefix(Node* node, Function &&function) noexcept;
	template<typename Function>
	void traversePrefix(const Node* node, Function &&function) const noexcept;

	template<typename Function>
	void traversePostfix(Node* node, Function &&function) noexcept;
	template<typename Function>
	void traversePostfix(const Node* node, Function &&function) const noexcept;

	void recursiveClear(Node *node) noexcept;

private:
	tree_utils::Data<Node> data;

	Allocator<Node> allocator;
	SizeType size = 0;

	Comparator<Type> comparator;
};

}} // namespace flame_ide::templates

// Implementation

// Utils
namespace flame_ide
{namespace templates
{namespace tree_utils
{

// Node

template<typename T, typename Traits>
template<typename ...Args>
Node<T, Traits>::Node(Args &&...args) noexcept : object{ flame_ide::forward<Args>(args)... }
{}

// CustomNode

template<typename T, typename Options, typename Traits>
template<typename ...Args>
CustomNode<T, Options, Traits>::CustomNode(Args &&...args) noexcept : Parent(flame_ide::forward<Args>(args)...)
{}

// AdelsonVelskyLandisNode

// RedBlackNode

// WrappedIterator

// Pair comparators

}}} // namespace flame_ide::templates::tree_utils

// Iterator
namespace flame_ide
{namespace templates
{namespace tree_utils
{

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
WrappedIterator<T, TreeNode, ACCESS>::WrappedIterator(
		NodePointer currentInit, NodePointer nextInit, NodePointer previousInit
) noexcept : current{ currentInit }, next{ nextInit }, previous{ previousInit }
{}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
WrappedIterator<T, TreeNode, ACCESS> &
WrappedIterator<T, TreeNode, ACCESS>::operator++() noexcept
{
	return *this;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
WrappedIterator<T, TreeNode, ACCESS> &
WrappedIterator<T, TreeNode, ACCESS>::operator--() noexcept
{
	return *this;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
WrappedIterator<T, TreeNode, ACCESS>
WrappedIterator<T, TreeNode, ACCESS>::operator++(int) noexcept
{
	Me copy = *this;
	return copy;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
WrappedIterator<T, TreeNode, ACCESS>
WrappedIterator<T, TreeNode, ACCESS>::operator--(int) noexcept
{
	Me copy = *this;
	return copy;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
typename WrappedIterator<T, TreeNode, ACCESS>::Reference
WrappedIterator<T, TreeNode, ACCESS>::operator*() noexcept
{
	return current->object;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
typename WrappedIterator<T, TreeNode, ACCESS>::ConstReference
WrappedIterator<T, TreeNode, ACCESS>::operator*() const noexcept
{
	return current->object;
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
typename WrappedIterator<T, TreeNode, ACCESS>::Pointer
WrappedIterator<T, TreeNode, ACCESS>::operator->() noexcept
{
	return &(operator*());
}

template<
	typename T, typename TreeNode, IteratorAccess ACCESS
>
typename WrappedIterator<T, TreeNode, ACCESS>::PointerToConst
WrappedIterator<T, TreeNode, ACCESS>::operator->() const noexcept
{
	return &(operator*());
}

}}} // namespace flame_ide::templates::tree_utils

// BinaryTree
namespace flame_ide
{namespace templates
{

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::BinaryTree(const Me &tree) noexcept
{
	operator=(tree);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::BinaryTree(Me &&tree) noexcept
{
	operator=(flame_ide::move(tree));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename ValueType, Types::size_t SIZE>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::BinaryTree(
		const ValueType (&a)[SIZE]
) noexcept
{
	for (const auto &i : a)
		push(i);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename ValueType, Types::size_t SIZE>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::BinaryTree(
		ValueType (&&a)[SIZE]
) noexcept
{
	for (auto &&i : a)
		push(flame_ide::move(i));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::~BinaryTree() noexcept
{
	recursiveClear(data.root);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator> &
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::operator=(const Me &tree) noexcept
{
	flame_ide::unused(tree);
	return *this;
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
BinaryTree<T, Traits, Comparator, TreeNode, Allocator> &
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::operator=(Me &&tree) noexcept
{
	flame_ide::unused(tree);
	return *this;
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::push(ConstReference value) noexcept
{
	auto *node = allocator.construct(value);
	if (!size)
	{
		data.root = data.first = data.last = node;
		++size;

		return;
	}

	Node *it = data.root;
	// SizeType left = 0;
	// SizeType right = 0;
	bool stop = false;
	while (!stop)
	{
		if (comparator(it->object, node->object)) // to right
		{
			if (it->right)
			{
				it = it->right;
				continue;
			}
			it->right = node;
		}
		else
		{
			if (it->left)
			{
				it = it->left;
				continue;
			}
			it->left = node;
		}

		node->previous = it;
		++size;

		stop = true;
	}
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::push(MoveReference value) noexcept
{
	flame_ide::unused(value);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename ...Args>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::emplace(Args &&.../*args*/) noexcept
{}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::erase(Iterator it) noexcept
{
	flame_ide::unused(it);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::erase(ConstIterator it) noexcept
{
	flame_ide::unused(it);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::erase(ReverseIterator it) noexcept
{
	flame_ide::unused(it);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::erase(ConstReverseIterator it) noexcept
{
	flame_ide::unused(it);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::clear() noexcept
{}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::Iterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::begin() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::Iterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::end() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::begin() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::end() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::cbegin() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::cend() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rbegin() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rend() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rbegin() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rend() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::crbegin() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::crend() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::Iterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::find() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::find() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::cfind() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rfind() noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rfind() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
typename BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::ConstReverseIterator
BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::crfind() const noexcept
{
	return {};
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traverseInfix(
		Function &&function
) noexcept
{
	traverseInfix(data.root, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traverseInfix(
		Function &&function
) const noexcept
{
	traverseInfix(data.root, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePrefix(
		Function &&function
) noexcept
{
	traversePrefix(data.root, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePrefix(
		Function &&function
) const noexcept
{
	traversePrefix(data.root, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePostfix(
		Function &&function
) noexcept
{
	traversePostfix(data.root, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePostfix(
		Function &&function
) const noexcept
{
	traversePostfix(data.root, flame_ide::move(function));
}

// private

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rotateLeft(Node *node) noexcept
{
	if (!node || !node->right)
		return;

	Node *nodeRight = node->right;
	node->right = nodeRight->left;
	nodeRight = node;

	// TODO: update for AVL
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::rotateRight(Node *node) noexcept
{
	if (!node || !node->left)
		return;

	Node *nodeLeft = node->left;
	node->left = nodeLeft->right;
	nodeLeft = node;

	// TODO: update for AVL
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traverseInfix(
		Node *node, Function &&function
) noexcept
{
	if (!node)
		return;

	traverseInfix(node->left, flame_ide::move(function));
	function(node->object);
	traverseInfix(node->right, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traverseInfix(
		const Node *node, Function &&function
) const noexcept
{
	if (!node)
		return;

	traverseInfix(node->left, flame_ide::move(function));
	function(node->object);
	traverseInfix(node->right, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePrefix(
		Node *node, Function &&function
) noexcept
{
	if (!node)
		return;

	function(node->object);
	traversePrefix(node->left, flame_ide::move(function));
	traversePrefix(node->right, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePrefix(
		const Node *node, Function &&function
) const noexcept
{
	if (!node)
		return;

	function(node->object);
	traversePrefix(node->left, flame_ide::move(function));
	traversePrefix(node->right, flame_ide::move(function));
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePostfix(
		Node *node, Function &&function
) noexcept
{
	if (!node)
		return;

	traversePostfix(node->left, flame_ide::move(function));
	traversePostfix(node->right, flame_ide::move(function));
	function(node->object);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
template<typename Function>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::traversePostfix(
		const Node *node, Function &&function
) const noexcept
{
	if (!node)
		return;

	traversePostfix(node->left, flame_ide::move(function));
	traversePostfix(node->right, flame_ide::move(function));
	function(node->object);
}

template<
	typename T, typename Traits, template<class> class Comparator
	, template<class> class TreeNode, template<class> class Allocator
>
void BinaryTree<T, Traits, Comparator, TreeNode, Allocator>::recursiveClear(Node *node) noexcept
{
	if (!node)
		return;

	recursiveClear(node->left);
	recursiveClear(node->right);

	allocator.destroy(node);
}

}} // namespace flame_ide::templates

// Utils default aliases
namespace flame_ide
{namespace templates
{namespace tree_utils
{namespace defaults
{

// Node

template<typename T>
using Node = flame_ide::templates::tree_utils::Node<T>;
template<typename T>
using AdelsonVelskyLandisNode =
		flame_ide::templates::tree_utils::AdelsonVelskyLandisNode<T>;
template<typename T>
using RedBlackNode =
		flame_ide::templates::tree_utils::RedBlackNode<T>;

// Pair comparators

template<typename T>
using PairLess = flame_ide::templates::tree_utils::PairLess<T>;

template<typename T>
using PairMore = flame_ide::templates::tree_utils::PairMore<T>;

}}}} // namespace flame_ide::templates::tree_utils::defaults

// Tree aliases
namespace flame_ide
{namespace templates
{

// Common

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, template<class> class Comparator = defaults::Less
	, template<class> class TreeNode = tree_utils::defaults::Node
	, template<class> class Allocator = allocator::defaults::ObjectAllocator
>
using Set = BinaryTree<T, Traits, Comparator, TreeNode, Allocator>;

template<
	typename Key, typename Value
	, typename Traits = ContainerTraits<Pair<typename DefaultTraits<Key>::ConstType, Value>>
	, template<class> class Comparator = tree_utils::defaults::PairLess
	, template<class> class TreeNode = tree_utils::defaults::Node
	, template<class> class Allocator = allocator::defaults::ObjectAllocator
>
using Map = BinaryTree<
	Pair<typename DefaultTraits<Key>::ConstType, Value>
	, Traits, Comparator, TreeNode, Allocator
>;

// Adelson-Velsky and Landis

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, template<class> class Comparator = defaults::Less
	, template<class> class TreeNode = tree_utils::defaults::AdelsonVelskyLandisNode
	, template<class> class Allocator = allocator::defaults::ObjectAllocator
>
using AvlSet = BinaryTree<T, Traits, Comparator, TreeNode, Allocator>;

template<
	typename Key, typename Value
	, typename Traits = ContainerTraits<Pair<typename DefaultTraits<Key>::ConstType, Value>>
	, template<class> class Comparator = tree_utils::defaults::PairLess
	, template<class> class TreeNode = tree_utils::defaults::AdelsonVelskyLandisNode
	, template<class> class Allocator = allocator::defaults::ObjectAllocator
>
using AvlMap = BinaryTree<
	Pair<typename DefaultTraits<Key>::ConstType, Value>
	, Traits, Comparator, TreeNode, Allocator
>;

// Red-black

}} // namespace flame_ide::templates

#endif // FLAMEIDE_TEMPLATES_BINARYTREES_HPP
