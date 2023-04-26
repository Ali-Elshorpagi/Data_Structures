#pragma once

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;
#define edl '\n'

template <class T>
struct S_Node
{
    T data{};
    S_Node<T> *next{};
    S_Node(T data) : data(data) {}
    // ~Node() { cout << "Value Deleted: " << data << " at Address: " << this << edl; }
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
    S_Node<type> frontptr{}; // used in palindrome function
public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    Singly_LinkedList<type>(const Singly_LinkedList<type> &) = delete;
    Singly_LinkedList<type> &operator=(const Singly_LinkedList<type> &another) = delete;

    Singly_LinkedList();
    ~Singly_LinkedList();
    int get_length();
    void insert_end(type val);
    void insert_front(type val);
    void insert_after(S_Node<type> *src, S_Node<type> *target);
    void insert_sorted(type val);
    void print();
    void print_recr(S_Node<type> *h);
    void print_recr_rever(S_Node<type> *h);
    int search(type val);
    int search_improved(type val);
    int search_improved_v2(type val);
    bool is_same(const Singly_LinkedList<type> &list);
    void delete_first();
    void delete_last();
    void delete_nth_node(int n);
    void delete_next_node(S_Node<type> *node);
    void delete_node_with_key(type val);
    void delete_even_positions();
    void delete_last_occurrence_not_sorted(type key);
    void remove_duplicates_not_sorted();
    void swap_repairs();
    void reverse();
    void swap_head_tail();
    void left_rotate(int key);
    void move_key_occurance_to_end_not_sorted(type key);
    type max_value();
    type min_value();
    type middle_value();
    void arrange_odd_pos_even_pos();
    void insert_alternate(Singly_LinkedList<type> &other);
    S_Node<type> *merge_two_lists_iterative(S_Node<type> &head1, S_Node<type> &head2);
    S_Node<type> *merge_two_lists_recursive(S_Node<type> &head1, S_Node<type> &head2);
    bool is_palindrome();
};