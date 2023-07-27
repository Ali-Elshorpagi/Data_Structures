#include "../source/Queue_LinkedList_Based.cpp"

Queue_LinkedList_Based<int> list_queue;
const void initializing()
{

    for (int i(1); i < 11; ++i)
        list_queue.enqueue(i);
}

const void test_get_size()
{
    assert(list_queue.get_size() == 10);
}

const void test_is_empty()
{
    assert(list_queue.is_empty() == false);
}

const void test_dequeue()
{
    int popped(list_queue.dequeue());
    assert(popped == 1);
    int popped2(list_queue.dequeue());
    assert(popped2 == 2);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_size();
    test_is_empty();
    test_dequeue();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
