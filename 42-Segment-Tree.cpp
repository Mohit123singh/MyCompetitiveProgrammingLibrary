#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

class segmentTree {
private: int seg[4 * N], lazy[4 * N];
public:

	segmentTree()
	{
		memset(seg, 0, sizeof(seg));
		memset(lazy, 0, sizeof(lazy));
	}

	void build(int index, int l, int h)
	{
		if (l == h)
		{
			seg[index] = a[l];
			return;
		}
		int mid = (l + h) / 2;
		build(2 * index + 1, l, mid);
		build(2 * index + 2, mid + 1, h);
		seg[index] = (seg[2 * index + 1] + seg[2 * index + 2]);
	}

	void pointUpdate(int index, int node, int val, int l, int h)
	{
		if (l == h)
		{
			seg[index] += val;
			a[l] += val;
			return;
		}

		int mid = (l + h) / 2;

		if (node >= l and node <= mid)
			pointUpdate(2 * index + 1, node, val, l, mid);
		else
			pointUpdate(2 * index + 2, node, val, mid + 1, h);

		seg[index] = seg[2 * index + 1] + seg[2 * index + 2];

	}

	int query(int index, int left, int right, int l, int h)
	{
		if (left > h || right < l || l > h)
			return 0;

		if (l >= left and h <= right)
			return seg[index];

		int mid = (l + h) / 2;

		int left_part = query(2 * index + 1, left, right, l, mid);

		int right_part = query(2 * index + 2, left, right, mid + 1, h);

		return left_part + right_part;
	}

	void rangeUpdate(int index, int left, int right, int val, int l, int h)
	{
		if (lazy[index])
		{
			seg[index] += (h - l + 1) * lazy[index];

			if (l != h)
			{
				lazy[2 * index + 1] += lazy[index];
				lazy[2 * index + 2] += lazy[index];
			}
		}

		if (left > h || right < l || l > h)
			return;

		if (l >= left and h <= right)
		{
			seg[index] += (h - l + 1) * val;
			if (l != h)
			{
				lazy[2 * index + 1] += val;
				lazy[2 * index + 2] += val;
			}
		}
		int mid = (l + h) / 2;
		rangeUpdate(2 * index + 1, left, right, val, l, mid);
		rangeUpdate(2 * index + 2, left, right, val, mid + 1, h);
		seg[index] = (seg[2 * index + 1] + seg[2 * index + 2]);

	}

	int queryRange(int index, int left, int right, int l, int h)
	{
		if (lazy[index])
		{
			seg[index] += (h - l + 1) * lazy[index];

			if (l != h)
			{
				lazy[2 * index + 1] += lazy[index];
				lazy[2 * index + 2] += lazy[index];
			}
		}

		if (l > right || h < left || l > h)
			return 0;

		if (l >= left and h <= right)
			return seg[index];

		int mid = (l + h) / 2;

		int left_part = queryRange(2 * index + 1, left, right, l, mid);
		int right_part = queryRange(2 * index + 2, left, right, mid + 1, h);
		return left_part + right_part;
	}

};

// Problem 1 : https://codeforces.com/contest/339/problem/D
// Solution : https://codeforces.com/contest/339/submission/160376342
