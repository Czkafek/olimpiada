#include <bits/stdc++.h>
using namespace std;

const int MAXT = 1e4 + 10;
long long tests[MAXT];


string hasOddDivisor(long long a) {
	while (a != 1) {
		if (a % 2 == 1)
			return "YES";
		a /= 2;
	}
	return "NOT";
}


int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
		cin >> tests[i];

	for(int i = 0; i < t; i++)
		cout << hasOddDivisor(tests[i]) << endl;
}