#ifndef FILE_H
#define FILE_H

#include <string>

namespace flame_ide
{

class File
{
	bool loadAll;
	bool loadByString;
	bool loadByWord;
	bool loadBySymbol;

	bool eof;

	int patition_bytes;

	std::string loaded_content;

protected:
	virtual void load();

public:
	File();
	File(std:string&);

	~File();

	void setToLoad(bool loadAll, bool loadByString,
					bool loadByWord, bool loadBySymbol);
	void setPartition(unsigned int partition_bytes);

	static unsigned int getSizeFile(std::string& file);
	static unsigned int getSizeFile(char* file);

	bool endOfFile();

	std::string getLoadedContent();
};

}


#endif // FILE_H
