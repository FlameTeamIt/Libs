#ifndef FILE_H
#define FILE_H

#include <string>

namespace flame_ide
{

struct FileLoadSettings
{
	bool all;
	
	bool words;
	bool patition;
	bool symbols;
	bool strings;
	
	unsigned long partition_size;
	
};
	
class BasicFile
{
protected:
	bool eof;
	int error;
	
	std::string filename;
	std::string content_string;

	virtual void initialization();
	
public:
	
	// constructor & destructor
	
	BasicFile();
	BasicFile(std::string&);
	BasicFile(const char*);
	
	~BasicFile();

	// virtuals
	
	virtual std::string load();
	virtual char*       load_c();
	
	virtual void save  (std::string&);
	virtual void save_c(char*);
	
	// statics
	
	static unsigned int getSize(std::string&);
	static unsigned int getSize(char*);
	
	// normal
	
	int getError();
};

}


#endif // FILE_H
