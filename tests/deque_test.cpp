#include "../source/Deque.cpp"

Deque<int> deque(20);
const void initializing()
{
    for (int i(1); i < 21; ++i)
        deque.enqueue_rear(i);
}

const void test_get_size()
{
    assert(deque.get_size() == 20);
}

const void test_is_full()
{
    assert(deque.is_full() == true);
}

const void test_is_empty()
{
    assert(deque.is_empty() == false);
}

const void test_dequeue()
{
    deque.dequeue_rear();
    assert(deque.get_size() == 19);

    deque.dequeue_front();
    assert(deque.get_size() == 18);
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
