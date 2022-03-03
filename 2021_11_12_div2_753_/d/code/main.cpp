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
const int N = 2e5 + 10 ;
vector< int >td[N] ;
vector<int> ds[ 22 ] ;
int ans[N] ;
vector<int > lc[2] ;
int xuli( int x ){
    int dem = 0 ;
    while( x > 1 ){
        dem++ ;
        x = x / 2 ;
    }
    return dem ;
}
void xuli2( int id ){
    int n = lc[ id ].size() ;
   // debug(n) ;
    vector<int > p ;
    int dem = 0 ;
    while( n > 0 ){
        if( n % 2 == 1 ){
            for(auto x : ds[ dem ] ){
               // debug(x) ;
                p.pb( x ) ;
               // debug(x) ;
            }
            ds[dem].clear() ;
        }
        n = n / 2 ; dem++;
    }
    n = lc[id].size() ;
    for(int i = 0 ; i < n ; i++ ){
       // debugp( ii( lc[id][i] , p[i] ) ) ;
        ans[ lc[id][i] ] = p[ i ] ;
    }
}
void xuli3( int id ){
    for(int i = 0; i < 5 ; i++ ){
       // invector(  ds[i]  ) ;
    }
    vector<int> p ;
    for(int i = 0; i <= 21 ; i++ ){
        if( ds[i].size() == 0 ) continue ;
        for( auto x : ds[i] ){
            //debug(x) ;
           // debug(x) ;
            p.pb( x ) ;
        }
    }
    for(int i = 0 ; i < lc[id].size() ; i++){
        //    debugp( ii( lc[id][i] , p[i] ) ) ;
        ans[ lc[id][ i ] ] = p[i] ;
    }
}
void dfs( int id , int rid , int vt ){
    lc[ vt ].pb( id ) ;
    //debug(id) ;
    for(auto x : td[id]  ){
        if( x == rid  ) continue;
        dfs( x , id , 1 - vt ) ;
    }
}
void solve(){
    int n ; cin>> n ;
    lc[0].clear() ;
    lc[1].clear() ;
    for(int i = 0;  i<= n ; i++){
        td[i].clear() ;
    }

    for(int i = 0;  i <= 21 ; i++){
        ds[i].clear() ;
    }

    for(int i = 1 ; i <= n ; i++ ){
        ds[ xuli( i ) ].pb( i ) ;
    }

    for(int i = 0; i < 5 ; i++ ){
       // invector(  ds[i]  ) ;
    }

    for(int i = 0 ;i + 1< n ; i++){
        int u , v ; cin>>u>>v ;
        td[ u ].pb( v ) ;
        td[ v ].pb( u ) ;
    }
    if( n <= 2 ){
        for(int i = 1;  i <= n ; i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return ;
    }
    dfs( 1ll , 0ll , 1 ) ;

    if( lc[0].size() < lc[1].size() ){
        xuli2( 0 ) ;
        xuli3(1) ;
    }
    else{
        xuli2(1) ;
        xuli3(0) ;
    }

    for(int i = 1;  i <= n ; i++){
        cout<<ans[i]<<" ";
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
