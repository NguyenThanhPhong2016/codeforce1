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

const int mod = 1e9 + 7 ;
const int N = 1e6 + 10  ;
int fac[4*N];
int inv[4*N];
int ans[4*N];
int ans1[4*N];
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
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int ckn( int x, int y ){
    int h =(fac[y] * inv[y-x] ) %mod  ;
    h = ( h * inv[x] ) % mod ;
    return h ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n  , q ; cin>>n>>q ;
    init( 4 *  n  + 5 );
    for(int i = 0 ; i <= 3*n+3 ; i++){
        ans1[ i ] = ckn( i , 3 * n + 3  ) ;
    }
    ans1[3] -= 1 ;
    ans1[2] -= 3 ;
    ans1[1] -= 3 ;
    ans1[0] -= 1 ;
    for(int i = 3*n ; i >=0 ; i--){
        ans[i] = ans1[i+3] ;
        ans1[i+2] =( ans1[i+2] -  ans1[i+3] * 3 + 3* mod ) % mod ;
        ans1[i+1] =( ans1[i+1] -  ans1[i+3] * 3 + 3* mod ) % mod ;

       // ans1[i]   -= ans1[i+3] * 3 ;
    }
    while( q-- ){
        int x ;cin>>x ;
        cout<<ans[x]<<endl;
    }
}
