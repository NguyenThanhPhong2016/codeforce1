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
const int N = 1e5 + 10 ;
int a[ N ] ;
struct cmp{
    bool operator()( ii x , ii y ) const  {
        return x.fi*y.se < x.se *y.fi ;
    }
};
int xuli(int x , int y ){
    if( x % y == 0 ){
        return x / y ;
    }
    else{
        return x / y + 1 ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ; cin>>n>> m ;
    for(int i = 1 ; i <= n ; i++ ) cin>>a[i] ;
    sort( a + 1 , a + n  + 1 ) ;
    if( m > n ){
        multiset< ii , cmp  > ds ;
      //  ds.insert( ii(1,1) ) ;
        for(int i = 1;  i < n ;i++ ){
            debug( a[i+1] - a[i] ) ;
            ds.insert(  ii( a[i+1] - a[i] , 1 )  ) ;
        }
        for(int o = 1 ; o <= m - n ; o++ ){
                debug(o) ;
            auto p = (--ds.end() ) ;
            ii x = *p ;
            ds.erase( p ) ;
            x.se += 1 ;
            ds.insert(x) ;
        }
        auto l = *ds.rbegin() ;
        int ans = xuli( l.fi , l.se ) ;
        cout<<ans<<endl ;
        return 0 ;
    }
    map< int , int > ds  ;
    for(int i = 1 ; i < m -1 ; i++ ){
        ds[ a[i+1] - a[i] ]++;
    }
    int ans = 1e18 ;
    for(int i = m ; i + 1 <= n ; i++ ){
        debug(i) ;
        ds[ a[ i + 1 ] - a[i] ]++;
        int id = a[ i - m + 2 ] - a[ i - m + 1 ] ;
        ds[ id ]--;
        if( ds[id] == 0 ){
            ds.erase( id ) ;
        }
        for(auto x : ds ){
            cout<<x.fi<<" "<<x.se<<endl;
        }
        cout<<endl;
        ans = min( ans , (--ds.end() )->first ) ;
    }
    cout<<ans<<endl;
}
