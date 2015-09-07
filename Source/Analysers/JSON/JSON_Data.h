#ifndef JSON_DATA
#define JSON_DATA

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

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

}}

#endif // JSON_DATA
