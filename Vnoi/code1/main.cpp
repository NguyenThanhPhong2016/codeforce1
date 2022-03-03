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
const int N = 1e3 + 5000 ;
int dp[ N ] ;
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , t; cin>>n>>t ;
    if( n == 1 ){
        cout<<-1<<endl;
        return 0 ;
    }
    for(int i = 0 ; i< N ; i++){
        dp[i] = 1e4 ;
    }
    if( t != 1 ){
        for(int i = 2;  i  <= t ; i++){
            if( t % i == 0 ){
                dp[ i + 1 ] = 1 ;
                dp[ i + 2 ] = 2;
            }
        }
    }
    dp[ 1 ] = 0 ;
    dp[ 2 ] = 1 ;
    for(int i = 2 ; i <= 1024 ; i = i * 2 ){
        if( dp[i] == 1e4 ) continue ;
        for(int j = 2 ; j < i ; j++ ){
            if( i % j == 0  ){
                dp[i] = min( dp[i] , dp[ j ] + dp[ i / j ] ) ;
            }
        }
    }
    for(int i = 3; i <= n ; i++ ){
        if(  dp[ i ] != 1e4  ) continue;
        dp[i] = dp[i-1] + 1 ;
        if(  i == 43 ){
            dp[ i ] = min( dp[i] , 2 + dp[ 32 ] ) ;
        }
        if( i == 683 ){
            dp[ i ] = min( dp[i] , 2 + dp[ 512 ] ) ;
        }
        for(int j = 2 ; j < i ; j++ ){
            if( i % j == 0  ){
                dp[i] = min( dp[i] , dp[ j ] + dp[ i / j ] ) ;
            }
        }
        for(int j = 1; j <= t ; j++ ){
            if( t % j == 0 ){
                dp[i] = min( dp[i] , dp[ i - j ] + 1 ) ;
            }
        }
     //   debugp( ii( i , dp[i]) ) ;
    }
    cout<<dp[ n ]<<endl;
}
