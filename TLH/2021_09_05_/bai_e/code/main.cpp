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

const int N = 3e5 + 10 ;
vector<int > a[N] ;
int rid[N] ;
int tt[N] ;
int kt[N] ;
void mer( int x , int y ){
    x = rid[ x ] ;
    y = rid[ y ] ;
    if( x == y ) return ;
    int val = tt[y] ;
    if( a[x].size() > a[y].size() ){
        swap(x , y) ;
    }
    tt[ y ] = val ;
    for( auto pt : a[x] ){
        rid[ pt ] = y ;
        a[y].pb( pt ) ;
    }
    a[x].clear() ;
}

signed main(){
      //  srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    for(int i = 1 ; i <= n ; i++){
        a[i].pb( i ) ;
        rid[i] = i ;
        tt[i] = i + 1 ;
    }
    int h = n ;
    while( h-- ){
        int id ; cin>>id ;
        if( kt[id] == 0 ){
            kt[id] = 1;
            cout<<id<<" ";
            continue;
        }
        int vt = rid[id] ;
        int k = tt[vt] ;
        if( k > n ) k-= n ;
        while( kt[ k ] == 1 ){
           // debug(k);
            mer( vt , k );
            vt = rid[vt] ;
         //   debug(vt);
            k = tt[vt] ;
            if( k > n ) k-= n ;
        }
      //  debug(vt);debug( tt[vt] ) ;
        cout<<k<<" ";
        kt[ k ] = 1;
        mer( vt , k ) ;
    }
}
