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
	inv[n]=pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 2e5 + 10  ;
int n ;
int s[N][23] ;
int get( int i , int j  ){
    if( j==i ) return s[ j ][0] ;
    int h = j - i + 1 ;
    int ans = -1 ;
    for(int k = 0 ; (1 << k )<= h ;k++ ){
        if( ( h & ( 1<<k ) ) == 0 ) continue;
        if( ans == -1 ) ans = s[ i ][ k ];
        else{
            ans = gcd( ans , s[i][k] );
        }
        h -=  ( 1<<k )  ;
        i = i + ( 1<<k );
    }
    return ans ;
}
void solve(){
    cin>> n ;
    int a[n] ;
    for(int i = 0 ; i < n ;i++) cin>>a[i];
    if( n==1 ){
        cout<<1<<endl; return ;
    }
    n--;
    for(int i = 0 ; i < n ;i++){
        s[i][0] = abs( a[i+1] - a[  i  ] ) ;
    }
    for(int j = 1 ; j < 23 ; j++){
        for(int i = 0 ; i + ( 1 << j ) <= n ; i++){
            s[i][j] = gcd( s[i][ j-1 ] , s[ i + ( 1 << (j-1) ) ][j-1] ) ;
        }
    }
    int ans = 0 ;
    int j = 0 ;
    for(int  i = 0 ; i < n ; i++){
        while( j <= i && get( j , i ) == 1 ){
            j++ ;
        }
        ans = max( ans , i - j + 1 );
      //  if( ans == 4 ) cout<<"ans : "<<i<<" "<<j<<endl;
       // cout<<" get "<<get(j,i)<<endl;

    }
    cout<<ans+1<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
