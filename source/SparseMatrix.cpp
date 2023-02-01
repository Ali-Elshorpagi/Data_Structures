#include "..\\header\SparseMatrix.h"

SparseMatrix::SparseMatrix(int col, int row) : col(col), row(row)
{
    list = new LinkedList[col];
}

SparseMatrix::~SparseMatrix()
{
    delete[] list;
}
void SparseMatrix::set_value(int col, int row, int val)
{
    list[row].insert_at_col(col, val);
}
void SparseMatrix::add_sparse_matrix(SparseMatrix &other)
{
    for (int i(0); i < row; ++i)
    {
        SM_Node *cur1{nullptr};
        if (other.list[i].head)
        {
            SM_Node *cur2(other.list[i].head);
            while (cur2)
            {
                if (list[i].head)
                {
                    if (!cur1)
                        cur1 = list[i].head;
                    if (list[i].head->col > cur2->col)
                        list[i].insert_front(cur2->col, cur2->data);
                    else if (list[i].tail->col < cur2->col)
                        list[i].insert_end(cur2->col, cur2->data);
                    else
                    {
                        while (cur1->col < cur2->col && cur1)
                        {
                            if (cur1->next->col > cur2->col)
                                break;
                            cur1 = cur1->next;
                        }
                        if (cur1->col == cur2->col)
                            cur1->data = cur2->data + cur1->data;
                        else
                        {
                            SM_Node *newNode = new SM_Node(cur2->data);
                            newNode->col = cur2->col;
                            newNode->next = cur1->next;
                            cur1->next = newNode;
                        }
                    }
                }
                else
                {
                    list[i].insert_row(cur2);
                    break;
                }
                if (cur2->next)
                    cur2 = cur2->next;
                else
                    break;
            }
        }
    }
}

void SparseMatrix::print_matrix()
{
    for (int i(0); i < row; ++i)
    {
        SM_Node *current(list[i].head);
        for (int j(0); j < col; ++j)
        {
            if (current)
            {
                if (current->col == j)
                {
                    cout << current->data << ' ';
                    current = current->next;
                }
                else
                    cout << "0 ";
            }
            else
                cout << "0 ";
        }
        cout << edl;
    }
}
void SparseMatrix::print_matrix_nonzero()
{
    // for(SM_Node*cur(head))
    for (int i(0); i < row; ++i)
    {
        for (SM_Node *cur(list[i].head); cur; cur = cur->next)
            cout << cur->data << ' ';
        cout << edl;
    }
}