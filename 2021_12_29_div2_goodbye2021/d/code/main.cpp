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
const int N = 5e4 +10;
int a[N] ;
int s[N] ;
int dp[N] ;
int xuli( int l , int r ){

}
void solve(){
    int n ; cin>> n ;
    for(int i = 0 ; i< n ; i++) cin>>a[i] ;
    int x ; cin>> x;
    int l ,r ; l = 0 ; r = 1;
    while( l < n ){
        int ok = 1 ;
        while( r < n ){
            if( r - 1 >= l ){
                if( a[ r -1  ] + a[r] < 2*x ){
                    ok = 0 ;
                }
            }
            if( r - 2 >= l ){
                if( a[ r - 1  ] + a[r] + a[r - 2] < 3 * x ){
                    ok = 0 ;
                }
            }
            if( ok == 0 ){
                break ;
            }
            r++ ;
        }
        s[  l  ] = r ;
        l++ ;
    }
    for(int i = 0 ; i < n ;i++){
     //   cout<<i<<" "<<s[ i ]<<endl;
    }
    dp[n+1] = 0 ;
    dp[ n ] = 0 ;
    dp[ n - 1 ] = 1 ;
    int ans = 1 ;
    for(int i = n -2 ; i >= 0 ; i--){
        dp[ i  ] = dp[ i + 1 ] ;
        dp[ i ] = max( dp[ s[i] + 1 ] + s[i] - i , dp[i] );
        ans = max( ans , dp[i] ) ;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
