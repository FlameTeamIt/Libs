#include <iostream>
#include "Test.h"
#include "../Others/TextStyle.h"

// Others
#include "../Others/Templates/Array.h"
#include "../Others/Templates/List.h"
#include "../Others/Templates/String.h"
#include "../Others/Templates/SmartPointer.h"
#include "../Others/JSON/JSON.h"

#include "../Store/BasicFile.h"

using namespace flame_ide;

void
Test::Others::all()
{
	std::cout << "Test::Others::all()" << '\n';
	this->count_success_tests = this->TList()
								+ this->TArray()
								+ this->TString()
								+ this->TSmartPointer();
	
	json_lib.all();
	
	std::cout << '\n';
}

unsigned int
Test::Others::TList()
{
	std::cout << "Test::Others::TList()" << '\n';
	
	size_t start_count = 4; // начиная с 4-х элементов не течет. Что? (О_о)
	std::cout << "Test::Others::TList()" << '\n';
	int arr[] = {5, 6};
	
	List<int> list(start_count);
	
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
	List<int> list1(list);
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
Test::Others::TString()
{
	std::cout << "Test::Others::TString()" << "\n";
	
	using namespace templates;
	
	String str1("Hello!");
	String str2("Bye!");
	
	str1 += "LOL!"; // нужно описывать оператор в String
	std::cout << str1 << '\n';
	str1 += str2;
	std::cout << str1 << '\n';
	str1 = str2;
	std::cout << str1 << '\n';
	str1 = str1.getSubstr(0, 3);
	std::cout << str1 << '\n';
	
	// work
//	std::cin >> str1;
//	std::cout << str1 << '\n';
	
	return 1;
}

unsigned int
Test::Others::TArray()
{
	using namespace templates;
	
	std::cout << "Test::Others::TArray()\n";
	
	Array<long> array;
	
	array.pushBack(10);
	array.pushBack(9);
	array.pushFront(7);
	array.pushFront(8);
	
	std::cout << "Push:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.popBack();
	array.popFront();
	
	std::cout << "Pop:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.insert(0, 8);
	array.insert(1, 9);
	array.insert(2, 11);
	
	std::cout << "Insert:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.popFront(2);
	array.popBack(1);
	std::cout << "Pop some:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	long test_array1[] = {1, 2};
	long test_array2[] = {101, 102, 103};
	long test_array3[] = {201, 202};
	
	array.insert(0, 2, test_array1);
	array.insert(2, 3, test_array2);
	array.insert(array.getSize(), 2, test_array3);
	std::cout << "Insert array:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
//#ifdef FUTURE
	Array<long> array1(array);
	
	array.erase(0);
	array.erase(2);
	array.erase(4);
	
	std::cout << "Erase:\n";
	for(size_t i = 0; i < array.getSize(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
//#endif
	
//#ifdef FUTURE
	array1.erase(0, 2);
	array1.erase(3, 2);
	array1.erase(1, 2);
	
	std::cout << "Erase some:\n";
	for(size_t i = 0; i < array1.getSize(); i++)
	{
		std::cout << i << ". - " << array1[i] << '\n';
	}
	std::cout << '\n';
	
//#endif
	
	return 1;
}


unsigned int
Test::Others::TSmartPointer()
{
	std::cout << "Test::Others::TSmartPointer()\n";
	SmartPointer<std::string> p_str;
	
	// 1. make
	p_str.make("Hello, world!");
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	// 2. clear
	p_str.clear();
	if(p_str.getPointer() != nullptr)
	{
		return 0;
	}
	
	// 3. using methods +
	// 4. assign
	std::string str("Bye!");
	
	p_str = str;
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	p_str = "Bye Bye!";
	std::cout << "1. * - " << *p_str << '\n'
			  << "2. -> - " << p_str->c_str() << '\n';
	
	return 1;
}
