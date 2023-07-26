#include "../source/Doubly_LinkedList.cpp"

const void test_get_length()
{
    Doubly_LinkedList<int> list;
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
    assert(list.get_length() == 10);
}

const void test_pop_front()
{
    Doubly_LinkedList<int> list;
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
    int popped1(list.pop_front());
    assert(popped1 == 1);
    list.insert_front(-4);
    int popped2(list.pop_front());
    assert(popped2 == -4);
}

const void test_pop_back()
{
    Doubly_LinkedList<int> list;
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
    int popped1(list.pop_back());
    assert(popped1 == 10);
    list.insert_end(-4);
    int popped2(list.pop_back());
    assert(popped2 == -4);
}

const void test_delete_all_nodes_with_key()
{
    Doubly_LinkedList<int> list;
    list.insert_end(-1);
    list.insert_end(1);
    list.insert_end(-1);
    list.insert_end(5);
    list.insert_end(-1);
    list.insert_end(8);
    list.delete_all_nodes_with_key(-1);
    assert(list.get_value(0) == 1);
    assert(list.get_value(1) == 5);
    assert(list.get_value(2) == 8);
}

const void test_get_value()
{
    Doubly_LinkedList<int> list;
    for (int i(5); i < 10; ++i)
        list.insert_end(i);
    assert(list.get_value(0) == 5);
    assert(list.get_value(1) == 6);
    assert(list.get_value(2) == 7);
    assert(list.get_value(3) == 8);
    assert(list.get_value(4) == 9);
}

const void test_reverse()
{
    Doubly_LinkedList<int> list;
    for (int i(1); i < 6; ++i)
        list.insert_end(i);
    list.reverse();
    assert(list.get_value(0) == 5);
    assert(list.get_value(1) == 4);
    assert(list.get_value(2) == 3);
    assert(list.get_value(3) == 2);
    assert(list.get_value(4) == 1);
}

const void test_middle_value()
{
    Doubly_LinkedList<int> list;
    for (int i(11); i < 21; ++i)
        list.insert_front(i);
    assert(list.middle_value_0() == 15);
    list.pop_back(), list.pop_back();
    assert(list.middle_value_1() == 16);
}

const void test_is_palindrome()
{
    Doubly_LinkedList<int> list;
    for (int i(11); i < 21; ++i)
        list.insert_end(i);
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
    test_get_length();
    test_pop_front();
    test_pop_back();
    test_delete_all_nodes_with_key();
    test_get_value();
    test_reverse();
    test_middle_value();
    test_is_palindrome();
    cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}