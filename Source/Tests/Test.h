#ifndef TEST_H
#define TEST_H

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{

class Test
{
public:
	Test();
	~Test();
	
	struct Base
	{
		bool success;
		unsigned int count_success_tests;
		
		virtual void all() = 0;
	};
	
	struct Analyzers : Base
	{
		void all();
		
		unsigned int CodeParcer();
		unsigned int CommandLine();
		
		struct JSONLib : Base
		{
			void all();
			
			JSON::Single single;
			JSON::Pair pair;
			JSON::Array array;
			JSON::Object object;
			
			unsigned int Single();
			unsigned int Pair();
			unsigned int Array();
			unsigned int Object();
			
		} json_lib;
		
	} analyzers;
	
	struct Bus : Base
	{
		void all();
		
		unsigned int MsgInterface();
	} bus;
	
	struct Filesystem : Base
	{
		void all();
		
		unsigned int BasicFile();
		unsigned int Project();
		unsigned int Session();
	} filesystem;
	
	struct Others : Base
	{
		void all();
		
	} others;
	
	struct Templates : Base
	{
		void all();
		
		unsigned int List();
		unsigned int Array();
		unsigned int String();
		unsigned int SmartPointer();
		
	} templates;

	void all();
};
	
}

#endif // TEST_H
