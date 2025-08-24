#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	long long int a, b;
	cin >> a >> b;

	long long int elementsAmount = b - a + 1;
	long long int rest = elementsAmount % 4;

	if (rest == 0)
		rest = 4;
	else if (rest == 1)
		rest = 3;

	long long int result = elementsAmount - 4 + rest;

	cout << result;

}