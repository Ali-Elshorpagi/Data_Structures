#pragma once
#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class type>
class Deque
{
    int size{};
    int front{0};
    int rear{0};
    int added_elements{};
    type *array{};

public:
    Deque(int size);
    ~Deque();
    int next(int pos);
    int prev(int pos);
    void enqueue_rear(type val);
    void enqueue_front(type val);
    type dequeue_front();
    type dequeue_rear();
    int is_empty();
    bool is_full();
    void print();
};
