#pragma once
#include "Singly_LinkedList.h"
#include "../source/Singly_LinkedList.cpp"

template <class type>
class Queue_LinkedList_Based
{
	Singly_LinkedList<type> list;

public:
	Queue_LinkedList_Based();
	~Queue_LinkedList_Based();
    bool is_empty();
    void enqueue(type val);
    	void dequeue();

};
