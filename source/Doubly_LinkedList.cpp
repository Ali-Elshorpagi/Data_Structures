#include "..\\header\Doubly_LinkedList.h"

template <class type>
Doubly_LinkedList<type>::Doubly_LinkedList() {}

template <class type>
Doubly_LinkedList<type>::~Doubly_LinkedList() {}

template <class type>
void Doubly_LinkedList<type>::add_node(D_Node<type> *node)
{
    debug_data.emplace_back(node);
    ++length;
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
    D_Node<type> *mid = new D_Node<type>(val);
    ++length;
    debug_data.emplace_back(mid);
    D_Node<type> *node_after(node_before->next);
    link(node_before, mid);
    link(mid, node_after);
}

template <class type>
void Doubly_LinkedList<type>::delete_node(D_Node<type> *node)
{
    auto it = std::find(debug_data.begin(), debug_data.end(), node);
    if (it == debug_data.end())
        cout << "Node does not exist" << edl;
    else
        debug_data.erase(it);
    --length;
    delete node;
}

template <class type>
D_Node<type> *Doubly_LinkedList<type>::delete_and_link(D_Node<type> *cur)
{
    D_Node<type> *ret = cur->prev;
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
void Doubly_LinkedList<type>::print() 
{
	for (D_Node<type>* cur(head); cur; cur = cur->next)
		cout << cur->data << " ";
	cout << edl;
}

template <class type>
void Doubly_LinkedList<type>::print_reversed() 
{
	for (D_Node<type>* cur(tail); cur; cur = cur->prev)
		cout << cur->data << " ";
	cout << edl;
}

template <class type>
void Doubly_LinkedList<type>::insert_end(type val)
{
	D_Node<type>* item = new D_Node<type>(val);
	add_node(item);
	if (!head)
		head = tail = item;
	else 
	{
		link(tail, item);
		tail = item;
	}
}

template <class type>
void Doubly_LinkedList<type>::insert_front(type val)
{
	D_Node<type>* item = new D_Node<type>(val);
	add_node(item);
	if (!head)
		head = tail = item;
	else 
	{
		link(item, head);
		head = item;
	}
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
		for (D_Node<type>* cur(head); cur; cur = cur->next)
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
void Doubly_LinkedList<type>::delete_front()
{
	if (!head)
		return;
	D_Node<type>* cur(head->next);
	delete_node(head);
	head = cur;
	if (head)
		head->prev = nullptr;
	else if (!length)
		tail = nullptr;

}


template <class type>
void Doubly_LinkedList<type>::delete_end() 
{
	if (!head)
		return;
	D_Node<type>* cur(tail->prev);
	delete_node(tail);
	tail = cur;
	if (tail)
		tail->next = nullptr;
	else if (!length)
		head = nullptr;

}