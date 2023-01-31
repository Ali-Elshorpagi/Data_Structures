#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class T>
struct D_Node
{
    T data{};
    D_Node *next{};
    D_Node *prev{};
    D_Node(T data) : data(data) {}
    void set(D_Node *next, D_Node *prev)
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
    unsigned long long length = 0;
    vector<D_Node<type> *> debug_data;
    void add_node(D_Node<type> *node);
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
    void print();
	void print_reversed();







};
