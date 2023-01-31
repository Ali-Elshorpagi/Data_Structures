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

public:
    Doubly_LinkedList();
    ~Doubly_LinkedList();
    Doubly_LinkedList(const Doubly_LinkedList &) = delete;
    Doubly_LinkedList &operator=(const Doubly_LinkedList &another) = delete;
};
