#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
#define edl '\n'
typedef long long ll;

template <class T>
struct S_Node
{
    T data{};
    S_Node *next{};
    S_Node(T data) : data(data) {}
    // ~Node() { cout << "Value Deleted: " << data << " at Address: " << this << '\n'; }
};

template <class type>
class Singly_LinkedList
{
    S_Node<type> *head{};
    S_Node<type> *tail{};
    unsigned long long length = 0;
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
    S_Node<type> *find(S_Node<type> *head, type val);
    void print();
    void print_recr(S_Node<type> *h);
    void print_recr_rever(S_Node<type> *h);
    unsigned long long get_size();
    S_Node<type> *get_nth(ll n);
    ll search(type val);
    ll search_improved(type val);
    ll search_improved_v2(type val);
    void insert_front(type val);
    S_Node<type> *get_nth_from_back(ll idx);
    bool is_same(const Singly_LinkedList<type> &list);
    void delete_node(S_Node<type> *node);
    void delete_first();
    void delete_last();
    void delete_nth_node(ll n);
    void delete_next_node(S_Node<type> *node);
    void delete_node_with_key(type val);
    void swap_repairs();
    void reverse();
    void delete_even_positions();
    void insert_sorted(type val);
    S_Node<type> *get_previous(S_Node<type> *node);
    void swap_head_tail();
    void left_rotate(ll key);
    void remove_duplicates_not_sorted();
    void delete_last_occurrence_not_sorted(type key);
S_Node<type>* move_to_end(S_Node<type>* cur, S_Node<type>* prv);
	void move_key_occurance_to_end_not_sorted(type key);
	
	ll max_node(S_Node<type>* h, S_Node<type>* mx);
	void arrange_odd_pos_even_pos();
	type middle_value();








};