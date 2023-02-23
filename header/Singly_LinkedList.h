#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
#define edl '\n'

template <class T>
struct S_Node
{
    T data{};
    S_Node<T> *next{};
    S_Node(T data) : data(data) {}
    // ~Node() { cout << "Value Deleted: " << data << " at Address: " << this << '\n'; }
};

template <class type>
class Singly_LinkedList
{
    S_Node<type> *head{};
    S_Node<type> *tail{};
    int length = 0;
    vector<S_Node<type> *> debug_data;

public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    Singly_LinkedList<type>(const Singly_LinkedList<type> &) = delete;
    Singly_LinkedList<type> &operator=(const Singly_LinkedList<type> &another) = delete;

    Singly_LinkedList();
    ~Singly_LinkedList();
    S_Node<type> *get_head();
    unsigned long long get_length();
    void insert_end(type val);
    void insert_front(type val);
    void insert_sorted(type val);

    S_Node<type> *find(S_Node<type> *head, type val);
    void print();
    void print_recr(S_Node<type> *h);
    void print_recr_rever(S_Node<type> *h);
    unsigned long long get_size();
    S_Node<type> *get_nth(int n);
    int search(type val);
    int search_improved(type val);
    int search_improved_v2(type val);

    S_Node<type> *get_nth_from_back(int idx);
    bool is_same(const Singly_LinkedList<type> &list);
    S_Node<type> *move_and_delete(S_Node<type> *node);
    void delete_node(S_Node<type> *node);
    void delete_first();
    void delete_last();
    void delete_nth_node(int n);
    void delete_next_node(S_Node<type> *node);
    void delete_node_with_key(type val);
    void swap_repairs();
    void reverse();
    void delete_even_positions();
    S_Node<type> *get_previous(S_Node<type> *node);
    void swap_head_tail();
    void left_rotate(int key);
    void remove_duplicates_not_sorted();
    void delete_last_occurrence_not_sorted(type key);
    S_Node<type> *move_to_end(S_Node<type> *cur, S_Node<type> *prv);
    void move_key_occurance_to_end_not_sorted(type key);
    int max_node(S_Node<type> *h, S_Node<type> *mx);
    void arrange_odd_pos_even_pos();
    type middle_value();
    void insert_after(S_Node<type> *src, S_Node<type> *target);
    void insert_alternate(Singly_LinkedList<type> &other);
    void add_num(Singly_LinkedList<type> &other);
    void remove_all_repeated_from_sorted_list();
    pair<S_Node<type> *, pair<S_Node<type> *, S_Node<type> *>> reverse_subchain(S_Node<type> *cur_head, int k);
    void reverse_chains(int k);
};