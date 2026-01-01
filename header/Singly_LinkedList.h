#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

#include <algorithm>
#include <cassert>
#include <iostream>

#define edl '\n'

template <class T>
struct S_Node
{
  T data{};
  S_Node<T> *next{};
  S_Node(T data) : data(data) {}
  // ~Node() { std::cout << "Value Deleted: " << data << " at Address: " << this
  // << edl; }
};

template <class type>
class Singly_LinkedList
{
  S_Node<type> *head{};
  S_Node<type> *tail{};
  int length{};

  S_Node<type> *find(type val);
  void delete_node(S_Node<type> *node);
  S_Node<type> *get_previous(S_Node<type> *node);
  S_Node<type> *move_to_end(S_Node<type> *cur, S_Node<type> *prv);
  S_Node<type> *move_and_delete(S_Node<type> *node);
  S_Node<type> *max_node(S_Node<type> *h);
  S_Node<type> *min_node(S_Node<type> *h);
  S_Node<type> *get_nth(int n);
  S_Node<type> *get_nth_from_back(int idx);
  bool recursive_check(S_Node<type> *cur_head);
  S_Node<type> *frontptr{}; // used in palindrome function
public:
  Singly_LinkedList<type>(const Singly_LinkedList<type> &another);
  Singly_LinkedList<type> &operator=(const Singly_LinkedList<type> &another);

  Singly_LinkedList();
  ~Singly_LinkedList();
  // Returns the value at the given index.
  type get_value(int idx) const;
  // Returns the length (number of nodes) of the linked list.
  int get_length() const;
  // Inserts a new node with the given value at the end of the linked list.
  void insert_end(type val);
  // Inserts a new node with the given value at the beginning of the linked
  // list.
  void insert_front(type val);
  // Inserts a new node with the given value after a specific node (`src`) in
  // the linked list.
  void insert_after(S_Node<type> *src, S_Node<type> *target);
  // Inserts a new node with the given value into the list while maintaining
  // sorted order.
  void insert_sorted(type val);
  // Prints the values of all nodes in the linked list
  void print();
  // Recursively prints the values of nodes in the linked list
  void print_recr(S_Node<type> *h);
  // Recursively prints the values of nodes in reverse order
  void print_recr_rever(S_Node<type> *h);
  // Returns the index of the node containing the value, or -1 if not found.
  int search(type val);
  int search_improved(type val);
  int search_improved_v2(type val);
  // Returns `true` if the lists are the same, otherwise `false`.
  bool is_same(const Singly_LinkedList<type> &list);
  // Removes and returns the value of the node at the front of the linked list.
  type pop_front();
  // Removes and returns the value of the node at the end of the linked list.
  type pop_back();
  // Deletes the node at the specified index `n` in the linked list.
  void delete_nth_node(int n);
  // Deletes the node that is the next ot the given node `node` in the linked
  // list.
  void delete_next_node(S_Node<type> *node);
  // Deletes the first occurrence of the node containing the specified value
  // from the linked list.
  void delete_node_with_key(type val);
  // Deletes nodes at even positions (0-based index) from the linked list.
  void delete_even_positions();
  // Deletes the last occurrence of the specified value from the linked list.
  void delete_last_occurrence_not_sorted(type key);
  // Removes duplicate values from the linked list, which is not necessarily
  // sorted.
  void remove_duplicates_not_sorted();
  // Swaps adjacent elements in the linked list, effectively repairing it.
  void swap_repairs();
  // Reverses the order of nodes in the linked list.
  void reverse();
  void swap_head_tail();
  void left_rotate(int key);
  void move_key_occurance_to_end_not_sorted(type key);
  // Returns the maximum value present in the linked list.
  type max_value();
  // Returns the minimum value present in the linked list.
  type min_value();
  // Returns the middle value of the linked list.
  type middle_value();
  // Rearranges nodes in such a way that odd-positioned nodes appear before
  // even-positioned nodes.
  void arrange_odd_pos_even_pos();
  // Inserts nodes from another linked list at alternate positions in the
  // current linked list.
  void insert_alternate(Singly_LinkedList<type> &other);
  // Merges two sorted linked lists iteratively into a single sorted linked
  // list.
  S_Node<type> *merge_two_lists_iterative(S_Node<type> &head1,
                                          S_Node<type> &head2);
  // Merges two sorted linked lists recursively into a single sorted linked
  // list.
  S_Node<type> *merge_two_lists_recursive(S_Node<type> &head1,
                                          S_Node<type> &head2);
  // Checks if the linked list is a palindrome.
  bool is_palindrome();
};
#endif