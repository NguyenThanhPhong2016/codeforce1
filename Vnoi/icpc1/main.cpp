#include<bits/stdc++.h>
using namespace std;

#define maxn 202
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}

int n, m, s, t, soluong;
int a[maxn][maxn], f[maxn][maxn];
int q[maxn], la[maxn], e[maxn];
int ans[ maxn ][maxn] ;
void tang() {
	int dt = e[t];
	soluong += dt;
	int v = t;
	while(la[v]!=v) {
		int u = la[v];
		if(u<0) {
			f[v][-u] -= dt;
			v = -u;
		}
		else {
			f[u][v] += dt;
			v = u;
		}
	}
}

bool bfs() {
	int l, r;
	q[l=r=0] = s;
	memset( la, 0, sizeof(la));
	memset( e, 0, sizeof(e));
	la[s] = s;
	e[s] = 1000000000;
	while(l<=r) {
		int u = q[l++];
		for(int v=1;v<=n;++v) if(e[v]==0) {
			if(a[u][v]>f[u][v]) {
				e[v] = min( e[u], a[u][v] - f[u][v]);
				q[++r] = v;
				la[v] = u;
			}
			else if(f[v][u]>0) {
				e[v] = min( e[u], f[v][u]);
				q[++r] = v;
				la[v] = -u;
			}
		}
		if(e[t]!=0) {
			tang();
			return true;
		}
	}
	return false;
}
void solve(int test){
    cin>>n ;
	for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= n ;j++){
            cin>>a[i][j] ;
        }
	}
	for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= n ; j++){
            if( i == j ) continue ;
            soluong = 0 ;
            s = i ; t = j ;
            for(int k = 0 ; k <= n ; k++){
                q[i] = la[ i ] = e[i] = 0 ;
                for(int h = 0 ; h <= n ; h++){
                    f[ k ][h] = 0 ;
                }
            }
           // debug( i ) ; debug(j) ;
            while( bfs() ){
            } ;
       //     debug( soluong ) ;
            ans[i][j] = soluong ;
        }
	}
	cout<<"Case #"<<test<<":"<<endl;

	for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++ ){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
	}
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i = 1 ; i <= t ; i++){
        solve( i );
    }
}
