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
const int N = 5e5 + 10 ;
int n , p , k ;
int a[N] ;
const int inf = 1e18 ;
struct node{
    ii id ;
    vector<int> ds ;
    node(){
        id.se = 0 ;
        id.fi = inf ;
        ds.clear() ;
    }
};
node seg[N*4] ;
void upd( int id , int val , int id1 ){
    if( val < seg[id].id.fi ){
        seg[id].id.fi = val ;
        seg[id].id.se = id1 ;
    }
    seg[id].ds.pb( val ) ;
    id = id / 2;
    while( id >= 1 ){
        seg[ id ].ds.pb( val ) ;
        if( val < seg[id].id.fi ){
            seg[id].id.fi = val ;
            seg[id].id.se = id1 ;
        }
        id = id / 2;
    }
}
int sl(  int id , int l , int r , int a , int b , int val ){
    if(  l > b || r < a  ) return 0 ;
    if( a <= l && r <= b ){
        auto &v = seg[id].ds ;
        int id1 = upper_bound( v.begin() , v.end() , val ) - v.begin() ;
        return id1 ;
    }
    int mid = ( l + r ) / 2 ;
    return sl( id<<1 , l , mid , a , b,  val ) + sl( id*2+1 , mid + 1 , r , a, b , val ) ;
}
ii findmin( int id , int l , int r , int a , int b  ){
    if(  l > b || r < a  ) return ii( inf , 0 ) ;
    if( a <= l && r <= b ){
        return seg[id].id ;
    }
    int mid = ( l + r ) / 2 ;
    return min( findmin( id<<1 , l , mid , a , b ) , findmin( id*2+1 , mid + 1 , r , a, b  ) );
}
int ans ;
void xuli(  int l , int r   ){
    //debugp( ii(l,r) ) ;
    if( l > r ){
        return ;
    }
    else if( l == r ){
        if( a[l] + a[l] + a[l] <= p ) ans++;
        return ;
    }
    auto [val , id ] = findmin(  1 , 0 , k - 1  , l , r   ) ;
    if( r- id > id - l ){
        for(int i = l ; i <= id ; i++){
            int slxuli = sl( 1 , 0 , k  -1 , id , r , p - val - a[i] ) ;
           // debug(i) ; debug(slxuli) ;
            ans += slxuli ;
        }
       // debug(id) ;debug(ans) ;
        xuli( l , id - 1  );
        xuli( id + 1 , r ) ;
    }
    else{
        for(int i = id ; i <= r ; i++){
            int slxuli = sl( 1 , 0 , k  -1 , l , id , p - val - a[i] ) ;
          //  debug(i) ; debug(slxuli) ;
            ans += slxuli ;
        }
       // debug(id) ;debug(ans) ;
        xuli( l , id - 1  );
        xuli( id + 1 , r ) ;
    }

}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>> p ;
    k = 1;
    while( k < n ) k = k  * 2 ;
    for(int i = 0 ; i <n ;i++){
        cin>>a[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        upd(  i + k , a[i] , i  ) ;
    }
    for(int i = 1 ; i < 2*k ; i++){
        auto &v = seg[i].ds ;
        if(  v.size()  ){
            sort(  v.begin() , v.end()  ) ;
        }
    }
    xuli( 0 , n -1 ) ;
    cout<<ans<<endl;

}
