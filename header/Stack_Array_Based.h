#pragma once

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'

template <class type>
class Stack_Array_Based
{
    int size{};
    type *arr{};
    int top{};

public:
    Stack_Array_Based(int sz);
    ~Stack_Array_Based();
    bool is_full();
    bool is_empty();
    void push(type val);
    type pop();
    type peek();
    void print();
    string reverse_subwords(string line);
    int reverse_num(int num);
    char get_open_match(char ch);
    bool valid_parentheses(string str);
    string remove_all_adjacent_duplicates(string str);
    void asteroid_collision(vector<type> &asteroids);
    void insert_at_bottom(type val);
    void reverse();
};
