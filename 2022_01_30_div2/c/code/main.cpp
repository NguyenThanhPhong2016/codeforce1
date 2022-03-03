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
// priority_queue<int, vector<int>, greater<int> > gquiz;
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
int get(int a , int c){
    return a %  c ;
}
vector<int > ds ;
int kiemtra(int a , int b , int c, int  d ){
   // debugp(  ii(c, d) ) ;
    int a1 = a| c ;
    int b1 = b| d ;
   // debugp( ii( a1 , b1) ) ;
 //   debug( b1 | a1 )  ;
    int ans = 0 ;
    if( a1 != a ){
        ans += c - get(a, c) ;
        a1 = a1 - get(a,c) ;
    }
    if( b1 != b ){
        ans += d - get( b , d ) ;
        b1 -= get( b , d ) ;
    }

    if( a1 > b1 ){
        return a1 - b1 +  ans  ;
    }
    else{
        return ( b1|a1 ) - b1 + 1 + ans  ;
    }
}
void solve(){
    int a , b ; cin>>a>>b ;
    if( a + 1 == b ){
        cout<<1<<endl; return ;
    }
    int ans = b - a ;
    int c = 1 ;
    for(int i = 0 ; i < ds.size() ; i++){
        for(int j = 0 ; j < ds.size() ; j++){
            int p  = kiemtra( a , b , ds[i] , ds[j] ) ;
            ans = min( ans , p ) ;
          //  debug(p ) ;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c = 1 ;
    ds.pb(0) ;
    while( c < 100 ){
        ds.pb(c) ;
        c = c  * 2 ;
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
