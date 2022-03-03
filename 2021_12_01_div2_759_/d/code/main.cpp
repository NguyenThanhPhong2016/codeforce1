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
const int N = 5e5 + 10 ;
int a[N] ;
const int mod = 998244353 ;
int power1( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power1( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
void cong( int &x ,int y ){
    x= ( x + y ) % mod;
}
int dp[N] ;
int dp1[N] ;
void solve(){
    int n ; cin>> n ;
    for(int i = 0 ; i<= n ;i++){
        dp[i]  = 0 ;
        dp1[ i ] =  0 ;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i] ;
    }
    int ans = 0 ;
    int dem = 0;
    for(int i = 0 ; i< n ; i++ ){
        if( a[i] == 1 ){
            dem++;
        }
    }
   // debug(dem) ;
    cong( ans , power1( 2 , dem )  ) ;
    cong(ans , mod - 1) ;
    for(int i = 0 ; i< n ; i++){
        if( a[i] == 0 ){
            dp[ 0 ] = dp[ 0 ] * 2 + 1;
            dp[ 0 ] %= mod ;
        }
        else{
            dp[ a[i] ]  = dp[ a[i] ] * 2 + dp[ a[i] - 1 ]   ;
            dp[ a[i] ] %= mod ;
        }
        int x = dp1[ a[i] ] ;
        if( a[i] >= 2 ){
            dp1[ a[i] ] = x*2 + dp[ a[i] - 2 ]  ;
            dp1[ a[i] ] %= mod ;
        }
        if( a[i] + 2 <= n ){
            dp1[ a[i] + 2 ] = dp1[ a[i] + 2 ] * 2 ;
            dp1[ a[i] + 2 ] %= mod ;
        }
    }
    for(int i = 0 ; i<= n ; i++){
     //   debug( dp[i]  ) ;debug( dp1[i] ) ;
        cong( ans , dp[i] ) ;
        cong( ans ,dp1[i] ) ;
    }
    ans = ans % mod ;
    if(  ans < 0  ) ans += mod ;
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
