#ifndef STACK_ARRAY_BASED_H
#define STACK_ARRAY_BASED_H

#include <iostream>
#include <cassert>
#include <vector>

#define edl '\n'

template <class type>
class Stack_Array_Based
{
    type *arr{};
    int size{};
    int top{};

public:
    Stack_Array_Based(int sz);
    ~Stack_Array_Based();
    // Prevent copying (Rule of Three)
    Stack_Array_Based(const Stack_Array_Based&) = delete;
    Stack_Array_Based& operator=(const Stack_Array_Based&) = delete;
    int get_size() const;
    bool is_full() const;
    bool is_empty() const;
    void push(type val);
    type pop();
    type peek() const;
    void print() const;
    std::string reverse_subwords(std::string line);
    int reverse_num(int num);
    char get_open_match(char ch);
    bool valid_parentheses(std::string str);
    std::string remove_all_adjacent_duplicates(std::string str);
    void asteroid_collision(std::vector<type> &asteroids);
    void insert_at_bottom(type val);
    void reverse();
};
#endif