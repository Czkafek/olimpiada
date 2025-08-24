#include <bits/stdc++.h>
using namespace std;


const int MAXN = 500 + 10;
const long long MOD = 1e9 + 7;
int players[MAXN];
int points[MAXN];


long long fastPower(long long a, long long b) {
	if (b == 1)
		return a % MOD;
	long long result = fastPower(a, b / 2);
	result = (result * result) % MOD;
	if (b % 2 == 1)
		return (result * a) % MOD;
	return result;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> players[i];
	for (int i = 0; i < n; i++)
		points[i] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			long long player1 = fastPower(players[j], players[i]);
			long long player2 = fastPower(players[i], players[j]);
			if (player1 > player2)
				points[i] += 2;
			else if (player2 > player1)
				points[j] += 2;
			else {
				points[i] += 1;
				points[j] += 1;
			}
		}
	}

	int index = 0;

	for (int i = 0; i < n; i++) {
		if (points[i] > points[index])
			index = i;
	}

	cout << index + 1;
}