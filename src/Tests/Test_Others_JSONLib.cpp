#include <iostream>
#include "Test.h"
#include "../Others/TextStyle.h"

#include "../Others/JSON/JSON.h"

#include "../Store/BasicFile.h"

using namespace flame_ide;

void
Test::Others::JSONLib::all()
{
	using namespace JSON;
	std::cout << "Test::Others::JSONLib::all()\n";
	
	this->count_success_tests =
			this->Single() + this->Pair()
			+ this->Array() + this->Object();
	
	// stress test
//	BasicFile basic_file("BigJSON.json");
//	std::string str_json = basic_file.load();
//	if(str_json.length() != 0)
//	{
//		std::cout << "File loaded\n";
//		Data* data = Data::getData(str_json);
		
//		std::cin.get();
		
//		str_json.clear();
		
//		std::cin.get();
		
//		if(data->getType() == JSON::ARRAY)
//		{
//			JSON::Array* json_array = static_cast<JSON::Array*>(data);
//			std::cout << "Size of array: " << json_array->getSize() << '\n';
//		}
//		std::cout << "OUTPUT test file :\n";
//				  << data->getAsString() << '\n';
//		delete data;
//	}
	
	std::cout << '\n';
}

unsigned int
Test::Others::JSONLib::Single()
{
	std::cout << "Test::Others::JSONLib::Single()\n";
	
	JSON::Single single;
	std::string json_single("   \"Start\"   ");
	
	std::cout << "INPUT (Single) : _"
			  << json_single << "_\n";
	
	single.setAsString(json_single);
	
	std::cout << "OUTPUT (Single) : _"
			  << single.getAsString() << "_\n\n";
	
	return 1;
}

unsigned int
Test::Others::JSONLib::Pair()
{
	std::cout << "Test::Others::JSONLib::Pair()\n";
	
	std::string json_pair_single("\"Start\":\"Start\"");
	
	std::cout << "INPUT (Pair-Single) :\n"
			  << json_pair_single << "\n\n";
	
	pair.setAsString(json_pair_single);
	
	std::cout << "OUTPUT (Pair-Single) :\n"
			  << pair.getAsString() << "\n\n";
	
	return 1;
}

unsigned int
Test::Others::JSONLib::Array()
{
	std::cout << "Test::Others::JSONLib::Array()\n";
	
	std::string json_array_single("[   \"Start\"  ,  \"Stop\"  ]");
	
	std::cout << "INPUT (Array-Single) :\n"
			  << json_array_single << "\n\n";
	
	array.setAsString(json_array_single);
	
	std::cout << "OUTPUT (Array-Single) :\n"
			  << array.getAsString() << "\n\n";
	
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
	
	return 1;
}

unsigned int
Test::Others::JSONLib::Object()
{
	std::cout << "Test::Others::JSONLib::Object()\n";
	
	std::string json_object_pair_single("{\"Start\":\"Start\",\"Stop\":\"Stop\"}");
	
	std::cout << "INPUT (Object-Single) :\n"
			  << json_object_pair_single << "\n\n";
	
	object.setAsString(json_object_pair_single);
	
	std::cout << "OUTPUT (Object-Single) :\n"
			  << object.getAsString() << "\n\n";
	
	std::cout << TEXT_STYLE_YELLOW
			  << "Test finctions for Object:\n\n"
			  << TEXT_STYLE_NULL;

	JSON::Array array1;
	array1.pushBack(&single);
	array1.pushBack(&pair);
	array1.pushBack(&array);
	array1.pushBack(&object);

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
	JSON::Pair pair1(std::string("Object3"), &array1);
	object1.insert(size_t(1), (JSON::Data*)&pair1);
	std::cout << "OUTPUT insert(index) (Object) :\n"
			  << "Pair: " << pair1.getAsString() << '\n'
			  << object1.getAsString() << "\n\n";
	//2
	JSON::Single single1(std::string("\"Something4\"")), single2(std::string("10000"));
	JSON::Pair pair2(std::string("Object3"), &single2);
	JSON::Pair pair3("Object4", &single1);
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
	
	return 1;
}
