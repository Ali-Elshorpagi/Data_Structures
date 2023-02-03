#include <bits/stdc++.h>
#include "include.cpp"

using namespace std;

typedef long long ll;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

void test_sparse()
{
	SpareCube<int> cube(10, 10, 10);
	cube.set_value(1, 5, 3, 5);
	cube.set_value(2, 7, 3, 7);
	cube.set_value(3, 2, 3, 2);
	cube.set_value(4, 0, 3, 2);
	cube.set_value(5, 6, 5, 6);
	cube.set_value(6, 4, 5, 4);
	cube.set_value(7, 3, 7, 3);
	cube.set_value(8, 1, 7, 1);
	// cube.set_value(1, 70, 1);
	cube.print_cube();
	cube.print_cube_nonzero();

	SpareCube<int> cube2(10, 10, 10);
	cube2.set_value(9, 5, 1, 9);
	cube2.set_value(10, 6, 3, 8);
	cube2.set_value(11, 9, 9, 9);
	cube.add(cube2);
	cube.print_cube_nonzero();
}

int main()
{
	Mesh_Ali;
	test_sparse();
	cout << edl << "DONE" << edl;
	return 0;
}