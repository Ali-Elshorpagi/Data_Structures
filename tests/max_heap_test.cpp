#include "../source/Max_Heap.cpp"

std::vector<int> vec{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
Max_Heap<int> heap;

const void initializing()
{
    for (int i(0); i < (int)vec.size(); ++i)
        heap.push(vec[i]);
}

const void test_get_size()
{
    assert(heap.get_size() == (int)vec.size());
}

const void test_search()
{
    assert(heap.search(17) == true), assert(heap.search(27) == false);
    assert(heap.search(7) == true), assert(heap.search(41) == false);
}

const void test_is_empty()
{
    assert(heap.is_empty() == false);
}

const void test_pop_and_top()
{
    heap.pop();
    assert(heap.search(37) == false);
    assert(heap.top() == 30);
    heap.pop(), heap.pop();
    assert(heap.search(30) == false), assert(heap.search(30) == false);
    assert(heap.search(25) == false), assert(heap.top() == 22);
    heap.pop();
    assert(heap.search(22) == false), assert(heap.top() == 19);
}

int main()
{
    freopen("../imports/test/output.txt", "w", stdout);
    initializing();
    test_get_size();
    test_search();
    test_is_empty();
    test_pop_and_top();
    std::cout << edl << "DONE" << edl;
    // you must see 'DONE' in output
    return (0);
}
