#ifndef SPARSE_ARRAY_H
#define SPARSE_ARRAY_H

#include <iostream>
#include <cassert>

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
class Sparse_Array
{
    Col_Node<type> *head{};
    Col_Node<type> *tail{};
    int length{};
    int cols{};

    void link(Col_Node<type> *first, Col_Node<type> *second);
    Col_Node<type> *add_node_between_node_and_next(Col_Node<type> *node_before, type data, int col);
    Col_Node<type> *get_col(int col, bool is_create_if_missing);

public:
    Sparse_Array(int cols);
    ~Sparse_Array();
    void print_row();
    void print_row_nonzero();
    void set_value(type data, int col);
    type get_value(int col);
    void add(Sparse_Array<type> &other);
};
#endif