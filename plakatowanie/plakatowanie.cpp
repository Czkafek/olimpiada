#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 250000 + 10;
ll buildings[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int tmp;
		cin >> tmp >> buildings[i];
	}

	vector<ll> posters;
	int result = 1;
	posters.push_back(buildings[1]);

	for (int i = 1; i < n + 1; i++) {
		while (!posters.empty() && buildings[i] < posters.back())
			posters.pop_back();
		if (posters.empty() || buildings[i] > posters.back()) {
			posters.push_back(buildings[i]);
			result++;
		}
	}

	cout << result;
}