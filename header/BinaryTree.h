#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <deque>
#include <sstream> // ostringstream

using namespace std;
#define edl '\n'
typedef long long ll;

template <class type>
class BinaryTree
{
    type data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(type data);
    ~BinaryTree();
    void clear();
    void add(vector<type> values, vector<char> direction);
	void print_in_order();










};
