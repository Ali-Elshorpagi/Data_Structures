#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>
#include <cassert>

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
    // Prevent copying (Rule of Three)
    Circular_Queue(const Circular_Queue&) = delete;
    Circular_Queue& operator=(const Circular_Queue&) = delete;
    bool is_full() const;
    bool is_empty() const;
    int get_size() const;
    void enqueue(type val);
    type dequeue();
    void print() const;
};
#endif