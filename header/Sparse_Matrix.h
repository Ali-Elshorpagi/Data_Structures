#pragma once

#include "Spare_Array.h"
#include "../source/Spare_Array.cpp"

template <class T>
struct Row_Node
{
    ll row;
    Spare_Array<T> list;
    Row_Node *next{};
    Row_Node *prev{};
    Row_Node(int r, int c) : row(r), list(c) {}
};

template <class type>
class Sparse_Matrix
{
    Row_Node<type> *head{};
    Row_Node<type> *tail{};
    ll length = 0;
    ll rows{};
    ll cols{};
    Row_Node<type> *get_row(ll row, bool flag);
    void link(Row_Node<type> *first, Row_Node<type> *second);
    Row_Node<type> *add_node_between_node_and_next(Row_Node<type> *node_before, ll row);

public:
    Sparse_Matrix(ll rows, ll cols);
    ~Sparse_Matrix();
    void set_value(type data, ll row, ll col);
    type get_value(ll row, ll col);
    void add(Sparse_Matrix<type> &other);
    void print_matrix();
    void print_matrix_nonzero();
};
