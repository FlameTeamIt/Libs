#include "JSON.h"

using namespace flame_ide::JSON;

Document::Document()
{
	set();
}

Document::Document(const Document &document)
{
	set(document);
}

Document::Document(Type type)
{
	switch (type)
	{
	case SINGLE:
		this->inc_data = new Single();
		break;
	case PAIR:
		this->inc_data = new Pair();
		break;
	case ARRAY:
		this->inc_data = new Array();
		break;
	case OBJECT:
		this->inc_data = new Object();
		break;
	default:
		break;
	}
	
	type_data = type;
}

Document::Document(Data *data)
{
	if(data->isTemporary())
	{
		this->inc_data = data;
	}
	else
	{
		this->inc_data = data->getCopy();
	}
	this->type_data = data->getType();
}

Document::Document(const Single &single)
{
	this->inc_data = single.getCopy();
	this->type_data = SINGLE;
}

Document::Document(const Pair &pair)
{
	this->inc_data = pair.getCopy();
	this->type_data = SINGLE;
}

Document::Document(const Array &array)
{
	this->inc_data = array.getCopy();
	this->type_data = SINGLE;
}

Document::Document(const Object &object)
{
	this->inc_data = object.getCopy();
	this->type_data = SINGLE;
}

Document::~Document()
{
	clear();
}

// private

void
Document::set()
{
	type_data = ERROR;
	inc_data = nullptr;
	inc_data_container = nullptr;
}

void
Document::set(const Document &document)
{
	if(document.type_data != ERROR)
	{
		this->type_data = document.type_data;
		
		if(document.inc_data->isTemporary())
		{
			this->inc_data = document.inc_data;
		}
		else
		{
			this->inc_data = document.inc_data->getCopy();
		}
		
		if(inc_data->isContainer())
		{
			inc_data_container = (DataContainer*)inc_data;
		}
	}
}

// public

void
Document::pushBack(const Data *data)
{
	
}

void
Document::pushBack(const Single &single)
{
	
}

void
Document::pushBack(const Pair &pair)
{
	
}

void
Document::pushBack(const Array &array)
{
	
}

void
Document::pushBack(const Object &object)
{
	
}

void
Document::setType(unsigned int type)
{
	if(this->type_data < ARRAY || this->type_data != ERROR)
	{
		this->type_data = type;
	}
	
	// restruct
}

unsigned int
Document::getType()
{
	return type_data;
}

void
Document::clear()
{
	if(inc_data != nullptr)
	{
		delete inc_data;
		
		inc_data = nullptr;
		inc_data_container = nullptr;
		
		type_data = ERROR;
	}
}

void
Document::setTemporary(bool is_temp) const
{
	this->inc_data->setTemporary(is_temp);
}
