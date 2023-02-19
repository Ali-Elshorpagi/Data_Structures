#include "..\\header\Stack_LinkedList_Based.h"

template <class type>
Stack_LinkedList_Based<type>::Stack_LinkedList_Based() {}

template <class type>
Stack_LinkedList_Based<type>::~Stack_LinkedList_Based()
{
    while (is_empty())
        pop();
}

template <class type>
type Stack_LinkedList_Based<type>::is_empty()
{
    return !head;
}

template <class type>
void Stack_LinkedList_Based<type>::push(type val)
{
    SDL_Node<type> *item = new SDL_Node<type>(val);
    item->next = head;
    head = item;
}

template <class type>
type Stack_LinkedList_Based<type>::pop()
{
    assert(!is_empty());
    type element(head->data);
    SDL_Node<type> *temp(head);
    head = head->next;
    delete temp;
    return element;
}

template <class type>
type Stack_LinkedList_Based<type>::peek()
{
    assert(!is_empty());
    type element(head->data);
    return element;
}

template <class type>
void Stack_LinkedList_Based<type>::print()
{
    for (SDL_Node<type> *cur(head); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}
