#ifndef TEMPLATES_LIST_HPP
#define TEMPLATES_LIST_HPP

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Allocator.hpp>

namespace flame_ide
{ namespace templates
{

namespace list_utils
{

template<typename T, typename Traits = ContainerTraits<T>>
struct Node: public Traits
{
	using Me = Node<T, Traits>;

	using typename Traits::Type;

	Node() = delete;
	Node(const Node &) = default;
	Node(Node &&) = default;

	template<typename ...Args>
	Node(Args &&...args);

	template<typename ...Args>
	Node(Me *initPrevious, Me *initNext, Args &&...args);

	Node *previous;
	Node *next;
	Type object;
};

template<typename T, typename Traits = ContainerTraits<T>>
class ListIterator: public iterator_utils::BaseIterator<Node<T> *
	, IteratorCategory::BIDIRECTIONAL, IteratorAccess::NON_CONSTANT, Traits>
{
public:
	using Me = ListIterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		Node<T> *
		, IteratorCategory::BIDIRECTIONAL
		, IteratorAccess::NON_CONSTANT
		, Traits
	>;

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	ListIterator() = default;
	ListIterator(const Me &) = default;
	ListIterator(Me &&) = default;
	ListIterator(Node<T> *node) : Parent(node)
	{}
	~ListIterator() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Me &operator++()
	{
		this->wrappedIterator = this->wrappedIterator->next;
		return *this;
	}
	const Me &operator++() const
	{
		this->wrappedIterator = this->wrappedIterator->next;
		return *this;
	}
	Me operator++(int) const
	{
		Me copy = *this;
		++(*this);
		return copy;
	}

	Me &operator--()
	{
		this->wrappedIterator = this->wrappedIterator->previous;
		return *this;
	}
	const Me &operator--() const
	{
		this->wrappedIterator = this->wrappedIterator->previous;
		return *this;
	}
	Me operator--(int) const
	{
		Me copy = *this;
		--(*this);
		return copy;
	}

	Reference operator*()
	{
		return this->wrappedIterator->object;
	}
	ConstReference operator*() const
	{
		return this->wrappedIterator->object;
	}

	Pointer operator->()
	{
		return &(this->wrappedIterator->object);
	}
	PointerToConst operator->() const
	{
		return &(this->wrappedIterator->object);
	}

private:
	using Parent::wrappedIterator;
};

}

template<typename T, typename Traits = ContainerTraits<T>
	, typename Allocator =
			allocator::ObjectAllocator<list_utils::Node<T, Traits>, Traits>
>
class List: public Traits
{
public:
	using Me = List<T, Traits, Allocator>;
	using Node = list_utils::Node<T, Traits>;

	using typename Traits::Type;
	using typename Traits::SizeType;

	using typename Traits::Type;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

	using Iterator = list_utils::ListIterator<T, Traits>;
	using ConstIterator = ConstIterator<Iterator>;
	using ReverseIterator = ReverseIterator<Iterator>;
	using ConstReverseIterator = ConstIterator<ReverseIterator>;

	List();
	List(const Me &list);
	List(Me &&list);
	~List();
	List &operator=(const Me &list);
	List &operator=(Me &&list);

	SizeType size() const;

	Type &first();
	const Type &first() const;

	Type &last();
	const Type &last() const;

	void clean();

	Me clone();

	Iterator begin();

	ConstIterator begin() const;

	Iterator end();

	ConstIterator end() const;

	ReverseIterator rbegin();

	ConstReverseIterator rbegin() const;

	ReverseIterator rend();

	ConstReverseIterator rend() const;

	void pushBack(const Type &object);

	void pushBack(Type &&object);

	template<typename ...Args>
	void emaplceBack(Args &&...args);

	void pushFront(const Type &object);

	void pushFront(Type &&object);

	template<typename ...Args>
	void emaplceFront(Args &&...args);

	void insert(Iterator it, const Type &object);

	void insert(Iterator it, Type &&object);

	template<typename InputIterator>
	void insert(Iterator it, InputIterator itBegin, InputIterator itEnd);

	template<typename ...Args>
	void emplace(Iterator it, Args &&...args);

	void popBack();

	void popFront();

	void erase(Iterator it);

	void erase(Iterator itBegin, Iterator itEnd);

private:
	Node *head;
	Node *tail;
	Allocator allocator;
};

}}

namespace flame_ide
{namespace templates
{



}}

#endif // TEMPLATES_LIST_HPP
