#include <bits/stdc++.h>
using namespace std;

long long int counter = 0;

long long int getLength(long long int n) {
	long long int l = 0;
	for (long long int i = n; i; i /= 10) l++;
	return l == 0 ? 1 : l;
}

long long int replace(long long int n) {
	long long int l = getLength(n);
	string tmp = to_string(n);
	for (int i = 0; i < l; i++) {
		if (tmp[0] != '0') {
			cout << "Jest ";
			tmp += tmp[0];
			counter++;
		}
		tmp.erase(0, 1);
	}
	cout << tmp << endl;
	return stoi(tmp);
}

int main()
{	
	long long int n;
	cin >> n;


	int a = 0;
	while (n != 1) {
		a++;
		cout << "#" << a << endl;
		cout << "counter: " << counter << endl;
		if (n == 0) {
			n++;
			counter++;
		}
		else if (n % 10 == 0) {
			cout << "start: " << n << endl;
			n = replace(n);
			cout << "end: " << n << endl;
			cout << endl;
		}
		else {
			counter += 10 - n % 10;
			n += 10 - n % 10;
		}
	}
	cout << counter;
}