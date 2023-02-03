#pragma once

#include "SparseMatrix.h"
#include "../source/SparseMatrix.cpp"

template <class T>
struct Depth_Node
{
    ll depth;
    SparseMatrix<T> matrix;
    Depth_Node *next{};
    Depth_Node *prev{};
    Depth_Node(int d, int r) : depth(d), matrix(r) {}
};

template <class type>
class SpareCube
{
    Depth_Node<type> *head{};
    Depth_Node<type> *tail{};
    ll length = 0;
    ll rows{};
    ll cols{};
    ll depths{};
    Depth_Node<type> *get_depth(ll depth, bool flag);
    void link(Depth_Node<type> *first, Depth_Node<type> *second);
    Depth_Node<type> *add_node_between_node_and_next(Depth_Node<type> *node_before, ll depth);

public:
    SpareCube(int row, int col, int depth);
    ~SpareCube();
};