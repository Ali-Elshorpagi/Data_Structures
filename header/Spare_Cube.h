#pragma once

#include "Sparse_Matrix.h"
#include "../source/Sparse_Matrix.cpp"

template <class T>
struct Depth_Node
{
    int depth;
    Sparse_Matrix<T> matrix;
    Depth_Node<T> *next{};
    Depth_Node<T> *prev{};
    Depth_Node(int d, int r, int c) : depth(d), matrix(r, c) {}
};

template <class type>
class Spare_Cube
{
    Depth_Node<type> *head{};
    Depth_Node<type> *tail{};
    int length = 0;
    int rows{};
    int cols{};
    int depths{};
    Depth_Node<type> *get_depth(int depth, bool flag);
    void link(Depth_Node<type> *first, Depth_Node<type> *second);
    Depth_Node<type> *add_node_between_node_and_next(Depth_Node<type> *node_before, int depth);

public:
    Spare_Cube(int row, int col, int depth);
    ~Spare_Cube();
    void set_value(type data, int row, int col, int depth);
    type get_value(int row, int col, int depth);
    void add(Spare_Cube<type> &other);
    void print_cube();
    void print_cube_nonzero();
};