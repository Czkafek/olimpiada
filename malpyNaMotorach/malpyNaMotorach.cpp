#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 200000 + 10;
pair <ll, ll> checkpoints[MAXN];
ll opponents[MAXN];
priority_queue<ll> results;

int main()
{
	int k, m, n;
	cin >> k >> m >> n;
	for (int i = 0; i < k; i++)
		cin >> checkpoints[i].first >> checkpoints[i].second;
	for (int i = 0; i < m; i++)
		cin >> opponents[i];

	// Sort checkpoints and opponents
	sort(checkpoints, checkpoints + k);
	sort(opponents, opponents + m);

	ll tmpResult = 0;
	int lastCheckpoint = 0;

	// Pierwszy i ostatni przedział bierzemy osobną pętlą
	int j = 0;
	for (; j < k && checkpoints[j].first < opponents[0]; j++) {
		tmpResult += checkpoints[j].second;
	}
	lastCheckpoint = j;
	results.push(tmpResult);
	tmpResult = 0;
	for (int i = k-1; i > -1 && checkpoints[i].first > opponents[m-1]; i--)
		tmpResult += checkpoints[i].second;
	results.push(tmpResult);

	// Pomiędzy przedziałami
	for (int i = 0; i < m - 1; i++) {
		ll whole = 0;
		ll max = 0;
		ll currentSum = 0;
		int nextCheckpoint = lastCheckpoint;
		int lMonkey = i, rMonkey = i + 1;

		if (lastCheckpoint >= k) break;
		
		while (nextCheckpoint < k && checkpoints[nextCheckpoint].first < opponents[rMonkey]) {
			if (nextCheckpoint < lastCheckpoint) {
				nextCheckpoint = lastCheckpoint;
				currentSum = 0;
			}
			if (checkpoints[lastCheckpoint].first - opponents[lMonkey] + opponents[rMonkey] - checkpoints[nextCheckpoint].first > abs(checkpoints[lastCheckpoint].first - checkpoints[nextCheckpoint].first) + 1) {
				whole += checkpoints[nextCheckpoint].second;
				currentSum += checkpoints[nextCheckpoint].second;
				if (currentSum > max)
					max = currentSum;
				nextCheckpoint++;
			}
			else {
				currentSum -= checkpoints[lastCheckpoint].second;
				lastCheckpoint++;
			}
		}

		results.push(max);
		results.push(whole - max);

		lastCheckpoint = nextCheckpoint;
		
	}

	ll result = 0;
	for (int i = 0; i < n && i < k*2; i++) {
		result += results.top();
		results.pop();
	}
	cout << result;
}