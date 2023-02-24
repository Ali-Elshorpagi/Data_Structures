#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;
#define edl '\n'

/* Probing techniques:
 * Linear Probing : index = (init_hash + i) % table_size
 * Quadratic Probing : index = (init_hash + i*i) % table_size
 * Double Hashing (use 2 independent hash functions) : index = (init_hash1 + init_hash2 * i) % table_size
 */

int hash_string_lower_upper_digits(string str, int n = 65407)
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
    int table_size;
    vector<Hash_Node *> table;
    // to mark a cell as deleted
    Hash_Node *deleted{};

public:
    Hash_Table(int sz) : table_size(sz)
    {
        table.resize(table_size);
        deleted = new Hash_Node("", "");
    }
    ~Hash_Table()
    {
        for (int i(0); i < table_size; ++i)
            delete table[i];
        delete[] deleted;
    }
    bool put(Hash_Node phone)
    {
        int idx(phone.hash() % table_size);
        // We max move table_size steps
        for (int step(0); step < table_size; ++step)
        {
            if (table[idx] == deleted || !table[idx]) // empty
            {
                table[idx] = new Hash_Node(phone.key, phone.data);
                return true;
            }
            else if (table[idx]->key == phone.key)
            {
                table[idx]->data = phone.data; // update
                return true;
            }
            idx = (idx + 1) % table_size; // move next
        }
        return false; // can't insert. Full table
    }

    bool remove(Hash_Node phone)
    {
        int idx(phone.hash() % table_size);

        for (int step(0); step < table_size; ++step)
        {
            if (!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->key == phone.key)
            {
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            idx = (idx + 1) % table_size; // move next
        }
        return false;
    }

    bool get(Hash_Node &phone)
    {
        int idx(phone.hash() % table_size);

        for (int step(0); step < table_size; ++step)
        {
            if (!table[idx])
                break;
            if (table[idx] != deleted && table[idx]->key == phone.key)
            {
                phone.data = table[idx]->data;
                return true;
            }
            idx = (idx + 1) % table_size; // move next
        }
        return false;
    }

    void print_all()
    {
        for (int hash(0); hash < table_size; ++hash)
        {
            cout << hash << " ";
            if (table[hash] == deleted)
                cout << " X ";
            else if (!table[hash])
                cout << " E ";
            else
                table[hash]->print();
            cout << edl;
        }
        cout << "******************" << edl;
    }
};

int count_unique_substrings(const string &str, unordered_set<string> &us) // O(L^2 * log(L))
{
    for (int i(0); i < (int)str.size(); ++i)
    {
        string ans("");
        for (int j(i); j < (int)str.size(); ++j)
            ans = ans + str[j], us.insert(ans); // O(log(L)
    }
    return (int)us.size();

    /* Another Solution Using Letter Tree */
    // Note: Using a trie: we can efficiently solve it in O(L^2)
    // Don't create the string and add to trie
    // For every stating position: let the second loop keep inserting
    // In trie letter by letter and mark as leaf
    // Hence overall only 2 loops
}

int count_substrings_match(const string &str1, const string &str2)
{
    unordered_set<string> us1, us2;
    count_unique_substrings(str1, us1);
    count_unique_substrings(str2, us2);
    int cnt(0);
    for (auto &it : us1)
        cnt += us2.count(it);
    return cnt;
}

int count_anagram_substrings(const string &str) // O(L^3 * log(L))
{
    unordered_set<string> us;
    for (int i(0); i < (int)str.size(); ++i)
    {
        string ans("");
        for (int j(i); j < (int)str.size(); ++j)
        {
            ans = ans + str[j];
            sort(ans.begin(), ans.end()); // O(L* log(L))
            us.insert(ans);               // O(log(L))
        }
    }
    return (int)us.size();
    // can be implemented in O(L^3) by representing each string as a freq of letters;
}