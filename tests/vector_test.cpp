#include "../source/Vector.cpp"

const void test_get_size()
{
    Vector<int> vec(3);
    assert(vec.get_size() == 3);
    int elements_added(5);
    for (int i(0); i < elements_added; ++i)
        vec.push_back(i);
    assert(vec.get_size() == 8);
}

const void test_is_empty()
{
    Vector<int> vec(3);
    assert(!vec.is_empty());
}

const void test_get_value()
{
    Vector<int> vec;
    vec.push_back(4), vec.push_back(9), vec.push_back(12);
    assert(vec.get_value(0) == 4);
    assert(vec.get_value(1) == 9);
    assert(vec.get_value(2) == 12);
}

const void test_get_front()
{
    Vector<int> vec;
    vec.push_back(4), vec.push_back(9), vec.push_back(12);
    assert(vec.get_front() == 4);
}

const void test_get_back()
{
    Vector<int> vec;
    vec.push_back(4), vec.push_back(9), vec.push_back(12);
    assert(vec.get_back() == 12);
}

const void test_pop_back()
{
    Vector<int> vec(1);
    vec.push_back(1), vec.push_back(2), vec.push_back(3);

    vec.pop_back();
    assert(vec.get_back() == 2);
    vec.push_back(3);
    assert(vec.get_size() == 4);

    vec.pop_back(), vec.pop_back();
    assert(vec.get_back() == 1);
    assert(vec.get_size() == 2);
}

const void test_pop()
{
    Vector<int> vec;
    vec.push_back(1), vec.push_back(2);
    vec.push_back(3), vec.push_back(3);

    int popped(vec.pop(0));
    assert(popped == 1);
    vec.push_back(9), vec.push_back(8);

    assert(vec.get_size() == 5);
    int popped2(vec.pop(4));
    assert(popped2 == 8);
    assert(vec.get_size() == 4);
}

const void test_remove()
{
    Vector<int> vec;
    vec.push_back(-1), vec.push_back(2);
    vec.push_back(-1), vec.push_back(4), vec.push_back(-1);
    vec.remove(-1);
    assert(vec.get_size() == 2);
    assert(vec.get_value(0) == 2);
    assert(vec.get_value(1) == 4);
}

const void test_set_value()
{
    Vector<int> vec;
    vec.push_back(5), vec.push_back(7), vec.push_back(9);
    vec.set_value(0, 4);
    assert(vec.get_value(0) == 4);
    assert(vec.get_value(1) == 7);
    assert(vec.get_value(2) == 9);
    vec.set_value(2, 8);
    assert(vec.get_value(2) == 8);
}

const void test_find()
{
    Vector<int> vec;
    vec.push_back(4), vec.push_back(7), vec.push_back(-5);
    assert(vec.find(5) == -1);
    assert(vec.find(4) == 0);
    assert(vec.find(7) == 1);
    assert(vec.find(-5) == 2);
}

const void test_insert()
{
    Vector<int> vec;
    vec.push_back(5), vec.push_back(7), vec.push_back(9);
    vec.insert(0, 4);
    assert(vec.get_value(0) == 4);
    assert(vec.get_value(1) == 5);
    assert(vec.get_value(2) == 7);
    assert(vec.get_value(3) == 9);
    vec.insert(3, 8);
    assert(vec.get_value(3) == 8);
    assert(vec.get_value(4) == 9);
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
