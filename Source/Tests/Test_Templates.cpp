#include <iostream>

#include <Templates/SimpleArray.h>
#include <Templates/Array.h>
#include <Templates/List.h>
#include <Templates/String.h>
#include <Templates/Pointers.h>
#include <Templates/Allocator.h>

#include <Tests/Test.h>

using namespace flame_ide;

void
Test::Templates::all()
{
	this->count_success_tests =
			this->SimpleArray()
//			+ this->Array()
//			+ this->List()
//			+ this->String()
//			+ this->UniquePointer()
//			+ this->SharedPointer()
			;
	
	std::cout << '\n';
}

unsigned int
Test::Templates::SimpleArray()
{
	std::cout << "Test::Templates::SimpleArray()\n";
	
	templates::SimpleArray<long> simple_array1, simple_array2;
	simple_array1.setSize(2);
	
	simple_array1[0] = 10;
	simple_array1[1] = 5;
	
	std::cout << "\nsimple_array1.getSize() = "
		<< simple_array1.getSize() << '\n'
			  << "simple_array1[0] = " << simple_array1[0] << '\n'
			  << "simple_array1[1] = " << simple_array1[1] << "\n";
	
	simple_array1.setSize(4);
	simple_array1.rewrite(2, 200);
	simple_array1.rewrite(3, 555);

	std::cout << "\nsimple_array1.getSize() = "
		<< simple_array1.getSize() << '\n'
			  << "simple_array1[2] = " << simple_array1[2] << '\n'
			  << "simple_array1[3] = " << simple_array1[3] << "\n";

	simple_array1.setSize(3);
	std::cout << "\nsimple_array1.getSize() = "
		<< simple_array1.getSize() << '\n';
	
	simple_array2 = simple_array1;
	simple_array1 = templates::SimpleArray<long>(size_t(8));
	std::cout << "\nsimple_array1.getSize() = "
		<< simple_array1.getSize() << '\n'
		      << "simple_array2.getSize() = "
		<< simple_array2.getSize() << '\n';
	
	std::cout << '\n';
	
	return 1;
}

unsigned int
Test::Templates::List()
{
	std::cout << "Test::Templates::List()" << '\n';
	
	using namespace flame_ide::templates;
	
	size_t start_count = 4; // начиная с 4-х элементов не течет. Что? (О_о)
	int arr[] = {5, 6};
	
	templates::List<int> list(start_count);
	
	for(size_t i = 0; i < start_count; i++)
	{ list[i] = int(i+1); }
	
	if(list[0] != 1 && list[1] != 2)
	{ return 0; }
	
	// добавление по одному элементу в конец и в начало
	list.pushFront(4);
	list.pushBack(1);
	
	// удаление с конца и с начала по элементу
	list.popBack();
	list.popFront();
	
	// вставка и удаление массива
	// в начало
	list.insert((list.begin())--, 2, arr);
	list.erase((list.begin())--, 2);
	
	// в середину
	list.insert(list.begin(), 2, arr);
	list.erase(list.begin(), 2);
	
	// в конец
	list.insert((list.end())--, 2, arr);
	list.erase((list.begin())++, 2);
	
	//добавление элемента в середину и его удаление
	list.insert(list.begin(), arr[0]);
	list.erase(list.begin()++);
	
	// проверка конструктора копирования
	templates::List<int> list1(list);
	list1.popBack(3);
	
	// проверка оператора присваивания
	list1 = list;
	list1.popFront(1);
	
	list1 = list;
	
	// добавление массива в конец и его удаление
	list1.pushBack(2, arr);
	list1.popBack(2);
	
	// добавление массива в начало и его удаление
	list1.pushFront(2, arr);
	list1.popFront(2);
	
	return 1;
}

unsigned int
Test::Templates::String()
{
	std::cout << "Test::Templates::String()" << "\n";
	
//	templates::String str1("Hello!");
//	templates::String str2("Bye!");
	
//	str1 += "LOL!"; // нужно описывать оператор в String
//	std::cout << str1 << '\n';
//	str1 += str2;
//	std::cout << str1 << '\n';
//	str1 = str2;
//	std::cout << str1 << '\n';
//	str1 = str1.getSubstr(0, 3);
//	std::cout << str1 << '\n';
	
	// work
//	std::cin >> str1;
//	std::cout << str1 << '\n';
	
	return 1;
}

unsigned int
Test::Templates::Array()
{
	using namespace templates;
	
	std::cout << "Test::Templates::Array()\n";
	
//	templates::Array<long> array;
	
//	array.pushBack(10);
//	array.pushBack(9);
//	array.pushFront(7);
//	array.pushFront(8);
	
//	std::cout << "Push:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
	
//	array.popBack();
//	array.popFront();
	
//	std::cout << "Pop:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
	
//	array.insert(0, 8);
//	array.insert(1, 9);
//	array.insert(2, 11);
	
//	std::cout << "Insert:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
	
//	array.popFront(2);
//	array.popBack(1);
//	std::cout << "Pop some:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
	
//	long test_array1[] = {1, 2};
//	long test_array2[] = {101, 102, 103};
//	long test_array3[] = {201, 202};
	
//	array.insert(0, 2, test_array1);
//	array.insert(2, 3, test_array2);
//	array.insert(array.getSize(), 2, test_array3);
//	std::cout << "Insert array:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
	
////#ifdef FUTURE
//	templates::Array<long> array1(array);
	
//	array.erase(0);
//	array.erase(2);
//	array.erase(4);
	
//	std::cout << "Erase:\n";
//	for(size_t i = 0; i < array.getSize(); i++)
//	{
//		std::cout << i << ". - " << array[i] << '\n';
//	}
//	std::cout << '\n';
////#endif

////#ifdef FUTURE
//	array1.erase(0, 2);
//	array1.erase(3, 2);
//	array1.erase(1, 2);
	
//	std::cout << "Erase some:\n";
//	for(size_t i = 0; i < array1.getSize(); i++)
//	{
//		std::cout << i << ". - " << array1[i] << '\n';
//	}
//	std::cout << '\n';
////#endif
	
	return 1;
}

unsigned int
Test::Templates::UniquePointer()
{
	std::cout << "Test::Templates::UniquePointer()\n";
	templates::UniquePointer<std::string> p_str, p_str1("LOL!");
	
	// 1. make
	p_str.make("Hello, world!");
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	// 2. clear
	p_str.clear();
	p_str = p_str1;
	std::cout << *p_str << '\n';
	
	// 3. using methods +
	// 4. assign
	std::string str("Bye!");
	
	p_str = str;
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	p_str = templates::make_unique<std::string>("Bye Bye!");
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	return 1;
}

unsigned int
Test::Templates::SharedPointer()
{
	std::cout << "Test::Templates::SharedPointer()\n";
	typedef templates::SharedPointer<std::string> SharedPointerString;
	typedef templates::UniquePointer<std::string> UniquePointerString;
	
	// 1. constructors
	// 1.0 default
	SharedPointerString p_str;
	UniquePointerString up_str(std::string("Unique"));
	
	// 1.1. move
	SharedPointerString p_str1(templates::make_shared<std::string>("Hello!"));
	
	// 1.2. copy
	SharedPointerString p_str2(p_str1);
	
	// 1.3. custom - object
	SharedPointerString p_str3(std::string("Bye-bye!"));
	
	// 2. make
	p_str.make("Lol!");
	
	// 3. clear
	// 3.1. if !first
	p_str2.clear();
	p_str2.make("World");
	
	// 3.2. if first
	p_str1.clear();
	
	// 4. assign
	// 4.1. copy
	p_str = p_str3;
	
	// 4.2. move
	p_str = templates::make_shared<std::string>(*p_str2);
	
	// 4.3. custom - object
	p_str = std::string("Hello, World");
	
	// 4.4. BasicPointer or child
	// p_str = up_str;
	
	p_str.clear();
	p_str1.clear();
	p_str2.clear();
	p_str3.clear();
	
	return 1;
}

unsigned int
Test::Templates::Allocator()
{
	std::cout << "Test::Templates::Allocator()\n";
	return 1;
}
