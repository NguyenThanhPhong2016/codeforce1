#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
void invector( vector< int > p ){
    cout<<" in p : ";
    for(auto x : p ){
        cout<<x<<" ";
    }
    cout<<endl;
}
/*
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10  ;
int fac[N];
int inv[N];
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10 ;
pair< int , ii > a[N] ;
int par[N] ;
int root( int id  ){
    return par[id] == id ? id : par[id] = root(  par[id] ) ;
}

signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ; cin>>n>>m ;
    for(int i = 0 ;i < m ; i++){
        cin>>a[i].se.fi>>a[i].se.se>>a[i].fi ;
    }
    sort( a , a + m ) ;
    for(int i = 1 ;i <= n ;i++){
        par[i] = i ;
    }
    int ans = 0 ;
    for(int i = 0 ; i< m ; i++){
        auto &[u,v] = a[i].se ;
        auto &w = a[i].fi ;
        u = root(u) ;
        v = root(v) ;
        if( u== v ) continue;
        ans += w;
        par[u] = v;
    }
    cout<<ans<<endl;
}
