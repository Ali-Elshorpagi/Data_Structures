#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

#define edl '\n'

template <class T>
struct D_Node
{
  T data{};
  D_Node<T> *next{};
  D_Node<T> *prev{};
  D_Node(T data) : data(data) {}
  void set(D_Node<T> *next, D_Node<T> *prev)
  {
    this->next = next;
    this->prev = prev;
  }
  // ~D_Node() { std::cout << "Destroy value: " << data << " at address " << this << edl; }
};

template <class type>
class Doubly_LinkedList
{
  D_Node<type> *head{};
  D_Node<type> *tail{};
  int length{};

  void delete_node(D_Node<type> *node);
  void link(D_Node<type> *first, D_Node<type> *second);
  void add_node_between_node_and_next(D_Node<type> *node_before, type val);
  D_Node<type> *delete_and_link(D_Node<type> *cur);
  void delete_and_link_v2(D_Node<type> *cur);

public:
  Doubly_LinkedList();
  ~Doubly_LinkedList();
  Doubly_LinkedList(const Doubly_LinkedList &another);
  Doubly_LinkedList &operator=(const Doubly_LinkedList &another);
  // Returns the length (number of nodes) of the doubly linked list.
  int get_length() const;
  // Returns the value at the given index.
  type get_value(int idx) const;
  // Inserts a new node with the given value at the end of the doubly linked list.
  void insert_end(type val);
  // Inserts a new node with the given value at the beginning of the doubly linked list.
  void insert_front(type val);
  // Inserts a new node with the given value into the list while maintaining sorted order.
  void insert_sorted(type val);
  // Prints the values of all nodes in the doubly linked list
  void print();
  // Prints the values of nodes in reverse order
  void print_reversed();
  // Removes and returns the value of the node at the front of the doubly linked list.
  type pop_front();
  // Removes and returns the value of the node at the end of the doubly linked list.
  type pop_back();
  // Deletes the first occurrence of the node containing the specified value from the doubly linked list.
  void delete_node_with_key(type val);
  // Deletes all nodes with a specific value from the doubly linked list.
  void delete_all_nodes_with_key(type val);
  // Deletes nodes at even positions (0-based index) from the doubly linked list.
  void delete_even_positions();
  // Deletes nodes at odd positions (0-based index) from the doubly linked list.
  void delete_odd_positions();
  // Checks if the doubly linked list is a palindrome.
  bool is_palindrome();
  // Returns the middle value of the doubly linked list.
  type middle_value_0();
  type middle_value_1();
  // Reverses the order of nodes in the doubly linked list.
  void reverse();
};
#endif