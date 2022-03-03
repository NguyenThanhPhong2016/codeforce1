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
const int N =3e5 ;
int s[ 20 ][ N ] ;
void solve(){
    int l ,r ; cin>>l>>r ;
    int ans = 1e18 ;
    for(int j = 0 ; j < 20 ; j++ ){
       // debug(j) ; debug( s[j][ r  ] ) ;
        int h = s[ j ][ r ] - s[ j ][ l - 1 ] ;
        if( h == r - l + 1 ) continue ;
        ans = min( ans , h ) ;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < 20 ; j++ ){
           // debug(i) ; debug(j) ;
            if( ( (i>>j)&1) == 0 ){
              //  debug(i) ; debug(j) ;
                s[ j ][ i ]++ ;
            }
        }
    }
    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < 20 ; j++ ){
            s[ j ][ i ] += s[ j ][ i - 1 ] ;
        }
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}