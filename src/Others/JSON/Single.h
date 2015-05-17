#ifndef JSON_SINGLE_H
#define JSON_SINGLE_H

#include "Data.h"

namespace flame_ide
{namespace JSON
{

class Single : public Data
{
	std::string str;
	
public:
	Single();
	Single(const std::string &value);
	
	~Single();
	
#ifdef FUTURE
	// future
	int           getInt();
	unsigned int  getUInt();
	
	long          getLong();
	unsigned long getULong();
	
	float         getFloat();
	double        getDouble();
	
	bool          getBool();
	
	bool          isNull();
#endif	
	std::string getAsString();
	void        setAsString(const std::string &single);
	
};

}}

#endif // JSON_SINGLE_H
