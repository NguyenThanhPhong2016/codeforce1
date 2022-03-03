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
const int N = 510  ;
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
int a[ N ][ N ] ;
int ckn( int n , int k  ){
    int kq = ( fac[ n ] * inv[k] )  % mod ;
    kq = (kq * inv[n-k] )% mod ;
    return kq ;
}
void cong(int &x , int y){
    x = (x + y ) % mod ;
    if( x < 0 ) x += mod ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(N-1) ;
    int n , x ; cin>>n>>x ;
    if( n == 2 ){
        cout<<x<<endl;
        return 0;
    }
    if(  x== 1  ){
        cout<<1<<endl;
        return 0 ;
    }
    for(int i = 1 ; i <= x ; i++ ){
        a[ i ][ 1 ] = 1 ;
    }
    a[1][1 ]  = 1;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 1; j <= n ; j++ ){
            if( a[i][j] == 0 ) continue ;
           // a[i][j ] = a[i][j] * j ;
            a[i][j] %= mod ;
            for(int k = j ; k <= n ; k++ ){
                if( i + k - 1 > x || k ==1 ) continue ;
                int t = ckn( n - j , k - j );
                t = ( t *  power1( k - 1 ,  k - j ) ) % mod ;
                t = ( t * a[i][j] ) % mod ;
                //debugp( ii(i,j) ) ;debug(k) ;
                //debug(t) ;
                //debug( i + k - 1 ) ;
                cong( a[ i + k - 1 ][ k ] , t );
              //  cout<<a[ i+k - 1][k]<<endl; ;
            }
        }
    }
    /*
    for(int i = 1 ; i <= x ; i++ ){
        for(int j = 1 ; j <= n ; j++){
            cout<<a[i][j] <<" ";
        }
        cout<<endl;
    }
    */
    int ans = power1( x , n ) ;
  //  debug(ans) ;
    for(int i = 1 ; i <= x ; i++ ){
        cong( ans , (-1ll) * a[ i ][n] * n ) ;
    }
    cout<<ans<<endl;
}
