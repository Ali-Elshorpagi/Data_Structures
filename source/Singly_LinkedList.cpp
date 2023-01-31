#include "..\\header\Singly_LinkedList.h"

template <class type>
Singly_LinkedList<type>::Singly_LinkedList() {}

template <class type>
Singly_LinkedList<type>::~Singly_LinkedList()
{
    while (head)
    {
        S_Node<type> *current = head->next;
        delete head;
        head = current;
    }
}

template <class type>
unsigned long long Singly_LinkedList<type>::get_length()
{
    return length;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::get_head()
{
    return head;
}

template <class type>
void Singly_LinkedList<type>::insert_end(type val)
{
    S_Node<type> *item = new S_Node<type>(val);
    if (!head)
        head = tail = item;
    else
    {
        tail->next = item;
        tail = item;
    }
    ++length;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::find(S_Node<type> *head, type val)
{
    for (S_Node<type> *i(head); i; i = i->next)
    {
        if (i->data == val)
            return i;
    }
    return nullptr;
}
