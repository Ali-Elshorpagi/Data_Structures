#ifndef SPARSE_CUBE_H
#define SPARSE_CUBE_H

#include "../source/Sparse_Matrix.cpp"

template <class T>
struct Height_Node
{
    int height;
    Sparse_Matrix<T> matrix;
    Height_Node<T> *next{};
    Height_Node<T> *prev{};
    Height_Node(int h, int r, int c) : height(h), matrix(r, c) {}
};

template <class type>
class Sparse_Cube
{
    Height_Node<type> *head{};
    Height_Node<type> *tail{};
    int length{};
    int rows{};
    int cols{};
    int heights{};

    Height_Node<type> *get_height(int height, bool flag);
    void link(Height_Node<type> *first, Height_Node<type> *second);
    Height_Node<type> *add_node_between_node_and_next(Height_Node<type> *node_before, int height);

public:
    Sparse_Cube(int row, int col, int height);
    ~Sparse_Cube();
    void set_value(type data, int row, int col, int height);
    type get_value(int row, int col, int height);
    void add(Sparse_Cube<type> &other);
    void print_cube();
    void print_cube_nonzero();
};
#endif