#ifndef JSON_H
#define JSON_H

#include <Templates/Array.h>
#include <Templates/List.h>
#include <Templates/SmartPointer.h>
//#include <Templates/String.h>

namespace flame_ide
{namespace JSON
{

typedef enum
{
	ERROR = 101,
	SINGLE = 1,
	PAIR = 0,
	ARRAY = 10,
	OBJECT = 100
} Type;

class Data;
class DataContainer;

class Single;

class Pair;

class Array;
class Object;

class Document;

typedef SmartPointer<Data> JsonPointer;
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
	
	virtual void set(const Data* data) = 0;
	
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
	bool isArray()  const;
	bool isSingle() const;
	bool isPair()	const;
	
	bool isContainer() const;
	
	bool isInitialize() const;
	
	unsigned int getType() const;
	
	static Data* getData(const std::string &json_string);

	virtual Data* getCopy() const = 0;
	
	virtual std::string getAsString() const = 0;
	virtual void        setAsString(const std::string&) = 0;
	
	virtual bool isTemporary() const = 0;
	virtual void setTemporary(bool is_temp) const = 0;
};

/* ------------------------------------------------------------ */

class DataContainer
		: public Data
{
protected:
	static templates::List<std::string> split(const std::string &json_container);
	
public:
	DataContainer(const bool& is_object_type
				  ,const bool& is_array_type);
	
	virtual void pushBack(const Data *data) = 0;
	virtual void pushFront(const Data *data) = 0;
	
	virtual void insert(const size_t &index, const Data *data) = 0;
	virtual void insert(const size_t &index, const size_t &count, const Data **data) = 0;
	
	virtual Data* at(const size_t &index) = 0;
	
	virtual void popBack() = 0;
	virtual void popFront() = 0;
	
	virtual void erase(const size_t &index) = 0;
	virtual void erase(const size_t &index, const size_t &count) = 0;
	
	virtual void clear() = 0;
	
	~DataContainer();
};

/* ------------------------------------------------------------ */

class Single
		: public Data
{
	std::string str_data;
	
	mutable bool is_temporary;
	
protected:
	void set(const Data *data);
	void set(const Single &single);
	
public:
	Single();
	Single(const Data *data);
	Single(const Single &single);
	Single(Single&& single);
	Single(const std::string& value);
	
	~Single();
	
	const Single & operator=(const Single& single);
	
#ifdef FUTURE // пока думаю, как с этим быть
	bool          isInt()     const;
	int           getInt()    const;
	unsigned int  getUInt()   const;
	long          getLong()   const;
	unsigned long getULong()  const;
	
	bool          isFloat()   const;
	float         getFloat()  const;
	double        getDouble() const;
	
	bool          isBool()    const;
	bool          getBool()   const;
	
	bool          isNull()    const;
#endif
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string& single);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;	
};

/* ------------------------------------------------------------ */

class Pair
		: public Data
{
	Data* inc_data;
	
protected:
	void set(const Data *data);
	void set(const Pair &pair);
	
public:
	std::string inc_key;
	
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
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;
	
	const Pair& operator=(const Pair& pair);
};

/* ------------------------------------------------------------ */

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
	
	Data* at(const size_t &index);
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_array);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;
};

/* ------------------------------------------------------------ */

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

	inline Data* at(const size_t &index);
#ifdef FUTURE // пока думаю, как с этим быть
	Data* at(const std::string &str_index) const;
	Data* at(const char *c_str_index)      const;
#endif
	
	void popBack();
	void popFront();
	
	void erase(const size_t &index);
	void erase(const size_t &index, const size_t &count);
	
	void clear();
	
	Data* getCopy() const;
	
	std::string getAsString() const;
	void        setAsString(const std::string &json_object);
	
	void setTemporary(bool is_temp = true) const;
	bool isTemporary() const;	
	
	inline Data* operator [](const size_t &index);
#ifdef FUTURE // пока думаю, как с этим быть
	Data* operator [](const std::string &str_index) const;
	Data* operator [](const char *c_str_index)      const;
#endif
};

/* ------------------------------------------------------------ */

class Document
{
	unsigned int type_data;
	
	Data *inc_data;
	DataContainer *inc_data_container;
	
	void set();
	void set(const Document &document);
	
protected:
	void restructing();
	
public:
	Document();
	Document(const Document &document);
	Document(Type type);
	Document(Data *data);
	Document(const Single &single);
	Document(const Pair &pair);
	Document(const Array &array);
	Document(const Object &object);
	
	~Document();
	
	void pushBack(const Data *data);
	void pushBack(const Single &single);
	void pushBack(const Pair &pair);
	void pushBack(const Array &array);
	void pushBack(const Object &object);
	
	void         setType(unsigned int type);
	unsigned int getType();
	
	Data* at(const size_t &index);
#ifdef FUTURE // пока думаю, как с этим быть
	Data* at(const std::string &str_index) const;
	Data* at(const char *c_str_index) const;
#endif
	
	void clear();
	
	bool isTemporary() const;
	void setTemporary(bool is_temp = true) const;
};

}}

#endif // JSON_H
