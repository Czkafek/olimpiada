#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
int books[MAXN];

int main()
{
	int n, maxT;
	cin >> n >> maxT;

	for (int i = 1; i < n+1; i++)
		cin >> books[i];

	int l = 0, r = 0;
	int curT = 0;
	int amount = 0;
	
	while (l < n) {
		while (r < n && curT <= maxT) {
			++r;
			curT += books[r];
			if (curT <= maxT) {
				amount = max(r - l, amount);
			}
		}
		++l;
		curT -= books[l];
	}
	cout << amount;

}