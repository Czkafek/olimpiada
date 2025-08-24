#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 10;
int values[MAXN];

int main()
{
	int n, poke;
	cin >> n >> poke;

	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	sort(values, values + n);

	int l = 0, r = n-1, mid;
	bool found = false;

	while (l <= r) {
		mid = (r - l) / 2 + l;

		if (values[mid] == poke) {
			found = true;
			break;
		}
		else if (values[mid] > poke) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	if (found)
		cout << "index: " << mid;
	else 
		cout << "not found";
	return 0;


}