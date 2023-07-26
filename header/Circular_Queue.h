#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class type>
class Circular_Queue
{
    int front{};
    int rear{};
    int size{};
    int added_elements{};
    type *arr{};
    int next(int pos);

public:
    Circular_Queue(int sz);
    ~Circular_Queue();
    bool is_full();
    bool is_empty();
    const int get_size();
    void enqueue(type val);
    type dequeue();
    void print();
};
#endif