#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2 * 1e5 + 10;

pair<ll, ll> stations[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i < n + 1; i++)
		cin >> stations[i].first >> stations[i].second;

	stations[0] = { -1, 0 };
	sort(stations, stations + n + 1);

	stations[0] = { 0, 0 };

	if (stations[n].first + k < m) {
		cout << "-1\n";
		return 0;
	}

	vector<int> nextCheaper(n + 1, -1);
	vector<int> nextMin(n + 1, -1);
	
	stack<int> st;

	for (int i = n; i > -1; i--) {

		while (!st.empty() && (stations[st.top()].second > stations[i].second || stations[st.top()].first > stations[i].first + k)) {
			if (nextMin[i] == -1 && stations[i].first + k >= stations[st.top()].first) {
				nextMin[i] = st.top();
			}
			else if (stations[nextMin[i]].second > stations[st.top()].second && stations[i].first + k >= stations[st.top()].first) {
				nextMin[i] = st.top();
			}
			st.pop();
		}

		if (!st.empty())
			nextCheaper[i] = st.top();

		st.push(i);
	}

	ll curStation = 0;
	ll cost = 0;
	ll tank = k;

	while (true) {
		
		if (nextCheaper[curStation] == -1 && stations[curStation].first + k >= m) {
			ll a = m - stations[curStation].first - tank;
			if (a > 0)
				cost += a * stations[curStation].second;
			cout << cost;
			break;
		}

		if (nextCheaper[curStation] != -1) {
			ll a = stations[nextCheaper[curStation]].first - stations[curStation].first - tank;
			if (a < 0)
				tank = a * -1;
			else {
				cost += a * stations[curStation].second;
				tank = 0;
			}
			curStation = nextCheaper[curStation];
		}
		else if (nextMin[curStation] != -1) {
			cost += (k - tank) * stations[curStation].second;
			tank = k - (stations[nextMin[curStation]].first - stations[curStation].first);
			curStation = nextMin[curStation];
		}
		else {
			cout << -1;
			break;
		}
	}
}