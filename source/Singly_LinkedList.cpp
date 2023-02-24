#include "..\\header\Singly_LinkedList.h"

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
    head = nullptr;
    tail = nullptr;
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
void Singly_LinkedList<type>::insert_front(type val)
{
    S_Node<type> *item = new S_Node<type>(val);
    ++length;
    item->next = head;
    head = item;
    if (length == 1)
        tail = head;
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
                S_Node<type> *item = (new S_Node<type>(val));
                ++length;
                item->next = prv->next;
                prv->next = item;
                break;
            }
        }
    }
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

template <class type>
void Singly_LinkedList<type>::print()
{
    for (S_Node<type> *i(head); i; i = i->next)
        cout << i->data << ' ';
    cout << edl;
}

template <class type>
void Singly_LinkedList<type>::print_recr(S_Node<type> *h)
{
    if (h == nullptr)
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
    if (h == nullptr)
    {
        cout << edl;
        return;
    }
    print_recr(h->next);
    cout << h->data << ' ';
}

template <class type>
unsigned long long Singly_LinkedList<type>::get_size()
{
    return length;
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::get_nth(int n)
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
        if (--n == 0)
            return cur;
    return nullptr;
}

template <class type>
int Singly_LinkedList<type>::search(type val)
{
    int idx(0);
    for (S_Node<type> *cur(head); cur; cur = cur->next, idx++)
        if (cur->data == val)
            return idx;
    return -1;
}

template <class type>
int Singly_LinkedList<type>::search_improved(type val)
{
    int idx(0);
    S_Node<type> *prv(nullptr);
    for (S_Node<type> *cur(head); cur; cur = cur->next, idx++)
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
S_Node<type> *Singly_LinkedList<type>::get_nth_from_back(int idx)
{
    if (idx > length)
        return nullptr;
    return get_nth(length - idx + 1);
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
    auto it = std::find(debug_data.begin(), debug_data.end(), node);
    if (it != debug_data.end())
    {
        debug_data.erase(it);
        --length;
        delete node;
    }
}

template <class type>
void Singly_LinkedList<type>::delete_first()
{
    if (head)
    {
        S_Node<type> *cur(head);
        head = head->next;
        delete_node(cur);
        if (!head)
            tail = nullptr;
    }
}

template <class type>
void Singly_LinkedList<type>::delete_last()
{
    if (length <= 1)
    {
        delete_first();
        return;
    }
    S_Node<type> *previous(get_nth(length - 1));
    delete_node(tail);
    tail = previous;
    tail->next = nullptr;
}

template <class type>
void Singly_LinkedList<type>::delete_nth_node(int n)
{
    if (n < 1 || n > length)
        cout << "Error. No such nth node" << edl;
    else if (n == 1)
        delete_first();
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
        cout << "list is Empty" << edl;
    else if (head->data == val)
        delete_first();
    else
    {
        for (S_Node<type> *cur(head), *prev = nullptr; cur; prev = cur, cur = cur->next)
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
    if (length <= 1)
        return;
    tail = head;
    S_Node<type> *prv(head);
    head = head->next;
    while (head)
    {
        S_Node<type> *next(head->next);
        head->next = prv;
        prv = head;
        head = next;
    }
    head = prv;
    tail->next = nullptr;
}

template <class type>
void Singly_LinkedList<type>::delete_even_positions()
{
    if (length <= 1)
        return;

    for (S_Node<type> *cur(head->next), *prv = head; cur;)
    {
        delete_next_node(prv);
        if (!prv->next)
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
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
    if (length <= 1)
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
    if (!key || length <= 1)
        return;
    S_Node<type> *cur(get_nth(key));
    tail->next = head;
    tail = cur;
    head = cur->next;
    tail->next = nullptr;
}

template <class type>
void Singly_LinkedList<type>::remove_duplicates_not_sorted()
{
    if (length <= 1)
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
void Singly_LinkedList<type>::delete_last_occurrence_not_sorted(type key)
{
    if (!length)
        return;
    S_Node<type> *delete_node(nullptr);
    bool flag(0);

    for (S_Node<type> *cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
    {
        if (cur->data == key)
            flag = 1, delete_node = prv;
    }
    if (flag)
    {
        if (delete_node)
            delete_next_node(delete_node);
        else
            delete_first();
    }
}

template <class type>
S_Node<type> *Singly_LinkedList<type>::move_to_end(S_Node<type> *cur, S_Node<type> *prv)
{
    S_Node<type> *next(cur->next);
    tail->next = cur;
    if (prv)
        prv->next = next;
    else
        head = next;
    tail = cur;
    tail->next = nullptr;
    return next;
}

template <class type>
void Singly_LinkedList<type>::move_key_occurance_to_end_not_sorted(type key)
{
    if (length <= 1)
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
int Singly_LinkedList<type>::max_node(S_Node<type> *h, S_Node<type> *mx)
{
    if (!length)
        return INT_MIN;
    if (!h)
        return mx->data;
    if (h->data > mx->data)
        mx = h;
    return max_node(h->next, mx);
}

template <class type>
void Singly_LinkedList<type>::arrange_odd_pos_even_pos()
{
    if (length <= 2)
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
        if (length % 2 == 1)
            tail = next_even;
    }
    // connect last odd with the first even
    cur_odd->next = first_even;
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
void Singly_LinkedList<type>::insert_after(S_Node<type> *src, S_Node<type> *target)
{
    assert(src && target);
    target->next = src->next;
    src->next = target;
    ++length;
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
        debug_data = other.debug_data;
    }
    else
    {
        S_Node<type> *cur2(other.head);
        for (S_Node<type> *cur1(head); cur1 && cur2;)
        {
            S_Node<type> *cur2_next_temp(cur2->next);
            insert_after(cur1, cur2);
            --other.length;
            cur2 = cur2_next_temp;
            if (cur1 == tail)
            {
                tail = other.tail;
                cur1->next->next = cur2;
                length += other.length;
                break;
            }
            cur1 = cur1->next->next;
        }
    }
    other.head = other.tail = nullptr;
    other.length = 0;
    other.debug_data.clear();
}

template <class type>
void Singly_LinkedList<type>::add_num(Singly_LinkedList<type> &other)
{
    if (!other.length)
        return;
    S_Node<type> *my_cur(head), *his_cur(other.head);
    int carry(0), my_val, his_val;
    while (my_cur || his_cur)
    {
        my_val = 0, his_val = 0;
        if (my_cur)
            my_val = my_cur->data;
        if (his_cur)
            his_val = his_cur->data, his_cur = his_cur->next;
        my_val += his_val + carry;
        carry = my_val / 10;
        my_val %= 10;
        if (my_cur)
            my_cur->data = my_val, my_cur = my_cur->next;
        else
            insert_end(my_val);
    }
    if (carry)
        insert_end(carry);
}

template <class type>
void Singly_LinkedList<type>::remove_all_repeated_from_sorted_list()
{
    if (length <= 1)
        return;
    // Add dummy head for easier prv linking
    insert_front(-1234);
    tail = head;
    S_Node<type> *previous(head);
    S_Node<type> *cur(head->next);

    while (cur)
    {

        bool any_removed(false);
        while (cur && cur->next && cur->data == cur->next->data)
        {
            type block_value(cur->data);
            any_removed = true;
            while (cur && cur->data == block_value)
                cur = move_and_delete(cur);
        }
        if (any_removed)
        {
            if (!cur)
                tail = previous;
            previous->next = cur;
            previous = cur;
        }
        else
        {
            tail = cur;
            previous = cur;
            cur = cur->next;
        }
    }
    previous = head->next;
    delete_first();
    head = previous;
    if (!head)
        tail = head;
}

template <class type>
pair<S_Node<type> *, pair<S_Node<type> *, S_Node<type> *>> Singly_LinkedList<type>::reverse_subchain(S_Node<type> *cur_head, int k)
{
    S_Node<type> *cur_tail(cur_head);
    S_Node<type> *prv(cur_head);
    cur_head = cur_head->next;
    for (int s(0); s < k - 1 && cur_head; ++s)
    {
        S_Node<type> *next(cur_head->next);
        cur_head->next = prv;
        prv = cur_head;
        cur_head = next;
    }
    // return: current chain head, current chain tail, next head
    return make_pair(prv, make_pair(cur_tail, cur_head));
}

template <class type>
void Singly_LinkedList<type>::reverse_chains(int k)
{
    if (length <= 1 || k == 1)
        return;
    S_Node<type> *last_tail(nullptr);
    S_Node<type> *next_chain_head(head);
    head = nullptr;

    while (next_chain_head)
    {
        pair<S_Node<type> *, pair<S_Node<type> *, S_Node<type> *>> p(reverse_subchain(next_chain_head, k));
        S_Node<type> *chain_head(p.first);
        S_Node<type> *chain_tail(p.second.first);
        next_chain_head = p.second.second;
        tail = chain_tail;
        if (!head)
            head = chain_head;
        else
            last_tail->next = chain_head;
        last_tail = chain_tail;
    }
    tail->next = nullptr;
}