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
	
	ArrayBlocks<long> & get_blocks() {return _blocks;}
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
	ArrayBlocks<long> __empty_blocks;
	
public:
	typedef arrblocks_constructs_empty this_type;
	
	arrblocks_constructs_empty();
	arrblocks_constructs_empty(const arrblocks_constructs_empty &) = delete;
	arrblocks_constructs_empty(arrblocks_constructs_empty &&) = delete;
	
	~arrblocks_constructs_empty();
protected:
	virtual int _start();
};


class arrblocks_constructs_front_adding : public virtual_arrblocks_test<void>
{
	ArrayBlocks<long> __front_adding_blocks;
	
public:
	typedef arrblocks_constructs_front_adding this_type;
	
	arrblocks_constructs_front_adding();
	arrblocks_constructs_front_adding(const this_type &) = delete;
	arrblocks_constructs_front_adding(this_type &&) = delete;
	
	~arrblocks_constructs_front_adding();
protected:
	virtual int _start();
};


class arrblocks_constructs_back_adding : public virtual_arrblocks_test<void>
{
	ArrayBlocks<long> __back_adding_blocks;
	
public:
	typedef arrblocks_constructs_back_adding this_type;
	
	arrblocks_constructs_back_adding();
	arrblocks_constructs_back_adding(const this_type &) = delete;
	arrblocks_constructs_back_adding(this_type &&) = delete;
	
	~arrblocks_constructs_back_adding();
	
protected:
	virtual int _start();
};




class arrblocks_push_back : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_push_back this_type;
	
	arrblocks_push_back() = delete;
	arrblocks_push_back(const this_type &) = delete;
	arrblocks_push_back(this_type &&) = delete;
	
	arrblocks_push_back(ArrayBlocks<long> & blocks);
	
	~arrblocks_push_back();
	
protected:
	virtual int _start();
};


class arrblocks_pop_back : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_pop_back this_type;
	
	arrblocks_pop_back() = delete;
	arrblocks_pop_back(const this_type &) = delete;
	arrblocks_pop_back(this_type &&) = delete;
	
	arrblocks_pop_back(ArrayBlocks<long> & blocks);
	
	~arrblocks_pop_back();
	
protected:
	virtual int _start();
};




class arrblocks_push_front : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_push_front this_type;
	
	arrblocks_push_front() = delete;
	arrblocks_push_front(const this_type &) = delete;
	arrblocks_push_front(this_type &&) = delete;
	
	arrblocks_push_front(ArrayBlocks<long> & blocks);
	
	~arrblocks_push_front();
	
protected:
	virtual int _start();
};


class arrblocks_pop_front : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_pop_front this_type;
	
	arrblocks_pop_front() = delete;
	arrblocks_pop_front(const this_type &) = delete;
	arrblocks_pop_front(this_type &&) = delete;
	
	arrblocks_pop_front(ArrayBlocks<long> & blocks);
	
	~arrblocks_pop_front();
	
protected:
	virtual int _start();
};




class arrblocks_insert : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_insert this_type;
	
	arrblocks_insert() = delete;
	arrblocks_insert(const this_type &) = delete;
	arrblocks_insert(this_type &&) = delete;
	
	arrblocks_insert(ArrayBlocks<long> & blocks);
	
	~arrblocks_insert();
	
protected:
	virtual int _start();
};


class arrblocks_insert_range : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_insert_range this_type;
	
	arrblocks_insert_range() = delete;
	arrblocks_insert_range(const this_type &) = delete;
	arrblocks_insert_range(this_type &&) = delete;
	
	arrblocks_insert_range(ArrayBlocks<long> & blocks);
	
	~arrblocks_insert_range();
	
protected:
	virtual int _start();
};




class arrblocks_erase : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_erase this_type;
	
	arrblocks_erase() = delete;
	arrblocks_erase(const this_type &) = delete;
	arrblocks_erase(this_type &&) = delete;
	
	arrblocks_erase(ArrayBlocks<long> & blocks);
	
	~arrblocks_erase();
	
protected:
	virtual int _start();
};


class arrblocks_erase_range : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_erase_range this_type;
	
	arrblocks_erase_range() = delete;
	arrblocks_erase_range(const this_type &) = delete;
	arrblocks_erase_range(this_type &&) = delete;
	
	arrblocks_erase_range(ArrayBlocks<long> & blocks);
	
	~arrblocks_erase_range();
	
protected:
	virtual int _start();
};




class arrblocks_clearing : public virtual_arrblocks_test<void>
{
public:
	typedef arrblocks_clearing this_type;
	
	arrblocks_clearing() = delete;
	arrblocks_clearing(const this_type &) = delete;
	arrblocks_clearing(this_type &&) = delete;
	
	arrblocks_clearing(ArrayBlocks<long> & blocks);
	
	~arrblocks_clearing();		
	
protected:
	virtual int _start();
};


#endif // TEMPLATES_ARRAYBLOCKS_H
