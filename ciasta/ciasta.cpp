#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 33;
bool isUsed[MAXN];
vector<int> prime;

int main()
{
	int n;
	cin >> n;

	// Sito
	for (int i = 2; i < n + 1; i++) {
		if (!isUsed[i]) {
			prime.push_back(i);
			for (int j = i + i; j < n + 1; j += i) {
				isUsed[j] = true;
			}
		}
	}

	ll wynik = 1;

	for (int i = 0; i < prime.size(); i++) {
		int count = 0;
		ll val = prime[i];
		while (val <= n) {
			count++;
			val *= prime[i];
		}
		wynik = (wynik * count) % MOD;
	}

	cout << wynik;
}