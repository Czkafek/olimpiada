#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000 + 10;

pair<int, int> ranges[MAXN];
int tree[4 * MAXN];
int lazy[4 * MAXN];


int query(int v, int tl, int tr, int l, int r) {
	// Sprawdza czy mieści się całkowicie w tym przedziale, jeśli nie to przekazuje przedział do swoich synów, dodaje do nich swój lazy i wybiera max z ich zwrotów
	if (tl == l && tr == r)
		return tree[v];
	
	if (lazy[v] != 0) {
		tree[2 * v] = lazy[v];
		tree[2 * v + 1] = lazy[v];
		lazy[2 * v] = lazy[v];
		lazy[2 * v + 1] = lazy[v];
		lazy[v] = 0;
	}

	int tm = (tl + tr) / 2;
	int max1 = query(2 * v, tl, tm, l, r);
	int max2 = query(2 * v + 1, tm + 1, tr, l, r);

	return max(max1, max2);
}

void update(int v, int tl, int tr, int l, int r, int x) {
	// Schodzi w dół, aż do znalezienia przedziału, który się całkowicie w nim znajduje i jemu ustawia lazy, a reszczie wchodzącej w przedział zmienia tylko wartość
	if (tl > r || tr < l)
		return;
	tree[v] = max(tree[v], x);
	if (tl >= l && tr <= r)
		lazy[v] = max(lazy[v], x);
	else {
		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, l, r, x);
		update(2 * v + 1, tm + 1, tr, l, r, x);
	}
}


int main()
{
	int d, n;
	cin >> d >> n;

	for (int i = 0; i < n; i++) {
		int l, x;
		cin >> l >> x;
		ranges[i] = make_pair(x, x + l - 1);
	}

	for (int i = 0; i < n; i++) {
		int max = query(0, ranges[i].first, ranges[i].second, ranges[i].first, ranges[i].second); //O(log n)
		update(0, ranges[i].first, ranges[i].second, ranges[i].first, ranges[i].second, max); //O(log n)
	}

	cout << query(0, 0, n-1, 0, n-1);

	//Finalna złożoność O(n * log n)

}