#ifndef TEMPLATES_STRING_TSTRING
#define TEMPLATES_STRING_TSTRING

#include <Templates/Traits.hpp>
#include <Templates/Array.hpp>
#include <Templates/String_Functions.hpp>

namespace flame_ide
{namespace templates
{

template<typename T>
class TString// : public Array<T>
{
	size_t real_size;
protected:
	mutable bool is_actual_hash;

	mutable unsigned long hash;

	void computeHash();
	inline void set(const size_t length, T* arr);

	// присваивание
	void assign(T* c_tstr);
	void assign(const T* c_tstr);
	void assign(const TString<T> &tstring);

	// сложение строк
	void concatenation(T* c_tstr
				       ,bool to_right = true);
	void concatenation(const T* c_tstr
					   ,bool to_right = true);
	void concatenation(const TString<T> &str
					   ,bool to_right = true);

	// сравнение
	bool is_equal(const T* c_tstr) const;
	bool is_equal(const TString<T> &str) const;

	bool is_not_equal(const T* c_tstr) const;
	bool is_not_equal(const TString<T> &str) const;
public:
	TString();
	explicit TString(const size_t &length, const T* &c_tstr);
	explicit TString(const TString<T> &tstring);

	~TString();

	virtual size_t getCStrLength(const T* c_tstr) = 0;
	virtual size_t getCStrLength(const T* c_tstr) const = 0;

	inline const T* getCString() const;

	virtual unsigned long getHash() const = 0;

};

}}

#endif // STRING_TSTRING
