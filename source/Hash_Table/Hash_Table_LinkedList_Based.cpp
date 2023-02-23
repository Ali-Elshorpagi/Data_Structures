#include <iostream>
#include <cassert>

using namespace std;
#define edl '\n'

int hash_num(int value, int n = 65407)
{
    long long m(n);
    return (value % m + m) % m;
}

int hash_string(string str, int n)
{
    long long m(n), sum(0);
    for (int i(0); i < (int)str.size(); ++i)
        sum = (sum * 26 + str[i] - 'a') % m;
    return sum % m;
}

struct Hash_Node
{
    // can change
    const static int INTERNAL_LIMIT = 65407;
    string key;
    string data;
    Hash_Node(string k, string d) : key(k), data(d) {}

    int hash()
    {
        return hash_string(key, INTERNAL_LIMIT);
    }
    void print()
    {
        cout << "(" << key << ", " << data << ")  ";
    }
};

class Hash_Table
{
private:
    struct LinkedHashEntry
    {
        Hash_Node item;
        LinkedHashEntry *next{};
        LinkedHashEntry(Hash_Node item) : item(item) {}
    };
    int table_size;
    LinkedHashEntry **table{};

public:
    Hash_Table(int sz) : table_size(sz)
    {
        table = new LinkedHashEntry *[table_size] {};
    }
    ~Hash_Table()
    {
        for (int i(0); i < table_size; ++i)
        {
            LinkedHashEntry *entry(table[i]);
            while (entry)
            {
                LinkedHashEntry *prev(entry);
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }
    void put(Hash_Node phone)
    {
        int idx(phone.hash() % table_size);
        if (!table[idx]) // first item (head)
            table[idx] = new LinkedHashEntry(phone);
        else
        {
            int flag(0);
            LinkedHashEntry *cur(table[idx]);
            while (cur->next)
            {
                if (cur->item.key == phone.key)
                {
                    cur->item = phone;
                    return;
                }
                cur = cur->next;
            }
            if (cur->item.key == phone.key)
                cur->item = phone;
            else
                cur->next = new LinkedHashEntry(phone);
        }
    }
    void print_all()
    {
        for (int hash(0); hash < table_size; ++hash)
        {
            if (!table[hash])
                continue;
            cout << "Hash " << hash << ": ";
            LinkedHashEntry *tmp(table[hash]);
            while (tmp)
            {
                tmp->item.print();
                tmp = tmp->next;
            }
            cout << "\n";
        }
    }
};