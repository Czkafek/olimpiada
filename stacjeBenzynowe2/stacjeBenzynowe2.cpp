#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2 * 1e5 + 10;

pair<ll, ll> stations[MAXN];


int main()
{
	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i < n + 1; i++)
		cin >> stations[i].first >> stations[i].second;

	stations[0] = { -1, 0 };
	sort(stations, stations + n + 1);

	stations[0] = { 0, 1e9 + 10 };

	ll curStation = 0;
	ll cost = 0;
	ll tank = k;

	if (stations[n].first + k < m)
		cout << "-1";
	else {
		while (true) {

			ll min = 0;
			ll lastStation = curStation;

			while (lastStation + 1 <= n && stations[lastStation + 1].first <= stations[curStation].first + k) {
				lastStation++;

				if (stations[lastStation].second < stations[min].second)
					min = lastStation;
			}

			if (curStation != n && curStation == lastStation) {
				cout << "-1";
				break;
			}

			if (stations[min].second <= stations[curStation].second) {
				ll a = stations[min].first - stations[curStation].first - tank;
				if (a < 0)
					tank = a * -1;
				else {
					cost += a * stations[curStation].second;
					tank = 0;
				}
				curStation = min;
			}
			else {
				if (stations[curStation].first + k >= m) {
					ll a = m - stations[curStation].first - tank;
					if (a > 0)
						cost += a * stations[curStation].second;
					cout << cost;
					break;
				}
				else {
					ll a = stations[lastStation].first - stations[curStation].first - tank;
					if (a < 0)
						tank = a * -1;
					else {
						cost += a * stations[curStation].second;
						tank = 0;
					}
					curStation = lastStation;
				}
			}

		}
	}
}