#include <bits/stdc++.h>
using namespace std;

int NWD(int a, int b) {
	int pom;
	while (b != 0) {
		pom = b;
		b = a % b;
		a = pom;
	}
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;
	if (n == 1)
		cout << "1\nP";
	else if (m == 1)
		cout << "1\nD";
	else if (NWD(n, m) < 3) {
		cout << "2\nDP";
	}
	else {
		int amount = min(n, m);
		cout << amount << "\n";
		if (n > m) {
			for (int i = 0; i < m - 1; i++)
				cout << "P";
			cout << "D";
		}
		else {
			for (int i = 0; i < amount - 1; i++)
				cout << "D";
			cout << "P";
		}
			
	}
}
