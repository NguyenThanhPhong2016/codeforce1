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
ii a[101][101] ;
int cot[101] ;
int dong[101] ;
int vis[ 101 ][101] ;
ii char1(char x ){
    ii y ;
    if(  x == '^'  ){
        y = ii( -1 , 0 ) ;
    }
    else if( x== '>' ){
        y = ii( 0 , 1 ) ;
    }
    else if( x == '<' ){
        y = ii( 0 , -1 ) ;
    }
    else if( x == 'v' ){
        y = ii( 1 , 0 ) ;
    }
    else{
        y = ii( 0 , 0 ) ;
    }
    return y ;
}

int ans  ;
int n , m ;
void dfs( int x , int y, int dem, int rx , int ry ){
    //debugp( ii( rx, ry ) ) ;
   //  debugp( ii( x , y ) ) ;
    if( x == 0 || y == 0 || x == n + 1 || y == m + 1 ){
    //    debugp( ii( rx, ry ) ) ; debugp( ii( x , y ) ) ;
        ans++ ;
        vis[ rx ][ ry ] = 1 ;
        return ;
    }
    if( vis[ x ][ y ] == 1 ){
        vis[ rx ][ ry ] = 1;
        return ;
    }
    if( a[ x ][ y ] == ii( 0 ,0  ) ){
        dfs(  x + a[ rx ][ ry ].fi , y + a[ rx ][ ry ].se , dem , rx,  ry  ) ;
    }
    else{
        vis[ rx ][ry] = 1 ;
        dfs(  x + a[ x ][ y ].fi , y + a[ x ][ y ].se , dem+1 , x,  y  ) ;
    }

}
void solve(){
    cin>> n>> m ;
    ans = 0;

    for(int i = 1 ; i<= n ; i++){
        dong[i] =  0 ;
    }
    for(int i = 1 ; i<= m ; i++){
        cot[i] =  0 ;
    }
    for(int i = 1; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            char p ; cin>>p ;
            a[i][j] = char1(p) ;
            vis[ i ][j] = 0 ;
            if( a[i][j] != ii(0,0) ){
                dong[ i ]++ ;
                cot[ j ]++ ;
            }
        }
    }
    for(int i = 1; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            if( a[i][j] == ii(0,0) ) continue ;
            if( dong[i] == 1 && cot[ j ] == 1 ){
                cout<<"IMPOSSIBLE"<<endl ;
                return ;
            }
        }
    }

    for(int i = 1; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            if( vis[ i ][ j ] == 1 ) continue ;
            if( vis[ i ][ j ] == -2 ) continue ;
            if( a[ i ][ j ] == ii( 0 ,0  ) ) continue ;
            //cout<<" chay : "<<i<<" "<<j<<endl;
            dfs(  i + a[ i ][ j ].fi , j + a[ i ][ j ].se , 0 , i,  j  ) ;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i = 1 ; i <= t; i++){
        cout<<"Case #"<<i<<": ";
        solve() ;
    }
}
