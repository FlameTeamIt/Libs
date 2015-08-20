#ifndef STRING_TSTRING
#define STRING_TSTRING

#include "For_All.h"
#include "Array.h"
#include "String_Functions.h"


namespace flame_ide
{namespace templates
{

template<typename T>
class TString : public Array<T>
{
protected:
	bool is_actual_hash;
	
//	constexpr static T null_string[] = "";
	unsigned long hash;
	
	void computeHash();
	inline void set(const size_t length, T* arr);
	
public:
	TString();
	explicit TString(const size_t &length, const T* &c_tstr);
	explicit TString(const TString<T> &tstring);
	
	~TString();
	
	virtual size_t getCStrLength(const T* c_tstr) const = 0;
	
	inline const T* getCString() const;
	
//	virtual inline unsigned long getHash(const T* c_tstr) = 0;
	
//	inline T& operator [](size_t index);
//	inline const T& operator [](size_t index) const;
	
	// присваивание
	void assign(const T* c_tstr);
	void assign(const TString<T> &tstring);
	
	// сложение строк
	void concatenation(const T* c_tstr
					   ,bool to_right = true);
	void concatenation(const TString<T> &str
					   ,bool to_right = true);
	
	// сравнение
	bool is_equal(const T* c_tstr) const;
	bool is_equal(const TString<T> &str) const;
	
	bool is_not_equal(const T* c_tstr) const;
	bool is_not_equal(const TString<T> &str) const;
};


}}

using namespace flame_ide::templates;

template<typename T>
TString<T>::TString()
	: Array<T>()
{
	this->is_actual_hash = false;
	this->hash = 0;
}

template<typename T>
TString<T>::TString(const size_t& length, const T *&c_tstr)
	: Array<T>(length, c_tstr)
{
	this->is_actual_hash = false;
	this->hash = 0;
}

template<typename T>
TString<T>::TString(const TString<T> &tstring)
	: Array<T>(static_cast<const Array<T>&>(tstring))
{
	if(tstring.is_actual_hash)
	{
		this->is_actual_hash = true;
		this->hash = tstring.hash;
	}
	else
	{
		this->is_actual_hash = false;
		this->hash = 0;
	}
}

template<typename T>
TString<T>::~TString() {}

// а нужно ли оно мне?
// protected

template<typename T>
void
TString<T>::computeHash()
{}

template<typename T>
void
TString<T>::assign(const T *c_tstr)
{
	size_t length_c_tstr = getCStrLength(c_tstr);
	
	if(length_c_tstr)
	{
		this->clear();
		this->inc_arr = array_get_new<T>(length_c_tstr);
		array_copying(length_c_tstr, c_tstr, this->inc_arr);
		
		is_actual_hash = false;
	}
}
template<typename T>
void
TString<T>::assign(const TString<T> &tstring)
{
	if(tstring.getSize())
	{
		this->clear();
		if(tstring.isTemporary())
		{
			this->inc_arr = tstring.inc_arr;
		}
		else
		{
			this->inc_arr = tstring.getPCopy();
		}
		this->arr_size = tstring.arr_size;
		this->is_initialised = true;
		
		if(tstring.is_actual_hash)
		{
			this->hash = tstring.hash;
			this->is_actual_hash = true;
		}
	}
}

template<typename T>
void
TString<T>::concatenation(const T* c_tstr, bool to_right)
{
	size_t length_c_tstr = getCStrLength(c_tstr);
	T* tmp_inc_arr = nullptr;
	if(to_right)
	{
		tmp_inc_arr = string_compose(this->arr_size, this->inc_arr,
								     length_c_tstr, c_tstr);
	}
	else
	{
		tmp_inc_arr = string_compose(length_c_tstr, c_tstr,
									 this->arr_size, this->inc_arr);
	}
	
	if(this->arr_size)
	{
		array_delete<T>(this->inc_arr);
	}
	this->inc_arr = tmp_inc_arr;
	this->arr_size += length_c_tstr;
	this->is_initialised = true;
}
template<typename T>
void
TString<T>::concatenation(const TString<T> &str, bool to_right)
{
	T* tmp_inc_arr;
	if(to_right)
	{
		tmp_inc_arr = string_compose(this->arr_size, this->inc_arr,
									 str.arr_size, str.inc_arr);
	}
	else
	{
		tmp_inc_arr = string_compose(str.arr_size, str.inc_arr,
									 this->arr_size, this->inc_arr);
	}
	
	if(this->arr_size)
	{
		array_delete<T>(this->inc_arr);
	}
	this->inc_arr = tmp_inc_arr;
	this->arr_size += str.arr_size;
	this->is_initialised = true;
}

template<typename T>
bool
TString<T>::is_equal(const T *c_tstr) const
{
	size_t length_c_tstr = getCStrLength(c_tstr);
	bool ret_value = false;
	
	if(length_c_tstr == this->arr_size)
	{
		size_t count_equal = 0;
		for(size_t i = 0; i < this->arr_size; i++)
		{
			if(this->inc_arr[i] == c_tstr[i])
			{
				count_equal++;
			}
			else
			{
				i = this->arr_size;
			}
		}
		
		if(count_equal == this->arr_size)
		{
			ret_value = true;
		}
	}
	
	return ret_value;
}
template<typename T>
bool
TString<T>::is_equal(const TString<T> &str) const
{
	bool ret_value = false;
	
	if(str.getSize() == this->arr_size)
	{
		size_t count_equal = 0;
		for(size_t i = 0; i < this->arr_size; i++)
		{
			if(this->inc_arr[i] == str[i])
			{
				count_equal++;
			}
			else
			{
				i = this->arr_size;
			}
		}
		
		if(count_equal == this->arr_size)
		{
			ret_value = true;
		}
	}
	
	return ret_value;
}

template<typename T>
bool
TString<T>::is_not_equal(const T *c_tstr) const
{
	size_t length_c_tstr = getCStrLength(c_tstr);
	bool ret_value = true;
	
	if(length_c_tstr == this->arr_size)
	{
		size_t count_equal = 0;
		for(size_t i = 0; i < this->arr_size; i++)
		{
			if(this->inc_arr[i] == c_tstr[i])
			{
				count_equal++;
			}
			else
			{
				i = this->arr_size;
			}
		}
		
		if(count_equal == this->arr_size)
		{
			ret_value = false;
		}
	}
	
	return ret_value;
}
template<typename T>
bool
TString<T>::is_not_equal(const TString<T> &str) const
{
	bool ret_value = true;
	
	if(str.getSize() == this->arr_size)
	{
		size_t count_equal = 0;
		for(size_t i = 0; i < this->arr_size; i++)
		{
			if(this->inc_arr[i] == str[i])
			{
				count_equal++;
			}
			else
			{
				i = this->arr_size;
			}
		}
		
		if(count_equal == this->arr_size)
		{
			ret_value = false;
		}
	}
	
	return ret_value;
}

// public

template<typename T>
const T*
TString<T>::getCString() const
{
	return this->inc_arr;
}

#endif // STRING_TSTRING
