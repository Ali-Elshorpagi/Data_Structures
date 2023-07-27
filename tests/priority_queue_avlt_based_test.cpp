#include "../source/Priority_Queue_AVLT_Based.cpp"

Priority_Queue_AVLT_Based<int> Priority_Queue;

const void initializing()
{
    Priority_Queue.enqueue(12, 0);
    Priority_Queue.enqueue(21, 2);
    Priority_Queue.enqueue(35, 3);
    Priority_Queue.enqueue(42, 4);
    Priority_Queue.enqueue(55, 5);
    Priority_Queue.enqueue(77, 6);
    Priority_Queue.enqueue(89, 7);
}

const void test_is_empty()
{
    assert(Priority_Queue.is_empty() == false);
}

const void test_dequeue_and_top()
{
    int dequeued(Priority_Queue.dequeue());
    assert(dequeued == 89);
    Priority_Queue.dequeue(), dequeued = Priority_Queue.dequeue();
    assert(dequeued == 55);
    dequeued = Priority_Queue.dequeue();
    assert(dequeued == 42);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_is_empty();
    test_dequeue_and_top();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
