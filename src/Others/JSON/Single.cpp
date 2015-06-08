#include "JSON.h"

using namespace flame_ide::JSON;

Single::Single()
	: JSON::Data(0, 0, 1), str_data("")
{}

Single::Single(const Data* data)
	: Single()
{
	if(data->getType() == SINGLE)
	{ Single(*((Single*)data)); }
}

Single::Single(const Single& single)
	: Single()
{ this->str_data = single.str_data; }

Single::Single(const std::string& value)
	: Single()
{ setAsString(value); }


Single::~Single() {}

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
	bool start = false;
	bool brace = false;
	bool spaces = false;
	bool end = false;
	
	str_data = "";
	if(json_single.length() > 1)
	{
		for(std::string::const_iterator it = json_single.begin(),
			it_end = json_single.end(), it_prevend = --(json_single.end());
			it != it_end && !end;
			++it)
		{
			// ignoring spaces and other
			if( (*it != ' ') && (*it != '\n') && (*it != '\r')
				&& !brace && !start)
			{
				start = true;
				
				if(*it == '"')
				{
					brace = true;
				}
				else
				{
					str_data += *it;
				}
			}
			else
			if(start) // starting write to sting data
			{
				if(brace)
				{
					
					if(*it == '"')
					{
						end = true;
					}
					else
					{
						str_data += *it;
					}

					
					if(it == it_prevend)
					{
						str_data = "";
						end = true;
					}
				}
				else
				{
					if(*it != '"')
					{
						if( (*it != ' ') && (*it != '\n') && (*it != '\r') )
						{
							if(!spaces)
							{
								str_data += *it;
							}
							else
							{
								str_data = "";
								end = true;
							}
						}
						else
						{
							spaces = true;
						}
					}
					else
					{
						str_data = ""; end = true;
					}
				}
			}
		}
	}
}
