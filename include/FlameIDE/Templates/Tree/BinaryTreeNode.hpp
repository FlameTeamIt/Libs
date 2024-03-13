#ifndef FLAMEIDE_TEMPLATES_TREE_BINARYTREENODE_HPP
#define FLAMEIDE_TEMPLATES_TREE_BINARYTREENODE_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

// Nodes

namespace flame_ide
{namespace templates
{namespace tree
{namespace node
{

// Default node for binary tree
template<typename T, typename Traits = DefaultTraits<T>>
struct BinaryNode
{
	using Me = BinaryNode<T, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;

	BinaryNode() noexcept = default;
	BinaryNode(Me &&node) noexcept = default;
	BinaryNode(const Me &node) noexcept = default;

	template<typename ...Args>
	BinaryNode(Args &&...args) noexcept;

	~BinaryNode() = default;

	Me *left = nullptr;
	Me *right = nullptr;
	Me *previous = nullptr;
	Type object;
};

// Customizаble node for binary tree
template<typename T, typename Options, typename Traits = DefaultTraits<T>>
struct CustomNode: public BinaryNode<T, Traits>
{
	using Me = CustomNode<T, Options, Traits>;
	using Parent = BinaryNode<T, Traits>;

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

}}}} // namespace flame_ide::templates::tree::node

// Custom nodes

namespace flame_ide
{namespace templates
{namespace tree
{namespace node
{

// Adelson-Velsky and Landis
struct AdelsonVelskyLandisOptions
{
	Types::ushort_t height = 0;
};
template<typename T, typename Traits = DefaultTraits<T>>
using AdelsonVelskyLandisNode = CustomNode<T, AdelsonVelskyLandisOptions, Traits>;

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

}}}} // namespace flame_ide::templates::tree::node

#endif // FLAMEIDE_TEMPLATES_TREE_BINARYTREENODE_HPP
