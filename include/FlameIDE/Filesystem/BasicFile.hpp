#ifndef FILESYSTEM_BASICFILE_HPP
#define FILESYSTEM_BASICFILE_HPP

#include <string>

namespace flame_ide
{

/*struct FileLoadSettings
{
	bool all;

	bool words;
	bool patition;
	bool symbols;
	bool strings;

	unsigned long partition_size;

};*/

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
			std::string &str_path,
			std::string &str_filename);

	// virtual

	virtual void initialization();

	// normal

public:

	// constructor & destructor

	BasicFile();
	BasicFile(std::string& str_filename);
	BasicFile(const char* str_filename);

	~BasicFile();

	// virtuals

	virtual std::string load();

	virtual void save(const std::string& text);

	// statics

	static unsigned long getSize(const std::string& str_filename);
	static unsigned long getSize(const char* str_filename);

	// normal

	void remove();

	void setName(const std::string& str_filename);
	void setName(const std::string& str_path, const std::string& str_filename);

	void setName(const char* str_filename);
	void setName(const char* str_path, const char* str_filename);

	std::string getName();

	std::string getPath();

	std::string getFullName();

	int getError();

};

}


#endif // FILESYSTEM_BASICFILE_HPP
