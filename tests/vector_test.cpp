#include "../source/Vector.cpp"

using namespace std;
#define edl '\n'

const void test_get_size()
{
    Vector<int> tester(3);
    assert(tester.get_size() != 0);
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

const void test_push_back(){}
// const void test_pop_back();
// const void test_pop();
// const void test_remove();
// const void test_set_value();
// const void test_find();
// const void test_insert();
// const void test_right_rotate();
// const void test_left_rotate();
// const void test_find_transposition();

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    // test_get_size();
    // test_is_empty();
    // test_get_value();
    // test_get_front();
    // test_get_back();
    test_push_back();
    // test_pop_back();
    // test_pop();
    // test_remove();
    // test_set_value();
    // test_find();
    // test_insert();
    // test_right_rotate();
    // test_left_rotate();
    // test_find_transposition();
    cout << edl << "DONE" << edl;
    return (0);
}
