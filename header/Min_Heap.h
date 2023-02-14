#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class type>
class Min_Heap
{
    type *array{};
    int size{}, capacity{1000};
    int left(int pos);
    int right(int pos);
    int parent(int pos);
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
public:
    Min_Heap();
    ~Min_Heap();
    void push(type val);
    void pop();
    type top();
    bool is_empty();
};
