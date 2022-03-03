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
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10 ;
int a[N] ;
vector<int > ds[N] ;
int r[ N ] ;
void mer( int x, int y ){
    x = r[ x ] ;
    y = r[ y ] ;
    if( x == y  ) return ;
    if( ds[ x ].size() > ds[ y ].size() ){
        swap( x,  y ) ;
    }
    for(  auto p : ds[ x ]  ){
        ds[ y ].pb( p ) ;
        r[ p ] = y ;
    }
    ds[x].clear() ;
}
void mer1( int x , int y ){

}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ; cin>>n>>m ;
    for(int i = 1 ; i <= n ; i++ ){
        cin>>a[i] ;
        ds[ i ].pb(i ) ;
        r[ i ]= i ;
    }

    while( m-- ){
        int x , y ; cin>> x >> y ;
        mer( x,  y ) ;
    }
    for(int i = 1 ; i <= n ; i++ ){
        if( ds[ i ].size() == 0  ) continue ;
        sort( ds[i].begin() , ds[ i ].end() ) ;
        vector<int> ds1 ;
        for(auto x : ds[i] ){
            ds1.pb( a[x] ) ;
        }
        sort( ds1.begin()  ,ds1.end() ) ;
        int k = ds1.size() ;
        for( int j = 0 ; j< ds1.size() ; j++ ){
            a[ ds[ i ][j] ] = ds1[ k - 1 - j ] ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<a[i]<<" " ;
    }
}
