#ifndef TEST_H
#define TEST_H

namespace flame_ide
{

class Test
{
public:
	Test();
	~Test();
	
	struct Actions
	{
		bool success;
		
		void all();
		
		void TCodeParcer();
		void TCommandLine();
	} actions;
	
	struct Bus
	{
		bool success;

		void all();
		
		void TMsgInterface();
	} bus;
	
	struct Store
	{
		bool success;
		
		void all();
		
		void TFile();
		void TProject();
		void TSession();
	} store;
	
	void all();
};
	
}

#endif // TEST_H
