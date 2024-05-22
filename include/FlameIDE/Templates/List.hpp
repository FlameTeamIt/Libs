#ifndef FLAMEIDE_TEMPLATES_LIST_HPP
#define FLAMEIDE_TEMPLATES_LIST_HPP

#include <FlameIDE/Templates/Allocator.hpp>
#include <FlameIDE/Templates/Iterator.hpp>
#include <FlameIDE/Templates/Range.hpp>
#include <FlameIDE/Templates/SimpleAlgorithms.hpp>
#include <FlameIDE/Templates/InitializerList.hpp>

#define TEMPLATE_DEFINE \
	template<typename T, typename Traits, typename Allocator>

#define LIST_TYPE \
	List<T, Traits, Allocator>


namespace flame_ide
{namespace templates
{

namespace list_utils
{

template<typename T, typename Traits = ContainerTraits<T>>
struct Node;

template<typename T, typename Traits = ContainerTraits<T>>
class ListIterator;

}

template<typename T, typename Traits, typename Allocator>
class List;

}}

namespace flame_ide
{ namespace templates
{

namespace list_utils
{

template<typename T, typename Traits>
struct Node
{
	using Me = Node<T, Traits>;

	using Type = typename Traits::Type;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;

	Node() = default;
	Node(const Me &) = default;
	Node(Me &&) = default;
	Node(ConstReference object);
	Node(MoveReference object);
	~Node() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	Node *previous;
	Node *next;
	Type object;
};

template<typename T, typename Traits>
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

template<typename T, typename Traits>
class ListConstIterator: public iterator_utils::BaseIterator<const Node<T> *
	, IteratorCategory::BIDIRECTIONAL, IteratorAccess::CONSTANT, Traits>
{
public:
	using Me = ListConstIterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		const Node<T> *
		, IteratorCategory::BIDIRECTIONAL
		, IteratorAccess::CONSTANT
		, Traits
	>;

	using typename Parent::Type;

	using typename Parent::Reference;
	using typename Parent::ConstReference;
	using typename Parent::MoveReference;

	using typename Parent::Pointer;
	using typename Parent::PointerToConst;

	ListConstIterator() = default;
	ListConstIterator(const Me &) = default;
	ListConstIterator(Me &&) = default;
	ListConstIterator(const Node<T> *node) : Parent(node)
	{}
	~ListConstIterator() = default;
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

	ConstReference operator*() const
	{
		return this->wrappedIterator->object;
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
	, typename Allocator = allocator::ObjectAllocator<list_utils::Node<T, Traits> >
>
class List
{
public:
	using Me = List<T, Traits, Allocator>;
	using Node = list_utils::Node<T, Traits>;

	using Type = typename Traits::Type;
	using Reference = typename Traits::Reference;
	using ConstReference = typename Traits::ConstReference;
	using MoveReference = typename Traits::MoveReference;
	using Pointer = typename Traits::Pointer;
	using PointerToConst = typename Traits::PointerToConst;
	using SizeType = typename Traits::SizeType;
	using SsizeType = typename Traits::SsizeType;

	using Iterator = list_utils::ListIterator<T, Traits>;
	using ConstIterator = list_utils::ListConstIterator<T, Traits>;
	using ReverseIterator = flame_ide::templates::ReverseIterator<
		Iterator
	>;
	using ConstReverseIterator = flame_ide::templates::ConstReverseIterator<
		ConstIterator
	>;

	List();
	List(const Me &list);
	List(Me &&list);
	List(InitializerList<Type> list);
	~List();
	List &operator=(const Me &list);
	List &operator=(Me &&list);

	Me &operator+=(ConstReference object);
	Me &operator+=(MoveReference object);
	template<typename InputIterator> Me &operator+=(Range<InputIterator> range);

	Me &operator-=(Iterator it);
	Me &operator-=(ReverseIterator it);
	Me &operator-=(Range<Iterator> range);
	Me &operator-=(Range<ReverseIterator> range);

	SizeType size() const;

	void clean();

	Me clone() const;

	Iterator begin();
	ConstIterator begin() const;
	ConstIterator cbegin() const;
	ReverseIterator rbegin();
	ConstReverseIterator rbegin() const;
	ConstReverseIterator crbegin() const;

	Iterator end();
	ConstIterator end() const;
	ConstIterator cend() const;
	ReverseIterator rend();
	ConstReverseIterator rend() const;
	ConstReverseIterator crend() const;

	void pushBack(ConstReference object);
	void pushBack(MoveReference object);
	template<typename ...Args> void emplaceBack(Args &&...args);

	void pushFront(ConstReference object);
	void pushFront(MoveReference object);
	template<typename ...Args> void emplaceFront(Args &&...args);

	void insert(Iterator it, ConstReference object);
	void insert(Iterator it, MoveReference object);
	template<typename InputIterator> void insert(Iterator it
			, InputIterator itBegin, InputIterator itEnd);
	template<typename ...Args> void emplace(Iterator it, Args &&...args);

	void popBack();
	void popFront();

	void erase(Iterator it);
	void erase(Iterator itBegin, Iterator itEnd);

private:
	inline void updateHeadLinks();
	inline void updateTailLinks();
	inline void updateLinks();

	inline void cleanLinks();

	Allocator allocator;
	Node postFirst;
	Node postLast;
	Node *head;
	Node *tail;
};

}}

namespace flame_ide
{namespace templates
{

namespace list_utils
{

// Node

template<typename T, typename Traits>
Node<T, Traits>::Node(typename Node<T, Traits>::ConstReference object)
		: previous(nullptr), next(nullptr), object(object)
{}

template<typename T, typename Traits>
Node<T, Traits>::Node(typename Node<T, Traits>::MoveReference object)
		: previous(nullptr), next(nullptr), object(object)
{}


// ListIterator

}

TEMPLATE_DEFINE
LIST_TYPE::List()
		: allocator()
		, postFirst(), postLast()
		, head(nullptr), tail(nullptr)
{}

TEMPLATE_DEFINE
LIST_TYPE::List(const LIST_TYPE &list) : List()
{
	if (list.size())
	{
		for (auto i : list)
		{
			pushBack(i);
		}
		updateHeadLinks();
	}
}

TEMPLATE_DEFINE
LIST_TYPE::List(LIST_TYPE &&list)
		: allocator()
		, postFirst(), postLast()
		, head(list.head), tail(list.tail)
{
	list.head = nullptr;
	list.tail = nullptr;
	list.cleanLinks();

	updateLinks();
}

TEMPLATE_DEFINE
LIST_TYPE::List(InitializerList<typename LIST_TYPE::Type> list) : List()
{
	for (auto i : list)
	{
		pushBack(i);
	}
	updateHeadLinks();
}

TEMPLATE_DEFINE
LIST_TYPE::~List()
{
	clean();
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator=(const LIST_TYPE &list)
{
	size_t mySize = this->size();
	size_t listSize = list.size();

	if (listSize)
	{
		if (listSize > mySize)
		{
			Iterator it = list.begin();
			for (auto &i : *this)
			{
				i = *it;
				++it;
			}
			for (; it != list.end(); ++it)
			{
				pushBack(*it);
			}
		}
		else
		{
			Iterator it = this->begin();
			for (auto &i : list)
			{
				*it = i;
				++it;
			}
			for (; listSize != mySize; --mySize)
			{
				popBack();
			}
		}
	}
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator=(LIST_TYPE &&list)
{
	clean();
	head = list.head;
	tail = list.tail;
	updateLinks();

	list.head = nullptr;
	list.tail = nullptr;
	list.cleanLinks();

	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator+=(typename LIST_TYPE::ConstReference object)
{
	pushBack(object);
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator+=(typename LIST_TYPE::MoveReference object)
{
	pushBack(move(object));
	return *this;
}

TEMPLATE_DEFINE template<typename InputIterator>
LIST_TYPE &LIST_TYPE::operator+=(Range<InputIterator> range)
{
	insert(end(), range.begin(), range.end());
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator-=(typename LIST_TYPE::Iterator it)
{
	erase(it);
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator-=(typename LIST_TYPE::ReverseIterator it)
{
	erase(it.internalData());
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator-=(Range<typename LIST_TYPE::Iterator> range)
{
	erase(range.begin(), range.end());
	return *this;
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator-=(Range<typename LIST_TYPE::ReverseIterator> range)
{
	erase(range.end().operator--().internalData()
			, range.begin().operator--().internalData());
	return *this;
}

TEMPLATE_DEFINE
typename LIST_TYPE::SizeType LIST_TYPE::size() const
{
	SizeType resultSize = 0;
	for (Node *pointer = head; pointer != &postLast; pointer = pointer->next)
		++resultSize;
	return resultSize;
}

TEMPLATE_DEFINE
void LIST_TYPE::clean()
{
	Node *pointer = head;
	while (pointer && pointer != &postLast)
	{
		Node *pointerPrevious = pointer;
		pointer = pointer->next;
		allocator.destroy(pointerPrevious);
	}

	head = tail = nullptr;
	cleanLinks();
}

TEMPLATE_DEFINE
LIST_TYPE LIST_TYPE::clone() const
{
	Me copy = *this;
	return copy;
}

TEMPLATE_DEFINE
typename LIST_TYPE::Iterator LIST_TYPE::begin()
{
	return Iterator(head);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::begin() const
{
	return ConstIterator(head);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::cbegin() const
{
	return begin();
}

TEMPLATE_DEFINE
typename LIST_TYPE::ReverseIterator LIST_TYPE::rbegin()
{
	return ReverseIterator(Iterator(tail));
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReverseIterator LIST_TYPE::rbegin() const
{
	return ConstReverseIterator(ConstIterator(tail));
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReverseIterator LIST_TYPE::crbegin() const
{
	return rbegin();
}

TEMPLATE_DEFINE
typename LIST_TYPE::Iterator LIST_TYPE::end()
{
	return Iterator(&postLast);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::end() const
{
	return ConstIterator(&postLast);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::cend() const
{
	return end();
}

TEMPLATE_DEFINE
typename LIST_TYPE::ReverseIterator LIST_TYPE::rend()
{
	return ReverseIterator(Iterator(&postFirst));
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReverseIterator LIST_TYPE::rend() const
{
	return ConstReverseIterator(ConstIterator(&postFirst));
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReverseIterator LIST_TYPE::crend() const
{
	return rend();
}

TEMPLATE_DEFINE
void LIST_TYPE::pushBack(typename LIST_TYPE::ConstReference object)
{
	Node *pointer = allocator.construct(object);
	if (head)
	{
		pointer->previous = tail;
		tail->next = pointer;
		tail = tail->next;
		updateTailLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::pushBack(typename LIST_TYPE::MoveReference object)
{
	Node *pointer = allocator.construct(object);
	if (head)
	{
		pointer->previous = tail;
		tail->next = pointer;
		tail = tail->next;
		updateTailLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE template<typename ...Args>
void LIST_TYPE::emplaceBack(Args &&...args)
{
	Node *pointer = allocator.construct(Type(forward<decltype(args)>(args)...));
	if (head)
	{
		pointer->previous = tail;
		tail->next = pointer;
		tail = tail->next;
		updateTailLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::pushFront(typename LIST_TYPE::ConstReference object)
{
	Node *pointer = allocator.construct(object);
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
		updateHeadLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::pushFront(typename LIST_TYPE::MoveReference object)
{
	Node *pointer = allocator.construct(object);
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
		updateHeadLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE template<typename ...Args>
void LIST_TYPE::emplaceFront(Args &&...args)
{
	Node *pointer = allocator.construct(Type(forward<decltype(args)>(args)...));
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
		updateHeadLinks();
	}
	else
	{
		head = tail = pointer;
		updateLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, typename LIST_TYPE::ConstReference object)
{
	if (!size())
	{
		Node *pointer = allocator.construct(object);
		head = tail = pointer;
	}
	else if (it == begin())
	{
		pushFront(object);
	}
	else if (it == end())
	{
		pushBack(object);
	}
	else
	{
		Node *pointer = allocator.construct(object);
		Node *pointers[] = { it.internalData()->previous, it.internalData() };

		pointers[0]->next = pointer;
		pointer->previous = pointers[0];

		pointers[1]->previous = pointer;
		pointer->next = pointers[1];
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, typename LIST_TYPE::MoveReference object)
{
	if (!size())
	{
		Node *pointer = allocator.construct(move(object));
		head = tail = pointer;
	}
	else if (it == begin())
	{
		pushFront(move(object));
	}
	else if (it == end())
	{
		pushBack(move(object));
	}
	else
	{
		Node *pointer = allocator.construct(move(object));
		Node *pointers[] = { it.internalData()->previous, it.internalData() };

		pointers[0]->next = pointer;
		pointer->previous = pointers[0];

		pointers[1]->previous = pointer;
		pointer->next = pointers[1];
	}
}

TEMPLATE_DEFINE template<typename InputIterator>
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	if (countIterations(itBegin, itEnd))
	{
		Node *pointerHead = nullptr;
		Node *pointerTail = nullptr;
		Range<InputIterator> inputRange(itBegin, itEnd);

		bool first = true;
		for (auto object : inputRange)
		{
			if (first)
			{
				pointerHead = allocator.construct(object);
				pointerTail = pointerHead;
				first = false;
			}
			else
			{
				Node *pointer = allocator.construct(object);
				pointerTail->next = pointer;
				pointer->previous = pointerTail;

				pointerTail = pointer;
			}
		}

		if (!size())
		{
			head = pointerHead;
			tail = pointerTail;
			updateLinks();
		}
		else if (it == begin())
		{
			pointerTail->next = head;
			head->previous = pointerTail;
			head = pointerHead;
			updateHeadLinks();
		}
		else if (it == end())
		{
			pointerHead->previous = tail;
			tail->next = pointerHead;
			tail = pointerTail;
			updateTailLinks();
		}
		else
		{
			Node *pointers[] = { it.internalData()->previous, it.internalData() };

			pointers[0]->next = pointerHead;
			pointerHead->previous = pointers[0];

			pointers[1]->previous = pointerTail;
			pointerTail->next = pointers[1];
		}
	}
}

TEMPLATE_DEFINE template<typename ...Args>
void LIST_TYPE::emplace(typename LIST_TYPE::Iterator it, Args &&...args)
{
	if (!size())
	{
		Node *pointer = allocator.construct(Type(forward<decltype(args)>(args)...));
		head = tail = pointer;
	}
	else if (it == begin())
	{
		emplaceFront(forward<decltype(args)>(args)...);
	}
	else if (it == end())
	{
		emplaceBack(forward<decltype(args)>(args)...);
	}
	else
	{
		Node *pointer = allocator.construct(Type(forward<decltype(args)>(args)...));
		Node *pointers[] = { it.internalData()->previous, it.internalData() };

		pointers[0]->next = pointer;
		pointer->previous = pointers[0];

		pointers[1]->previous = pointer;
		pointer->next = pointers[1];
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::popBack()
{
	if (tail->previous)
	{
		auto pointer = tail;
		tail = tail->previous;
		tail->next = nullptr;

		allocator.destroy(pointer);

		updateTailLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::popFront()
{
	if (head->next)
	{
		auto pointer = head;
		head = head->next;
		head->previous = nullptr;

		allocator.destroy(pointer);

		updateHeadLinks();
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::erase(typename LIST_TYPE::Iterator it)
{
	if (it == begin())
	{
		popFront();
	}
	else if (it == end())
	{
		popBack();
	}
	else
	{
		Node *removeNode = it.internalData();
		Node *previousNode = removeNode->previous;
		Node *nextNode = removeNode->next;

		previousNode->next = nextNode;
		nextNode->previous = previousNode;

		allocator.destroy(removeNode);
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::erase(typename LIST_TYPE::Iterator itBegin
		, typename LIST_TYPE::Iterator itEnd)
{
	Types::uichar_t variaint = 10u * (itBegin == begin())
			+ (itEnd == end());

	switch (variaint)
	{
		case 11: // itBegin == begin() && itEnd == end()
		{
			clean();
			break;
		}
		case 10: // itBegin == begin()
		{
			while (head != itEnd.internalData())
			{
				popFront();
			}
			break;
		}
		case 1: // itEnd == end()
		{
			while (tail != itBegin.internalData())
			{
				popBack();
			}
			popBack();
			break;
		}
		default: // itBegin != begin() && itEnd != end()
		{
			Node *previousNode = itBegin.internalData()->previous;
			previousNode->next = itEnd.internalData();
			itEnd.internalData()->previous = previousNode;

			for (Node *removingNode = itBegin.internalData();
					removingNode != itEnd.internalData();)
			{
				Node *pointer = removingNode;
				removingNode = pointer->next;
				allocator.destroy(pointer);
			}
			break;
		}
	}
}

TEMPLATE_DEFINE inline
void LIST_TYPE::updateHeadLinks()
{
	postFirst.next = head;
	head->previous = &postFirst;
}

TEMPLATE_DEFINE inline
void LIST_TYPE::updateTailLinks()
{
	postLast.previous = tail;
	tail->next = &postLast;
}

TEMPLATE_DEFINE inline
void LIST_TYPE::updateLinks()
{
	updateHeadLinks();
	updateTailLinks();
}

TEMPLATE_DEFINE inline
void LIST_TYPE::cleanLinks()
{
	postFirst.previous = nullptr;
	postFirst.next = nullptr;

	postLast.previous = nullptr;
	postLast.next = nullptr;
}

}}

#undef TEMPLATE_DEFINE
#undef LIST_TYPE

#endif // FLAMEIDE_TEMPLATES_LIST_HPP
