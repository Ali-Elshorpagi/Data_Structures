#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'

template <class type>
class Min_Heap
{
    type *array{};
    int size{};
    int capacity{1}; // we made capacity trick like vector;
    int left(int pos);
    int right(int pos);
    int parent(int pos);
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void heapify();
    bool is_heap(int parent_pos);
    void expand_capacity();

public:
    Min_Heap();
    Min_Heap(const vector<type> &vec);
    ~Min_Heap();
    void push(type val);
    void pop();
    type top();
    int get_size();
    bool is_empty();
    void print_less_than(type val, int pos = 0);
    bool is_heap_array(type *p, int n);
    void heap_sort(type *p, int n);
};
#endif