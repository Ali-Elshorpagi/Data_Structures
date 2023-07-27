#ifndef STACK_ARRAY_BASED_CPP
#define STACK_ARRAY_BASED_CPP

#include "../header/Stack_Array_Based.h"

template <class type>
Stack_Array_Based<type>::Stack_Array_Based(int sz) : size(sz), top(-1)
{
    arr = new type[size];
}

template <class type>
Stack_Array_Based<type>::~Stack_Array_Based()
{
    delete[] arr;
    arr = nullptr;
}

template <class type>
const int Stack_Array_Based<type>::get_size()
{
    return size;
}

template <class type>
bool Stack_Array_Based<type>::is_full()
{
    return top == size - 1;
}

template <class type>
bool Stack_Array_Based<type>::is_empty()
{
    return top == -1;
}

template <class type>
void Stack_Array_Based<type>::push(type val)
{
    assert(!is_full());
    arr[++top] = val;
}

template <class type>
type Stack_Array_Based<type>::pop()
{
    assert(!is_empty());
    return arr[top--];
}

template <class type>
type Stack_Array_Based<type>::peek()
{
    assert(!is_empty());
    return arr[top];
}

template <class type>
void Stack_Array_Based<type>::print()
{
    for (int i(top); i > -1; --i)
        std::cout << arr[i] << ' ';
    std::cout << edl;
}

template <class type>
std::string Stack_Array_Based<type>::reverse_subwords(std::string line)
{
    line += ' ';
    std::string ans("");
    int len((int)line.size());
    Stack_Array_Based<char> st(len);
    for (int i(0); i < len; ++i)
    {
        if (line[i] == ' ')
        {
            while (!st.is_empty())
                ans += st.pop();
            ans += ' ';
        }
        else
            st.push(line[i]);
    }
    return ans;
}

template <class type>
int Stack_Array_Based<type>::reverse_num(int num)
{
    if (!num)
        return 0;
    Stack_Array_Based<int> st(51);
    while (num)
        st.push(num % 10), num /= 10;
    int ans(0), i(1);
    while (!st.is_empty())
        ans = st.pop() * i + ans, i *= 10;
    return ans;
}

template <class type>
char Stack_Array_Based<type>::get_open_match(char ch)
{
    if (ch == ')')
        return '(';
    if (ch == ']')
        return '[';
    return '{';
}

template <class type>
bool Stack_Array_Based<type>::valid_parentheses(std::string str)
{
    int len(str.size());
    Stack_Array_Based<char> st(len);
    for (int i(0); i < len; ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else if (st.is_empty() || st.pop() != st.get_open_match(str[i]))
            return false;
    }
    return st.is_empty();
}

template <class type>
std::string Stack_Array_Based<type>::remove_all_adjacent_duplicates(std::string str)
{
    int len(str.size());
    Stack_Array_Based<char> st(len);
    for (int i(0); i < len; ++i)
    {
        if (!st.is_empty() && st.peek() == str[i])
            st.pop();
        else
            st.push(str[i]);
    }
    str = "";
    while (!st.is_empty())
        str = st.pop() + str;
    return str;
}

template <class type>
void Stack_Array_Based<type>::asteroid_collision(std::vector<type> &asteroids)
{
    int len(asteroids.size());
    Stack_Array_Based<type> st(len);
    for (int i(0); i < len; ++i)
    {
        int flag(0);
        while (!st.is_empty() && asteroids[i] < 0 && st.peek() > -1)
        {
            if (st.peek() < -asteroids[i])
            {
                st.pop();
                continue;
            }
            else if (st.peek() == -asteroids[i])
                st.pop();
            flag = 1;
            break;
        }
        if (!flag)
            st.push(asteroids[i]);
    }
    for (int i(0); i <= top; ++i)
        std::cout << st.arr[i] << ' ';
    std::cout << edl;
}

template <class type>
void Stack_Array_Based<type>::insert_at_bottom(type val)
{
    if (is_empty())
        push(val);
    else
    {
        type cur(pop());
        insert_at_bottom(val);
        push(cur);
    }
}

template <class type>
void Stack_Array_Based<type>::reverse()
{
    if (is_empty())
        return;
    type cur(pop());
    reverse();
    insert_at_bottom(cur);
}
#endif