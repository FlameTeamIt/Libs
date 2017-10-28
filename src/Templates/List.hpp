#ifndef TEMPLATES_LIST_HPP
#define TEMPLATES_LIST_HPP

#include <Templates/Allocator.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/View.hpp>
#include <Templates/Utils.hpp>
#include <Templates/InitializerList.hpp>

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
struct Node: public Traits
{
	using Me = Node<T, Traits>;

	using typename Traits::Type;

	Node() = delete;
	Node(const Me &) = default;
	Node(Me &&) = default;
	~Node() = default;
	Me &operator=(const Me &) = default;
	Me &operator=(Me &&) = default;

	template<typename ...Args>
	Node(Args &&...args);

	template<typename ...Args>
	Node(Me *initPrevious, Me *initNext, Args &&...args);

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
class ListConstIterator: public iterator_utils::BaseIterator<Node<T> *
	, IteratorCategory::BIDIRECTIONAL, IteratorAccess::CONSTANT, Traits>
{
public:
	using Me = ListConstIterator<T, Traits>;
	using Parent = iterator_utils::BaseIterator<
		Node<T> *
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
class List: public Traits
{
public:
	using Me = List<T, Traits, Allocator>;
	using Node = list_utils::Node<T, Traits>;

	using typename Traits::Type;
	using typename Traits::SizeType;

	using typename Traits::Reference;
	using typename Traits::ConstReference;
	using typename Traits::MoveReference;

	using typename Traits::Pointer;
	using typename Traits::PointerToConst;

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

	SizeType size() const;

	Reference first();
	ConstReference first() const;

	Reference last();
	ConstReference last() const;

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

	template<typename ...Args>
	void emaplceBack(Args &&...args);

	void pushFront(ConstReference object);

	void pushFront(MoveReference object);

	template<typename ...Args>
	void emplaceFront(Args &&...args);

	void insert(Iterator it, ConstReference object);

	void insert(Iterator it, MoveReference object);

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

namespace list_utils
{

// Node

template<typename T, typename Traits>
template<typename ...Args>
Node<T, Traits>::Node(Args &&...args)
		: previous(nullptr), next(nullptr), object(forward<Args>(args)...)
{}

template<typename T, typename Traits>
template<typename ...Args>
Node<T, Traits>::Node(Me *initPrevious, Me *initNext, Args &&...args)
		: previous(initPrevious), next(initNext), object(forward<Args>(args)...)
{}

// ListIterator

}

TEMPLATE_DEFINE
LIST_TYPE::List() : head(nullptr), tail(nullptr), allocator()
{}

TEMPLATE_DEFINE
LIST_TYPE::List(const LIST_TYPE &list) : List()
{
	if (list.size())
	{
		head = allocator.construct(*list.head);
		if (list.head != list.tail)
		{
			tail = head;
		}
		else
		{
			Node *listPointer = list.head;
			Node *pointer = head;

			while (listPointer->next)
			{
				pointer->next = allocator.construct(*listPointer->next);
				pointer->next->previous = pointer;

				listPointer = listPointer->next;
				pointer = pointer->next;
			}
			tail = pointer;
		}
	}
}

TEMPLATE_DEFINE
LIST_TYPE::List(LIST_TYPE &&list) : head(list.head), tail(list.tail), allocator()
{
	list.head = nullptr;
	list.tail = nullptr;
}

TEMPLATE_DEFINE
LIST_TYPE::List(InitializerList<typename LIST_TYPE::Type> list) : List()
{
	for (auto i : list)
	{
		pushBack(i);
	}
}

TEMPLATE_DEFINE
LIST_TYPE::~List()
{
	clean();
}

TEMPLATE_DEFINE
LIST_TYPE &LIST_TYPE::operator=(const LIST_TYPE &list)
{
	clean();

	if (list.size())
	{
		head = allocator.construct(*list.head);
		if (list.head != list.tail)
		{
			tail = head;
		}
		else
		{
			Node *listPointer = list.head;
			Node *pointer = head;

			while (listPointer->next)
			{
				pointer->next = allocator.construct(*listPointer->next);
				pointer->next->previous = pointer;

				listPointer = listPointer->next;
				pointer = pointer->next;
			}
			tail = pointer;
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

	list.head = nullptr;
	list.tail = nullptr;

	return *this;
}

TEMPLATE_DEFINE
typename LIST_TYPE::SizeType LIST_TYPE::size() const
{
	SizeType resultSize = 0;
	for (Node *pointer = head; pointer; pointer = pointer->next)
		++resultSize;
	return resultSize;
}

TEMPLATE_DEFINE
typename LIST_TYPE::Reference LIST_TYPE::first()
{
	return head->object;
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReference LIST_TYPE::first() const
{
	return head->object;
}

TEMPLATE_DEFINE
typename LIST_TYPE::Reference LIST_TYPE::last()
{
	return tail->object;
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReference LIST_TYPE::last() const
{
	return tail->object;
}

// FIXME
TEMPLATE_DEFINE
void LIST_TYPE::clean()
{
	Node *pointer = head;
	while (pointer)
	{
		Node *pointerPrevious = pointer;
		allocator.destroy(pointerPrevious);
		pointer = pointer->next;
	}

	head = tail = nullptr;
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
	return Iterator(nullptr);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::end() const
{
	return ConstIterator(nullptr);
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstIterator LIST_TYPE::cend() const
{
	return end();
}

TEMPLATE_DEFINE
typename LIST_TYPE::ReverseIterator LIST_TYPE::rend()
{
	return ReverseIterator(Iterator(nullptr));
}

TEMPLATE_DEFINE
typename LIST_TYPE::ConstReverseIterator LIST_TYPE::rend() const
{
	return ConstReverseIterator(ConstIterator(nullptr));
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
	}
	else
	{
		head = tail = pointer;
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
	}
	else
	{
		head = tail = pointer;
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void LIST_TYPE::emaplceBack(Args &&...args)
{
	Node *pointer = allocator.contruct(forward<Args>(args)...);
	if (head)
	{
		pointer->previous = tail;
		tail->next = pointer;
		tail = tail->next;
	}
	else
	{
		head = tail = pointer;
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::pushFront(typename LIST_TYPE::ConstReference object)
{
	Node *pointer = allocator.contruct(object);
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
	}
	else
	{
		head = tail = pointer;
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::pushFront(typename LIST_TYPE::MoveReference object)
{
	Node *pointer = allocator.contruct(object);
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
	}
	else
	{
		head = tail = pointer;
	}
}

TEMPLATE_DEFINE
template<typename ...Args>
void LIST_TYPE::emplaceFront(Args &&...args)
{
	Node *pointer = allocator.contruct(forward<Args>(args)...);
	if (head)
	{
		head->previous = pointer;
		pointer->next = head;
		head = head->previous;
	}
	else
	{
		head = tail = pointer;
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, typename LIST_TYPE::ConstReference object)
{
	if (!size())
	{
		Node *pointer = allocator.contruct(object);
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
		Node *pointer = allocator.contruct(object);

	}
}

TEMPLATE_DEFINE
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, typename LIST_TYPE::MoveReference object)
{
	if (!size())
	{
		Node *pointer = allocator.contruct(move(object));
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
		Node *pointer = allocator.contruct(move(object));
		Node *pointers[] = { it.internalData()->previous, it.internalData() };

		pointers[0]->next = pointer;
		pointer->previous = pointers[0];

		pointers[1]->previous = pointer;
		pointer->next = pointers[1];
	}
}

TEMPLATE_DEFINE
template<typename InputIterator>
void LIST_TYPE::insert(typename LIST_TYPE::Iterator it
		, InputIterator itBegin, InputIterator itEnd)
{
	if (countIterations(itBegin, itEnd))
	{
		Node *pointerHead;
		Node *pointerTail;
		Range<InputIterator> inputRange(itBegin, itEnd);

		bool first = true;
		for (auto object : inputRange)
		{
			if (first)
			{
				pointerHead = allocator.contruct(object);
				pointerTail = pointerHead;
				first = false;
			}
			else
			{
				Node *pointer = allocator.contruct(object);
				pointerTail->next = pointer;
				pointer->previous = pointerTail;

				pointerTail = pointer;
			}
		}

		if (!size())
		{
			head = pointerHead;
			tail = pointerTail;
		}
		else if (it == begin())
		{
			pointerTail->next = head;
			head->previous = pointerTail;
			head = pointerHead;
		}
		else if (it == end())
		{
			pointerHead->previous = tail;
			tail->next = pointerHead;
			tail = pointerTail;
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

TEMPLATE_DEFINE
template<typename ...Args>
void LIST_TYPE::emplace(typename LIST_TYPE::Iterator it, Args &&...args)
{
	Node *pointer = allocator.contruct(forward<Args>(args)...);
	if (!size())
	{
		head = tail = pointer;
	}
	else if (it == begin())
	{
		pointer->next = head;
		head->previous = pointer;
		head = pointer;
	}
	else if (it == end())
	{
		tail->next = pointer;
		pointer->previous = tail;
		tail = pointer;
	}
	else
	{
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

		allocator.destroy(pointer);
	}
}

TEMPLATE_DEFINE
void LIST_TYPE::popFront()
{
	if (head->next)
	{
		auto pointer = head;
		head = head->next;

		allocator.destroy(pointer);
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
}

}}

#undef TEMPLATE_DEFINE
#undef LIST_TYPE

#endif // TEMPLATES_LIST_HPP
