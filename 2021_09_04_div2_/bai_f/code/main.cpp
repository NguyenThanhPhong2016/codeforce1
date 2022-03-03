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
const int mod = 998244353 ;
const int N = 410 ;
int dp[ N ][ N ] ;
int dpn[ N ][ N ] ;
int a[N][N] ;

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
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void c( int& x , int y ){
    x = ( x + y ) % mod ;
}
int nhan( int x , int y ){
    x = ( x * y ) % mod ;
    return x ;
}
int ckn( int n , int k ){
    int kq = nhan( fac[n] , inv[k] );
    kq = nhan( kq , inv[n-k] ) ;
    return kq ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(N-1) ;
    int n  , m ; cin>>n>>m ;
    for(int i = 0 ;  i< m ; i++){
        int u , v ; cin>>u>>v ;
        a[u][v] = 1 ;
        a[v][u] = 1 ;
    }
    n = n * 2 ;
    for(int i = 1;  i < n ; i++){
        if( a[ i ][i+1] == 1 ){
            dp[ i ][i+1] = 1;
            dpn[i][i+1 ] = 1 ;
        }
    }
    for(int kc = 3 ; kc <= n ; kc = kc + 2){
        for(int i = 1 ; i <= n ; i++){
            if( i + kc > n  ) break ;
            int r = i + kc ;
            if( a[i][r] == 1)  dpn[ i ][ r ] = dp[ i + 1 ][r-1] ;
            for(int j = 1 ; j < kc ; j = j + 2){
                int mid = i + j ;
                int kq = ckn( (kc + 1)/2 , (j + 1)/2 ) ;
                kq = nhan( kq , nhan( dpn[ i ][ mid ] , dp[mid + 1][r] )  ) ;
                c(   dp[ i ][ r ] , kq );
            }
            if( a[i][r] == 1) c( dp[i][r] , dpn[ i ][r] ) ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <=n ; j++){
           // cout<<dp[i][j]<<" ";
        }
     //   cout<<endl;
    }
    cout<<dp[ 1 ][n]<<endl;
}
