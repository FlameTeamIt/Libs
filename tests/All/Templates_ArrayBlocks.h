#ifndef TEMPLATES_ARRAYBLOCKS_H
#define TEMPLATES_ARRAYBLOCKS_H

#include "../Test.h"
#include <Templates/ArrayBlocks.h>

void
print_all(ArrayBlocks<long> &blocks);




template<typename T>
class virtual_arrblocks_test : public VirtualTest<void>
{
protected:
	ArrayBlocks<long> & _blocks;
	
public:
	virtual_arrblocks_test() = delete;
	virtual_arrblocks_test(const virtual_arrblocks_test &) = delete;
	virtual_arrblocks_test(virtual_arrblocks_test &&) = delete;
	
	virtual_arrblocks_test(ArrayBlocks<long> & blocks, const char *cstr_name)
	    : VirtualTest<void>(cstr_name)
	      , _blocks(blocks) {}

};




class arrblocks_constructs_empty;
class arrblocks_constructs_back_adding;
class arrblocks_constructs_front_adding;

class arrblocks_push_back;
class arrblocks_pop_back;

class arrblocks_push_front;
class arrblocks_pop_front;

class arrblocks_insert;
class arrblocks_insert_range;

class arrblocks_erase;
class arrblocks_erase_range;

class arrblocks_clearing;




class arrblocks_constructs_empty : public virtual_arrblocks_test<void>
{
public:
	arrblocks_constructs_empty();
	arrblocks_constructs_empty(const virtual_arrblocks_test &) = delete;
	arrblocks_constructs_empty(virtual_arrblocks_test &&) = delete;
	
	~arrblocks_constructs_empty();
protected:
	virtual int _start();
};


class arrblocks_constructs_front_adding : public virtual_arrblocks_test<void>
{
public:
	arrblocks_constructs_front_adding();
	arrblocks_constructs_front_adding(const virtual_arrblocks_test &) = delete;
	arrblocks_constructs_front_adding(virtual_arrblocks_test &&) = delete;
	
	~arrblocks_constructs_front_adding();
protected:
	virtual int _start();
};


class arrblocks_constructs_back_adding : public virtual_arrblocks_test<void>
{
public:
	arrblocks_constructs_back_adding();
	arrblocks_constructs_back_adding(const virtual_arrblocks_test &) = delete;
	arrblocks_constructs_back_adding(virtual_arrblocks_test &&) = delete;
	
	~arrblocks_constructs_back_adding();
	
protected:
	virtual int _start();
};




class arrblocks_push_back : public virtual_arrblocks_test<void>
{
public:
	arrblocks_push_back() = delete;
	arrblocks_push_back(const virtual_arrblocks_test &) = delete;
	arrblocks_push_back(virtual_arrblocks_test &&) = delete;
	
	arrblocks_push_back(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};


class arrblocks_pop_back : public virtual_arrblocks_test<void>
{
public:
	arrblocks_pop_back() = delete;
	arrblocks_pop_back(const virtual_arrblocks_test &) = delete;
	arrblocks_pop_back(virtual_arrblocks_test &&) = delete;
	
	arrblocks_pop_back(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};




class arrblocks_push_front : public virtual_arrblocks_test<void>
{
public:
	arrblocks_push_front() = delete;
	arrblocks_push_front(const virtual_arrblocks_test &) = delete;
	arrblocks_push_front(virtual_arrblocks_test &&) = delete;
	
	arrblocks_push_front(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};


class arrblocks_pop_front : public virtual_arrblocks_test<void>
{
public:
	arrblocks_pop_front() = delete;
	arrblocks_pop_front(const virtual_arrblocks_test &) = delete;
	arrblocks_pop_front(virtual_arrblocks_test &&) = delete;
	
	arrblocks_pop_front(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};




class arrblocks_insert : public virtual_arrblocks_test<void>
{
public:
	arrblocks_insert() = delete;
	arrblocks_insert(const virtual_arrblocks_test &) = delete;
	arrblocks_insert(virtual_arrblocks_test &&) = delete;
	
	arrblocks_insert(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};


class arrblocks_insert_range : public virtual_arrblocks_test<void>
{
public:
	arrblocks_insert_range() = delete;
	arrblocks_insert_range(const virtual_arrblocks_test &) = delete;
	arrblocks_insert_range(virtual_arrblocks_test &&) = delete;
	
	arrblocks_insert_range(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};




class arrblocks_erase : public virtual_arrblocks_test<void>
{
public:
	arrblocks_erase() = delete;
	arrblocks_erase(const virtual_arrblocks_test &) = delete;
	arrblocks_erase(virtual_arrblocks_test &&) = delete;
	
	arrblocks_erase(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};


class arrblocks_erase_range : public virtual_arrblocks_test<void>
{
public:
	arrblocks_erase_range() = delete;
	arrblocks_erase_range(const virtual_arrblocks_test &) = delete;
	arrblocks_erase_range(virtual_arrblocks_test &&) = delete;
	
	arrblocks_erase_range(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};




class arrblocks_clearing : public virtual_arrblocks_test<void>
{
public:
	arrblocks_clearing() = delete;
	arrblocks_clearing(const virtual_arrblocks_test &) = delete;
	arrblocks_clearing(virtual_arrblocks_test &&) = delete;
	
	arrblocks_clearing(ArrayBlocks<long> & blocks);
	
protected:
	virtual int _start();
};


#endif // TEMPLATES_ARRAYBLOCKS_H
