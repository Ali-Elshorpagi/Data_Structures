#include "test/include.cpp"

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE
#define Mesh_Ali (ios_base::sync_with_stdio(false), cin.tie(NULL))
#define edl '\n'

struct Node
{
	int data{};
	Node *next{};
	Node(int d) : data(d) {}
};

class Linked_list
{
	Node *head{};
	Node *tail{};
	int length{};

public:
	Linked_list() {}
	~Linked_list()
	{
		while (head)
		{
			Node *cur(head->next);
			delete head;
			head = cur;
		}
		head = nullptr;
		tail = nullptr;
	}
	void insert_end(int val)
	{
		Node *item(new Node(val));
		if (!head)
			head = tail = item;
		else
		{
			tail->next = item;
			tail = item;
		}
		tail->next = nullptr;
		++length;
	}
	void insert_front(int val)
	{
		Node *item(new Node(val));
		if (!head)
			head = tail = item; // 1 2 3
		else
		{
			item->next = head;
			head = item;
		}
		++length;
	}
	void print()
	{
		for (Node *cur(head); cur; cur = cur->next)
			cout << cur->data << ' ';
		cout << edl;
	}
	Node *get_nth(int n)
	{
		for (Node *cur(head); cur; cur = cur->next)
		{
			if (!(--n))
				return cur;
		}
		return nullptr;
	}

	void reverse()
	{
		if (length < 2)
			return;
		Node *prev(nullptr);
		Node *curr(head);
		while (curr)
		{
			Node *nxt(curr->next);
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		tail = head;
		head = prev;
		tail->next = nullptr;
	}
	Node *get_head() { return head; }
	int getMax(Node *head)
	{
		if (head == nullptr)
		{
			return INT_MIN;
		}
		else
		{
			int maxRest = getMax(head->next);
			return max(head->data, maxRest);
		}
	}
	int max_value(Node *h)
	{
		if (!h)
			return INT_MIN;
		else
		{
			int mx_val(max_value(h->next));
			return max(h->data, mx_val);
		}
	}
};

int main()
{
	Mesh_Ali;
	// freopen("test/input.txt", "r", stdin);
	freopen("test/output.txt", "w", stdout);
	Singly_LinkedList<int> list;
	// Linked_list list;
	list.insert_end(1);
	list.insert_end(-2);
	list.insert_end(3);
	list.insert_front(58);
	list.insert_front(5);
	list.insert_end(8);
	list.insert_end(9);
	list.insert_end(2);
	list.insert_end(12);
	list.insert_end(45);
	list.print();
	cout << list.max_value() << edl
		 << list.min_value() << edl;
	list.reverse();
	list.print();

	cout << edl << "DONE" << edl;
	return (0);
}