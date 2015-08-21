#ifndef TEST_H
#define TEST_H

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
	
	struct Actions : Base
	{
		void all();
		
		unsigned int TCodeParcer();
		unsigned int TCommandLine();
	} actions;
	
	struct Bus : Base
	{
		void all();
		
		unsigned int TMsgInterface();
	} bus;
	
	struct Store : Base
	{
		void all();
		
		unsigned int TBasicFile();
		unsigned int TProject();
		unsigned int TSession();
	} store;
	
	struct Others : Base
	{
		void all();
		
		// тестирование
		// JSON
		// Templates -- Array & List
		
		unsigned int TList();
		unsigned int TArray();
		unsigned int TString();
		
		unsigned int TJSON();
		
	} others;

	void all();
};
	
}

#endif // TEST_H
