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
	this->count_success_tests = // this->TList()
//								+ this->TArray()
//								+ this->TString()
								+ this->TSmartPointer();
//								+ this->TJSON();
	
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
	std::cout << str1.getSubstr(0, 3) << "\n\n";
	
	str1 = "Hello!";
	str2 = "Bye!";
	
	// str1
	
	std::cout << "str1(\"" << str1 << "\") == \"Hello!\" : ";
	if(str1 == "Hello!")
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	std::cout << "str1(\"" << str1 << "\") == \"He1lo!\" : ";
	if(str1 == "He1lo!")
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str1 += "LOL!";
	std::cout << "str1(\"" << str1 << "\") == \"Hello!\" : ";
	if(str1 == "Hello!")
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
	str1 = "Hello!";
	
	std::cout << "str1(\"" << str1 << "\") != \"Hello!\" : ";
	if(str1 != "Hello!")
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	std::cout << "str1(\"" << str1 << "\") != \"He1lo!\" : ";
	if(str1 != "He1lo!")
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str1 += "LOL!";
	std::cout << "str1(\"" << str1 << "\") != \"Hello!\" : ";
	if(str1 != "Hello!")
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
	// str2
	
	std::cout << "\"Bye!\" == str2(\"" << str2 << "\") : ";
	if("Bye!" == str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	std::cout << "\"Byu!\" == str2(\"" << str2 << "\") : ";
	if("Byu!" == str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str2 += "LOL2!";
	std::cout << "\"Bye!\" == str2(\"" << str2 << "\") : ";
	if("Bye!" == str2)
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
	str2 = "Bye!";
	
	std::cout << "\"Bye!\" != str2(\"" << str2 << "\") : ";
	if("Bye!" != str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	std::cout << "\"Byu!\" != str2(\"" << str2 << "\") : ";
	if("Byu!" != str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str2 += "LOL2!";
	std::cout << "\"Bye!\" != str2(\"" << str2 << "\") : ";
	if("Bye!" != str2)
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
	// str1 and str2
	str1 = str2;
	std::cout << "str1(\"" << str1 << "\") == str2(\"" << str2 << "\") : ";
	if(str1 == str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str1[2] = 'G';
	std::cout << "str1(\"" << str1 << "\") == str2(\"" << str2 << "\") : ";
	if(str1 == str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str2 += "LOLIK!";
	std::cout << "str1(\"" << str1 << "\") == str2(\"" << str2 << "\") : ";
	if(str1 == str2)
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
	str2 = "linux!";
	
	str1 = str2;
	std::cout << "str1(\"" << str1 << "\") != str2(\"" << str2 << "\") : ";
	if(str1 != str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str1[2] = 'G';
	std::cout << "str1(\"" << str1 << "\") != str2(\"" << str2 << "\") : ";
	if(str1 != str2)
	{ std::cout << "true\n"; }
	else
	{ std::cout << "false\n"; }
	
	str2 += "LOLIK!";
	std::cout << "str1(\"" << str1 << "\") != str2(\"" << str2 << "\") : ";
	if(str1 != str2)
	{ std::cout << "true\n\n"; }
	else
	{ std::cout << "false\n\n"; }
	
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
Test::Others::TJSON()
{
	using namespace JSON;
	std::cout << "Test::Others::TJSON()\n";
	
	std::string json_single("   \"Start\"   "),
			json_pair_single("\"Start\":\"Start\""),
			json_array_single("[   \"Start\"  ,  \"Stop\"  ]"),
			json_object_pair_single("{\"Start\":\"Start\",\"Stop\":\"Stop\"}");
	
	JSON::Single single;
	JSON::Pair pair;
	JSON::Array array;
	JSON::Object object;
	
	// Single
	std::cout << "INPUT (Single) : _"
			  << json_single << "_\n";
	
	single.setAsString(json_single);
	
	std::cout << "OUTPUT (Single) : _"
			  << single.getAsString() << "_\n\n";
	
	// Pair-Single
	std::cout << "INPUT (Pair-Single) :\n"
			  << json_pair_single << "\n\n";
	
	pair.setAsString(json_pair_single);
	
	std::cout << "OUTPUT (Pair-Single) :\n"
			  << pair.getAsString() << "\n\n";
	
	// Array-Single
	std::cout << "INPUT (Array-Single) :\n"
			  << json_array_single << "\n\n";
	
	array.setAsString(json_array_single);
	
	std::cout << "OUTPUT (Array-Single) :\n"
			  << array.getAsString() << "\n\n";
	
	// Object-Pair_Single
	std::cout << "INPUT (Object-Single) :\n"
			  << json_object_pair_single << "\n\n";
	
	object.setAsString(json_object_pair_single);
	
	std::cout << "OUTPUT (Object-Single) :\n"
			  << object.getAsString() << "\n\n";
	
	// test finctions for Array
	
	std::cout << TEXT_STYLE_YELLOW
			  << "Test finctions for Array:\n\n"
			  << TEXT_STYLE_NULL;
	// copy constructors
	// 1
	JSON::Array array1(array);
	// 2
	const JSON::Array array2(array1);
	
	std::cout << "OUTPUT copy constructors (Array)\n"
			  << array1.getAsString() << '\n'
			  << array2.getAsString() << "\n\n";
	
	// adding
	// push_back
	// Single
	array1.pushBack(&single);
	std::cout << "OUTPUT push_back(Single) (Array-Single) :\n"
			  << array1.getAsString() << "\n\n";
	// Pair
	array1.pushBack(&pair);
	std::cout << "OUTPUT push_back(Pair) (Array-Single_Pair) :\n"
			  << array1.getAsString() << "\n\n";
	// Array
	array1.pushBack(&array);
	std::cout << "OUTPUT push_back(Array) (Array-Single_Pair_Array) :\n"
			  << array1.getAsString() << "\n\n";
	// Object
	array1.pushBack(&object);
	std::cout << "OUTPUT push_back(Object) (Array-Single_Pair_Array_Object) :\n"
			  << array1.getAsString() << "\n\n";
	
	// -----
	
	array1.clear();
	
	// push_front
	// Single
	array1.pushFront(&single);
	std::cout << "OUTPUT push_front(Single) (Array-Single) :\n"
			  << array1.getAsString() << "\n\n";
	// Pair
	array1.pushFront(&pair);
	std::cout << "OUTPUT push_front(Pair) (Array-Single_Pair) :\n"
			  << array1.getAsString() << "\n\n";
	// Array
	array1.pushFront(&array);
	std::cout << "OUTPUT push_front(Array) (Array-Single_Pair_Array) :\n"
			  << array1.getAsString() << "\n\n";
	// Object
	array1.pushFront(&object);
	std::cout << "OUTPUT push_front(Object) (Array-Single_Pair_Array_Object) :\n"
			  << array1.getAsString() << "\n\n";
	// insert
	// -----
	
	// Array
	array1.insert(1, &array1);
	std::cout << "OUTPUT insert(Array) (Array) :\n"
			  << array1.getAsString() << "\n\n";
	
	// deleting
	// pop_back
	array1.popBack();
	std::cout << "OUTPUT pop_back() (Array) :\n"
			  << array1.getAsString() << "\n\n";
	// pop_front
	array1.popFront();
	std::cout << "OUTPUT pop_front() (Array) :\n"
			  << array1.getAsString() << "\n\n";
	
	// erase
	// 1
	array1.erase(0);
	std::cout << "OUTPUT erase(index) (Array) :\n"
			  << array1.getAsString() << "\n\n";
	
	// 2
	array1.erase(0,2);
	std::cout << "OUTPUT erase(index, count) (Array) :\n"
			  << array1.getAsString() << "\n\n";
	
	std::cout << TEXT_STYLE_YELLOW
			  << "Test finctions for Object:\n\n"
			  << TEXT_STYLE_NULL;

	// copy constructors
	// 1
	JSON::Object object1(object);
	// 2
	const JSON::Object object2(&object1);
	
	std::cout << "OUTPUT copy constructors (Object)\n"
			  << object1.getAsString() << '\n'
			  << object2.getAsString() << "\n\n";
	
	// adding
	// push_back
	object1.pushBack(&pair);
	object1.pushBack(std::string("Object1"), &array);
	std::cout << "OUTPUT push_back (Object) :\n"
			  << object1.getAsString() << "\n\n";
	// push_front
	object1.pushFront(&pair);
	object1.pushFront(std::string("Object2"), &object);
	std::cout << "OUTPUT push_front (Object) :\n"
			  << object1.getAsString() << "\n\n";
	// insert
	// 1
	Pair pair1(std::string("Object3"), &array2);
	object1.insert(size_t(1), (Data*)&pair1);
	std::cout << "OUTPUT insert(index) (Object) :\n"
			  << "Pair: " << pair1.getAsString() << '\n'
			  << object1.getAsString() << "\n\n";
	//2
	Single single1(std::string("\"Something4\"")), single2(std::string("10000"));
	Pair pair2(std::string("Object3"), &single2);
	Pair pair3("Object4", &single1);
	const JSON::Data* pairs[] = {&pair2, &pair3};
	object1.insert(1,2,pairs);
	std::cout << "OUTPUT insert(index) (Object) :\n"
			  << "Pairs: "
			  << pairs[0]->getAsString() << ' '
			  << pairs[1]->getAsString() << '\n'
			  << object1.getAsString() << "\n\n";
	
	// deleting
	// pop_back
	object1.popBack();
	object1.popBack();
	std::cout << "OUTPUT pop_back (Object) :\n"
			  << object1.getAsString() << "\n\n";
	// pop_front
	object1.popFront();
	object1.popFront();
	std::cout << "OUTPUT pop_front (Object) :\n"
			  << object1.getAsString() << "\n\n";
	// erase
	object1.erase(3);
	std::cout << "OUTPUT erase (index) :\n"
			  << object1.getAsString() << "\n\n";
	object1.erase(1,3);
	std::cout << "OUTPUT erase (index, count) :\n"
			  << object1.getAsString() << "\n\n";
	
	BasicFile basic_file("BaltimoreDataBase.json");
	std::string str_json = basic_file.load();
	
	if(str_json.length() != 0)
	{
		std::cout << "File loaded\n";
		
		Data* data = Data::getData(str_json);
//		std::cout << "OUTPUT test file :\n";
//				  << data->getAsString() << '\n';
		
		delete data;
	}
	
	
	return 1;
}

unsigned int
Test::Others::TSmartPointer()
{
	std::cout << "Test::Others::TSmartPointer()\n";
	SmartPointer<std::string> p_str("10");
	
	std::cout << *p_str << '\n';
	
	return 1;
}
