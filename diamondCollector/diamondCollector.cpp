#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000 + 10;
int diamonds[MAXN];
int length[MAXN];
int maxPref[MAXN];

bool comp(int a, int b) {
	return a > b;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++) {
		cin >> diamonds[i];
	}

	sort(diamonds + 1, diamonds + n);

	int l = 0, r = 0;
	length[0] = 0;
	diamonds[0] = 0;

	while (l < n) {
		while (r < n && diamonds[r] - diamonds[l+1] <= k) {
			r++; 
			if (diamonds[r] - diamonds[l + 1] <= k)
				length[l + 1] = max(length[l + 1], r - l);
		}
		l++;
	} 

	for (int i = n; i >= 1; i--)
		maxPref[i] = max(maxPref[i + 1], length[i]);

	int wynik = 0;
	l = 0, r = 0;

	while (l < n) {
		while (r < n && diamonds[r] - diamonds[l + 1] <= k) {
			r++;
			if (diamonds[r] - diamonds[l + 1] <= k)
				wynik = max(r - l + maxPref[r + 1], wynik);
		}
		l++;
	}

	cout << wynik;

}