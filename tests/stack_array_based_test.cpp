#include "../source/Stack_Array_Based.cpp"

Stack_Array_Based<int> stack(10);
const void initializing()
{
    for (int i(1); i < 11; ++i)
        stack.push(i);
}

const void test_get_size()
{
    assert(stack.get_size() == 10);
}

const void test_is_full()
{
    assert(stack.is_full() == true);
}

const void test_is_empty()
{
    assert(stack.is_empty() == false);
}

const void test_pop()
{
    int popped(stack.pop());
    assert(popped == 10);
    stack.push(11);
    int popped2(stack.pop());
    assert(popped2 == 11);
}

const void test_peek()
{
    assert(stack.peek() == 9);
    stack.pop();
    assert(stack.peek() == 8);
    stack.pop();
    assert(stack.peek() == 7);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_size();
    test_is_full();
    test_is_empty();
    test_pop();
    test_peek();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
