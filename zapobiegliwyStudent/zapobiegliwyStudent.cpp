#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comparison(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
	return get<2>(a) < get<2>(b);
}

int main()
{
	ll n;
	vector<tuple<ll, ll, ll>> lecture; //id, start, end

	cin >> n;

	for (ll i = 0; i < n; i++) {
		ll start, end;
		cin >> start >> end;
		lecture.push_back(make_tuple(i + 1, start, end));
	}

	sort(lecture.begin(), lecture.end(), comparison);

	vector<int> main;
	ll u_end = 0;

	for (int i = 0; i < n; i++) {
		if (get<1>(lecture[i]) >= u_end) {
			main.push_back(get<0>(lecture[i]));
			u_end = get<2>(lecture[i]);
		}
	}

	u_end = 0;
	ll second_u_end = 0;
	ll second_z_end = 0;
	ll z_end = 0;
	vector<int> u;
	vector<int> z;

	for (int i = 0; i < n; i++) {
		if (u.size() == z.size()) {
			if (u_end <= get<1>(lecture[i]) && z_end <= get<1>(lecture[i])) {
				u.push_back(get<0>(lecture[i]));
				if (u_end != 0)
					second_u_end = u_end;
				u_end = get<2>(lecture[i]);
			}
			else if (u_end <= get<1>(lecture[i])) {
				z.push_back(get<0>(lecture[i]));
				if (z_end != 0)
					second_z_end = z_end;
				z_end = get<2>(lecture[i]);
			}
		}
		else if (u.size() + 1 == z.size()) {
			if (u_end <= get<1>(lecture[i]) && second_z_end <= get<1>(lecture[i])) {
				u.push_back(get<0>(lecture[i]));
				if (u_end != 0)
					second_u_end = u_end;
				u_end = get<2>(lecture[i]);
			}
		}
		else {
			if (second_u_end <= get<1>(lecture[i])) {
				z.push_back(get<0>(lecture[i]));
				if (z_end != 0)
					second_z_end = z_end;
				z_end = get<2>(lecture[i]);
			}
		}
	}

	if (main.size() - 1 > min(u.size(), z.size())) {
		cout << main.size() - 1;
		for (int i = 0; i < main.size() - 1; i++)
			cout << "\n" << main[i] << " " << main[main.size() - 1];
	}
	else {
		if (u.size() > z.size())
			cout << z.size();
		else
			cout << u.size();

		for (int i = 0; i < u.size() && i < z.size(); i++) {
			cout << "\n" << u[i] << " " << z[i];
		}
	}
}