#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll, ll>> smaller;
vector<pair<ll, ll>> bigger;
vector<tuple<int, ll, ll, ll, ll>> results;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll total = 0;

	for (int i = 1; i < n+1; i++) {
		ll tmp;
		cin >> tmp;
		if (tmp <= k)
			smaller.push_back({ i, tmp });
		else
			bigger.push_back({ i, tmp });
		total += tmp;
	}

	if (total > n * k)
		cout << "NIE";
	else {
		while (!smaller.empty() && !bigger.empty()) {
			pair<ll, ll> s = smaller.back();
			pair<ll, ll> b = bigger.back();
			smaller.pop_back();
			bigger.pop_back();
			ll rest = k - s.second;
			b.second -= rest;
			results.push_back(make_tuple(2, s.first, s.second, b.first, rest));
			if (b.second > k)
				bigger.push_back(b);
			else
				smaller.push_back(b);
		}
		
		if (!bigger.empty())
			cout << "NIE";
		else {
			cout << "TAK";
			while (!smaller.empty()) {
				results.push_back(make_tuple(1, smaller.back().first, smaller.back().second, 0, 0));
				smaller.pop_back();
			}
			int counter = -1;
			while (++counter < results.size()) {
				if (get<0>(results[counter]) == 1)
					cout << "\n1 " << get<1>(results[counter]) << " " << get<2>(results[counter]);
				else
					cout << "\n2 " << get<1>(results[counter]) << " " << get<2>(results[counter]) << " " << get<3>(results[counter]) << " " << get<4>(results[counter]);
			}
			while (counter++ < n)
				cout << "\n0";
		}
	}
}