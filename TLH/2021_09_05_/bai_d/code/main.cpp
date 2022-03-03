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
const int N = 1e5 + 10 ;
ii x[N] ;
ii y[N] ;
ii z[N] ;
int kt[N] ;
int c( int a , int b , ii f[] ){
  //  debug( f[a].fi ) ; debug( f[b].fi ) ;
    return abs( f[a].fi - f[b].fi ) ;
}
void in( set<ii> d ){
    cout<<"in : "<<endl;
    for(auto p : d){
        cout<<p.fi<<" "<<p.se<<endl;
    }
}
set< ii > ds1 ;
void xuli( int &l , int &r , ii a[] , int id , int n){
    while( l>= 0 && kt[ a[l].se ] == 1  ) l--;
    while( r < n && kt[ a[r].se ] == 1  ) r++;
  //  debug(l) ; debug(r) ;
    if( l>=1 && r < n - 1 ){
        if(  c( l - 1, l , a ) > c( r , r  + 1, a )  ){
            ds1.insert( { c( r , r  + 1, a ) , a[r+1].se }  );
        }
        else{
            ds1.insert( { c( l - 1, l , a ) , a[l-1].se }  ) ;
        }
    }
    else if( l >=0 ){
    //    debug( c(id,l,a) ) ;
        ds1.insert( { c( l - 1, l , a ) , a[l-1].se }  ) ;
    }
    else if( r < n ){
        ds1.insert( { c( r , r  + 1, a ) , a[r+1].se }  );
    }
   // in(ds1);
}
signed main(){
      //  srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    for(int i = 0 ; i < n ; i++){
        cin>>x[i].fi>>y[i].fi>>z[i].fi;
        x[i].se = y[i].se = z[i].se = i ;
    }
    int  x1 , y1 , z1 ;
    x1 = x[0].fi ;
    y1 = y[0].fi ;
    z1 = z[0].fi ;
    sort( x , x + n  ) ;
    sort( y , y + n  ) ;
    sort( z , z + n  ) ;
 //   stack< int > ds ;
  //  ds.push(1) ;
    int lx ,ly , lz , rx , ry , rz  ;
    lx = lower_bound( x , x + n ,ii(x1,0) ) - x ;
    rx = lx ;
    ly = lower_bound( y , y + n , ii(y1,0) ) - y ;
    ry = ly ;
    lz = lower_bound( z , z + n , ii(z1,0) ) - z ;
    rz = lz ;
    x1 = lx ; y1 = ly ; z1 = lz ;
    kt[0] = 1 ;
   // lx-- ; ly-- ; lz-- ;
   // rx++ ; ry++ ; rz++ ;
    int ans=  0 ;
    int sl = 1 ;
    while( sl < n ){
        sl++;
        ds1.clear() ;
        xuli( lx , rx , x , x1 , n ) ;
        xuli( ly , ry , y , y1 , n ) ;
        xuli( lz , rz , z , z1 , n ) ;
        auto p = *(ds1.begin() );
       // in(ds1) ;
        ans += p.fi ;
      //  debug(ans) ;
        kt[ p.se ] = 1;
       // debugp( p ) ;
    }
    cout<<ans<<endl;
}
