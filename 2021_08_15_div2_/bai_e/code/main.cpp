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
const int M =1e5 + 10;
const int N = 53 ;
int dp[ N ][M] ;
int ans[M] ;
const int mod = 998244353 ;
void add( int &x , int y ){
    x = ( x + y ) % mod ;
}
int dem = 0;
void in(){
    cout<<"dang chay "<<dem++<<endl;
}
signed main(){
    //    srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ; cin>>n>>m ;
    vector< ii > a(n+1) ;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i].fi>>a[i].se ;
    }
    dp[ 0 ][ 0 ] = 1 ;
    for(int i = 1 ; i <= m ; i++){
        dp[ 0 ][ i ] =  dp[0][i-1] +  1 ;
    }

    for(int id = m ; id >= 1; id-- ){

        int h = m / id ;
        for(int i = 1 ; i<= n ; i++){
            for(int j=  0 ; j <= h ; j++){
                dp[i][j] = 0 ;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            int l = a[i].fi / id ;
            if( a[i].fi % id != 0 ) l++;
            int r = a[i].se / id ;
            if( l > r ) break;
            for(int j = 0 ; j <= h ; j++){
                if( j > r ){

                    add( dp[ i ][ j  ] ,dp[ i-1 ][ j - l ] + mod - dp[i-1][ j - r - 1 ] ) ;
                }
                else if( j >= l ){
                    dp[ i ][ j ] = dp[ i - 1 ][j-l] ;
                }
                else{
                    dp[ i ][j] = 0 ;
                }
                if( j > 0 ){
                    add( dp[ i ][j] , dp[ i ][j-1] ) ;
                }

            }
        }
        ans[ id ] = dp[ n ][ h ] - dp[ n ][h-1] ;
        for(int i = id*2 ; i <= m ; i += id){
            add( ans[id] , mod - ans[i] ) ;
        }
    }

    cout<<ans[1]<<endl;
}
