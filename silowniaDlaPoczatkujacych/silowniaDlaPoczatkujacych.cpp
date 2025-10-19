#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = n % 8;
	result = result % 3;

	if (result == 0 || (result == 1 && n > 8) || (result == 2 && n > 16))
		cout << "TAK";
	else
		cout << "NIE";
}