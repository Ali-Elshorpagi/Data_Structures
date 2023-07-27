#include "../source/AVL_Tree_v2.cpp"

AVL_Tree_v2<int> tree(0);

const void initializing()
{
    for (int i(1); i < 33; ++i)
        tree.insert(i);
}

const void test_search()
{
    assert(tree.search(25) == true), assert(tree.search(17) == true);
    assert(tree.search(55) == false), assert(tree.search(35) == false);
}

const void test_max_and_min_value()
{
    assert(tree.min_value() == 0), assert(tree.max_value() == 32);
}

const void test_delete_value()
{
    assert(tree.search(32) == true);
    tree.delete_value(32);
    assert(tree.search(32) == false);

    assert(tree.search(28) == true);
    tree.delete_value(28);
    assert(tree.search(28) == false);

    assert(tree.search(18) == true);
    tree.delete_value(18);
    assert(tree.search(18) == false);

    assert(tree.search(5) == true);
    tree.delete_value(5);
    assert(tree.search(5) == false);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_search();
    test_max_and_min_value();
    test_delete_value();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
