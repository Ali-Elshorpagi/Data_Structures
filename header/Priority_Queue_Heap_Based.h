#ifndef PRIORITY_QUEUE_HEAP_BASED_H
#define PRIORITY_QUEUE_HEAP_BASED_H

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class type>
class Priority_Queue_Heap_Based
{
    int capacity{1};
    type *key{};
    type *value{};
    int size{};

    int left(int pos);
    int right(int pos);
    int parent(int pos);
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void expand_capacity();

public:
    Priority_Queue_Heap_Based();
    ~Priority_Queue_Heap_Based();
    bool is_empty();
    void enqueue(type val, int priority);
    type dequeue();
    type top();
};
#endif