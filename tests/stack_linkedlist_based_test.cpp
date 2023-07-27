#include "../source/Stack_LinkedList_Based.cpp"

Stack_LinkedList_Based<int> stack;
const void initializing()
{
    for (int i(11); i < 20; ++i)
        stack.push(i);
}

const void test_get_size()
{
    assert(stack.get_size() == 9);
}

const void test_is_empty()
{
    assert(stack.is_empty() == false);
}

const void test_pop()
{
    int popped(stack.pop());
    assert(popped == 19);
    stack.push(20);
    int popped2(stack.pop());
    assert(popped2 == 20);
}

const void test_peek()
{
    assert(stack.peek() == 18);
    stack.pop();
    assert(stack.peek() == 17);
    stack.pop();
    assert(stack.peek() == 16);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_size();
    test_is_empty();
    test_pop();
    test_peek();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
