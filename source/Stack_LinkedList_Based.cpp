#include "..\\header\Stack_LinkedList_Based.h"

template <class type>
Stack_LinkedList_Based<type>::Stack_LinkedList_Based()
{
}

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
    SLL_Node *item = new SLL_Node(val);
    item->next = head;
    head = item;
}

template <class type>
type Stack_LinkedList_Based<type>::pop()
{
    assert(!is_empty());
    type element = head->data;
    SLL_Node *temp = head;
    head = head->next;
    delete temp;
    return element;
}

template <class type>
type Stack_LinkedList_Based<type>::peek()
{
    assert(!is_empty());
    type element = head->data;
    return element;
}

template <class type>
void Stack_LinkedList_Based<type>::print()
{
    for (SLL_Node *cur(head); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}
