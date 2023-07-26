#include "../source/Binary_Search_Tree_v2.cpp"

const void test_search()
{
    Binary_Search_Tree_v2<int> *tree(new Binary_Search_Tree_v2<int>());
    tree->insert_value(20), tree->insert_value(60);
    tree->insert_value(15), tree->insert_value(45);
    tree->insert_value(70), tree->insert_value(35);
    assert(tree->search(45) == true), assert(tree->search(70) == true);
    assert(tree->search(55) == false), assert(tree->search(17) == false);
}

const void test_max_and_min_value()
{
    Binary_Search_Tree_v2<int> *tree(new Binary_Search_Tree_v2<int>());
    tree->insert_value(20), tree->insert_value(60);
    tree->insert_value(15), tree->insert_value(45);
    tree->insert_value(70), tree->insert_value(35);
    assert(tree->min_value() == 15), assert(tree->max_value() == 70);
}

const void test_delete_value()
{
    Binary_Search_Tree_v2<int> *tree(new Binary_Search_Tree_v2<int>());
    tree->insert_value(20), tree->insert_value(60);
    tree->insert_value(15), tree->insert_value(45);
    tree->insert_value(70), tree->insert_value(35);
    assert(tree->search(15) == true), assert(tree->search(60) == true);
    tree->delete_value(15), tree->delete_value(60);
    assert(tree->search(15) == false), assert(tree->search(60) == false);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_search();
    test_max_and_min_value();
    test_delete_value();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
