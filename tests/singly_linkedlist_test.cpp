#include "../source/Singly_LinkedList.cpp"

const void test_get_length()
{
    Singly_LinkedList<int> list;
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
    assert(list.get_length() == 10);
}

const void test_pop_front()
{
    Singly_LinkedList<int> list;
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
    Singly_LinkedList<int> list;
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
    int popped1(list.pop_back());
    assert(popped1 == 10);
    list.insert_end(-4);
    int popped2(list.pop_back());
    assert(popped2 == -4);
}

const void test_get_value()
{
    Singly_LinkedList<int> list;
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
    Singly_LinkedList<int> list;
    for (int i(1); i < 6; ++i)
        list.insert_end(i);
    list.reverse();
    assert(list.get_value(0) == 5);
    assert(list.get_value(1) == 4);
    assert(list.get_value(2) == 3);
    assert(list.get_value(3) == 2);
    assert(list.get_value(4) == 1);
}

const void test_min_and_middle_and_max_value()
{
    Singly_LinkedList<int> list;
    for (int i(11); i < 21; ++i)
        list.insert_end(i);
    assert(list.min_value() == 11);
    assert(list.max_value() == 20);
    assert(list.middle_value() == 16);
    list.pop_front(), list.pop_back();
    assert(list.min_value() == 12);
    assert(list.max_value() == 19);
    assert(list.middle_value() == 16);
}

const void test_is_palindrome()
{
    Singly_LinkedList<int> list;
    for (int i(11); i < 21; ++i)
        list.insert_end(i);
    assert(list.is_palindrome() == false);
    list.~Singly_LinkedList();
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
    test_get_value();
    test_reverse();
    test_min_and_middle_and_max_value();
    test_is_palindrome();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}