#include<bits/stdc++.h>
using namespace std;
/*
Design a hash map

Constraints and assumptions

For simplicity, are the keys integers only?
Yes

For collision resolution, can we use chaining?
Yes

Do we have to worry about load factors?
No

Can we assume inputs are valid or do we have to validate them?
Assume they're valid

Can we assume this fits memory?
Yes
*/
class Item {
public:
    int key, val;
    Item(int key, int val) {
        this->key = key;
        this->val = val;
    }
};

class HashMap {
private:
    int bucket_size;
    vector<vector<Item>> table;

    int getHash(int key) {
        return key % bucket_size;
    }

public:
    HashMap(int bucket_size) {
        this->bucket_size = bucket_size;
        table.resize(bucket_size);
    }

    void set(int key, int val) {
        int bucket = getHash(key);
        for (auto &item : table[bucket]) {
            if (item.key == key) {
                item.val = val;
                return;
            }
        }
        table[bucket].push_back(Item(key, val));
    }

    int get(int key) {
        int bucket = getHash(key);
        for (auto &item : table[bucket]) {
            if (item.key == key) {
                return item.val;
            }
        }
        return -1;
    }

    void remove(int key) {
        int bucket = getHash(key), ind = -1;

        for (int i = 0; i < (int)table[bucket].size(); i++) {
            auto item = table[bucket][i];
            if (item.key == key) {
                ind = i;
                break;
            }
        }

        if (ind != -1) table[bucket].erase(table[bucket].begin() + ind);
        return;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    HashMap H(20);
    H.set(2, 3);
    H.set(22, 1);
    cout << H.get(2) << "\n" << H.get(22) << "\n";
    H.remove(2);
    cout << H.get(2) << "\n" << H.get(22) << "\n";

    return 0;
}