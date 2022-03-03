#include <bits/stdc++.h>

using namespace std;

inline void minimize(long long &a, long long b) {
	if (a >= b) a = b;
}
const int N = 1e4+ 10 ;
int n ;
long long dp[N][N] ;
const long long INF = 1e16;
long long sum[N] ;
long long get_sum(int i , int j ){
    return sum[j] - sum[i-1] ;
}
int dem = 0 ;
int main() {
	srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
  //  n = 1000 ;
	vector<int> a(n + 1);
	//vector<long long> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		 cin >> a[i];
	//	a[i] = i + 1 ;
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 0 ; i <= n ; i++){
        for(int j =  0 ; j <= n ; j++){
            dp[i][j] = INF ;
        }
	}
	//vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		dp[i][1] = sum[i];
		int cur = 1;
		for (int j = 2; j <= i; j++) {
			minimize(dp[i][j], max(dp[cur][j - 1], get_sum(cur + 1, i)));
			if (cur + 2 <= i) minimize(dp[i][j], max(dp[cur + 1][j - 1], get_sum(cur + 2, i)));
			cur = max( cur, j - 1 ) ;
			dem++ ;
			while (cur + 1 < i && dp[cur + 1][j - 1] <= get_sum(cur + 2, i)) {
				dem++ ;
				minimize(dp[i][j], max(dp[cur][j - 1], get_sum(cur + 1, i)));
				minimize(dp[i][j], max(dp[cur + 1][j - 1], get_sum(cur + 2, i)));
				cur++;
			}
			if (cur + 1 < i) minimize(dp[i][j], max(dp[cur + 1][j - 1], get_sum(cur + 2, i)));
		}
	}
	//cout << dp[3][1] << endl;

	// naive:
	/*vector<long long> p(n + 1);
	for (int k = 1; k <= n; k++) {
		long long lo = 0, hi = 1e16, res = -1;
		while (lo <= hi) {
			long long mid = (lo + hi) >> 1;
			int nseg = 0;
			int i = 1;
			while (i <= n) {
				if (a[i] > mid) {
					nseg = n + 100;
					break;
				}
				long long cur_sum = 0;
				int nxt = -1;
				for (int j = i; j <= n; j++) {
					cur_sum += a[j];
					if (cur_sum > mid) {
						nxt = j;
						cur_sum -= a[j];
						break;
					}
				}
				nseg++;
				if (nxt == -1) break;
				i = nxt;
			}
			if (nseg <= k) {
				res = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		cout << res << " ";
		p[k] = res;
	}
	cout << "\n";*/

	for (int i = 1; i <= n; i++) {
		cout << dp[n][i] << " ";
		//assert(dp[n][i] == p[i]);
	}
// cout<<"Dem : "<<dem<<endl;
	return 0;
}
