#include "../source/Vector.cpp"

const void test_get_size()
{
    Vector<int> tester(3);
    assert(tester.get_size() == 3);
    int elements_added(5);
    for (int i(0); i < elements_added; ++i)
        tester.push_back(i + 1);
    assert(tester.get_size() != elements_added);
}

const void test_is_empty()
{
    Vector<int> tester(3);
    assert(!tester.is_empty());
}

const void test_get_value()
{
    Vector<int> tester;
    tester.push_back(4);
    tester.push_back(9);
    tester.push_back(12);
    assert(tester.get_value(0) == 4);
    assert(tester.get_value(1) == 9);
    assert(tester.get_value(2) == 12);
}

const void test_get_front()
{
    Vector<int> tester;
    tester.push_back(4);
    tester.push_back(9);
    tester.push_back(12);
    assert(tester.get_front() == 4);
}

const void test_get_back()
{
    Vector<int> tester;
    tester.push_back(4);
    tester.push_back(9);
    tester.push_back(12);
    assert(tester.get_back() == 12);
}

const void test_pop_back()
{
    Vector<int> tester(1);
    tester.push_back(1);
    tester.push_back(2);
    tester.push_back(3);

    tester.pop_back();
    assert(tester.get_back() == 2);
    tester.push_back(3);
    assert(tester.get_size() == 4);

    tester.pop_back(), tester.pop_back();
    assert(tester.get_back() == 1);
    assert(tester.get_size() == 2);
}

const void test_pop()
{
    Vector<int> tester;
    tester.push_back(1);
    tester.push_back(2);
    tester.push_back(3);
    tester.push_back(3);

    int popped(tester.pop(0));
    assert(popped == 1);
    tester.push_back(9);
    tester.push_back(8);

    assert(tester.get_size() == 5);
    int popped2(tester.pop(4));
    assert(popped2 == 8);
    assert(tester.get_size() == 4);
}

const void test_remove()
{
    Vector<int> tester;
    tester.push_back(-1);
    tester.push_back(2);
    tester.push_back(-1);
    tester.push_back(4);
    tester.push_back(-1);
    tester.remove(-1);
    assert(tester.get_size() == 2);
    assert(tester.get_value(0) == 2);
    assert(tester.get_value(1) == 4);
}

const void test_set_value()
{
    Vector<int> tester;
    tester.push_back(5);
    tester.push_back(7);
    tester.push_back(9);
    tester.set_value(0, 4);
    assert(tester.get_value(0) == 4);
    assert(tester.get_value(1) == 7);
    assert(tester.get_value(2) == 9);
    tester.set_value(2, 8);
    assert(tester.get_value(2) == 8);
}

const void test_find()
{
    Vector<int> tester;
    tester.push_back(4);
    tester.push_back(7);
    tester.push_back(-5);
    assert(tester.find(5) == -1);
    assert(tester.find(4) == 0);
    assert(tester.find(7) == 1);
    assert(tester.find(-5) == 2);
}

const void test_insert()
{
    Vector<int> tester;
    tester.push_back(5);
    tester.push_back(7);
    tester.push_back(9);
    tester.insert(0, 4);
    assert(tester.get_value(0) == 4);
    assert(tester.get_value(1) == 5);
    assert(tester.get_value(2) == 7);
    assert(tester.get_value(3) == 9);
    tester.insert(3, 8);
    assert(tester.get_value(3) == 8);
    assert(tester.get_value(4) == 9);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_get_size();
    test_is_empty();
    test_get_value();
    test_get_front();
    test_get_back();
    test_pop_back();
    test_pop();
    test_remove();
    test_set_value();
    test_find();
    test_insert();
    cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
