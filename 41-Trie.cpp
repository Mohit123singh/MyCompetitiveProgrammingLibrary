#include<bits/stdc++.h>>
using namespace std;


struct Node {

	Node *links[2];
	int cnt = 0;
	bool containsKey(int bit)
	{
		return links[bit] != NULL;
	}
	void put(int bit, Node *node)
	{
		links[bit] = node;
	}
	Node *get(int bit)
	{
		return links[bit];
	}
	void increaseCnt()
	{
		cnt++;
	}
	void decreseCnt()
	{
		cnt--;
	}
	int getCount(int bit)
	{
		return links[bit]->cnt;
	}

};

class Trie {
private: Node *root;
public:
	Trie()
	{
		root = new Node();
	}
	void insert(int x)
	{
		Node *node = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
			if (!node->containsKey(bit))
				node->put(bit, new Node());
			node = node->get(bit);
			node->increaseCnt();
		}
	}
	int getMax(int x)
	{
		Node *node = root;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
			if (node->containsKey(!bit) and node->getCount(!bit))
			{
				ans |= (1 << i);
				node = node->get(!bit);
			}
			else
				node = node->get(bit);
		}
		return ans;
	}

	int getMin(int x)
	{
		Node *node = root;
		int ans = 0;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
			if (node->containsKey(bit) and node->getCount(bit))
				node = node->get(bit);
			else
			{
				ans |= (1 << i);
				node = node->get(!bit);
			}
		}
		return ans;
	}

	void remove(int x)
	{
		Node *node = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (x >> i) & 1;
			node = node->get(bit);
			node->decreseCnt();
		}
	}
};


// Problem1 : https://codeforces.com/contest/706/problem/D
// Solution : https://codeforces.com/contest/706/submission/159881684