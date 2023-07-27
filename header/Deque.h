#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cassert>

#define edl '\n'

template <class type>
class Deque
{
    int size{};
    int front{};
    int rear{};
    int added_elements{};
    type *array{};
    int next(int pos);
    int prev(int pos);

public:
    Deque(int size);
    ~Deque();
    const int get_size();
    void enqueue_rear(type val);
    void enqueue_front(type val);
    type dequeue_front();
    type dequeue_rear();
    int is_empty();
    bool is_full();
    void print();
};
#endif