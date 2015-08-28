#include "JSON.h"

inline bool is_separator(char ch)
{
	return (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t');
}

using namespace flame_ide::JSON;

Single::Single()
	: JSON::Data(0, 0, 1), str_data("")
{
	is_temporary = false;
}

Single::Single(const Data* data)
	: Single()
{
	set(data);
}

Single::Single(const Single& single)
	: Single()
{
	set(single);
}

Single::Single(const std::string& value)
	: Single()
{ setAsString(value); }

Single::~Single() {}

void
Single::set(const Data *data)
{
	if(data->getType() == SINGLE)
	{
		const Single* single = static_cast<const Single*>(data);
		set(*single);
	}
}

void
Single::set(const Single &single)
{
	this->str_data = single.str_data;
}

const Single &
Single::operator =(const JSON::Single &single)
{
	this->str_data = single.str_data;
	return *this;
}

Data*
Single::getCopy() const
{
	Data *data = new Single(*this);
	return data;
}

std::string
Single::getAsString() const
{ return this->str_data; }

void
Single::setAsString(const std::string &json_single)
{
	if(json_single.length() <= 1)
	{ return; }
		
	bool start = false;
	bool end = false;
	
	size_t pos_start = 0, pos_end = 0;
	unsigned short count_braces = 0;
	
	for(std::string::const_iterator it = json_single.begin(),
		it_end = json_single.end(), it_prevend = --(json_single.end());
		it != it_end && !end;
		++it)
	{
		if(*it == '"')
		{ count_braces++; }
		
		if(!start)
		{
			if(is_separator(*it))
			{
				pos_start++;
			}
			else
			{
				start = true;
				pos_end = pos_start;
			}
		}
		else
		{
			pos_end++;
			if(count_braces == 2)
			{
				end = true;
				pos_end++;
			}
			
			if(count_braces == 0 && is_separator(*it))
			{
				end = true; 
				pos_start = pos_end = 0;
			}
			
			if(it == it_prevend && (count_braces != 2 && count_braces != 0) )
			{
				end = true;
				pos_start = pos_end = 0;
			}
		}
	}
		
	if((!pos_start && !pos_end) && (pos_end < pos_start))
	{ return; }
	
	str_data = json_single.substr(pos_start, pos_end-pos_start);
}

void
Single::setTemporary(bool is_temp) const
{
	this->is_temporary = is_temp;
}

bool
Single::isTemporary() const
{
	return is_temporary;
}
