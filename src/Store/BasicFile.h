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
	std::string path;
	
	// static
	
	static bool
	parceFullFilename(const std::string& fullfilename,
					  std::string &path,
					  std::string &filename);
	
	// virtual
	
	virtual void initialization();
	
	// normal
	
public:
	
	// constructor & destructor
	
	BasicFile();
	BasicFile(std::string& filename);
	BasicFile(const char* filename);
	
	~BasicFile();

	// virtuals
	
	virtual std::string
	load();
	
	virtual void
	save(const std::string& text);
	
	// statics
	
	static unsigned long
	getSize(const std::string& filename);
	
	static unsigned long
	getSize(const char* filename);
	
	// normal
	
	void
	deleteFile();
	
	void
	setName(const std::string& filename);
	
	void
	setName(const std::string& path, const std::string& filename);
	
	void
	setName(const char* filename);
	
	void
	setName(const char* path, const char* filename);
	
	std::string
	getFileName();
	
	std::string
	getPath();
	
	std::string
	getFullName();
	
	int
	getError();
	
};

}


#endif // FILE_H
