#include<bits/stdc++.h>>
using namespace std;


struct Node{
	
	Node *links[2];
	int cnt=0;
	
	bool containsKey(int bit)
	{
		return links[bit]!=NULL;
	}
	void put(int bit,Node *node)
	{
		links[bit]=node;
	}
	
	Node *get(int bit)
	{
		return links[bit];
	}
};

class Trie{
private:Node *root;
public:
	Trie()
	{
		root=new Node();
	}

	void insert(int x)
	{
		Node *node=root;
		for(int i=31;i>=0;i--)
		{
			int bit=((x>>i)&1);
			if(!node->containsKey(bit))
				node->put(bit,new Node());
			node=node->get(bit);
			node->cnt++;
		}
	}
	
	int maxXor(int x)
	{
		Node *node=root;
		int ans=0;
		for(int i=31;i>=0;i--)
		{
			int bit=((x>>i)&1);
			if(node->containsKey(!bit))
			{
				ans|=(1<<i);
				node=node->get(!bit);
			}
			else
				node=node->get(bit);
		}
		return ans;
	}

	void remove(int x)
	{
		Node *node=root;
		for(int i=31;i>=0;i--)
		{
			int bit=((x>>i)&1);
			node=node->get(bit);
			node->cnt--;
		}
	}

};

// Problem1 : https://codeforces.com/contest/706/problem/D
// Solution : https://codeforces.com/contest/706/submission/159881684