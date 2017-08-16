#ifndef TEMPLATES_LIST
#define TEMPLATES_LIST

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>
#include <Templates/Allocator.hpp>

namespace flame_ide
{ namespace templates
{

template<typename T, typename Traits = ContainerTraits<T>
	, typename Allocator = allocator::ObjectAllocator<typename Node, Traits>
>
class List
{
public:
	// TODO: typedefs

	struct Node
	{
		Node() = delete;
		Node(const Node &) = default;
		Node(Node &&) = default;

		template<typename ...Args>
		Node(Node *initPrevious, Node *initNext, Args &&...args);

		Node *previous;
		Node *next;
		T object;
	};

	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(const Iterator &) = default;
		Iterator(Iterator &&) = default;
		~Iterator() = default;
		Iterator &operator=(const Iterator &) = default;
		Iterator &operator=(Iterator &&) = default;

		Iterator &operator++();
		Iterator operator++(int) const;
		const Iterator &operator++() const;

		Iterator &operator--();
		Iterator operator--(int) const;
		const Iterator &operator--() const;

	private:
		Node *node;
	};

	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator, Traits>;

private:
	Node *head;
	Node *tail;
	Allocator<Node> allocator;
};

}}

#endif // TEMPLATES_LIST
