#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
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
    int left(int pos);
    int right(int pos);
    int parent(int pos);
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void heapify();
    void expand_capacity();

public:
    Max_Heap();
    Max_Heap(const vector<type> &vec);
    ~Max_Heap();
    void push(type val);
    void pop();
    type top();
    int get_size();
    bool is_empty();
};