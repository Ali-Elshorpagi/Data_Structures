#include "..\\header\Stack_Array_Based.h"

template <class type>
Stack_Array_Based<type>::Stack_Array_Based(unsigned long long sz) : size(sz), top(-1)
{
    arr = new type[size];
}

template <class type>
Stack_Array_Based<type>::~Stack_Array_Based()
{
    delete[] arr;
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
	for (ll i(top); i > -1; --i)
		cout << arr[i] << " ";
	cout << edl;
}

template <class type>
string Stack_Array_Based<type>::reverse_subwords(string line)
{
	line += ' ';
	string ans = "";
	ll len(line.size());
	Stack_Array_Based<char>st(len);
	for (ll i(0); i < len; ++i)
	{
		if (line[i] == ' ') {
			while (!st.is_empty())
				ans += st.pop();
			ans += ' ';
		}
		else
			st.push(line[i]);
	}
	return ans;
}


