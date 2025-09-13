#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60000 + 10;
int values[MAXN];
pair<int, int> scaling[MAXN];
const int base = 1 << 16;
int tree[2 * base];

int query(int l, int r) {
	l = l + base - 1;
	r = r + base + 1;
	int result = 0;

	while (l/2 != r/2) {
		if (l % 2 == 0) result += tree[l + 1];
		if (r % 2 == 1) result += tree[r - 1];
		l /= 2;
		r /= 2;	
	}
	return result;
}

void add(int index) {
	index = index + base;
	tree[index]++;
	index /= 2;
	while (index > 0) {
		tree[index]++;
		index /= 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		scaling[i] = make_pair(tmp, i);
	}

	sort(scaling, scaling + n);

	int x = 0;
	values[scaling[0].second] = x;
	for (int i = 1; i < n; i++) {
		if (scaling[i].first > scaling[i - 1].first) x++;
		values[scaling[i].second] = x;
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += query(values[i] + 1, n);
		add(values[i]);
	}
	
	cout << result;

}