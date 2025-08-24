#include <bits/stdc++.h>
using namespace std;

bool isFit(long long m1, long long m2, long long d1, long long d2) {
	if ((m1 <= d1 && m2 <= d2) || (m2 <= d1 && m1 <= d2)) {
		return 1;
	}
	return 0;
 }

int main()
{
	long long a, b, c, d;

	cin >> a >> b >> c >> d;

	vector<long long> cFactors;
	vector<long long> dFactors;

	for (int i = 1; i <= sqrt(c)+2; i++) {
		if (c % i == 0) {
			cFactors.push_back(i);
			cFactors.push_back(c / i);
		}
	}

	for (int i = 1; i <= sqrt(d)+2; i++) {
		if (d % i == 0) {
			dFactors.push_back(i);
			dFactors.push_back(d / i);
		}
	}
		
	long long area = c * d;

	for (int i = 0; i < cFactors.size(); i++) {
		for (int j = 0; j < dFactors.size(); j++) {
			long long tmp = cFactors[i] * dFactors[j];
			if (isFit(tmp, area / tmp, a, b)) {
				cout << "TAK";
				return 0;
			}
		}
	}
	cout << "NIE";

}