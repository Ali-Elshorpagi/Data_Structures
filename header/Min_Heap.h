#pragma once

#include <iostream>
#include <cassert>
#include <vector>

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
    void heapify();
    bool is_heap(int parent_pos);

public:
    Min_Heap();
    Min_Heap(const vector<type> &v);
    ~Min_Heap();
    void push(type val);
    void pop();
    type top();
    bool is_empty();
    void print_less_than(type val, int pos = 0);
    bool is_heap_array(type *p, int n);
    void heap_sort_0(type *p, int n);
    void heap_sort_1(type *p, int n);
};
