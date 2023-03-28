#pragma once

#include "Spare_Array.h"
#include "../source/Spare_Array.cpp"

template <class T>
struct Row_Node
{
    int row;
    Spare_Array<T> list;
    Row_Node<T> *next{};
    Row_Node<T> *prev{};
    Row_Node(int r, int c) : row(r), list(c) {}
};

template <class type>
class Sparse_Matrix
{
    Row_Node<type> *head{};
    Row_Node<type> *tail{};
    int length{};
    int rows{};
    int cols{};

    Row_Node<type> *get_row(int row, bool flag);
    void link(Row_Node<type> *first, Row_Node<type> *second);
    Row_Node<type> *add_node_between_node_and_next(Row_Node<type> *node_before, int row);

public:
    Sparse_Matrix(int rows, int cols);
    ~Sparse_Matrix();
    void set_value(type data, int row, int col);
    type get_value(int row, int col);
    void add(Sparse_Matrix<type> &other);
    void print_matrix();
    void print_matrix_nonzero();
};