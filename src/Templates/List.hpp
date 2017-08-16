#ifndef TEMPLATES_LIST
#define TEMPLATES_LIST

#include <Templates/Utils.hpp>
#include <Templates/Iterator.hpp>

namespace flame_ide
{ namespace templates
{

template<typename T, typename Traits = ContainerTraits<T>>
class List
{
public:


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
		Iterator &operator++() const;

		Iterator &operator--();
		Iterator operator--(int) const;
		Iterator &operator--() const;

	private:
		Node *node;
	};

	using ReverseIterator = flame_ide::templates::ReverseIterator<Iterator, Traits>;

private:
	Node *head;
	Node *tail;
};

}}

#endif // TEMPLATES_LIST
