#include "../source/Binary_Tree.cpp"

const void test_in_order()
{
    Binary_Tree<int> tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'}), tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'}), tree.add({3, 6, 10}, {'R', 'R', 'L'});
    std::vector<int> inorder_valuse;
    tree.get_in_order(inorder_valuse);
    assert(inorder_valuse[0] == 7), assert(inorder_valuse[1] == 4);
    assert(inorder_valuse[2] == 8), assert(inorder_valuse[3] == 2);
    assert(inorder_valuse[4] == 5), assert(inorder_valuse[5] == 9);
}

const void test_tree_max()
{
    Binary_Tree<int> tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'}), tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'}), tree.add({3, 6, 10}, {'R', 'R', 'L'});
    assert(tree.max_value() == 10);
}

const void test_is_exists()
{
    Binary_Tree<int> tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'}), tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'}), tree.add({3, 6, 15}, {'R', 'R', 'L'});

    assert(tree.total_nodes() == 10), assert(tree.no_leaf_nodes() == 4);
    assert(tree.is_exists(1) == true), assert(tree.is_exists(15) == true);
    assert(tree.is_exists(4) == true), assert(tree.is_exists(61) == false);
}

const void test_tree_height()
{
    Binary_Tree<int> tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'}), tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'}), tree.add({3, 6, 10}, {'R', 'R', 'L'});
    assert(tree.tree_height_0() == 3), assert(tree.tree_height_1() == 3);
}

const void test_is_perfect()
{
    Binary_Tree<int> tree(1);
    assert(tree.is_perfect() == true), assert(tree.is_perfect_fomula() == true);
    tree.add({2}, {'L'});
    tree.add({3}, {'R'});
    assert(tree.is_perfect() == true), assert(tree.is_perfect_fomula() == true);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 15}, {'R', 'R', 'L'});
    assert(tree.is_perfect() == 0), assert(tree.is_perfect_fomula() == false);
    tree.add({2, 5, 13}, {'L', 'R', 'L'});
    tree.add({3, 6, 12}, {'R', 'R', 'R'});
    tree.add({3, 14, 15}, {'R', 'L', 'L'});
    tree.add({3, 14, 16}, {'R', 'L', 'R'});
    assert(tree.is_perfect() == true), assert(tree.is_perfect_fomula() == true);
}

const void test_tree_diameter()
{
    Binary_Tree<int> tree(1);
    assert(tree.tree_diameter().first == 0);
    tree.add({2}, {'L'});
    tree.add({3}, {'R'});
    assert(tree.tree_diameter().first == 2);
    tree.add({2, 4, 7}, {'L', 'L', 'L'}), tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'}), tree.add({3, 6, 15}, {'R', 'R', 'L'});
    tree.add({2, 5, 13}, {'L', 'R', 'L'}), tree.add({3, 6, 12}, {'R', 'R', 'R'});
    tree.add({3, 14, 15}, {'R', 'L', 'L'}), tree.add({3, 14, 16}, {'R', 'L', 'R'});
    assert(tree.tree_diameter().first == 6);
}

const void test_is_complete()
{
    Binary_Tree<int> tree(1);
    assert(tree.is_complete() == true);
    tree.add({2, 4}, {'L', 'L'});
    tree.add({2, 5}, {'L', 'R'});
    tree.add({3}, {'R'});
    assert(tree.is_complete() == true);
    tree.add({3, 7}, {'R', 'R'});
    assert(tree.is_complete() == false);
    tree.add({2, 4, 8}, {'L', 'L', 'L'});
    tree.add({2, 4, 9}, {'L', 'L', 'R'});
    tree.add({2, 5, 10}, {'L', 'R', 'L'});
    tree.add({2, 5, 11}, {'L', 'R', 'R'});
    assert(tree.is_complete() == false);
    tree.add({3, 6, 12}, {'R', 'L', 'L'});
    tree.add({3, 6, 13}, {'R', 'L', 'R'});
    tree.add({3, 7, 14}, {'R', 'R', 'L'});
    tree.add({3, 7, 15}, {'R', 'R', 'R'});
    assert(tree.is_complete() == true);
}

const void test_is_symmetric()
{
    Binary_Tree<int> tree(1);
    assert(tree.is_symmetric() == true);
    tree.add({2}, {'L'});
    tree.add({2}, {'R'});
    assert(tree.is_symmetric() == true);
    tree.add({2, 3, 5}, {'L', 'L', 'L'});
    tree.add({2, 3, 6}, {'L', 'L', 'R'});
    tree.add({2, 4, 7}, {'L', 'R', 'L'});
    tree.add({2, 4, 8}, {'L', 'R', 'R'});
    assert(tree.is_symmetric() == false);
    tree.add({2, 4, 8}, {'R', 'L', 'L'});
    tree.add({2, 4, 7}, {'R', 'L', 'R'});
    tree.add({2, 3, 6}, {'R', 'R', 'L'});
    assert(tree.is_symmetric() == false);
    tree.add({2, 3, 5}, {'R', 'R', 'R'});
    assert(tree.is_symmetric() == true);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_in_order();
    test_tree_max();
    test_is_exists();
    test_tree_height();
    test_is_perfect();
    test_tree_diameter();
    test_is_complete();
    test_is_symmetric();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
