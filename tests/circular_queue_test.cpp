#include "../source/Circular_Queue.cpp"

Circular_Queue<int> c_queue(20);
const void initializing()
{
    for (int i(1); i < 21; ++i)
        c_queue.enqueue(i);
}

const void test_get_size()
{
    assert(c_queue.get_size() == 20);
}

const void test_is_full()
{
    assert(c_queue.is_full() == true);
}

const void test_is_empty()
{
    assert(c_queue.is_empty() == false);
}

const void test_dequeue()
{
    int popped(c_queue.dequeue());
    assert(popped == 1);
    int popped2(c_queue.dequeue());
    assert(popped2 == 2);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_size();
    test_is_full();
    test_is_empty();
    test_dequeue();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
