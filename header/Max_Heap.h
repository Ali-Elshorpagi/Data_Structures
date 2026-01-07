#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <cassert>
#include <vector>

#define edl '\n'

/*
 * we can build it using min heap by the following:
 *  -1 create an object from Min_Heap;
 *  -2 any element we choose will be multiplied by -1 before being pushed to the Min_heap;
 *  -3 before printing the top, it will be multiplied by -1 to get back the real value;
 */

template <class type>
class Max_Heap
{
    type *array{};
    int size{};
    int capacity{1}; // we made capacity trick like vector;
    int left(int pos) const;
    int right(int pos) const;
    int parent(int pos) const;
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void heapify();
    void expand_capacity();
    bool search_helper(type val, int pos) const;

public:
    Max_Heap();
    Max_Heap(const std::vector<type> &vec);
    ~Max_Heap();
    // Prevent copying (Rule of Three)
    Max_Heap(const Max_Heap &) = delete;
    Max_Heap &operator=(const Max_Heap &) = delete;

    void push(type val);
    void pop();
    type top() const;
    int get_size() const;
    bool is_empty() const;
    bool search(type val) const;
};
#endif