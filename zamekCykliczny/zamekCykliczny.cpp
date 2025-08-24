#include <bits/stdc++.h>
using namespace std;

string clearZeros(long long int n) {
	string tmp = to_string(n);
	tmp.erase(std::remove(tmp.begin(), tmp.end() - 1, '0'), tmp.end() - 1);
	return tmp;
}
long long int getLength(long long int n) {
	long long int l = 0;
	for (long long int i = n; i; i /= 10) l++;
	return l == 0 ? 1 : l;
}

int main()
{
	long long int n;
	cin >> n;

	string tmp = clearZeros(n);
	n = stoi(tmp);

	long long int counter = 0;
	while (n != 1) {
		if (n == 0) {
			n++;
			counter++;
		}
		else if (n % 10 == 0) {
			tmp = clearZeros(n);
			long long int l = getLength(stoi(tmp));
			tmp.erase(tmp.end() - 1);
			n = stoi(tmp);
			counter += (l - 1);
		}
		else {
			counter += 10 - n % 10;
			n += 10 - n % 10;
		}
	}
	cout << counter;
}