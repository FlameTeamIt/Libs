#include <iostream>
#include <functional>

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
	this->count_success_tests = 0
//			+ this->SimpleArray()
//			+ this->Array()
			+ this->Array_MemoryBlock()
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
	
	templates::SimpleArray<long> simple_array1(10), simple_array2;
	
	
// pushBack
	simple_array1.pushBack(10);
	simple_array1.pushBack(5);
	
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array1.pushBack(10);\n"
			   "\t" "simple_array1.pushBack(5);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array1.getSize() = " << simple_array1.getSize() << '\n'
			<< "\t" "simple_array1[0] = "        << simple_array1[0] << '\n'
			<< "\t" "simple_array1[1] = "        << simple_array1[1] << "\n\n";
// rewrite
	simple_array1.rewrite(2, 200);
	simple_array1.rewrite(3, 555);
	
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array1.rewrite(2, 200);\n"
			   "\t" "simple_array1.rewrite(3, 555);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array1.getSize() = " << simple_array1.getSize() << '\n'
			<< "\t" "simple_array1[2] = "        << simple_array1[2] << '\n'
			<< "\t" "simple_array1[3] = "        << simple_array1[3] << '\n';

	simple_array2 = simple_array1;
	simple_array1 = templates::SimpleArray<long>(8);
	std::cout
		<< "\n" "Code:" "\n"
		<< "\t" "simple_array2 = simple_array1;" "\n"
		   "\t" "simple_array1 = templates::SimpleArray<long>(8);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array1.getSize() = "     << simple_array1.getSize() << '\n'
			<< "\t" "simple_array1.getCapacity() = " << simple_array1.getCapacity() << '\n'
			<< "\t" "simple_array2.getSize() = "     << simple_array2.getSize() << '\n';
	
	long array[4] {-64, -82, -55, -39};
	
// insert -- with start & end iterators
	auto returned_insert2 = simple_array2.insert(0, &array[0], &array[4]);
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.insert(0, &array[0], &array[4]);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each(
		&simple_array2[0],
		&simple_array2[simple_array2.getSize()],
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
// popBack
	returned_insert2 = simple_array2.popBack();
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.popBack();"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each(
		&simple_array2[0],
		&simple_array2[simple_array2.getSize()],
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
// popBack - count
	returned_insert2 = simple_array2.popBack(3);
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.popBack(3);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	for(auto it = simple_array2.begin();
			it != simple_array2.end();
			++it)
	{
		std::cout << '\t' << *it << '\n';
	}
	std::cout << '\n';
	
// insert
	returned_insert2 = simple_array2.insert(0, 260);
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.insert(0, 260);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each
	(
		simple_array2.begin(), simple_array2.end(),
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
// insert -- iterator
	returned_insert2 = simple_array2.insert(simple_array2.begin(), 620);
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.insert(simple_array2.begin(), 620);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each
	(
		simple_array2.begin(), simple_array2.end(),
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
	// insert -- reverse iterator
	returned_insert2 = simple_array2.insert(--(simple_array2.rend()), 602);
	std::cout
			<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.insert(--(simple_array2.rend()), 602);"
			<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each
	(
		simple_array2.begin(), simple_array2.end(),
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
	// insert -- reverse iterator
	
	auto rit = simple_array2.rend()-1;
	returned_insert2 = simple_array2.insert(rit, 206);
	std::cout
			<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.insert((simple_array2.rend())-1, 206);"
			<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each
	(
		simple_array2.begin(), simple_array2.end(),
		[](long out)
		{
			std::cout << '\t' << out << '\n';
		}
	);
	std::cout << '\n';
	
// erase
	returned_insert2 = simple_array2.erase(4);
	std::cout
		<< "\n" "Code:" "\n"
			<< "\t" "simple_array2.erase(4);"
		<< "\n" "Result:" "\n"
			<< "\t" "simple_array2.getSize() = " << simple_array2.getSize() << '\n'
			<< "\t" "returned_insert2 = "        << returned_insert2 << '\n';
	
	std::cout << "All values:" "\n";
	std::for_each
	(
		simple_array2.begin(), simple_array2.end(),
		[](long out) {std::cout << '\t' << out << '\n';}
	);
	std::cout << '\n';
	
	std::cout << "\n" "Reverse iterators:" "\n";
	std::for_each
	(
		simple_array2.rbegin(), simple_array2.rend(),
		[](long out) {std::cout << '\t' << out << '\n';}
	);
	
	std::cout << '\n';
	
	return 1;
}

unsigned int
Test::Templates::Array_MemoryBlock()
{
	std::cout << "Test::Templates::Array_MemoryBlock()\n";
	
	MemoryBlock<long> empty_block;
	MemoryBlock<long> back_add_block(10);
	MemoryBlock<long> front_add_block(true, 10);
	
	long test_obj = 0;
	
	std::cout << "default capacity = " << empty_block.getCapacity() << '\n';
	
	
// push_back
	
	// back adding block
	{
		back_add_block.pushBack(test_obj);
		back_add_block.pushBack(1);
		back_add_block.pushBack(2);
		back_add_block.pushBack(3);
		
		std::cout
			<< "Code (back adding block):" "\n"
				<< "\t" "back_add_block.pushBack(test_obj); // test_obj == 0" "\n"
				<< "\t" "back_add_block.pushBack(1);" "\n"
				<< "\t" "back_add_block.pushBack(2);" "\n"
				<< "\t" "back_add_block.pushBack(3);" "\n"
			<< "Result:" "\n"
				<< '\t' << back_add_block[0] << '\n'
				<< '\t' << back_add_block[(size_t)1] << '\n'
				<< '\t' << back_add_block[(size_t)2] << '\n'
				<< '\t' << back_add_block[(size_t)3] << '\n';
		std::cout << '\n';
	}
	
	// front adding block
	{
		front_add_block.pushBack(test_obj);
		front_add_block.pushBack(1);
		front_add_block.pushBack(2);
		front_add_block.pushBack(3);
		
		std::cout
			<< "Code (front adding block):" "\n"
				<< "\t" "front_add_block.pushBack(test_obj); // test_obj == 0" "\n"
				<< "\t" "front_add_block.pushBack(1);" "\n"
				<< "\t" "front_add_block.pushBack(2);" "\n"
				<< "\t" "front_add_block.pushBack(3);" "\n"
			<< "Result:" "\n"
				<< '\t' << front_add_block[0] << '\n'
				<< '\t' << front_add_block[(size_t)1] << '\n'
				<< '\t' << front_add_block[(size_t)2] << '\n'
				<< '\t' << front_add_block[(size_t)3] << '\n';
		std::cout << '\n';
	}
// push_front
	
	// back adding block
	{
		back_add_block.pushFront(test_obj);
		back_add_block.pushFront(-1);
		back_add_block.pushFront(-2);
		back_add_block.pushFront(-3);
		
		std::cout
			<< "Code (back adding block):" "\n"
			   << "\t" "back_add_block.pushFront(-3);" "\n"
			   << "\t" "back_add_block.pushFront(-2);" "\n"
			   << "\t" "back_add_block.pushFront(-1);" "\n"
			   << "\t" "back_add_block.pushFront(test_obj);" "\n"
			<< "Result:" "\n"
				<< '\t' << back_add_block[0] << '\n'
				<< '\t' << back_add_block[(size_t)1] << '\n'
				<< '\t' << back_add_block[(size_t)2] << '\n'
				<< '\t' << back_add_block[(size_t)3] << '\n';
		std::cout << '\n';
		
		std::cout << "All containts (back adding block):" "\n";
	    std::for_each
	    (
		    back_add_block.begin(), back_add_block.end(),
		    [](long out)
		    {
			    std::cout << '\t' << out << '\n';
		    }
	    );
		std::cout << '\n';
	}
	
	// front adding block
	{
		front_add_block.pushFront(test_obj);
		front_add_block.pushFront(-1);
		front_add_block.pushFront(-2);
		front_add_block.pushFront(-3);
		
		std::cout
			<< "Code (front adding block):" "\n"
				<< "\t" "front_add_block.pushFront(-3);" "\n"
				<< "\t" "front_add_block.pushFront(-2);" "\n"
				<< "\t" "front_add_block.pushFront(-1);" "\n"
				<< "\t" "front_add_block.pushFront(test_obj);" "\n"
			<< "Result:" "\n"
				<< '\t' << front_add_block[0] << '\n'
				<< '\t' << front_add_block[(size_t)1] << '\n'
				<< '\t' << front_add_block[(size_t)2] << '\n'
				<< '\t' << front_add_block[(size_t)3] << '\n';
		std::cout << '\n';
		
		std::cout << "All containts (front adding block):" "\n";
		std::for_each
		(
			front_add_block.begin(), front_add_block.end(),
			[](long out)
			{
				std::cout << '\t' << out << '\n';
			}
		);
		std::cout << '\n';
	}
	
// at()
	
	// back adding block
	{
		std::cout
			<< "Code (back adding block):" "\n"
				<< "\t" "back_add_block.at(index)" "\n"
			<< "Result:" "\n";
		for(size_t i = 0, size = back_add_block.getSize(); i < size; ++i)
		{
			std::cout << '\t' << back_add_block.at(i) << '\n';
		}
		std::cout << '\n';
	}
	
	// front adding block
	{
		std::cout
			<< "Code (front adding block):" "\n"
				<< "\t" "front_add_block.at(index)" "\n"
			<< "Result:" "\n";
		for(size_t i = 0, size = front_add_block.getSize(); i < size; ++i)
		{
			std::cout << '\t' << front_add_block.at(i) << '\n';
		}
		std::cout << '\n';
	}
	
// copy constructor
	MemoryBlock<long> copied_block = front_add_block;
		
	
// pop_back
	
	// back adding block
	{
		back_add_block.popBack(2);
		back_add_block.popBack();
		std::cout
			<< "Code (back adding block):" "\n"
				<< "\t" "back_add_block.popBack(2);" "\n"
				<< "\t" "back_add_block.popBack();" "\n"
			<< "Result:" "\n";
		std::for_each
		(
			back_add_block.begin(), back_add_block.end(),
			[](long out)
			{
				std::cout << '\t' << out << '\n';
			}
		);
		std::cout << '\n';
		
	}
	
	// front adding block
	{
		front_add_block.popBack(2);
		front_add_block.popBack();
		std::cout
			<< "Code (front adding block):" "\n"
				<< "\t" "front_add_block.popBack(2);" "\n"
				<< "\t" "front_add_block.popBack();" "\n"
			<< "Result:" "\n";
		std::for_each
		(
			front_add_block.begin(), front_add_block.end(),
			[](long out)
			{
				std::cout << '\t' << out << '\n';
			}
		);
		std::cout << '\n';
		
	}
	
// pop_front
	
	// back adding block
	{
		back_add_block.popFront(2);
		back_add_block.popFront();
		std::cout
			<< "Code (back adding block):" "\n"
				<< "\t" "back_add_block.popFront(2);" "\n"
				<< "\t" "back_add_block.popFront();" "\n"
			<< "Result:" "\n";
		std::for_each
		(
			back_add_block.begin(), back_add_block.end(),
			[](long out)
			{
				std::cout << '\t' << out << '\n';
			}
		);
		std::cout << '\n';
		
	}
	
	// front adding block
	{
		front_add_block.popFront(2);
		front_add_block.popFront();
		std::cout
			<< "Code (front adding block):" "\n"
				<< "\t" "front_add_block.popFront(2);" "\n"
				<< "\t" "front_add_block.popFront();" "\n"
			<< "Result:" "\n";
		std::for_each
		(
			front_add_block.begin(), front_add_block.end(),
			[](long out)
			{
				std::cout << '\t' << out << '\n';
			}
		);
		std::cout << '\n';
		
	}
	
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
