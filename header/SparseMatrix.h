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
    int col{};
    Col_Node *next{};
    Col_Node *prev{};
    Col_Node(T data, int col) : data(data), col(col) {}
};

template <class ty>
class LinkedList
{
private:
    Col_Node<ty> *head{};
    Col_Node<ty> *tail{};
    int length = 0;
    int cols{};
    void link(Col_Node<ty> *first, Col_Node<ty> *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }
    Col_Node<ty> *add_node_between_node_and_next(Col_Node<ty> *node_before, ty data, int col)
    {
        Col_Node<ty> *middle = new Col_Node<ty>(data, col);
        ++length;
        Col_Node<ty> *node_after = node_before->next;
        link(node_before, middle);
        if (!node_after)
            tail = middle;
        else
            link(middle, node_after);
        return middle;
    }
    Col_Node<ty> *get_col(int col, bool is_create_if_missing)
    {
        Col_Node<ty> *prev_col(head);
        while (prev_col->next && prev_col->next->col < col)
            prev_col = prev_col->next;
        bool found = prev_col->next && prev_col->next->col == col;
        if (found)
            return prev_col->next;
        if (!is_create_if_missing)
            return nullptr;
        return add_node_between_node_and_next(prev_col, 0, col);
    }

public:
    LinkedList(int cols) : cols(cols)
    {
        tail = head = new Col_Node<ty>(0, -1);
        ++length;
    }

    void print_row()
    {
        Col_Node<ty> *cur(head->next);
        for (int c(0); c < cols; ++c)
        {
            if (cur && cur->col == c)
            {
                cout << cur->data << ' ';
                cur = cur->next;
            }
            else
                cout << "0 ";
        }
        cout << edl;
    }

    void print_row_nonzero()
    {
        for (Col_Node<ty> *cur = head->next; cur; cur = cur->next)
            cout << cur->data << ' ';
        cout << edl;
    }
    void set_value(int data, int col)
    {
        get_col(col, true)->data = data;
    }

    int get_value(int col)
    {
        Col_Node<ty> *node(get_col(col, false));
        if (!node)
            return 0;
        return node->data;
    }
    void add(LinkedList<ty> &other)
    {
        assert(cols == other.cols);
        for (Col_Node<ty> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
        {
            Col_Node<ty> *this_col = get_col(other_cur->col, true);
            this_col->data += other_cur->data;
        }
    }
};

template <class dt>
struct Row_Node
{
    int row;
    LinkedList<dt> list;
    Row_Node *next{};
    Row_Node *prev{};
    Row_Node(int r, int c) : row(r), list(c) {}
};

template <class type>
class SparseMatrix
{
private:
    Row_Node<type> *head{};
    Row_Node<type> *tail{};
    ll length = 0;
    int rows{};
    int cols{};
    Row_Node<type> *get_row(int row, bool flag);
    void link(Row_Node<type> *first, Row_Node<type> *second);
    Row_Node<type> *add_node_between_node_and_next(Row_Node<type> *node_before, int row);

public:
    SparseMatrix(int rows, int cols);
    ~SparseMatrix();
    void set_value(type data, int row, int col);
    type get_value(int row, int col);
    void add(SparseMatrix<type> &other);
    void print_matrix();
    void print_matrix_nonzero();
};
