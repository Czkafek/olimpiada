#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2 * 1e5 + 10;

pair<int, int> stations[MAXN];


int main()
{
	int n, m, k;
	cin >> n >> m >> k;



	for (int i = 1; i < n + 1; i++)
		cin >> stations[i].first >> stations[i].second;

	stations[0] = { -1, 0 };
	sort(stations, stations + n + 1);

	stations[0] = { 0, 1e9 + 10 };

	int curStation = 0;
	int cost = 0;
	int tank = k;
	int whileCounter = 0;

	while (true) {

		int lastStation = curStation;
		int min = 0;

		while (lastStation + 1 <= n && stations[lastStation + 1].first <= stations[curStation].first + k) {
			lastStation++;

			if (stations[lastStation].second < stations[min].second)
				min = lastStation;
		}

		if ((lastStation == curStation && curStation != n) || (lastStation == curStation && curStation == n && stations[curStation].first + k < m)) {
			cout << "-1";
			break;
		}
		if (stations[min].second <= stations[curStation].second && curStation != n) {
			int road = stations[min].first - stations[curStation].first;
			road -= tank;
			if (road < 0)
				tank = road * -1;
			else {
				cost += road * stations[curStation].second;
				tank = 0;
			}
			curStation = min;
		}
		else {
			if (stations[curStation].first + k >= m) {
				int road = m - stations[curStation].first;
				road -= tank;
				if (road >= 0) {
					cost += road * stations[curStation].second;
				}
				cout << cost;
				break;
			}
			else {
				int road = stations[lastStation].first - stations[curStation].first;
				road -= tank;
				if (road < 0)
					tank = road * -1;
				else {
					cost += road * stations[curStation].second;
					tank = 0;
				}
				curStation = lastStation;
			}
		}

	}

	cout << "\n";
	cout << "curStation = " << curStation;

	cout << "\n";
	for (int i = 0; i <= n; i++) {
		cout << "\n" << stations[i].first << " " << stations[i].second;
	}
}