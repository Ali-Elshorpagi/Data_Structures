#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
#define edl '\n'

template <class T>
struct D_Node
{
    T data{};
    D_Node<T> *next{};
    D_Node<T> *prev{};
    D_Node(T data) : data(data) {}
    void set(D_Node<T> *next, D_Node<T> *prev)
    {
        this->next = next;
        this->prev = prev;
    }
    // ~D_Node() { cout << "Destroy value: " << data << " at address " << this << edl; }
};

template <class type>
class Doubly_LinkedList
{
    D_Node<type> *head{};
    D_Node<type> *tail{};
    int length{};

    void delete_node(D_Node<type> *node);
    void link(D_Node<type> *first, D_Node<type> *second);
    void add_node_between_node_and_next(D_Node<type> *node_before, type val);
    D_Node<type> *delete_and_link(D_Node<type> *cur);
    void delete_and_link_v2(D_Node<type> *cur);

public:
    Doubly_LinkedList();
    ~Doubly_LinkedList();
    Doubly_LinkedList(const Doubly_LinkedList &) = delete;
    Doubly_LinkedList &operator=(const Doubly_LinkedList &another) = delete;
    void insert_end(type val);
    void insert_front(type val);
    void insert_sorted(type val);
    void print();
    void print_reversed();
    void delete_front();
    void delete_end();
    void delete_node_with_key(type val);
    void delete_all_nodes_with_key(type val);
    void delete_even_positions();
    void delete_odd_positions();
    bool is_palindrome();
    type middle_value_0();
    type middle_value_1();
    void reverse();
};
#endif