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
int s[19] ;
int a[11] ;
void solve(){
    int n , k ; cin>>n>>k ;
    for(int i = 0 ; i< n ; i++){
        cin>>a[i] ;
    }
    int b[n];
    b[ 0 ] = 9 ;
    for(int i = 0 ; i < n -1 ; i++){
        b[i] = s[ a[i+1] - a[i] ] -1 ;
    }
    int ans = 0 ;
    k++;
    for(int i = 0 ;i + 1 < n ; i++){
        //debugp( ii( k , b[i] ) ) ;
        if( k <= b[i] ){
            ans += k * s[ a[i] ] ;
            k = 0;
            break ;
        }
        else{
            k -= b[i] ;
            ans += b[i] * s[ a[i] ] ;
        }
       // debug(ans) ;
    }
    if( k > 0 ){
        ans += k * s[ a[n-1] ] ;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    s[0] = 1 ;
    for(int i = 1; i <= 18; i++){
        s[i] = s[i-1] * 10 ;
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
