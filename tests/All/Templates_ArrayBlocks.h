#ifndef TEMPLATES_ARRAYBLOCKS_H
#define TEMPLATES_ARRAYBLOCKS_H

#include "../Test.h"
#include <Templates/ArrayBlocks.h>

void
print_all(ArrayBlocks<long> &blocks);




template<typename T>
class abstract_arrblocks_test : public AbstractTest<void>
{
protected:
	ArrayBlocks<long> & _blocks;
	
public:
	abstract_arrblocks_test() = delete;
	abstract_arrblocks_test(const abstract_arrblocks_test &) = delete;
	abstract_arrblocks_test(abstract_arrblocks_test &&) = delete;
	
	abstract_arrblocks_test(ArrayBlocks<long> & blocks, const char *cstr_name)
	    : AbstractTest<void>(cstr_name)
	      , _blocks(blocks) {}
	
	ArrayBlocks<long> & get_blocks() {return _blocks;}
};




class test_arrblocks_constructs_empty;
class test_arrblocks_constructs_back_adding;
class test_arrblocks_constructs_front_adding;

class test_arrblocks_push_back;
class test_arrblocks_pop_back;

class test_arrblocks_push_front;
class test_arrblocks_pop_front;

class test_arrblocks_insert;
class arrblocks_insert_range;

class test_arrblocks_erase;
class test_arrblocks_erase_range;

class test_arrblocks_clearing;




class test_arrblocks_constructs_empty : public abstract_arrblocks_test<void>
{
	ArrayBlocks<long> __empty_blocks;
	
public:
	typedef test_arrblocks_constructs_empty this_type;
	
	test_arrblocks_constructs_empty();
	test_arrblocks_constructs_empty(const test_arrblocks_constructs_empty &) = delete;
	test_arrblocks_constructs_empty(test_arrblocks_constructs_empty &&) = delete;
	
	~test_arrblocks_constructs_empty();
protected:
	virtual int _start();
};


class test_arrblocks_constructs_front_adding : public abstract_arrblocks_test<void>
{
	ArrayBlocks<long> __front_adding_blocks;
	
public:
	typedef test_arrblocks_constructs_front_adding this_type;
	
	test_arrblocks_constructs_front_adding();
	test_arrblocks_constructs_front_adding(const this_type &) = delete;
	test_arrblocks_constructs_front_adding(this_type &&) = delete;
	
	~test_arrblocks_constructs_front_adding();
protected:
	virtual int _start();
};


class test_arrblocks_constructs_back_adding : public abstract_arrblocks_test<void>
{
	ArrayBlocks<long> __back_adding_blocks;
	
public:
	typedef test_arrblocks_constructs_back_adding this_type;
	
	test_arrblocks_constructs_back_adding();
	test_arrblocks_constructs_back_adding(const this_type &) = delete;
	test_arrblocks_constructs_back_adding(this_type &&) = delete;
	
	~test_arrblocks_constructs_back_adding();
	
protected:
	virtual int _start();
};




class test_arrblocks_push_back : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_push_back this_type;
	
	test_arrblocks_push_back() = delete;
	test_arrblocks_push_back(const this_type &) = delete;
	test_arrblocks_push_back(this_type &&) = delete;
	
	test_arrblocks_push_back(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_push_back();
	
protected:
	virtual int _start();
};


class test_arrblocks_pop_back : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_pop_back this_type;
	
	test_arrblocks_pop_back() = delete;
	test_arrblocks_pop_back(const this_type &) = delete;
	test_arrblocks_pop_back(this_type &&) = delete;
	
	test_arrblocks_pop_back(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_pop_back();
	
protected:
	virtual int _start();
};




class test_arrblocks_push_front : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_push_front this_type;
	
	test_arrblocks_push_front() = delete;
	test_arrblocks_push_front(const this_type &) = delete;
	test_arrblocks_push_front(this_type &&) = delete;
	
	test_arrblocks_push_front(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_push_front();
	
protected:
	virtual int _start();
};


class test_arrblocks_pop_front : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_pop_front this_type;
	
	test_arrblocks_pop_front() = delete;
	test_arrblocks_pop_front(const this_type &) = delete;
	test_arrblocks_pop_front(this_type &&) = delete;
	
	test_arrblocks_pop_front(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_pop_front();
	
protected:
	virtual int _start();
};




class test_arrblocks_insert : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_insert this_type;
	
	test_arrblocks_insert() = delete;
	test_arrblocks_insert(const this_type &) = delete;
	test_arrblocks_insert(this_type &&) = delete;
	
	test_arrblocks_insert(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_insert();
	
protected:
	virtual int _start();
};


class arrblocks_insert_range : public abstract_arrblocks_test<void>
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




class test_arrblocks_erase : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_erase this_type;
	
	test_arrblocks_erase() = delete;
	test_arrblocks_erase(const this_type &) = delete;
	test_arrblocks_erase(this_type &&) = delete;
	
	test_arrblocks_erase(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_erase();
	
protected:
	virtual int _start();
};


class test_arrblocks_erase_range : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_erase_range this_type;
	
	test_arrblocks_erase_range() = delete;
	test_arrblocks_erase_range(const this_type &) = delete;
	test_arrblocks_erase_range(this_type &&) = delete;
	
	test_arrblocks_erase_range(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_erase_range();
	
protected:
	virtual int _start();
};




class test_arrblocks_clearing : public abstract_arrblocks_test<void>
{
public:
	typedef test_arrblocks_clearing this_type;
	
	test_arrblocks_clearing() = delete;
	test_arrblocks_clearing(const this_type &) = delete;
	test_arrblocks_clearing(this_type &&) = delete;
	
	test_arrblocks_clearing(ArrayBlocks<long> & blocks);
	
	~test_arrblocks_clearing();		
	
protected:
	virtual int _start();
};


#endif // TEMPLATES_ARRAYBLOCKS_H
