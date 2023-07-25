#ifndef PRIORITY_QUEUE_AVLT_BASED_H
#define PRIORITY_QUEUE_AVLT_BASED_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
#define edl '\n'

template <class T>
struct PQ_Node
{
    int priority{};
    int height{};
    vector<T> task_ids{};
    PQ_Node<T> *left{};
    PQ_Node<T> *right{};

    PQ_Node(T task_id, int priority) : priority(priority)
    {
        task_ids.push_back(task_id);
    }

    int ch_height(PQ_Node<T> *node)
    {
        if (!node)
            return -1;
        return node->height;
    }
    int update_height()
    {
        return height = 1 + max(ch_height(left), ch_height(right));
    }
    int balance_factor()
    {
        return ch_height(left) - ch_height(right);
    }
};

template <class type>
class Priority_Queue_AVLT_Based
{
    PQ_Node<type> *root{};

    bool search(type target, PQ_Node<type> *node);
    PQ_Node<type> *right_rotation(PQ_Node<type> *Q);
    PQ_Node<type> *left_rotation(PQ_Node<type> *P);
    PQ_Node<type> *balance(PQ_Node<type> *node);
    PQ_Node<type> *insert_node(type task_id, int priority, PQ_Node<type> *node);
    PQ_Node<type> *min_node(PQ_Node<type> *cur);
    PQ_Node<type> *max_node(PQ_Node<type> *cur);
    PQ_Node<type> *delete_node(int priority, PQ_Node<type> *node);
    void clear(PQ_Node<type> *node);

public:
    Priority_Queue_AVLT_Based();
    ~Priority_Queue_AVLT_Based();
    void enqueue(type task_id, int task_priority);
    type dequeue();
    bool is_empty();
};
#endif