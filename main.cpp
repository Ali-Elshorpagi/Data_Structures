#include <bits/stdc++.h>
#include "include.cpp"

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

void test_sparse()
{
	SparseMatrix mat(10, 10);
	mat.set_value(5, 3, 5);
	mat.set_value(7, 3, 7);
	mat.set_value(2, 3, 2);
	mat.set_value(0, 3, 2);
	mat.set_value(6, 5, 6);
	mat.set_value(4, 5, 4);
	mat.set_value(3, 7, 3);
	mat.set_value(1, 7, 1);
	// mat.set_value(1, 70, 1);
	// mat.print_matrix();
	mat.print_matrix_nonzero();
	cout << edl << edl;
	SparseMatrix mat2(10, 10);
	mat2.set_value(5, 1, 9);
	mat2.set_value(6, 3, 8);
	mat2.set_value(9, 9, 9);
	mat.add_sparse_matrix(mat2);
	mat.print_matrix_nonzero();
}

int main()
{
	Mesh_Ali;
	test_sparse();
	cout << edl << "DONE" << edl;
	return 0;
}