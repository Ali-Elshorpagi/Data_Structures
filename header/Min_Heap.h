#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <cassert>
#include <vector>

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
    Min_Heap(const std::vector<type> &vec);
    ~Min_Heap();
    // Prevent copying (Rule of Three)
    Min_Heap(const Min_Heap&) = delete;
    Min_Heap& operator=(const Min_Heap&) = delete;

    void push(type val);
    void pop();
    type top() const;
    int get_size() const;
    bool is_empty() const;
    void print_less_than(type val, int pos = 0) const;
    bool is_heap_array(type *p, int n);
    void heap_sort(type *p, int n);
    bool search(type val) const;
};
#endif