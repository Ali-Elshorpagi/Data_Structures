#include "../source/Circular_Queue.cpp"

const void test_get_size()
{
    Circular_Queue<int> c_queue(8);
    assert(c_queue.get_size() == 8);
}

const void test_is_full()
{
    Circular_Queue<int> c_queue(5);
    for (int i(1); i < 6; ++i)
        c_queue.enqueue(i);
    assert(c_queue.is_full());
}

const void test_is_empty()
{
    Circular_Queue<int> c_queue(3);
    assert(c_queue.is_empty());
}

const void test_dequeue()
{
    Circular_Queue<int> c_queue(9);
    c_queue.enqueue(1), c_queue.enqueue(2);
    c_queue.enqueue(3), c_queue.enqueue(3);

    int popped(c_queue.dequeue());
    assert(popped == 1);
    c_queue.enqueue(9), c_queue.enqueue(8);
    int popped2(c_queue.dequeue());
    assert(popped2 == 2);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_get_size();
    test_is_full();
    test_is_empty();
    test_dequeue();
    cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
