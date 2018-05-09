#ifndef TEMPLATES_TREES_HPP
#define TEMPLATES_TREES_HPP

#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

namespace tree_utils
{

// Nodes

template<typename T, typename Traits = ContainerTraits<T>>
struct Node: public Traits
{
	using Me = Node<T, Traits>;

	using typename Traits::Type;
	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	Node() = default;
	Node(Me &&node);
	Node(const Me &node);

	Me *left;
	Me *right;
	Me *previous;
	Type object;
};

template<typename T, typename Traits = ContainerTraits<T>, typename Options>
struct CustomNode: public Node<T, Traits>
{
	using Me = CustomNode<T, Traits, Options>;
	using Parent = Node<T, Traits>;

	using typename Parent::Type;
	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	CustomNode() = default;

	using Parent::left;
	using Parent::right;
	using Parent::previous;
	Options options;
	using Parent::object;
};

template<typename Node>
struct ThreadingOption
{
	Node *next;
	Node *previous;
};

struct RbOptions
{
};

template<typename T, typename Traits>
using RbNode = Node<T, Traits, RbOptions>;

// Iterator

template<typename T, typename Traits, typename Options>
class TreeIterator: public iterator_utils::BaseIterator<Node<T, Traits, Options> *
		, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT, Traits>
{
public:
	using Me = TreeIterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		Node<T, Traits, Options> *
		, IteratorCategory::BIDIRECTIONAL
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;
	using Node = Node<T, Traits, Options>;

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

private:
	Node *current;
	Node *next;
	Node *previous;
};

/*
 * Обход дерева на псевдокоде:
 * left()
 * right()
 * current.
*/
}

template<
	typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<tree_utils::Node<T, Traits>>
>
class Tree
{

};

}}

#endif // TEMPLATES_TREES_HPP