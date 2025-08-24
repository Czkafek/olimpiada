#include <bits/stdc++.h>
using namespace std;

const int MAXW = 1e5 + 10;
const int MAXN = 100 + 10;

pair<int, int> items[MAXN];
long long backpack[MAXW];

int main()
{
	int n, w;
	cin >> n >> w;

	for (int i = 0; i < n; i++)
		cin >> items[i].first >> items[i].second;

	for (int i = 0; i < w+1; i++)
		backpack[i] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = w; j > 0; j--) {
			if (items[i].first > j)
				break;

			backpack[j] = max(backpack[j], items[i].second + backpack[j - items[i].first]);
		}
	}

	cout << backpack[w];



}