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
/*
int par[N] ;
int root( int id ){
    return ( par[id] == id )? id : par[id] = root( par[id] ) ;
}
struct node{
    int p1 ; int p2 ;
    int ic ;
    node();
    node(int p11, int p21 , int ic1){
        p1 = p11;
        p2 = p21 ;
        ic = ic1 ;
    };
};
*/
vector< ii > ds[N] ;
int kt[N] ;
void cap( int &x, int y ){
    if( y == -1 ) return ;
    if( x== -1   ) x = y ;
    else x += y ;
}
int ans1 , sl ;
void dfs( int id ){
    sl++;
    if( ans1 == -1 ) return ;
    if( kt[ id ] == 1 ) ans1++;
    for( auto [x,y] : ds[id] ){
        if( kt[x] != -1 ){
            if(  kt[x] ^ kt[id] != y ){
                ans1 = -1 ;
                return ;
            }
        }
        else{
            kt[x] = kt[ id ] ^ y ;
            dfs( x ) ;
        }
    }
}
void solve(){
    int n , m ; cin>>n>>m ;
    for(int i = 1; i <= n ; i++){
        ds[i].clear() ;
        kt[i] = -1 ;
    }
    for(int i = 0 ; i < m ; i++){
        int x , y ;string l ;
        cin>>x>>y>>l ;
        if( x > y ) swap( x , y ) ;
        int z = 0 ;
        if( l[0] == 'i' ) z = 1;
        ds[ x ].pb( ii( y , z ) ) ;
        ds[ y ].pb( ii( x , z ) ) ;
    }
    int ans = -1 ;
    for(int i = 1; i <= n ; i++){
        if( kt[i] != -1 ) continue ;
        ans1 = 0 ;
        sl = 0 ;
        kt[i] = 0 ;
        dfs( i  );
        if( ans1 == -1 ){
            ans = -1 ;
            break ;
        }
      //  debug(i) ; debug( ans1 ) ;
        cap( ans , max( sl - ans1 , ans1 ) ) ;
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
