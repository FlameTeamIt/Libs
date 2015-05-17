#ifndef JSON_DATA_H
#define JSON_DATA_H

#include <string>

namespace flame_ide
{namespace JSON
{
class Data
{
	bool is_object;
	bool is_array;
	bool is_single;
	
	// 100 -- object
	// 10 -- array
	// 1 -- single
	unsigned char status;
protected:
	
public:
	Data();
	Data(const bool& is_object_type
		 ,const bool& is_array_type
		 ,const bool& is_single_type);
	
	virtual ~Data();
	
	bool isObject();
	bool isArray();
	bool isSingle();
	
	unsigned char getStatus();
	
	virtual std::string getAsString() = 0;
	virtual void        setAsString(const std::string&) = 0;
};
}}
#endif // JSON_DATA_H
