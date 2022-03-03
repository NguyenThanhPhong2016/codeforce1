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
const int mod = 1e9 + 7 ;
int power( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void solve(){
    int n , k ; cin>>n>>k ;
    if( k==0 ){
        cout<<1<<endl;
        return ;
    }
    int y = power( 2 , n ) ;
    if( n% 2 == 1 ){
        int ans = 0 ;
        int h = ( n - 1 ) / 2 ;
        int x = 1 ;
        for(int i = k -1 ; i >= 0 ; i--){
            int t = power( 2 , 2 * h ) - 1 ;
            t = ( t * power(   y , i   ) )%  mod ;
            t = ( t*x )% mod ;
            ans = ( ans + t ) % mod ;
            x= x * ( power( 2 , 2*h ) + 1 ) ;
            x= x %mod;
        }
        ans = power( y , k )  - ans ;
        ans = ans % mod ;
        if( ans <0 ) ans+= mod ;
        cout<<ans<<endl;
    }
    else{
        int ans = 0 ;
        int h = n / 2 ;
        int x = 1;
        for(int i = k -1 ; i >= 0 ; i--){
            int t = power( 2 , 2 * h -1 )  ;
            t = ( t * power(  y , i   ) )%  mod ;

            t = (t * x ) % mod  ;
            ans = ( ans + t ) % mod ;
           // debug(i);debug(ans) ;
            x = x *  ( power( 2 , 2 * h -1 ) -1 );
            x= x % mod ;
        }
        ans = power( y , k )  - ans ;
        ans = ans % mod ;
        if( ans <0 ) ans+= mod ;
        cout<<ans<<endl;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
