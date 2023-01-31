#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class Stack_LinkedList_Based
{
	struct SLL_Node
	{
		type data{};
		SLL_Node* next{};
		SLL_Node(type val) : data(val) {}
	};
	SLL_Node* head{};
public:
	Stack_LinkedList_Based();
	~Stack_LinkedList_Based();
    type is_empty();
    void push(type val);
	type pop();
	type peek();
};

