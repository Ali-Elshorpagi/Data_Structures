#ifndef DOUBLY_LINKEDLIST_CPP
#define DOUBLY_LINKEDLIST_CPP

#include "../header/Doubly_LinkedList.h"

template <class type>
Doubly_LinkedList<type>::Doubly_LinkedList() {}

template <class type>
Doubly_LinkedList<type>::~Doubly_LinkedList()
{
    while (head)
    {
        D_Node<type> *current(head->next);
        delete head;
        head = current;
    }
    head = tail = nullptr;
    length = 0;
}

template <class type>
void Doubly_LinkedList<type>::link(D_Node<type> *first, D_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
void Doubly_LinkedList<type>::add_node_between_node_and_next(D_Node<type> *node_before, type val)
{
    D_Node<type> *middle(new D_Node<type>(val));
    ++length;
    D_Node<type> *node_after(node_before->next);
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
}

template <class type>
void Doubly_LinkedList<type>::delete_node(D_Node<type> *node)
{
    --length;
    delete node;
}

template <class type>
D_Node<type> *Doubly_LinkedList<type>::delete_and_link(D_Node<type> *cur)
{
    D_Node<type> *ret(cur->prev);
    link(cur->prev, cur->next);
    delete_node(cur);
    return ret;
}

template <class type>
void Doubly_LinkedList<type>::delete_and_link_v2(D_Node<type> *cur)
{
    link(cur->prev, cur->next);
    delete_node(cur);
}

template <class type>
const int Doubly_LinkedList<type>::get_length()
{
    return length;
}

template <class type>
const type Doubly_LinkedList<type>::get_value(int idx)
{
    assert(idx >= 0 || idx < length);
    D_Node<type> *cur(head);
    int cur_idx(0);
    while (cur_idx < idx)
        cur = cur->next, ++cur_idx;
    return cur->data;
}

template <class type>
void Doubly_LinkedList<type>::insert_end(type val)
{
    D_Node<type> *item(new D_Node<type>(val));
    ++length;
    if (!head)
        head = tail = item;
    else
    {
        link(tail, item);
        tail = item;
    }
    // tail->next = nullptr; // it depends on the compiler
}

template <class type>
void Doubly_LinkedList<type>::insert_front(type val)
{
    D_Node<type> *item(new D_Node<type>(val));
    ++length;
    if (!head)
        head = tail = item;
    else
    {
        link(item, head);
        head = item;
    }
    // head->prev = nullptr; // it depends on the compiler
}

template <class type>
void Doubly_LinkedList<type>::insert_sorted(type val)
{
    if (!length || val <= head->data)
        insert_front(val);
    else if (tail->data <= val)
        insert_end(val);
    else
    {
        for (D_Node<type> *cur(head); cur; cur = cur->next)
        {
            if (val <= cur->data)
            {
                add_node_between_node_and_next(cur->prev, val);
                break;
            }
        }
    }
}

template <class type>
void Doubly_LinkedList<type>::print()
{
    for (D_Node<type> *cur(head); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}

template <class type>
void Doubly_LinkedList<type>::print_reversed()
{
    for (D_Node<type> *cur(tail); cur; cur = cur->prev)
        cout << cur->data << ' ';
    cout << edl;
}

template <class type>
type Doubly_LinkedList<type>::pop_front()
{
    assert(head);
    type val(head->data);
    D_Node<type> *cur(head->next);
    delete_node(head);
    head = cur;
    if (head)
        head->prev = nullptr;
    else if (!length)
        tail = nullptr;
    return val;
}

template <class type>
type Doubly_LinkedList<type>::pop_back()
{
    assert(head);
    type val(tail->data);
    D_Node<type> *cur(tail->prev);
    delete_node(tail);
    tail = cur;
    if (tail)
        tail->next = nullptr;
    else if (!length)
        head = nullptr;
    return val;
}

template <class type>
void Doubly_LinkedList<type>::delete_node_with_key(type val)
{
    if (!length)
        return;
    if (head->data == val)
        pop_front();
    else
    {
        for (D_Node<type> *cur(head); cur; cur = cur->next)
        {
            if (cur->data == val)
            {
                cur = delete_and_link(cur);
                if (!cur->next)
                    tail = cur;
                break;
            }
        }
    }
}

template <class type>
void Doubly_LinkedList<type>::delete_all_nodes_with_key(type val)
{
    if (!length)
        return;
    insert_front(-val);
    for (D_Node<type> *cur(head); cur;)
    {
        if (cur->data == val)
        {
            cur = delete_and_link(cur);
            if (!cur->next)
                tail = cur;
        }
        else
            cur = cur->next;
    }
    pop_front(); // delete the dummy value;
}

template <class type>
void Doubly_LinkedList<type>::delete_even_positions()
{
    if (length < 2)
        return;
    for (D_Node<type> *cur(head); cur && cur->next; cur = cur->next)
    {
        delete_and_link_v2(cur->next);
        if (!cur->next)
            tail = cur;
    }
}

template <class type>
void Doubly_LinkedList<type>::delete_odd_positions()
{
    insert_front(-1);
    delete_even_positions();
    pop_front(); // delete the dummy value;
}

template <class type>
bool Doubly_LinkedList<type>::is_palindrome()
{
    if (length < 2)
        return true;
    D_Node<type> *start(head), *end(tail);
    int len(length >> 1);
    while (len--)
    {
        if (start->data != end->data)
            return false;
        start = start->next, end = end->prev;
    }
    return true;
}

template <class type>
type Doubly_LinkedList<type>::middle_value_0()
{
    assert(head);
    D_Node<type> *start(head), *end(tail);
    while (start != end && start->next != end)
        start = start->next, end = end->prev;
    return end->data;
}

template <class type>
type Doubly_LinkedList<type>::middle_value_1()
{
    // based on The Tortoise and the Hare Algorithm
    assert(head);
    D_Node<type> *fast(head), *slow(head);
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

template <class type>
void Doubly_LinkedList<type>::reverse()
{
    if (length < 2)
        return;
    D_Node<type> *first(head), *second(head->next);
    while (second)
    {
        D_Node<type> *first_temp(second), *second_temp(second->next);
        link(second, first);
        first = first_temp, second = second_temp;
    }
    swap(head, tail);
    head->prev = tail->next = nullptr;
}
#endif