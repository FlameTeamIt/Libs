#ifndef FLAMEIDE_TEMPLATES_TREE_TREESTRATEGY_HPP
#define FLAMEIDE_TEMPLATES_TREE_TREESTRATEGY_HPP

#include <FlameIDE/Common/Utils.hpp>

#include <FlameIDE/Templates/Iterator/ConstIterator.hpp>
#include <FlameIDE/Templates/Iterator/ConstReverseIterator.hpp>
#include <FlameIDE/Templates/Iterator/Iterator.hpp>
#include <FlameIDE/Templates/Iterator/ReverseIterator.hpp>

namespace flame_ide
{namespace templates
{namespace tree
{namespace base
{

template<typename TreeNode, typename Allocator, typename SizeType>
struct TreeContext
{
	TreeNode *root = nullptr;
	SizeType size = 0;
	Allocator allocator;
};

template<
	typename T
	, typename Traits
	, template<class> class TreeNode
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename Meta
>
struct TreeIterators
{
	using Iterator = templates::Iterator<
		TreeIterator<T, TreeNode, IteratorAccess::NON_CONSTANT>
		, IteratorCategory::BIDIRECTIONAL, Traits, Meta
	>;
	using ConstIterator = templates::ConstIterator<
		TreeIterator<T, TreeNode, IteratorAccess::CONSTANT>
		, IteratorCategory::BIDIRECTIONAL, Traits, Meta
	>;
	using ReverseIterator = templates::ReverseIterator<
		Iterator, IteratorCategory::BIDIRECTIONAL, Traits, Meta
	>;
	using ConstReverseIterator = templates::ConstReverseIterator<
		ConstIterator, IteratorCategory::BIDIRECTIONAL, Traits, Meta
	>;
};

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
class TreeStrategy:
		public TreeIterators<
			T, Traits, TreeNode, TreeIterator
			, TreeStrategy<
				T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
			>
		>
		, private TreeImpl
{
private:
	using Iterators = TreeIterators<
		T, Traits, TreeNode, TreeIterator
		, TreeStrategy<
			T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
		>
	>;

public:
	using Me = TreeStrategy<
		T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
	>;
	using Parent = TreeImpl;
	using Comparator = TreeComparator<T>;
	using Node = TreeNode<T>;
	using Allocator = TreeAllocator<T>;

	using Type = typename Traits::Type;

	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	using typename Iterators::Iterator;
	using typename Iterators::ConstIterator;
	using typename Iterators::ReverseIterator;
	using typename Iterators::ConstReverseIterator;

	TreeStrategy() noexcept = default;
	TreeStrategy(const Me &) noexcept;
	TreeStrategy(Me &&) noexcept;

	~TreeStrategy() noexcept;

	Me &operator=(const Me &) noexcept;
	Me &operator=(Me &&) noexcept;

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

private:
	Parent &parent() noexcept;
	const Parent &parent() const noexcept;

	template<typename ...Args>
	Node *makeNode(Args &&...args) noexcept;

	template<typename ...Args>
	auto makeNodeCreator(Args &&...args) noexcept;

	void destroyNode(Node *node) noexcept;

private:
	TreeContext<Node, Allocator, SizeType> context;
};

}}}} // namespace flame_ide::templates::tree::base

namespace flame_ide
{namespace templates
{namespace tree
{namespace base
{

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::TreeStrategy(const Me &) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::TreeStrategy(Me &&) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::~TreeStrategy() noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
> &
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::operator=(const Me &) noexcept
{
	return *this;
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
> &
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::operator=(Me &&) noexcept
{
	return *this;
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::push(ConstReference value) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
push(MoveReference value) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
template<typename ...Args>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::emplace(Args &&...args) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::erase(Iterator it) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::erase(ConstIterator it) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::erase(ReverseIterator it) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::erase(ConstReverseIterator it) noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::clear() noexcept
{}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Iterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::begin() noexcept
{
	return Iterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Iterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::end() noexcept
{
	return Iterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::begin() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::end() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::cbegin() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::cend() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rbegin() noexcept
{
	return ReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rend() noexcept
{
	return ReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rbegin() const noexcept
{
	return ConstReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rend() const noexcept
{
	return ConstReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::crbegin() const noexcept
{
	return ConstReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::crend() const noexcept
{
	return ConstReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Iterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::find() noexcept
{
	return Iterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::find() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::cfind() const noexcept
{
	return ConstIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rfind() noexcept
{
	return ReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::rfind() const noexcept
{
	return ConstReverseIterator{};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::ConstReverseIterator
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::crfind() const noexcept
{
	return ConstReverseIterator{};
}

// private

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Parent &
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::parent() noexcept
{
	return *this;
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
const typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Parent &
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::parent() const noexcept
{
	return *this;
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
template<typename ...Args>
typename TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::Node *
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::makeNode(Args &&...args) noexcept
{
	return context.allocator.construct(flame_ide::forward<Args>(args)...);
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
template<typename ...Args>
auto
TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::makeNodeCreator(Args &&...args) noexcept
{
	return [this, &args...]()
	{
		return makeNode(flame_ide::forward<Args>(args)...);
	};
}

template<
	typename T
	, typename Traits
	, template<class> class TreeComparator
	, template<class> class TreeNode
	, template<class> class TreeAllocator
	, template<class, template<class> class, IteratorAccess> class TreeIterator
	, typename TreeImpl
>
void TreeStrategy<
	T, Traits, TreeComparator, TreeNode, TreeAllocator, TreeIterator, TreeImpl
>::destroyNode(Node *node) noexcept
{
	context.allocator.destroy(node);
}

}}}} // namespace flame_ide::templates::tree::base

#endif // FLAMEIDE_TEMPLATES_TREE_TREESTRATEGY_HPP
