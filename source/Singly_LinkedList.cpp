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
S_Node<type> *Singly_LinkedList<type>::get_nth(ll n)
{
    for (S_Node<type> *cur(head); cur; cur = cur->next)
        if (--n == 0)
            return cur;
    return nullptr;
}

template <class type>
ll Singly_LinkedList<type>::search(type val)
{
    ll idx(0);
    for (S_Node<type> *cur(head); cur; cur = cur->next, idx++)
        if (cur->data == val)
            return idx;
    return -1;
}

template <class type>
ll Singly_LinkedList<type>::search_improved(type val)
{
    ll idx(0);
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
ll Singly_LinkedList<type>::search_improved_v2(type val) // commonly used
{
    ll idx(0);
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
S_Node<type> *Singly_LinkedList<type>::get_nth_from_back(ll idx)
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
    S_Node<type> *temp = list.head;
    for (S_Node<type> *cur(head); cur; cur = cur->next)
    {
        if (cur->data != temp->data)
            return false;
        temp = temp->next;
    }
    return true;
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
        S_Node<type> *cur = head;
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
    S_Node<type> *previous = get_nth(length - 1);
    delete_node(tail);
    tail = previous;
    tail->next = nullptr;
}

template <class type>
void Singly_LinkedList<type>::delete_nth_node(ll n)
{
    if (n < 1 || n > length)
        cout << "Error. No such nth node" << edl;
    else if (n == 1)
        delete_first();
    else
    {
        S_Node<type> *before_nth = get_nth(n - 1);
        S_Node<type> *nth = before_nth->next;
        bool is_tail = nth == tail;
        before_nth->next = nth->next;
        if (is_tail)
            tail = before_nth;
        delete_node(nth);
    }
}

template <class type>
void Singly_LinkedList<type>::delete_next_node(S_Node<type> *node)
{
    S_Node<type> *to_delete = node->next;
    bool is_tail = to_delete == tail;
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
    for (S_Node<type>* cur(head); cur; cur = cur->next)
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
    S_Node<type>* prv = head;
    head = head->next;
    while (head) 
    {
        S_Node<type>* next = head->next;
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

    for (S_Node<type>* cur = head->next, *prv = head; cur;)
    {
        delete_next_node(prv);	
        if (!prv->next)	
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
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
       
       for (S_Node<type>* cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
        {
            if (cur->data >= val)
            {
                S_Node<type>* item = new S_Node<type>(val);
                ++length;
                item->next = prv->next;
                prv->next = item;
                break;
            }
        }
    }
}

template <class type>
S_Node<type>* Singly_LinkedList<type>::get_previous(S_Node<type>* node)
{		
    for (S_Node<type>* cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
    {
        if (cur == node)
            return prv;
    }
    return nullptr;	
}

template <class type>
void Singly_LinkedList<type>::swap_head_tail()
{
    if (length <= 1) return;
    S_Node<type>* prv(get_previous(tail));
    tail->next = head->next;
    prv->next = head;
    head->next = nullptr;
    swap(tail, head);
}

template <class type>
void Singly_LinkedList<type>::left_rotate(ll key)
{
    key %= length;
    if (!key || length <= 1) return;
    S_Node<type>* cur(get_nth(key));
    tail->next = head;
    tail = cur;
    head = cur->next;
    tail->next = nullptr;
}


template <class type>
void Singly_LinkedList<type>::remove_duplicates_not_sorted()
{
    if (length <= 1) return;

    for (S_Node<type>* cur1(head); cur1; cur1 = cur1->next)
    {
        for (S_Node<type>* cur2(cur1->next), *prv (cur1); cur2;)
        {
            if (cur1->data == cur2->data) {
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
    if (!length) return;
    S_Node<type>* delete_node(nullptr);
    bool flag(0);

    for (S_Node<type>* cur(head), *prv(nullptr); cur; prv = cur, cur = cur->next)
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