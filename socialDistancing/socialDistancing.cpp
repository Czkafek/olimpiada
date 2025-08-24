#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXM = 100000 + 10;
pair<ll, ll> queries[MAXM];

int main()
{
	ll n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	sort(queries, queries + m);

	ll l = 1, r = queries[m - 1].second;


	while (l < r) {
		ll mid = (l + r + 1) / 2;
		int positioned = 0;
		int i = 0;
		ll current = queries[0].first;
		while (positioned < n && i < m) {
			if (current >= queries[i].first && current <= queries[i].second) {
				positioned++;
				current += mid;
			}
			else {
				if (current < queries[i].first)
					current = queries[i].first;
				else
					while (i < m && current > queries[i].second) {
						i++;
					}
			}
		}
		if (positioned < n)
			r = mid - 1;
		else
			l = mid;
	}

	cout << l;
}