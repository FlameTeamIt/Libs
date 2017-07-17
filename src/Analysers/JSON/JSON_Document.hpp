#ifndef JSON_DOCUMENT
#define JSON_DOCUMENT

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

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

#endif // JSON_DOCUMENT
