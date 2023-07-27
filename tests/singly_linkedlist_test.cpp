#include "../source/Singly_LinkedList.cpp"

Singly_LinkedList<int> list;
const void initializing()
{
    for (int i(1); i < 11; ++i)
        list.insert_end(i);
}

const void test_get_length()
{
    assert(list.get_length() == 10);
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
    assert(popped1 == 10);
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

const void test_reverse()
{
    list.reverse();
    assert(list.get_value(0) == 9);
    assert(list.get_value(1) == 8);
    assert(list.get_value(2) == 7);
    assert(list.get_value(3) == 6);
    assert(list.get_value(4) == 5);
}

const void test_min_and_middle_and_max_value()
{
    assert(list.min_value() == 2);
    assert(list.max_value() == 9);
    assert(list.middle_value() == 5);
    list.pop_front(), list.pop_back();
    assert(list.min_value() == 3);
    assert(list.max_value() == 8);
    assert(list.middle_value() == 5);
}

const void test_is_palindrome()
{
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
    initializing();
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