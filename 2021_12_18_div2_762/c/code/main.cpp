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
vector<int> ds  ;
bool xuli( int sl , int nhan , int x ){
    int h = x / nhan ;
    if( sl <= 2 * h ){
        return sl* nhan < x ;
    }
    else{
        return false ;
    }
}
void solve(){
    int n , k , x ; cin>>n>>k>>x ;
    string a ; cin>>a ;
    ds.clear() ;
    for(int i = 0 , dem = 0 ; i < n ; i++){
        if( a[i] == 'a' ){
            ds.pb( dem * k ) ;
            dem = 0 ;
        }
        else{
            dem++ ;
        }
        if( i == n - 1 ){
            ds.pb(dem*k) ;
        }
    }
    int n1 = ds.size() ;
    vector<int > ds1  = ds ;
    for(int i = 0 ; i < n1 ; i++){
        ds1[ i ] = 0 ;
      //  debugp( ii( i , ds[i] ) ) ;
    }
    while( x > 0 ){
       // debug(x) ;
        if( x <= ds[n1-1]  + 1  ){
            ds1[ n1 - 1 ] = x - 1 ; break ;
        }
        int sl = 1 ;
        int id = -1  ;
        for(int i = n1 - 1  ; i >= 0 ; i-- ){
            if( xuli( sl , ds[i]  + 1 , x ) ){
                sl = sl * (ds[i] + 1 )  ;
                id = i ;
            }
            else{
                break ;
            }
        }
      //  debug(sl) ;
       // debug(id) ;
        if( x % sl == 0 ){
            int h = x / sl ;
            ds1[ id - 1 ] = h - 1 ;
            x = sl ;
        }
        else{
            int h = x / sl ;
            ds1[id-1] = h ;
            x = x % sl ;
        }
    }
    for(int i = 0 ; i < n1 ; i++ ){
        for(int j = 0 ; j < ds1[ i ] ; j++ ){
            cout<<'b';
        }
        if( i != n1 - 1 ){
            cout<<'a' ;
        }
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
