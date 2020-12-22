#ifndef FLAMEIDE_TEMPLATES_ARRAYBLOCKS_HPP
#define FLAMEIDE_TEMPLATES_ARRAYBLOCKS_HPP

#include <FlameIDE/Common/Traits.hpp>
#include <FlameIDE/Common/Utils.hpp>

#include <FlameIDE/Templates/Allocator.hpp>
#include <FlameIDE/Templates/Array.hpp>

namespace flame_ide
{namespace templates
{

namespace arrayblocks_utils
{

enum class FromBlock
{
	FROM_NULL  = char(0),
	FROM_FRONT = char(1),
	FROM_BACK  = char(2)
};

template<typename T
	, SizeTraits::SizeType SIZE
	, typename Traits = ContainerTraits<T>
>
struct Node
{
	using Me = Node<T, SIZE, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	using Block = Array<T, SIZE, false, Traits>;

	Node();
	Node(const Me &);
	Node(Me &&);
	~Node();
	Me &operator=(const Me &);
	Me &operator=(Me &&);

	Me *next;
	Me *prev;
	Block block;
};

}

template<typename T
	, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<T, Traits>
>
class ArrayBlocks: protected Allocator
{
	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;
};

}}

#endif // FLAMEIDE_TEMPLATES_ARRAYBLOCKS_HPP
