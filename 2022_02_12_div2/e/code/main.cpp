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
const int N = 3e5 + 10 ;
int a[N] ;
vector< ii > ds ;
int n , m ;
int ans = 0 ;
set< ii > k ;
void xuli( ){
    map<int , int > p ;
    for(int i = 1  ; i <= n ; i++ ){
        p[ a[i] ]++ ;
    }
    vector< ii  > ds1 ;
    for(auto x : p ){
        ds1.pb( ii(  x.se , x.fi ) ) ;
    }
    sort( ds1.begin() , ds1.end() ) ;
    int n1 = ds1.size() ;
    int id = 0 ;
    while( id < n1 ){
       // debug(id) ;
        vector< int > u ;
        u.pb( ds1[ id ].se ) ;
        while( id + 1 < n1 && ds1[ id ].fi == ds1[id+1].fi ){
            u.pb( ds1[ id+1 ].se ) ;
            id++ ;
        }
        if( u.size() >=2   ){
            int tk = 0 ;
            for(int i = 0 ; i < u.size() ; i++ ){
                for( int j = u.size()  -1 ; j > i ; j-- ){
                    if( k.find( ii(  u[i]  , u[j] ) ) == k.end() ){
                        tk = max( u[i] + u[j] , tk  ) ;
                        break ;
                    }
                    else{
                        continue ;
                    }
                }
            }
            ans = max( ans , tk*2*ds1[ id ].fi ) ;
        }
        ds.pb( ii( u[ u.size() - 1 ] , ds1[id].fi ) ) ;
     //   debugp( ii( ds1[id].fi , maxh ) ) ;
        id++ ;
    }
}
void solve(){
    ans = 0;
    cin>> n >> m ;
    for(int i = 1  ; i <= n ; i++ ){
        cin>>a[i] ;
    }
    k.clear() ;
    while( m-- ){
        int x , y ; cin>>x>> y ;
        if( x > y ){
            swap( x,  y ) ;
        }
        k.insert( ii( x , y ) ) ;
        k.insert( ii( y ,x  ) ) ;
    }
    ds.clear() ;
    xuli() ;
    int n1 = ds.size() ;
    for(int i = 0; i < n1 ; i++ ){
        for(int j = i + 1 ; j < n1 ; j++ ){
            if( k.find( ii(  ds[i].fi  , ds[j].fi ) ) != k.end() ){
                continue ;
            }
        //    debugp( ii( i , j ) ) ;
        //    debugp(  ds[i]  ) ;debugp( ds[j] ) ;
            int kq = ( ds[i].fi + ds[j].fi )*( ds[i].se + ds[j].se ) ;
            ans = max( ans , kq ) ;
        }
    }
    cout<<ans<<endl;


}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
