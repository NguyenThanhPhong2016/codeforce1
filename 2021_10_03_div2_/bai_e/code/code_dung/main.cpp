#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], c[N];
map<int, int> mp[2];

int main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int res = 0;
    for (int i = 20; i >= 0; i--) {
        int sum = 0;
        for (int j = 1; j <= n; j ++) {
            if ((a[j] >> i) & 1) {
            	int d = j % 2;
                if (mp[d ^ 1].find(sum) == mp[d ^ 1].end())
                    mp[d ^ 1][sum] = j - 1;

            	sum ^= c[j];
            	if (mp[d].find(sum) != mp[d].end())
                    res = max(res, j - mp[d][sum]);
                c[j] += 1 << i;
            }
            else {
            	sum ^= c[j];
                for(int j = 0; j <= 1; j ++) mp[j].clear();
            }

        }
    }
    cout << res << '\n';
}
