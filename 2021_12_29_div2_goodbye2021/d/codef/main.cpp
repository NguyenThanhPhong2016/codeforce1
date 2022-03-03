#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		ll x;
		cin >> x;

		int r = 0;
		int amt = 0;
		ll mn = 0;
		for (ll c : v) {
			c -= x;
			if (amt == 0) {
				++amt;
				++r;
				mn = c;
			} else {
				if (mn + c < 0) amt = 0;
				else {
					++amt;
					++r;
					if (c < mn + c) mn = c;
					else mn += c;
				}
			}
		}
		cout << r << '\n';
	}
}
