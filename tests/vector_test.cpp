#include "../source/Vector.cpp"

Vector<int> vec;
const void initializing()
{
    for (int i(0); i < 20; ++i)
        vec.push_back(i);
}

const void test_get_size()
{
    assert(vec.get_size() == 20);
    int elements_added(5);
    for (int i(0); i < elements_added; ++i)
        vec.push_back(i);
    assert(vec.get_size() == 25);
}

const void test_is_empty()
{
    assert(vec.is_empty() == false);
}

const void test_get_value()
{
    assert(vec.get_value(10) == 10);
    assert(vec.get_value(15) == 15);
    assert(vec.get_value(2) == 2);
}

const void test_get_front()
{
    assert(vec.get_front() == 0);
}

const void test_get_back()
{
    assert(vec.get_back() == 4);
}

const void test_pop_back()
{
    vec.pop_back();
    assert(vec.get_back() == 3);
    vec.push_back(-5);
    assert(vec.get_size() == 25);

    vec.pop_back(), vec.pop_back();
    assert(vec.get_back() == 2);
    assert(vec.get_size() == 23);
}

const void test_pop()
{
    int popped(vec.pop(1));
    assert(popped == 1);
    assert(vec.get_size() == 22);
    int popped2(vec.pop(4));
    assert(popped2 == 5);
    assert(vec.get_size() == 21);
}

const void test_remove()
{
    vec.push_back(-1), vec.push_back(-1), vec.push_back(-1);
    vec.remove(-1);
    assert(vec.get_size() == 21);
    assert(vec.get_value(1) == 2);
    assert(vec.get_value(5) == 7);
}

const void test_set_value()
{
    vec.set_value(0, 4);
    assert(vec.get_value(0) == 4);
    assert(vec.get_value(1) == 2);
    assert(vec.get_value(4) == 6);
    vec.set_value(2, 8);
    assert(vec.get_value(2) == 8);
}

const void test_find()
{
    assert(vec.find(5) == -1);
    assert(vec.find(4) == 0);
    assert(vec.find(7) == 5);
    assert(vec.find(-5) == -1);
}

const void test_insert()
{
    vec.insert(0, -2);
    assert(vec.get_value(0) == -2);
    assert(vec.get_value(1) == 4);
    assert(vec.get_value(7) == 8);
    assert(vec.get_value(5) == 6);
    vec.insert(3, 8);
    assert(vec.get_value(3) == 8);
    assert(vec.get_value(5) == 4);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
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
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
