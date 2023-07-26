#ifndef SINGLY_LINKEDLIST_CPP
#define SINGLY_LINKEDLIST_CPP

#include "../header/Singly_LinkedList.h"

template <class type>
Singly_LinkedList<type>::Singly_LinkedList() {}

template <class type>
Singly_LinkedList<type>::~Singly_LinkedList()
{
    while (head)
    {
        S_Node<type> *cur(head->next);
        delete head;
        head = cur;
    }
    head = tail = nullptr;
    length = 0;
}

template <class type>
const type Singly_LinkedList<type>::get_value(int idx)
{
    assert(idx >= 0 || idx < length);
    S_Node<type> *cur(head);
    int cur_idx(0);
    while (cur_idx < idx)
        cur = cur->next, ++cur_idx;
    return cur->data;
}

template <class type>
const int Singly_LinkedList<type>::get_length()
{
    return length;
}

template <class type>
void Singly_LinkedList<type>::insert_end(type val)
{
    S_Node<type> *item(new S_Node<type>(val));
    if (!head)
        head = tail = item;
    else
    {
        tail->next = item;
        tail = item;
    }
    // tail->next = nullptr; // it depends on the compiler
    ++length;
}

template <class type>
void Singly_LinkedList<type>::insert_front(type val)
{
    S_Node<type> *item(new S_Node<type>(val));
    ++length;
    item->next = head;
    head = item;
    if (length == 1)
        tail = head;
}

template <class type>
void Singly_LinkedList<type>::insert_after(S_Node<type> *src, S_Node<type> *target)
{
    assert(src && target);
    target->next = src->next;
    src->next = target;
    ++length;
}

template <class type>
void Singly_LinkedList<type>::insert_sorted(type val)
{
    if (!length || head->data >= val)
        insert_front(val);
    else if (tail->data <= val)
        insert_end(val);
    else
    {
        for (S_Node<type> *cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
        {
            if (cur->data >= val)
            {
                S_Node<type> *item(new S_Node<type>(val));
                ++length;
                item->next = prv->next;
                prv->next = item;
                break;
            }
        }
    }
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::find(type val)
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
    {
        if (cur->data == val)
            return cur;
    }
    return nullptr;
}

template <class type>
void Singly_LinkedList<type>::print()
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}

template <class type>
void Singly_LinkedList<type>::print_recr(S_Node<type> *h)
{
    if (!h)
    {
        cout << edl;
        return;
    }
    cout << h->data << ' ';
    print_recr(h->next);
}

template <class type>
void Singly_LinkedList<type>::print_recr_rever(S_Node<type> *h)
{
    if (!h)
    {
        cout << edl;
        return;
    }
    print_recr(h->next);
    cout << h->data << ' ';
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::get_nth(int n)
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
        if (!(--n))
            return cur;
    return nullptr;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::get_nth_from_back(int idx)
{
    if (idx > length)
        return nullptr;
    return get_nth(length - idx + 1);
}

template <class type>
int Singly_LinkedList<type>::search(type val)
{
    int idx(0);
    for (S_Node<type> *cur(head); cur; cur = cur->next, ++idx)
        if (cur->data == val)
            return idx;
    return -1;
}

template <class type>
int Singly_LinkedList<type>::search_improved(type val)
{
    int idx(0);
    S_Node<type> *prv(nullptr);
    for (S_Node<type> *cur(head); cur; cur = cur->next, ++idx)
    {
        if (cur->data == val)
        {
            if (!prv)
                return idx;
            swap(prv->data, cur->data);
            return idx - 1;
        }
        prv = cur;
    }
    return -1;
}

template <class type>
int Singly_LinkedList<type>::search_improved_v2(type val) // commonly used
{
    int idx(0);
    for (S_Node<type> *cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
    {
        if (cur->data == val)
        {
            if (!prv)
                return idx;
            swap(prv->data, cur->data);
            return idx - 1;
        }
        ++idx;
    }
    return -1;
}

template <class type>
bool Singly_LinkedList<type>::is_same(const Singly_LinkedList<type> &list)
{
    if (length != list.length)
        return false;
    S_Node<type> *temp(list.head);
    for (S_Node<type> *cur(head); cur; cur = cur->next)
    {
        if (cur->data != temp->data)
            return false;
        temp = temp->next;
    }
    return true;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::move_and_delete(S_Node<type> *node)
{
    S_Node<type> *tmp(node->next);
    delete_node(node);
    return tmp;
}

template <class type>
void Singly_LinkedList<type>::delete_node(S_Node<type> *node)
{
    --length;
    delete node;
}

template <class type>
type Singly_LinkedList<type>::pop_front()
{
    assert(head);
    S_Node<type> *cur(head);
    type val(cur->data);
    head = head->next;
    delete_node(cur);
    if (!head)
        tail = nullptr;
    return val;
}

template <class type>
type Singly_LinkedList<type>::pop_back()
{
    if (length < 2)
        return pop_front();
    S_Node<type> *previous(get_nth(length - 1));
    type val(tail->data);
    delete_node(tail);
    tail = previous;
    tail->next = nullptr;
    return val;
}

template <class type>
void Singly_LinkedList<type>::delete_nth_node(int n)
{
    if (n < 1 || n > length)
        cout << "Error. No such nth node" << edl;
    else if (n == 1)
        pop_front();
    else
    {
        S_Node<type> *before_nth(get_nth(n - 1));
        S_Node<type> *nth(before_nth->next);
        bool is_tail(nth == tail);
        before_nth->next = nth->next;
        if (is_tail)
            tail = before_nth;
        delete_node(nth);
    }
}

template <class type>
void Singly_LinkedList<type>::delete_next_node(S_Node<type> *node)
{
    S_Node<type> *to_delete(node->next);
    bool is_tail(to_delete == tail);
    node->next = node->next->next;
    delete_node(to_delete);
    if (is_tail)
        tail = node;
}

template <class type>
void Singly_LinkedList<type>::delete_node_with_key(type val)
{
    if (!length)
        cout << "List is Empty" << edl;
    else if (head->data == val)
        pop_front();
    else
    {
        for (S_Node<type> *cur(head), *prev(nullptr); cur; prev = cur, cur = cur->next)
        {
            if (cur->data == val)
            {
                delete_next_node(prev);
                break;
            }
        }
    }
}

template <class type>
void Singly_LinkedList<type>::delete_even_positions()
{
    if (length < 2)
        return;
    for (S_Node<type> *cur(head->next), *prv(head); cur;)
    {
        delete_next_node(prv);
        if (!prv->next)
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
}

template <class type>
void Singly_LinkedList<type>::delete_last_occurrence_not_sorted(type key)
{
    if (!length)
        return;
    S_Node<type> *delete_node(nullptr);
    bool flag(false);
    for (S_Node<type> *cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
    {
        if (cur->data == key)
            flag = true, delete_node = prv;
    }
    if (flag)
    {
        if (delete_node)
            delete_next_node(delete_node);
        else
            pop_front();
    }
}

template <class type>
void Singly_LinkedList<type>::remove_duplicates_not_sorted()
{
    if (length < 2)
        return;

    for (S_Node<type> *cur1(head); cur1; cur1 = cur1->next)
    {
        for (S_Node<type> *cur2(cur1->next), *prv(cur1); cur2;)
        {
            if (cur1->data == cur2->data)
            {
                delete_next_node(prv);
                cur2 = prv->next;
            }
            else
                prv = cur2, cur2 = cur2->next;
        }
    }
}

template <class type>
void Singly_LinkedList<type>::swap_repairs()
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
    {
        if (cur->next)
        {
            swap(cur->data, cur->next->data);
            cur = cur->next;
        }
    }
}

template <class type>
void Singly_LinkedList<type>::reverse()
{
    if (length < 2)
        return;
    S_Node<type> *cur(head), *prev(nullptr), *nxt(nullptr);
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    tail = head;
    head = prev;
    // tail->next = nullptr; // it depends on the compiler
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::get_previous(S_Node<type> *node)
{
    for (S_Node<type> *cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
    {
        if (cur == node)
            return prv;
    }
    return nullptr;
}

template <class type>
void Singly_LinkedList<type>::swap_head_tail()
{
    if (length < 2)
        return;
    S_Node<type> *prv(get_previous(tail));
    tail->next = head->next;
    prv->next = head;
    head->next = nullptr;
    swap(tail, head);
}

template <class type>
void Singly_LinkedList<type>::left_rotate(int key)
{
    key %= length;
    if (!key || length < 2)
        return;
    S_Node<type> *cur(get_nth(key));
    tail->next = head;
    tail = cur;
    head = cur->next;
    tail->next = nullptr;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::move_to_end(S_Node<type> *cur, S_Node<type> *prv)
{
    S_Node<type> *nxt(cur->next);
    tail->next = cur;
    if (prv)
        prv->next = nxt;
    else
        head = nxt;
    tail = cur;
    tail->next = nullptr;
    return nxt;
}

template <class type>
void Singly_LinkedList<type>::move_key_occurance_to_end_not_sorted(type key)
{
    if (length < 2)
        return;
    int len(length);
    for (S_Node<type> *cur(head), *prv(nullptr); len--;)
    {
        if (cur->data == key)
            cur = move_to_end(cur, prv);
        else
            prv = cur, cur = cur->next;
    }
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::max_node(S_Node<type> *h)
{
    if (!h)
        return nullptr;
    else
    {
        S_Node<type> *mx_node(max_node(h->next));
        if (!mx_node || h->data > mx_node->data)
            mx_node = h;
        return mx_node;
    }
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::min_node(S_Node<type> *h)
{
    if (!h)
        return nullptr;
    else
    {
        S_Node<type> *mn_node(min_node(h->next));
        if (!mn_node || h->data < mn_node->data)
            mn_node = h;
        return mn_node;
    }
}

template <class type>
type Singly_LinkedList<type>::max_value()
{
    return max_node(head)->data;
}

template <class type>
type Singly_LinkedList<type>::min_value()
{
    return min_node(head)->data;
}

template <class type>
type Singly_LinkedList<type>::middle_value()
{
    // based on The Tortoise and the Hare Algorithm
    assert(head);
    S_Node<type> *fast(head), *slow(head);
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

template <class type>
void Singly_LinkedList<type>::arrange_odd_pos_even_pos()
{
    if (length < 3)
        return;
    S_Node<type> *first_even(head->next), *cur_odd(head);
    while (cur_odd->next && cur_odd->next->next)
    {
        S_Node<type> *next_even(cur_odd->next);
        // connect odd with odd and even with even
        cur_odd->next = cur_odd->next->next;
        next_even->next = next_even->next->next;
        cur_odd = cur_odd->next;
        // for odd length, tail is changed to last even node
        if (length & 1)
            tail = next_even;
    }
    // connect last odd with the first even
    cur_odd->next = first_even;
}

template <class type>
void Singly_LinkedList<type>::insert_alternate(Singly_LinkedList<type> &other)
{
    if (!other.length)
        return;
    if (!length)
    {
        head = other.head;
        tail = other.tail;
        length = other.length;
    }
    else
    {
        S_Node<type> *his_cur(other.head);
        for (S_Node<type> *my_cur(head); my_cur && his_cur;)
        {
            S_Node<type> *his_cur_next_tmp(his_cur->next);
            insert_after(my_cur, his_cur);
            --other.length;
            his_cur = his_cur_next_tmp;
            if (my_cur == tail)
            {
                tail = other.tail;
                my_cur->next->next = his_cur;
                length += other.length;
                break;
            }
            my_cur = my_cur->next->next;
        }
    }
    other.head = other.tail = nullptr;
    other.length = 0;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::merge_two_lists_iterative(S_Node<type> &head1, S_Node<type> &head2)
{
    S_Node<type> *dummy(new S_Node<type>(-1));
    S_Node<type> *ptr(dummy);
    while (head1 && head2)
    {
        if (head1->data < head2->data)
            ptr->next = head1, head1 = head1->next;
        else
            ptr->next = head2, head2 = head2->next;
        ptr = ptr->next;
    }
    ptr->next = (head1 ? head1 : head2);
    // while (head1)
    //     ptr->next = head1, ptr = ptr->next, head1 = head1->next;
    // while (head2)
    //     ptr->next = head2, ptr = ptr->next, head2 = head2->next;
    return dummy->next;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::merge_two_lists_recursive(S_Node<type> &head1, S_Node<type> &head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    S_Node<type> *ans;
    if (head1->data < head2->data)
        ans = head1, ans->next = merge_two_lists_recursive(head1->next, head2);
    else
        ans = head2, ans->next = merge_two_lists_recursive(head1, head2->next);
    return ans;
}

template <class type>
bool Singly_LinkedList<type>::recursive_check(S_Node<type> *cur_head)
{
    if (cur_head)
    {
        if (!recursive_check(cur_head->next))
            return false;
        if (frontptr->data != cur_head->data)
            return false;
        frontptr = frontptr->next;
    }
    return true;
}

template <class type>
bool Singly_LinkedList<type>::is_palindrome()
{
    // see the slides here
    // https://leetcode.com/problems/palindrome-linked-list/editorial/
    frontptr = head;
    return recursive_check(head);
}
#endif