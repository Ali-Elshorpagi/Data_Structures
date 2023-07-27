#include <iostream>
#include <vector>
#include <set>
#include <cassert>

#define edl '\n'

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
    const static int INTERNAL_LIMIT = 65407;
    std::string key;
    std::string data;

    int hash()
    {
        return hash_string_lower_upper_digits(key, INTERNAL_LIMIT);
    }

    Hash_Node(std::string key, std::string data) : key(key), data(data) {}
    void print()
    {
        std::cout << "(" << key << ", " << data << ")  ";
    }
};

class Hash_Table
{
private:
    int table_size;
    std::vector<Hash_Node *> table;
    // to mark a cell as deleted
    Hash_Node *deleted{};

public:
    Hash_Table(int table_size) : table_size(table_size)
    {
        table.resize(table_size);
        deleted = new Hash_Node("", "");
    }
    void put(Hash_Node phone)
    {
        int idx(phone.hash() % table_size), step(0), original_idx(idx);
        do
        {
            if (table[idx] == deleted || !table[idx])
            {
                table[idx] = new Hash_Node(phone.key, phone.data);
                return;
            }
            else if (table[idx]->key == phone.key)
            {
                table[idx]->data = phone.data; // update
                return;
            }
            ++step;
            idx = (original_idx + step * step) % table_size;
        } while (idx != original_idx); // catch that we repeated

        // If we failed: rehash to increase size, then add this element
        rehashing();
        put(phone);
    }

    bool remove(Hash_Node phone)
    {
        int idx(phone.hash() % table_size), step(0), original_idx(idx);
        do
        {
            if (!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->key == phone.key)
            {
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            ++step;
            idx = (original_idx + step * step) % table_size;
        } while (idx != original_idx); // catch that we repeated
        return false;
    }

    bool get(Hash_Node &phone)
    {
        int idx(phone.hash() % table_size), step(0), original_idx(idx);
        do
        {
            if (!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->key == phone.key)
            {
                phone.data = table[idx]->data;
                return true;
            }
            ++step;
            idx = (original_idx + step * step) % table_size;
        } while (idx != original_idx); // catch that we repeated
        return false;
    }

    void rehashing()
    {
        std::cout << "Rehashing..." << edl;
        Hash_Table tmp(2 * table_size);
        for (int hash(0); hash < table_size; ++hash)
        {
            if (table[hash] == deleted || !table[hash])
                continue;
            tmp.put(*table[hash]);
        }
        table_size *= 2;
        table = tmp.table;
    }

    void print_all()
    {
        for (int hash(0); hash < table_size; ++hash)
        {
            std::cout << hash << " ";
            if (table[hash] == deleted)
                std::cout << " X ";
            else if (!table[hash])
                std::cout << " E ";
            else
                table[hash]->print();
            std::cout << edl;
        }
        std::cout << "******************" << edl;
    }
};