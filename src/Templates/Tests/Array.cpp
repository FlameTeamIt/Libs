/*
 * file:       Array.cpp
 *
 * created:    21.07.2017
 * author:     kachsheev
 */
#include "Array.hpp"

using namespace flame_ide::test;

Array::Array()
{
	using flame_ide::templates::Array;
	using flame_ide::templates::InitializerList;
	// FIXME: I want this!
	Array<int, 10> array({1,2,3,4,5});
}
