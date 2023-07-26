#include "../source/Deque.cpp"

const void test_get_size()
{
    Deque<int> deque(2);
    deque.enqueue_front(1), deque.enqueue_front(2);
    assert(deque.get_size() == 2);
}

const void test_is_full()
{
    Deque<int> deque(5);
    for (int i(1); i < 6; ++i)
        deque.enqueue_rear(i);
    assert(deque.is_full());
}

const void test_is_empty()
{
    Deque<int> deque(3);
    assert(deque.is_empty());
}

const void test_dequeue()
{
    Deque<int> deque(5);
    deque.enqueue_rear(1), deque.enqueue_rear(2);
    deque.enqueue_rear(3), deque.enqueue_rear(4);

    deque.dequeue_rear();
    assert(deque.get_size() == 3);

    deque.dequeue_front();
    assert(deque.get_size() == 2);
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
