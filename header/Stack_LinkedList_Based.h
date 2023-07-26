#ifndef STACK_LINKEDLIST_BASED_H
#define STACK_LINKEDLIST_BASED_H

#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

template <class T>
struct SDL_Node
{
    T data{};
    SDL_Node<T> *next{};
    SDL_Node(T val) : data(val) {}
};

template <class type>
class Stack_LinkedList_Based
{
    SDL_Node<type> *head{};
    int size{};

public:
    Stack_LinkedList_Based();
    ~Stack_LinkedList_Based();
    const int get_size();
    type is_empty();
    void push(type val);
    type pop();
    type peek();
    void print();
};
#endif