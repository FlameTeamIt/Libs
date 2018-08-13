#ifndef TEMPLATES_TREES_HPP
#define TEMPLATES_TREES_HPP

#include <Common/Traits.hpp>
#include <Common/Utils.hpp>
#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>

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

template<typename T, typename Options, typename Traits = ContainerTraits<T>>
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
using RbNode = CustomNode<T, RbOptions, Traits>;

// Iterator

template<typename T, typename Options, typename Traits>
class TreeIterator: public iterator_utils::BaseIterator<CustomNode<T, Options, Traits> *
		, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT, Traits>
{
public:
	using Me = flame_ide::templates::tree_utils::TreeIterator<T, Options, Traits>;
	using Parent = iterator_utils::BaseIterator<
		CustomNode<T, Options, Traits> *
		, IteratorCategory::BIDIRECTIONAL
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;
	using Node = flame_ide::templates::tree_utils::CustomNode<T, Options, Traits>;

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
