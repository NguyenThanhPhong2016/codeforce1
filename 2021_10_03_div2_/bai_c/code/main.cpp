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
const int N = 1e5 + 10 ;
int a[N] ;
vector<int > td[N] ;
int kt[N] ;
int ans  ;
int sxor  ;
void dfs( int id , int rid ){
    for(auto x : td[id]){
        if( kt[x] == 1 ) continue ;
        kt[x] = 1 ;
        dfs( x , id ) ;
    }
    if( false ){
        debug(sxor) ;
        debug( a[id] ) ;
        debug(ans) ;
    }
    if( a[id ] == 0 ) return ;
    else{
        if( sxor == a[id] ){
            ans++;
        }
        else{
            a[ rid ] ^= a[id] ;
        }
    }
}
void solve(){
    ans = 0 ;
    sxor = 0 ;
    int n , k ; cin>>n>> k;
    k--;
    for(int i = 0 ; i < n ;i++){
        td[i].clear() ;
        kt[i] = 0 ;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        sxor ^= a[i] ;
    }
    for(int i = 0 ; i < n -1 ; i++){
        int u , v ; cin>>u>>v ;
        u--;v--;
        td[u].pb(v) ;
        td[v].pb(u) ;
    }
    if( sxor == 0 ){
        cout<<"YES"<<endl;
        return ;
    }
    kt[0] = 1;
    dfs( 0 , 0 ) ;
  //  debug(ans) ;
    if( ans ==  1 ){
        cout<<"NO"<<endl;
    }
    else{
        if( k >= 2 ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
