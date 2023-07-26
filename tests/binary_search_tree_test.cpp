#include "../source/Binary_Search_Tree.cpp"

const void test_is_bst()
{
    Binary_Search_Tree<int> *tree(new Binary_Search_Tree<int>(50));
    tree->insert(20), tree->insert(60);
    tree->insert(15), tree->insert(45);
    tree->insert(70), tree->insert(35);
    tree->insert(73), tree->insert(14);
    tree->insert(16), tree->insert(36), tree->insert(58);
    assert(tree->is_bst_0() == true), assert(tree->is_bst_1() == true);
}

const void test_search()
{
    Binary_Search_Tree<int> *tree(new Binary_Search_Tree<int>(50));
    tree->insert(20), tree->insert(60);
    tree->insert(15), tree->insert(45);
    tree->insert(70), tree->insert(35);
    tree->insert(73), tree->insert(14);
    tree->insert(16), tree->insert(36), tree->insert(58);
    assert(tree->search_iterative(35) == true), assert(tree->search(70) == true);
    assert(tree->search_iterative(55) == false), assert(tree->search(25) == false);
}

const void test_max_and_min_value()
{
    Binary_Search_Tree<int> *tree(new Binary_Search_Tree<int>(50));
    tree->insert(20), tree->insert(60);
    tree->insert(15), tree->insert(45);
    tree->insert(70), tree->insert(35);
    assert(tree->min_value() == 15), assert(tree->max_value() == 70);
}

const void test_LCA()
{
    Binary_Search_Tree<int> *tree(new Binary_Search_Tree<int>(50));
    tree->insert(20), tree->insert(60), tree->insert(15), tree->insert(45);
    tree->insert(70), tree->insert(35), tree->insert(73), tree->insert(14);
    tree->insert(16), tree->insert(36);
    assert(tree->LCA(35, 60) == 50), assert(tree->LCA(14, 16) == 15);
    assert(tree->LCA(70, 73) == 70);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_is_bst();
    test_search();
    test_max_and_min_value();
    test_LCA();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
