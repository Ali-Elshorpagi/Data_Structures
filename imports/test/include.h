// #include "../Elshorpagi.h"
#include <iostream>

#ifdef DS_AVL_TREE_V2
#include "../../source/AVL_Tree_v2.cpp"
#endif
#ifdef DS_AVL_TREE
#include "../../source/AVL_Tree.cpp"
#endif
#ifdef DS_BINARY_SEARCH_TREE_V2
#include "../../source/Binary_Search_Tree_v2.cpp"
#endif
#ifdef DS_BINARY_SEARCH_TREE
#include "../../source/Binary_Search_Tree.cpp"
#endif
#ifdef DS_BINARY_TREE
#include "../../source/Binary_Tree.cpp"
#endif
#ifdef DS_CIRCULAR_QUEUE
#include "../../source/Circular_Queue.cpp"
#endif
#ifdef DS_DEQUE
#include "../../source/Deque.cpp"
#endif
#ifdef DS_DOUBLY_LINKEDLIST
#include "../../source/Doubly_Linkedlist.cpp"
#endif
#ifdef DS_TRIE_TREE
#include "../../source/Trie_Tree.cpp"
#endif
#ifdef DS_MAX_HEAP
#include "../../source/Max_Heap.cpp"
#endif
#ifdef DS_MIN_HEAP
#include "../../source/Min_Heap.cpp"
#endif
#ifdef DS_PRIORITY_QUEUE_AVLT_BASED
#include "../../source/Priority_Queue_AVLT_Based.cpp"
#endif
#ifdef DS_PRIORITY_QUEUE_HEAP_BASED
#include "../../source/Priority_Queue_Heap_Based.cpp"
#endif
#ifdef DS_QUEUE_LINKEDLIST_BASED
#include "../../source/Queue_Linkedlist_Based.cpp"
#endif
#ifdef DS_SINGLY_LINKEDLIST
#include "../../source/Singly_Linkedlist.cpp"
#endif
#ifdef DS_SPARSE_ARRAY
#include "../../source/Sparse_Array.cpp"
#endif
#ifdef DS_SPARSE_CUBE
#include "../../source/Sparse_Cube.cpp"
#endif
#ifdef DS_SPARSE_MATRIX
#include "../../source/Sparse_Matrix.cpp"
#endif
#ifdef DS_STACK_ARRAY_BASED
#include "../../source/Stack_Array_Based.cpp"
#endif
#ifdef DS_STACK_LINKIEDLIST_BASED
#include "../../source/Stack_Linkedlist_Based.cpp"
#endif
#ifdef DS_VECTOR
#include "../../source/Vector.cpp"
#endif

// some macros to test faster, and you can modify them
#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (std::ios_base::sync_with_stdio(false), std::cin.tie(NULL))
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define cl(v) ((v).clear())
#define edl '\n'
#define fr(i, x, n) for (int i(x); i < n; ++i)
#define fl(i, x, n) for (int i(x); i > n; --i)
#define fc(it, v) for (auto &(it) : (v))
#define sq(x) (x) * (x)
#define yes std::cout << "YES\n"
#define no std::cout << "NO\n"