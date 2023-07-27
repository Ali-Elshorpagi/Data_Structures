#include "../source/Doubly_LinkedList.cpp"

Doubly_LinkedList<int> list;
const void initializing()
{
    for (int i(1); i < 21; ++i)
        list.insert_end(i);
}

const void test_get_length()
{
    assert(list.get_length() == 20);
}

const void test_pop_front()
{
    int popped1(list.pop_front());
    assert(popped1 == 1);
    list.insert_front(-4);
    int popped2(list.pop_front());
    assert(popped2 == -4);
}

const void test_pop_back()
{
    int popped1(list.pop_back());
    assert(popped1 == 20);
    list.insert_end(-4);
    int popped2(list.pop_back());
    assert(popped2 == -4);
}

const void test_get_value()
{
    assert(list.get_value(0) == 2);
    assert(list.get_value(1) == 3);
    assert(list.get_value(2) == 4);
    assert(list.get_value(3) == 5);
    assert(list.get_value(4) == 6);
}

const void test_delete_all_nodes_with_key()
{
    list.insert_front(-1);
    list.insert_front(-1);
    list.insert_end(-1);
    list.delete_all_nodes_with_key(-1);
    assert(list.get_value(0) == 2);
    assert(list.get_value(1) == 3);
}

const void test_reverse()
{
    Doubly_LinkedList<int> list1;
    for (int i(1); i < 6; ++i)
        list1.insert_end(i);
    list1.reverse();
    assert(list1.get_value(0) == 5);
    assert(list1.get_value(1) == 4);
    assert(list1.get_value(2) == 3);
    assert(list1.get_value(3) == 2);
    assert(list1.get_value(4) == 1);
}

const void test_middle_value()
{
    assert(list.middle_value_0() == 11);
    list.pop_back(), list.pop_back();
    assert(list.middle_value_1() == 10);
}

const void test_is_palindrome()
{
    assert(list.is_palindrome() == false);
    list.~Doubly_LinkedList();
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(2);
    list.insert_end(1);
    assert(list.is_palindrome() == true);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_length();
    test_pop_front();
    test_pop_back();
    test_get_value();
    test_delete_all_nodes_with_key();
    test_reverse();
    test_middle_value();
    test_is_palindrome();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}