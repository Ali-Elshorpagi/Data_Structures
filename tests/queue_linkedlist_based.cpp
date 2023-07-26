#include "../source/Queue_LinkedList_Based.cpp"

const void test_get_size()
{
    Queue_LinkedList_Based<int> list_queue;
    for (int i(1); i < 6; ++i)
        list_queue.enqueue(i);
    assert(list_queue.get_size() == 5);
}

const void test_is_empty()
{
    Queue_LinkedList_Based<int> list_queue;
    assert(list_queue.is_empty());
}

const void test_dequeue()
{
    Queue_LinkedList_Based<int> list_queue;
    list_queue.enqueue(1), list_queue.enqueue(2);
    list_queue.enqueue(3), list_queue.enqueue(4);

    int popped(list_queue.dequeue());
    assert(popped == 1);
    list_queue.enqueue(9), list_queue.enqueue(8);
    int popped2(list_queue.dequeue());
    assert(popped2 == 2);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    test_get_size();
    test_is_empty();
    test_dequeue();
    cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
