#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class T>
struct Col_Node
{
    T data{};
    int col{};
    Col_Node<T> *next{};
    Col_Node<T> *prev{};
    Col_Node(T data, int col) : data(data), col(col) {}
};

template <class type>
class Spare_Array
{
    Col_Node<type> *head{};
    Col_Node<type> *tail{};
    int length = 0;
    int cols{};
    void link(Col_Node<type> *first, Col_Node<type> *second);
    Col_Node<type> *add_node_between_node_and_next(Col_Node<type> *node_before, type data, int col);
    Col_Node<type> *get_col(int col, bool is_create_if_missing);

public:
    Spare_Array(int cols);
    ~Spare_Array();
    void print_row();
    void print_row_nonzero();
    void set_value(type data, int col);
    type get_value(int col);
    void add(Spare_Array<type> &other);
};