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
const int N = 1e3 + 10 ;
vector<int> a[N] ;
int r[ N ] ;
int du = 1 ;
map<int , int> s ;
void join( int x , int y ){
    x = r[x] ;
    y = r[y] ;
    if(  x == y  ){
        du++;
        return ;
    }
    if(  a[x].size() > a[y].size() ){
        swap( x , y ) ;
    }
    s[ a[x].size() ]--;
    s[ a[y].size() ]--;
    for(auto p : a[x] ){
        a[ y ].pb( p ) ;
        r[ p ] = y ;
    }
 //   debug( a[y].size() ) ;
    s[ a[y].size() ]++ ;
    a[ x ].clear() ;
}
signed main(){
       srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , q;  cin>>n>>q ;
    int ans[ n + 1] ;
    for(int i = 1 ; i <= n ;i++ ){
        r[i] = i ;
        a[i].pb( i ) ;
        s[1]++;
    }
    for(int i = 1; i <= q ; i++ ){
        int u , v ;cin>>u>>v ;
        join( u , v  ) ;
        int ans = 0 ;
        auto x = s.end() ;
        int sl = du ;
        while( sl > 0 ){
            if( x == s.begin() ){
                break ;
            }
            x--;
            auto x1 = *x ;
            if( x1.se <= sl ){
                sl -= x1.se ;
                ans += x1.fi*x1.se ;
            }
            else{
                ans += x1.fi * sl ;
                break ;
            }
        }
        cout<<ans-1<<endl;
    }
}
