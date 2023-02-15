#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'

template <class type>
class Max_Heap
{
    type *array{};
    int size{}, capacity{1000};
    int left(int pos);
    int right(int pos);
    int parent(int pos);
    void heapify_up(int child_pos);
    void heapify_down(int parent_pos);
    void heapify();

public:
    Max_Heap();
    Max_Heap(const vector<type> &vec);
    ~Max_Heap();
    void push(type val);
    void pop();
    type top();
    bool is_empty();
};
