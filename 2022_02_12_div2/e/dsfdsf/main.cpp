#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &x : a) {
        x = rand() % 10000 ;
        cnt[x]++;
    }

    vector<pair<int, int>> bad_pairs;
    bad_pairs.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        bad_pairs.emplace_back(x, y);
        bad_pairs.emplace_back(y, x);
    }
    sort(bad_pairs.begin(), bad_pairs.end());

    vector<vector<int>> occ(n);
    for (auto &[x, c] : cnt)
        occ[c].push_back(x);

    for (auto &v : occ)
        reverse(v.begin(), v.end());
    int dem = 0;
    long long answer = 0;
    for (int cnt_x = 1; cnt_x < n; cnt_x++)
        for (int x : occ[cnt_x])
            for (int cnt_y = 1; cnt_y <= cnt_x; cnt_y++)
                for (auto y : occ[cnt_y]){
                    dem++ ;
                    if (x != y && !binary_search(bad_pairs.begin(), bad_pairs.end(), pair<int, int>{x, y})) {
                        answer = max(answer, 1ll * (cnt_x + cnt_y) * (x + y));
                        break;
                    }
                }

    cout<<"dem" << dem<<endl;
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
