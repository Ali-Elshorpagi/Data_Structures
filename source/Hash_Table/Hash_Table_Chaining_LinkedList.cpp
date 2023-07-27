#include <iostream>
#include <cassert>

#define edl '\n'

int hash_num(int value, int n = 65407)
{
    long long m(n);
    return (value % m + m) % m;
}

int hash_string(std::string str, int n)
{
    long long m(n), sum(0);
    for (int i(0); i < (int)str.size(); ++i)
        sum = (sum * 26 + str[i] - 'a') % m;
    return sum % m;
}

int hash_string_lower_upper_digits(std::string str, int n = 65407)
{
    int base(2 * 26 + 10); // 26-lower, 26-upper and 10-digits
    long long m(n), sum(0);

    for (int i(0); i < (int)str.size(); ++i)
    {
        // lowers from [0-25], upper [26-51] and digits [52-61]
        int value(0);
        if (islower(str[i]))
            value = str[i] - 'a'; // [0, 25]
        else if (isupper(str[i]))
            value = 26 + str[i] - 'A'; // [26, 51]
        else if (isdigit(str[i]))
            value = 26 + 26 + str[i] - '0'; // [52, 61]
        else
            assert(false); // invalid input
        sum = sum * base + value;
        sum %= m; // reduce to minimize overflows
    }
    return sum;
}

struct Hash_Node
{
    // can change
    const static int INTERNAL_LIMIT = 2147483647;
    std::string key;
    std::string data;
    Hash_Node(std::string k, std::string d) : key(k), data(d) {}

    int hash()
    {
        return hash_string_lower_upper_digits(key, INTERNAL_LIMIT);
    }
    void print()
    {
        std::cout << "(" << key << ", " << data << ")  ";
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
            delete[] table[i];
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
            std::cout << "Hash " << hash << ": ";
            LinkedHashEntry *tmp(table[hash]);
            while (tmp)
            {
                tmp->item.print();
                tmp = tmp->next;
            }
            std::cout << edl;
        }
    }
};