#include "..\\header\SpareArray.h"

template <class type>
SpareArray<type>::SpareArray(ll cols) : cols(cols)
{
    tail = head = new Col_Node<type>(0, -1);
    ++length;
}

template <class type>
SpareArray<type>::~SpareArray()
{
    while (head)
    {
        Col_Node<type> *current(head->next);
        delete head;
        head = current;
    }
    head = nullptr;
    tail = nullptr;
}

template <class type>
void SpareArray<type>::link(Col_Node<type> *first, Col_Node<type> *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

template <class type>
Col_Node<type> *SpareArray<type>::add_node_between_node_and_next(Col_Node<type> *node_before, type data, ll col)
{
    Col_Node<type> *middle = new Col_Node<type>(data, col);
    ++length;
    Col_Node<type> *node_after = node_before->next;
    link(node_before, middle);
    if (!node_after)
        tail = middle;
    else
        link(middle, node_after);
    return middle;
}

template <class type>
Col_Node<type> *SpareArray<type>::get_col(ll col, bool is_create_if_missing)
{
    Col_Node<type> *prev_col(head);
    while (prev_col->next && prev_col->next->col < col)
        prev_col = prev_col->next;
    bool found = prev_col->next && prev_col->next->col == col;
    if (found)
        return prev_col->next;
    if (!is_create_if_missing)
        return nullptr;
    return add_node_between_node_and_next(prev_col, 0, col);
}

template <class type>
void SpareArray<type>::print_row()
{
    Col_Node<type> *cur(head->next);
    for (ll c(0); c < cols; ++c)
    {
        if (cur && cur->col == c)
        {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        else
            cout << "0 ";
    }
    cout << edl;
}

template <class type>
void SpareArray<type>::print_row_nonzero()
{
    for (Col_Node<type> *cur(head->next); cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << edl;
}

template <class type>
void SpareArray<type>::set_value(type data, ll col)
{
    get_col(col, true)->data = data;
}

template <class type>
type SpareArray<type>::get_value(ll col)
{
    Col_Node<type> *node(get_col(col, false));
    if (!node)
        return 0;
    return node->data;
}

template <class type>
void SpareArray<type>::add(SpareArray<type> &other)
{
    assert(cols == other.cols);
    for (Col_Node<type> *other_cur(other.head->next); other_cur; other_cur = other_cur->next)
    {
        Col_Node<type> *this_col = get_col(other_cur->col, true);
        this_col->data += other_cur->data;
    }
}