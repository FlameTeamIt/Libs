#ifndef JSON_SINGLE
#define JSON_SINGLE

#include <Analysers/JSON/JSON.h>

namespace flame_ide
{namespace JSON
{

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

}}

#endif // JSON_SINGLE
