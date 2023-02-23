#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <string>

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

int hash_string_lower_upper_digits(string str, int n = 65407)
{
    int base(2 * 26 + 10); // lower, upper and 10 digits
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
            assert(false);        // invalid input
        sum = sum * base + value; // base 26 number
        sum %= m;                 // reduce to minimize overflows
    }
    return sum;
}

int hash_string_folding(string str, int n = 65407)
{
    long long m(n), sum(0);
    for (int i(0); i < (int)str.size(); i += 4)
    {
        string block(str.substr(i, 4));
        sum += hash_string_lower_upper_digits(block);
        sum %= m;
    }
    return sum;
}

struct Hash_Node
{
    const static int INTERNAL_LIMIT = 65407;
    string key;
    string data;

    Hash_Node(string key, string data) : key(key), data(data) {}
    int hash()
    {
        return hash_string_lower_upper_digits(key, INTERNAL_LIMIT);
    }
    void print()
    {
        cout << "(" << key << ", " << data << ")  ";
    }
};

class Hash_Table
{
private:
    int table_size{};
    double limit_load_factor{};
    int added_elements{};
    vector<vector<Hash_Node>> table;
    // we can use others: e.g. list<Hash_Node>
public:
    Hash_Table(int sz, double llf) : table_size(sz), limit_load_factor(llf)
    {
        table.resize(table_size);
    }

    bool get(Hash_Node &phone)
    {
        int idx(phone.hash() % table_size);
        for (int i(0); i < (int)table[idx].size(); ++i)
        {
            if (table[idx][i].key == phone.key)
            {
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }
    void put(Hash_Node phone)
    {
        int idx(phone.hash() % table_size);
        for (int i(0); i < (int)table[idx].size(); ++i)
        {
            if (table[idx][i].key == phone.key)
            {
                table[idx][i] = phone;
                return;
            }
        }
        ++added_elements;
        rehashing();
        table[idx].push_back(phone);
    }
    void rehashing()
    {
        double cur_load_factor((double)added_elements / table_size);
        // cout << cur_load_factor << edl;
        if (cur_load_factor < limit_load_factor)
            return;

        Hash_Table tmp(2 * table_size, limit_load_factor);
        for (int i(0); i < table_size; ++i)
        {
            if (!table[i].size())
                continue;
            for (int j(0); j < (int)table[i].size(); ++j)
                tmp.put(table[i][j]);
        }
        table_size <<= 1;
        table = tmp.table;
    }
    bool remove(Hash_Node phone)
    {
        int idx(phone.hash() % table_size);
        for (int i(0); i < (int)table[idx].size(); ++i)
        {
            if (table[idx][i].key == phone.key)
            {
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                --added_elements;
                rehashing();
                return true;
            }
        }
        return false;
    }
    void print_all()
    {
        for (int i(0); i < table_size; ++i)
        {
            if (!table[i].size())
                continue;

            cout << "Hash " << i << ": ";
            for (int j(0); j < (int)table[i].size(); ++j)
                table[i][j].print();
            cout << edl;
        }
    }
};