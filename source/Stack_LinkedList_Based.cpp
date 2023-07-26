#ifndef STACK_LINKEDLIST_BASED_CPP
#define STACK_LINKEDLIST_BASED_CPP

#include "../header/Stack_LinkedList_Based.h"

template <class type>
Stack_LinkedList_Based<type>::Stack_LinkedList_Based() {}

template <class type>
Stack_LinkedList_Based<type>::~Stack_LinkedList_Based()
{
    while (is_empty())
        pop();
    head = nullptr;
}

template <class type>
const int Stack_LinkedList_Based<type>::get_size()
{
    return size;
}

template <class type>
type Stack_LinkedList_Based<type>::is_empty()
{
    return !head;
}

template <class type>
void Stack_LinkedList_Based<type>::push(type val)
{
    SDL_Node<type> *item(new SDL_Node<type>(val));
    item->next = head;
    head = item;
    ++size;
}

template <class type>
type Stack_LinkedList_Based<type>::pop()
{
    assert(!is_empty());
    type element(head->data);
    SDL_Node<type> *tmp(head);
    head = head->next;
    delete tmp;
    return element;
}

template <class type>
type Stack_LinkedList_Based<type>::peek()
{
    assert(!is_empty());
    return head->data;
}

template <class type>
void Stack_LinkedList_Based<type>::print()
{
    for (SDL_Node<type> *cur(head); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}
#endif