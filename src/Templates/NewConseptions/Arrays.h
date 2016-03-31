#ifndef TEMPLATES_ARRAYS_H
#define TEMPLATES_ARRAYS_H

#include <Templates/For_All.h>

namespace flame_ide
{namespace templates
{namespace containers
{

template<typename T> class ArrayInterface;

template<typename T> class SimpleArray;
template<typename T> class ArrayBlocks;
template<typename T> class Array;

template<typename T> class FrontArray;
template<typename T> class BackArray;

template<typename T> class TString;

template<typename T> class List;

namespace iterators
{

template<class TIterator, class TData> class IteratorInterface;


template<typename T> class SimpleArrayIterator;
template<typename T> class SimpleArrayReverseIterator;

template<typename T> class ArrayBlocksIterator;
template<typename T> class ArrayBlocksReverseIterator;


}

}}}

#endif // TEMPLATES_ARRAYS_H
