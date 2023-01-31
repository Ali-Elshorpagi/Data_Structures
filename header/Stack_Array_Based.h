#pragma once

#include <iostream>
#include <cassert>

using namespace std;
typedef long long ll;
#define edl '\n'

template <class type>
class Stack_Array_Based
{
    unsigned long long size{};
    type *arr{};
    ll top{};

public:
    Stack_Array_Based(unsigned long long size);
    ~Stack_Array_Based();
    bool is_full();
    bool is_empty();
    void push(type val);
    type pop();
    type peek();
    void print();
    string reverse_subwords(string line);
ll reverse_num(ll num);
	char get_open_match(char ch);
	bool valid_parentheses(string str);
	string remove_all_adjacent_duplicates(string str);
	void insert_at_bottom(type val);







};
