#include "JSON.h"

namespace flame_ide
{namespace JSON
{

DataContainer::DataContainer(const bool &is_object_type
							 , const bool &is_array_type)
	: Data(is_object_type, is_array_type, false)
{}

DataContainer::~DataContainer()
{}

}}


