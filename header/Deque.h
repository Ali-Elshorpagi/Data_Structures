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
    // Prevent copying (Rule of Three)
    Deque(const Deque&) = delete;
    Deque& operator=(const Deque&) = delete;
    int get_size() const;
    void enqueue_rear(type val);
    void enqueue_front(type val);
    type dequeue_front();
    type dequeue_rear();
    bool is_empty() const;
    bool is_full() const;
    void print() const;
};
#endif