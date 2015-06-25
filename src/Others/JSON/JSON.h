#ifndef JSON_H
#define JSON_H

#include <string>

#include "../Templates/Array.h"
#include "../Templates/List.h"

namespace flame_ide
{namespace JSON
{

typedef enum
{
	ERROR = -1,
	SINGLE = 1,
	PAIR = 0,
	ARRAY = 10,
	OBJECT = 100
} Type;

class Data;
class DataContainer;

class Single;

struct Pair;

class Array;
class Object;

/* ------------------------------------------------------------ */

class Data
{
	bool is_single;
	bool is_array;
	bool is_object;
	
	bool is_container;
	
	unsigned int type;

protected:
	mutable bool is_initialize;
	
	mutable unsigned long level; // глубина записи
	mutable std::string str_level;
	
	static Type getDataType(const std::string &json_string);
public:
	Data();
	Data(bool is_object_type
		 ,bool is_array_type
		 ,bool is_single_type);
	
	virtual ~Data();
	
	void          setLevel(const unsigned long &new_level) const;
	unsigned long getLevel() const;
	
	bool isObject() const;
	bool isArray() const;
	bool isSingle() const;
	bool isPair() const;
	
	bool isContainer() const;
	
	bool isInitialize() const;
	
	unsigned int getType() const;
	
	static Data* getData(const std::string &json_string);

	virtual Data* getCopy() const = 0;
		
	virtual std::string getAsString() const = 0;
	virtual void        setAsString(const std::string&) = 0;
	
#ifdef FUTURE
	static templates::Array<std::string> splitStrings(const std::string& json_string);
	static Data* parseString(const std::string& json_string);
#endif
};

class DataContainer
		: public Data
{
protected:
	static templates::Array<std::string> split(const std::string &json_container);
	
	virtual void set(const Data* data) = 0;
	
public:
	DataContainer(const bool& is_object_type
				  ,const bool& is_array_type);
	
	virtual void pushBack(const Data *data) = 0;
	virtual void pushFront(const Data *data) = 0;
	
	virtual void insert(const size_t &index, const Data *data) = 0;
	virtual void insert(const size_t &index, const size_t &count, const Data **data) = 0;
	
	virtual void popBack() = 0;
	virtual void popFront() = 0;
	
	virtual void erase(const size_t &index) = 0;
	virtual void erase(const size_t &index, const size_t &count) = 0;
	
	virtual void clear() = 0;
	
	~DataContainer();
};

class Single
		: public Data
{
	std::string str_data;
	
public:
	Single();
	Single(const Data *data);
	Single(const Single &single);
	Single(const std::string& value);
	
	~Single();
	
	const Single & operator=(const Single& single);
	
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
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string& single);
	
};

class Pair
		: public Data
{
	Data* inc_data;
public:
	std::string key;
	
	Pair();
	Pair(const std::string &json_pair);
	Pair(const Pair &pair);
	Pair(const Data* data);
	Pair(const std::string &json_key, const Data *data);
	Pair(const char* key, const Data *data);
	
	~Pair();
	
	Data* getData() const;
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string& json_pair);
	
	const Pair& operator=(const Pair& pair);
};

class Array
		: public DataContainer
{
	templates::Array<Data*> inc_arr;
	
protected:
	void set(const Data *data);
	void set(const Array &array);
	
public:
	Array();
	Array(const Data *data);
	Array(const Array &array);
	Array(const std::string &json_array);
	
	~Array();
	
	Data* operator[](const size_t &index);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	void pushBack(const Data *data);
	void pushFront(const Data *data);
	
	void insert(const size_t &index, const Data *data);
	void insert(const size_t &index, const size_t &count, const Data **data);
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_array);
};

class Object
		: public DataContainer
{
	templates::Array<Pair*> inc_arr;
protected:
	void set(const Data *data);
	void set(const Object &object);
	
public:
	Object();
	Object(const Data *data);
	Object(const Object &object);
	Object(const std::string& json_object);
	
	~Object();
	
#ifdef FUTURE // пока думаю, как с этим быть
	Data* operator [](const std::string &str_index) const;
	Data* operator [](const char *c_str_index) const;
#endif
	Data* operator [](const size_t &index);
	
	const Object & operator=(const Object& object);
	
	void   setSize(const size_t &new_size);
	size_t getSize();
	
	void pushBack(const Data *data);
	void pushFront(const Data *data);
	void pushBack(const std::string &key, const Data *data);
	void pushFront(const std::string &key, const Data *data);
	
	void insert(const size_t &index, const Data *data);
	void insert(const size_t &index, const size_t &count, const Data **data);
	
#ifdef FUTURE // пока думаю, как с этим быть
	void insert(const size_t &index, const Pair *pair);
	void insert(const size_t &index, const size_t &count, const Pair **pairs);
#endif
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_object);
};

}}

#endif // JSON_H
