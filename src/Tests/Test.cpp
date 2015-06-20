#include "Test.h"

#include "../Actions/CommandLine.h"
#include "../Actions/CodeParcer.h"

#include "../Bus/MsgInterface.h"

#include "../Store/BasicFile.h"
#include "../Store/Project.h"
#include "../Store/Session.h"

#include "../Others/Templates/Array.h"
#include "../Others/Templates/List.h"
#include "../Others/JSON/JSON.h"

#include "../Others/TextStyle.h"

#include <iostream>

struct Kilobyte
{
	char data[1024];
};

using namespace flame_ide;

Test::Test()
{}

Test::~Test()
{}

void
Test::all()
{
	std::cout << TEXT_STYLE_CYAN << TEXT_STYLE_BOLD
			  << "Test::all()" << TEXT_STYLE_NULL << '\n';
	
	actions.all();
	bus.all();
	store.all();
	
	others.all();
	
	std::cout << '\n';
}

// Actions

void
Test::Actions::all()
{
	std::cout << "Test::Actions::all()\n";
	
	this->TCodeParcer();
	this->TCommandLine();
	
	std::cout << '\n';
}

unsigned int
Test::Actions::TCodeParcer()
{
	std::cout << '\t' << "Test::Actions::TCodeParcer()\n";
	return 1;
}

unsigned int
Test::Actions::TCommandLine()
{
	std::cout << '\t' << "Test::Actions::TCommandLine()\n";
	
	CommandLine commands;
	
#define c_comm "ls -a"
	
	char str[] = c_comm;
	std::string command(str);
	
	std::cout << commands.getOutput(str) << "\n";
	std::cout << commands.getOutput(std::string(str)) << "\n";
	std::cout << commands.getOutput(command) << '\n';
	std::cout << commands.getOutput(c_comm) << '\n';
	
	return 1;
#undef c_comm
}

// Bus

void
Test::Bus::all()
{
	std::cout << "Test::Bus::all()" << '\n';
	count_success_tests = this->TMsgInterface();
	
	std::cout << '\n';
}

unsigned int
Test::Bus::TMsgInterface()
{
	std::cout << '\t' << "Test::Bus::TMsgInterface()" << '\n';
	return 1;
}

// Store

void
Test::Store::all()
{
	std::cout << "Test::Store::all()" << '\n';
	count_success_tests = this->TBasicFile()
						  + this->TProject()
						  + this->TSession();
	std::cout << '\n';
}

unsigned int
Test::Store::TBasicFile()
{
	std::cout << '\t' << "Test::Store::TBasicFile()" << '\n';
	
	BasicFile basic_file("test.txt");
	std::string text("This is test file\n"), out_text;
	
	basic_file.save(text);
	out_text = basic_file.load();
	std::cout << out_text;// << '\n';
	
	basic_file.remove();
	
	basic_file.setName(std::string("/usr/bin/qtcreator.txt"));
	std::cout << basic_file.getFullName() << " | "
			  << basic_file.getPath() << " | "
			  << basic_file.getName() << '\n';
	
	basic_file.setName(std::string("qtcreator.txt"));
	std::cout << basic_file.getFullName() << " | "
			  << basic_file.getPath() << " | "
			  << basic_file.getName() << '\n';
	
	return 1;
}

unsigned int
Test::Store::TProject()
{
	std::cout << "Test::Store::TProject()" << '\n';
	return 1;
}

unsigned int
Test::Store::TSession()
{
	std::cout << '\t' << "Test::Store::TSession()" << '\n';
	return 1;
}

// Others
void
Test::Others::all()
{
	std::cout << "Test::Others::all()" << '\n';
	this->count_success_tests = this->TList()
			+ this->TArray()
			+ this->TJSON();
	
	std::cout << '\n';
}

unsigned int
Test::Others::TList()
{
	std::cout << '\t' << "Test::Others::TList()" << '\n';
	
	size_t start_count = 4; // начиная с 4-х элементов не течет. Что? (О_о)
	std::cout << "Test::Others::TList()" << '\n';
	int arr[] = {5, 6};
	
	List<int> list(start_count);
	
	for(size_t i = 0; i < start_count; i++)
	{ list[i] = i+1; }
	
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
	list1.pushBackArray(2, arr);
	list1.popBack(2);
	
	// добавление массива в начало и его удаление
	list1.pushFrontArray(2, arr);
	list1.popFront(2);
	
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
	array.pushFront(8);
	
	std::cout << "Push:\n";
	for(size_t i = 0; i < array.getLength(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.popBack();
	array.popFront();
	
	std::cout << "Pop:\n";
	for(size_t i = 0; i < array.getLength(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.insert(0, 8);
	array.insert(1, 9);
	array.insert(2, 11);
	
	std::cout << "Insert:\n";
	for(size_t i = 0; i < array.getLength(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	array.popFront(2);
	array.popBack(1);
	std::cout << "Pop some:\n";
	for(size_t i = 0; i < array.getLength(); i++)
	{
		std::cout << i << ". - " << array[i] << '\n';
	}
	std::cout << '\n';
	
	long test_array1[] = {1, 2};
	long test_array2[] = {101, 102, 103};
	long test_array3[] = {201, 202};
	
	array.insert(0, 2, test_array1);
	array.insert(2, 3, test_array2);
	array.insert(array.getLength(), 2, test_array3);
	std::cout << "Insert array:\n";
	for(size_t i = 0; i < array.getLength(); i++)
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
	for(size_t i = 0; i < array.getLength(); i++)
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
	for(size_t i = 0; i < array1.getLength(); i++)
	{
		std::cout << i << ". - " << array1[i] << '\n';
	}
	std::cout << '\n';
	
//#endif
	
	return 1;
}

unsigned int
Test::Others::TJSON()
{
	std::cout << "Test::Others::TJSON()\n";
	
	std::string json_single("   \"Start\"   "),
			json_pair_single("\"Start\":\"Start\""),
			json_array_single("[   \"Start\"  ,  \"Stop\"  ]"),
			json_object_pair_single("{\"Start\":\"Start\",\"Stop\":\"Stop\"}");
	
	JSON::Single single;
	JSON::Pair pair;
	JSON::Array array;
	
	std::cout << "INPUT (Single) : _"
			  << json_single << "_\n";
	
	single.setAsString(json_single);
	
	std::cout << "OUTPUT (Single) : _"
			  << single.getAsString() << "_\n\n";
	
	std::cout << "INPUT (Pair-Single) :\n"
			  << json_pair_single << "\n\n";
	
	pair.setAsString(json_pair_single);
	
	std::cout << "OUTPUT (Pair-Single) :\n"
			  << pair.getAsString() << "\n\n";
	
	std::cout << "INPUT (Array-Single) :\n"
			  << json_array_single << "\n\n";
	
	array.setAsString(json_array_single);
	
	std::cout << "OUTPUT (Array-Single) :\n"
			  << array.getAsString() << "\n\n";
	
	return 1;
}
