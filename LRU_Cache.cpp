#include<bits/stdc++.h>
using namespace std;
/*
Design an LRU cache

Constraints and assumptions

What are we caching?
We are caching the results of web queries

Can we assume inputs are valid or do we have to validate them?
Assume they're valid

Can we assume this fits memory?
Yes
*/
class Node {
public:
	int key, val;
	Node *prev, *next;

	Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
};

class DLL {
private:
	Node *head = new Node(-1, -1);
	Node *tail = new Node(-1, -1);
public:
	DLL() {
		head->next = tail;
		tail->prev = head;
	}

	void insert(Node *cur) {
		Node *nxt = head->next;

		head->next = cur;
		cur->prev = head;

		nxt->prev = cur;
		cur->next = nxt;
	}

	void remove(Node *cur) {
		Node *pre = cur->prev;
		Node *nxt = cur->next;

		cur->prev = NULL;
		cur->next = NULL;

		pre->next = nxt;
		nxt->prev = pre;
	}

	Node* add(int key, int val) {
		Node *cur = new Node(key, val);
		insert(cur);
		return cur;
	}

	void add(Node *cur) {
		remove(cur);
		insert(cur);
	}

	int pop() {
		Node *cur = tail->prev;
		int key = cur->key;

		remove(cur);
		delete cur;

		return key;
	}
};

class LRUCache {
private:
	int capacity, cnt;
	DLL linked_list;
	unordered_map<int, Node*> mp;

public:
	LRUCache(int capacity) : capacity(capacity), cnt(0) {}

	int get(int key) {
		auto it = mp.find(key);

		if (it != mp.end()) {
			Node *cur = it->second;
			linked_list.add(cur);
			return cur->val;
		}
		return -1;
	}

	void put(int key, int val) {
		auto it = mp.find(key);

		if (it != mp.end()) {
			Node *cur = it->second;
			cur->val = val;
			linked_list.add(cur);
		}
		else {
			if (cnt == capacity) {
				cnt--;
				mp.erase(linked_list.pop());
			}
			cnt++;
			mp[key] = linked_list.add(key, val);
		}
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	LRUCache L(2);
	L.put(2, 1);
	L.put(1, 4);
	L.put(5, 6);
	cout << L.get(1) << "\n";
	cout << L.get(2) << "\n";


	return 0;
}