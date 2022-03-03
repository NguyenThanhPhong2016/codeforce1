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
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10 ;
vector< int > par[N] ;
int val[N] ;
int val1[N] ;
int rid[N] ;
vector< int > l ;
void mer( int x , int y ){
    x = rid[x] ;
    y = rid[y] ;
    if(  rid[ x ] == rid[ y ]  ) return ;
    if( par[x].size() > par[y].size() ){
        swap(x,y) ;
    }
    val[y] += val[x] ;
    val1[y] = max( val1[x] , val1[y] ) ;
    for(auto p : par[x]){
   //     debug(p) ;
        rid[ p ] = y ;
        par[ y ].pb( p ) ;
    }
    val[x] =  0;
    par[x].clear() ;
}
void in( int n ){
    for(int i = 1 ; i <= n ; i++){
        cout<<"par "<<i<<" : ";
        for(auto x : par[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int tk( int value ){
    int u = lower_bound( l.begin() , l.end() , value ) - l.begin() ;
    return u ;
}
signed main(){
      //  srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , q ; cin>>n>>q  ;
    stack<int > kq ;

    vector<ii> ds ;
    for(int i = 1 ;i <= q ;i++){
        int c , x ; cin>>c>>x ;
        ds.pb( {c,x} ) ;
        if( c == 1 ){
            l.pb(x) ;
        }
    }
    l.pb(n) ;
    l.pb(0) ;
    sort( l.begin() , l.end()  ) ;
    n = l.size() -1  ;
    for(int i = 1 ; i <= n ; i++){
        val[i] = l[ i ] - l[i-1] ;
        val1[i] = i+1 ;
    }
    for(int i = 1 ; i <= n ; i++){
        rid[i] = i ;
        par[i].pb( i ) ;
    }
    for(int i = ds.size() -1 ; i >= 0 ; i--){
        auto [c , x] = ds[i] ;
        int id = tk( x ) ;
        id = rid[id] ;
        if( c == 2 ){
            int h = val[id] ;
            kq.push(   h   ) ;
        }
        else{
         //   debug(id);
            mer( id , val1[id] ) ;
         //   in(n) ;
        }
    }
    while( !kq.empty() ){
        cout<<kq.top()<<endl;
        kq.pop() ;
    }
}
