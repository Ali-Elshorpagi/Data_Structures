#pragma once

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'
typedef long long ll;

struct SM_Node
{
    int data{};
    int col{};
    SM_Node *next{nullptr};
    SM_Node(int data) : data(data) {}
};

class LinkedList
{
public:
    SM_Node *head;
    SM_Node *tail;
    ll length{};

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList()
    {
        while (head)
        {
            SM_Node *current = head->next;
            delete head;
            head = current;
        }
        head = nullptr;
        tail = nullptr;
    }
    void insert_front(int col, int val)
    {
        SM_Node *item = new SM_Node(val);
        item->col = col;
        ++length;
        item->next = head;
        head = item;
        if (length == 1)
            tail = head;
    }
    void insert_end(int col, int val)
    {
        SM_Node *item = new SM_Node(val);
        item->col = col;
        if (!head)
            head = tail = item;
        else
        {
            tail->next = item;
            tail = item;
        }
        ++length;
    }
    void insert_at_col(int col, int val)
    {
        if (!head || head->col > col)
            insert_front(col, val);
        else if (tail->col < col)
            insert_end(col, val);
        else
        {
            SM_Node *prev(head);
            while (prev->col < col && prev)
            {
                if (prev->next->col > col)
                    break;
                prev = prev->next;
            }
            if (prev->col == col)
                prev->data = val;
            else
            {
                SM_Node *newNode = new SM_Node(val);
                newNode->col = col;
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }
    void insert_row(SM_Node *other)
    {
        while (other)
        {
            insert_end(other->col, other->data);
            other = other->next;
        }
    }
};

class SparseMatrix
{
    LinkedList *list;
    int col{};
    int row{};

public:
    SparseMatrix(int col, int row);
    ~SparseMatrix();
    void set_value(int col, int row, int val);
    void add_sparse_matrix(SparseMatrix &other);
    void print_matrix();
    void print_matrix_nonzero();
};
