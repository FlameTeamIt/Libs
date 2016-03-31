#ifndef JSON_H
#define JSON_H

#include <Templates/Pointers.h>
#include <Templates/String.h>
#include <Templates/Array.h>
#include <Templates/List.h>

namespace flame_ide
{namespace JSON
{

typedef enum
{
	ERROR = 101,
	SINGLE = 1,
	PAIR = 0,
	ARRAY = 10,
	OBJECT = 100
} Type;

class Data;           
class DataContainer;  

class Single;  
class Pair;    
class Array;   
class Object;  

class Document; 

typedef UniquePointer<DataContainer>  UPDataContainer;
typedef UniquePointer<Data>           UPData;

typedef UniquePointer<Single>		  UPSingle;
typedef UniquePointer<Pair>           UPPair;
typedef UniquePointer<Array>          UPArray;
typedef UniquePointer<Object>         UPObject;

typedef UniquePointer<Document>       UPDocument;


typedef SharedPointer<DataContainer>  SPDataContainer;
typedef SharedPointer<Data>           SPData;

typedef SharedPointer<Single>		  SPSingle;
typedef SharedPointer<Pair>           SPPair;
typedef SharedPointer<Array>          SPArray;
typedef SharedPointer<Object>         SPObject;

typedef SharedPointer<Document>       SPDocument;

}}

/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Data.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_DataContainer.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Single.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Pair.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Array.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Object.h>
/* ------------------------------------------------------------ */
#include <Analysers/JSON/JSON_Document.h>
/* ------------------------------------------------------------ */

#endif // JSON_H
