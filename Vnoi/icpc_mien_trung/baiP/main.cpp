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
const int N = 101 ;
const int M =11 ;
int dp[ M ][N][N][N] ;
int get(int a , int b , int c , int u){
    if( a > b ) swap(a,b) ;
    if( b > c ){
        swap( b , c ) ;
        if( a > b ) swap(a,b) ;
    }
    return dp[ u ][ a ][b][c] ;
}
void solve(){
    int a , b , c , u ; cin>>a>>b>>c>>u ;
    cout<< get( a , b , c , u )<<endl;
}
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int u = 1 ; u < M ; u++){
        for(int i = 1; i < N ; i++){
            for(int j = i ; j < N ; j++){
                for(int k = j ; k < N ; k++){
                    if( i < u ){
                        dp[u][ i ][j][k] = 0 ;
                    }
                    else{
                        dp[u][ i ][j][k] = get( i , j , k - u , u ) + i*j ;
                        dp[u][ i ][j][k] = max( dp[u][i][j][k] , get( i - u , j , k , u ) + k*j  );
                        dp[u][ i ][j][k] = max( dp[u][i][j][k] , get( i  , j - u , k , u ) + k*i  );
                    }
                   // cout<<u<<" "<<i<<" "<<j<<" "<<k<<" "<<dp[u][i][j][k]<<endl;
                }
            }
        }
    }

    int t;cin>>t;
    while(t--){
        solve();
    }
}
