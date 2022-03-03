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
	inv[n]=power(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 1e5 ;
//int s[ 28 ][N] ;
vector<int > kt ;
vector<int> kta ;
bool xuli1( ){
    int n = kt.size() ;
    for(int i = 0 ; i < n ; i++ ){
        if( kt[i] != kt[ n - i -1  ]  ){
            return false ;
        }
    }
    return true ;
}
int xuli2(){
    int ans = 0 ;
    int n = kta.size()  ;
    int mid = n / 2 ;
    if( n % 2 == 0 ){
        for(int i = 0 ; i < mid ; i++){
         //   debug( abs( kta[i] - kta[n-1-i] ) ) ;
            ans += abs( kta[i] - kta[n-1-i] ) ;
        }
    }
    else{
        for(int i = 0 ; i < mid ; i++){
          //  debug( abs( kta[i] - kta[n-1-i] ) ) ;
            ans += abs( kta[i] - kta[n - 1 - i] ) ;
        }
    }
    return ans ;
}
void solve(){
    int n ; cin>>n ;
    string a ; cin>>a ;
    a = " " + a ;
    int ans = -1 ;
    for(int j = 0 ; j < 26 ; j++){
        kt.clear() ;
        kta.clear() ;
        int sl = 0 ;
        for(int i = 1; i <= n ; i++){
            if( a[i] - 'a' != j ){
                kt.pb( a[i] - 'a' ) ;
                kta.pb( sl ) ;
                sl = 0 ;
            }
            else{
                sl++ ;
            }
            if( i ==n  ){
                kta.pb( sl ) ;
            }
        }
        if( xuli1() == false  ){
            continue ;
        }
        int kq = xuli2() ;
      //  debug( kq ) ; cout<<"chuoi : "<<kt<<endl; invector( kta  ) ;
        if( ans == -1 ) ans = kq ;
        else{
            ans = min( ans , kq) ;
        }
    }
    cout<<ans<<endl ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
