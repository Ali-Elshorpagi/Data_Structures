#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class T>
struct Col_Node
{
    T data{};
    ll col{};
    Col_Node *next{};
    Col_Node *prev{};
    Col_Node(T data, ll col) : data(data), col(col) {}
};

template <class type>
class Spare_Array
{
    Col_Node<type> *head{};
    Col_Node<type> *tail{};
    ll length = 0;
    ll cols{};
    void link(Col_Node<type> *first, Col_Node<type> *second);
    Col_Node<type> *add_node_between_node_and_next(Col_Node<type> *node_before, type data, ll col);
    Col_Node<type> *get_col(ll col, bool is_create_if_missing);

public:
    Spare_Array(ll cols);
    ~Spare_Array();
    void print_row();
    void print_row_nonzero();
    void set_value(type data, ll col);
    type get_value(ll col);
    void add(Spare_Array<type> &other);
};