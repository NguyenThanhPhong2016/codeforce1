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
int n , m ;
vector< ii > ds ;
vector<string> a ;
vector<string> kq ;
int kt( int x , int y ){
    if(  x < 0 || y < 0 || x >= n || y >= m  ){
        return false ;
    }
    return true ;
}
void bfs(  int x , int y , int rx ,int ry ){
    if(  x < 0 || y < 0 || x >= n || y >= m  ){
        return ;
    }
    if( a[ x ][y] != '.' ) return ;
    int dem = 0 ;
    ii next ;
    for(auto h : ds ){
        int tdx = h.fi + x ;
        int tdy = h.se + y ;
        if( kt( tdx , tdy ) == false ){
            continue ;
        }
        if( tdx == rx && tdy == ry  ){
            continue ;
        }
        if( kq[ tdx ][ tdy ] == '+' ){
            continue ;
        }
        if(  a[ tdx ][ tdy ] == '.' ){
            dem++;
            next.fi = tdx ; next.se = tdy ;
        }
    }
    if( dem == 0 ){
        kq[  x  ][y] = '+' ; return ;
    }
    if( dem == 1 ){
        kq[ x ][ y ] = '+' ;
        bfs( next.fi , next.se , x , y ) ;
    }
}
void solve(){
    cin>>n>>m ;
    a.clear() ;
    ii l ;
    for(int i = 0 ; i < n ; i++){
        string p ; cin>>p ;
        a.pb( p ) ;
        for(int j = 0; j < m ; j++){
            if( p[ j ] == 'L' ){
                l.fi = i ;
                l.se = j ;
            }
        }
    }
    kq = a;
    for(auto x : ds){
        bfs( l.fi + x.fi , l.se + x.se , l.fi , l.se ) ;
    }
    for(int i = 0 ;i <n ; i++){
        cout<<kq[i]<<endl;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ds.pb( ii( 1 , 0 ) ) ;
    ds.pb( ii( 0 , 1 ) ) ;
    ds.pb( ii( 0 , -1 ) ) ;
    ds.pb( ii( -1 , 0 ) ) ;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
