
#include "SpareArray.h"
#include "../source/SpareArray.cpp"

template <class T>
struct Row_Node
{
    ll row;
    SpareArray<T> list;
    Row_Node *next{};
    Row_Node *prev{};
    Row_Node(int r, int c) : row(r), list(c) {}
};

template <class type>
class SparseMatrix
{
private:
    Row_Node<type> *head{};
    Row_Node<type> *tail{};
    ll length = 0;
    ll rows{};
    ll cols{};
    Row_Node<type> *get_row(ll row, bool flag);
    void link(Row_Node<type> *first, Row_Node<type> *second);
    Row_Node<type> *add_node_between_node_and_next(Row_Node<type> *node_before, ll row);

public:
    SparseMatrix(ll rows, ll cols);
    ~SparseMatrix();
    void set_value(type data, ll row, ll col);
    type get_value(ll row, ll col);
    void add(SparseMatrix<type> &other);
    void print_matrix();
    void print_matrix_nonzero();
};
