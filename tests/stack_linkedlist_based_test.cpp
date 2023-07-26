#include "../source/Stack_LinkedList_Based.cpp"

const void test_get_size()
{
    Stack_LinkedList_Based<int> stack;
    for (int i(1); i < 10; ++i)
        stack.push(i);
    assert(stack.get_size() == 9);
}

const void test_is_empty()
{
    Stack_LinkedList_Based<int> stack;
    stack.push(4);
    assert(!stack.is_empty());
}

const void test_pop()
{
    Stack_LinkedList_Based<int> stack;
    stack.push(1), stack.push(2);
    stack.push(3), stack.push(4);
    int popped(stack.pop());
    assert(popped == 4);
    stack.push(9), stack.push(8);
    int popped2(stack.pop());
    assert(popped2 == 8);
}

const void test_peek()
{
    Stack_LinkedList_Based<int> stack;
    stack.push(-1), stack.push(2);
    stack.push(9), stack.push(4), stack.push(-1);
    assert(stack.peek() == -1);
    stack.pop();
    assert(stack.peek() == 4);
    stack.pop();
    assert(stack.peek() == 9);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_get_size();
    test_is_empty();
    test_pop();
    test_peek();
    cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
