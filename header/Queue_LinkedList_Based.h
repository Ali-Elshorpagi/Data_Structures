#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include "Singly_LinkedList.h"
#include "../source/Singly_LinkedList.cpp"

template <class type>
class Queue_LinkedList_Based
{
    Singly_LinkedList<type> list;
    int size{};

public:
    Queue_LinkedList_Based();
    ~Queue_LinkedList_Based();
    const int get_size();
    bool is_empty();
    void enqueue(type val);
    type dequeue();
    void print();
};
#endif