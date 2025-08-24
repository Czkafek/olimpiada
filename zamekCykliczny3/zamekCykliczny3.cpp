#include <bits/stdc++.h>
using namespace std;

long long int counter = 0;

long long int getLength(long long int n) {
	long long int l = 0;
	for (long long int i = n; i; i /= 10) l++;
	return l == 0 ? 1 : l;
}

bool isFullOfNine(long long int n) {
	string tmp = to_string(n);
	int l = getLength(n);
	for (int i = 0; i < l; i++) {
		if (tmp[i] != '9')
			return false;
	}
	return true;
}

long long int turn(long long int n) {
	string tmp = to_string(n);
	tmp += tmp[0];
	tmp.erase(0, 1);

	return stoi(tmp);
}

int main()
{
	long long int n;
	cin >> n;

	int a = 0;
	while (n != 1) {
		string tmp = to_string(n);
		if (tmp.back() == '0') {
			counter++;
			n = turn(n);
		}
		else if (tmp.back() != '9') {
			counter += 9 - (n % 10);
			n += 9 - (n % 10);
		}
		else if (isFullOfNine(n)) {
			counter++;
			n++;
		}
		else {
			counter++;
			n = turn(n);
		}
	}
	cout << counter;
}