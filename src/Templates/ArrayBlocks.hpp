#ifndef TEMPLATES_ARRAYBLOCKS_HPP
#define TEMPLATES_ARRAYBLOCKS_HPP

#include <Templates/Allocator.hpp>
#include <Templates/Array.hpp>
#include <Templates/Traits.hpp>
#include <Templates/Utils.hpp>

namespace flame_ide
{namespace templates
{

typedef enum
{
	FROM_NULL  = char(0),
	FROM_FRONT = char(1),
	FROM_BACK  = char(2)
} FromBlock;

namespace arrayblocks_utils
{

template<typename T
	, SizeTraits::SizeType SIZE
	, typename Traits = ContainerTraits<T>
>
struct Node: public Traits
{
	using Me = Node<T, SIZE, Traits>;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;

	using typename Traits::SizeType;
	using typename Traits::SsizeType;

	using Block = Array<T, SIZE, Traits>;

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
	, typename Allocator = allocator::ObjectAllocator
>
class ArrayBlocks
{
};

}}

#endif // TEMPLATES_ARRAYBLOCKS_HPP
