#pragma once

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

public:
    Stack_LinkedList_Based();
    ~Stack_LinkedList_Based();
    type is_empty();
    void push(type val);
    type pop();
    type peek();
    void print();
};