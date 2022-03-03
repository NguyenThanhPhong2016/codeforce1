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
int power1( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power1( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power1(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void solve(){
    int n  , a , b ; cin>>n>>a>>b ;
    int n1 = n / 2;
    if( n - a + 1  < n1 ){
        cout<<-1<<endl;
        return ;
    }
    if( b < n1 ){
        cout<<-1<<endl;
        return ;
    }
    int ans[n+1] ;
    int kt[n+1 ] ;
    for(int i = 0 ; i<= n ; i++){
        kt[i] = ans[i] = 0 ;
    }
    kt[a] = kt[b] = 1;
    ans[1] = a ;
    int ed = n ;
    for(int i = 2 ; i <= n1 ; i++ ){
        if(  ed == b  ) ed-- ;
        if( ed == a ){
            cout<<-1<<endl; return ;
        }
        ans[i] = ed ;
        kt[ ed ] = i ;
        ed--;
    }
    int id = 1 ;
    ans[n] = b ;
    for(int i = n1 + 1; i < n ; i++ ){
        while( id <= n && kt[id] != 0  ) id++;
        if( id > b ){
            cout<<-1<<endl;
            return ;
        }
        ans[ i ] = id ;
        id++;
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
