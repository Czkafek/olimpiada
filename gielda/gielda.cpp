#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int stakes[MAXN];
long long dp[MAXN];


int main()
{
	int n, x;
	cin >> n >> x;

	for (int i = 1; i < n + 1; i++)
		cin >> stakes[i];

	long long maks = 0 - stakes[1];
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i < n + 1; i++) {
		dp[i] = max(dp[i - 1], maks + stakes[i] - x);
		maks = max(maks, dp[i-1] - stakes[i]);
	}

	cout << dp[n];

}