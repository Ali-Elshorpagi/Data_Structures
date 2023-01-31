#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class T>
struct S_Node
{
    T data{};
    S_Node *next{};
    S_Node(T data) : data(data) {}
    // ~Node() { cout << "Value Deleted: " << data << " at Address: " << this << '\n'; }
};

template <class type>
class Singly_LinkedList
{
    S_Node<type> *head{};
    S_Node<type> *tail{};
    unsigned long long length = 0;
    vector<S_Node<type> *> debug_data;

public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    Singly_LinkedList<type>(const Singly_LinkedList<type> &) = delete;
    Singly_LinkedList<type> &operator=(const Singly_LinkedList<type> &another) = delete;

    Singly_LinkedList();
    ~Singly_LinkedList();
    S_Node<type>* get_head();
	unsigned long long get_length();
};