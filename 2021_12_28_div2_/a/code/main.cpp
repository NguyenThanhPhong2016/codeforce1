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
const int N = 1001 ;
ii a[N] ;
ii p[N] ;
int b[N] ;
int ans[N] ;
bool cmp( ii x , ii y ){
    return ( x.se - x.fi ) < ( y.se - y.fi ) ;
}
void solve(){
    int n ; cin>> n ;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i].fi >> a[i].se ;
     //   p[i] = a[i] ;
        ans[ i ] = -1 ;
        b[i] = -1 ;
    }
    sort( a + 1, a + n  + 1 ) ;
    for(int i = 1; i <= n ;i++){
        p[i] = a[i] ;
    }
    int dem = 0 ;
    while( dem < n ){
        for(int i = 1; i <= n; i++ ){
            auto &[l , r] = a[i] ;
           // debugp( a[i] ) ;
            if( b[i] != -1 ) continue ;
            if( l == r ){
                b[ i ] = l ;
                ans[ l ] = 1 ;
                dem++;
            }
            else{
                while( l <= r && ans[l] != -1 ) l++;
                while( r >= l && ans[r] != -1 ) r--;
                if( l == r ){
                    b[ i ] = l ;
                    ans[ l ] = 1 ;
                    dem++;
                }
            }
        }
    }
    for(int i = 1; i <= n ; i++){
        auto [l, r] = p[i] ;
        cout<<l<<" "<<r<<" "<<b[i]<<endl;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
