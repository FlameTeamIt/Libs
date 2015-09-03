#ifndef TEMPLATES_ALLOCATOR
#define TEMPLATES_ALLOCATOR

//#ifdef WITH_CUSTOM_ALLOCATOR

//#if defined(MAX_KBYTES) && !defined(MAX_MBYTES)

//#define MAX_BYTES        MAX_KBYTES*1024
//#define MAX_NODE_SIZE    MAX_BYTES

//#endif

//#if !defined(MAX_KBYTES) && defined(MAX_MBYTES)

//#define MAX_KBYTES       MAX_MBYTES*1024
//#define MAX_BYTES        MAX_KBYTES*1024
//#define MAX_NODE_SIZE    MAX_BYTES

//#endif

//// 16 KBYTES
//#if !defined(MAX_KBYTES) || !defined(MAX_MBYTES)

//#define MAX_KBYTES       16
//#define MAX_BYTES        MAX_KBYTES*1024
//#define MAX_NODE_SIZE    MAX_BYTES

//#endif

//#include <Templates/For_All.h>

//namespace flame_ide
//{namespace templates
//{

//struct Node
//{
//	char data[MAX_NODE_SIZE - 2*sizeof(void*)];
	
//	Node *next;
//	Node *prev;
//};

//class Allocator
//{
//	Node *head;
//	Node *tail;
	
//public:
//	Allocator();
	
//	void* allocate(unsigned long size);
//	void  deallocate(void* pointer, unsigned long size);
	
//	template<class T>
//	void construct(T* t_pointer);
////	template<class T>
////	void construct(T* t_pointer, const T& t_const_ref);
//	template<class T, class ... Ts>
//	void construct(T* t_pointer, Ts ... args);
	
//	template<class T>
//	void destroy(T* t_pointer);
	
//	~Allocator();
//};

//}}

//using namespace flame_ide::templates;

//Allocator::Allocator()
//{
//	head = new Node;
//	head->next = head->prev = nullptr;
//}

//Allocator::~Allocator()
//{
//	while(head != nullptr)
//	{
//		auto tmp_head = head->next;
//		delete head;
		
//		head = tmp_head;
//	}
//}

//// сдвиги указателя
//void*
//Allocator::allocate(unsigned long size)
//{
	
//}

//void
//Allocator::deallocate(void *pointer, unsigned long size)
//{
	
//}

///*

//Есть несколько вещей, с которыми хотел бы разобраться:

//1. Сдвиг указателя -- как нужно хранить информацию о том, где расположено начало объекта?
//2. Стоит ли для всех типов делать один общий аллокатор?
//3. Выделили, а нужно еще очистить. Как? + еще и сдвиги нужно делать.

//Пиздец это, в общем.

//*/

//#undef MAX_NODE_SIZE
//#undef MAX_BYTES
//#undef MAX_KBYTES

//#endif

#endif // ALLOCATOR

