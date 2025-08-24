
#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long int a, b, c, d;

	cin >> a >> b >> c >> d;

	unsigned long long int area = c * d;
	unsigned long long int bigger = max(a, b);
	unsigned long long int smaller = min(a, b);

	bool isPossible = true;

	for (unsigned long long int i = 1; i < area / 2; i++) {
		if (i > smaller) {
			isPossible = false;
			break;
		}
		else if (area % i == 0 && area / i <= bigger) {
			break;
		}
	}

	if (isPossible) {
		cout << "TAK";
	}
	else {
		cout << "NIE";
	}

}