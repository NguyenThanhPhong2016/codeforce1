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
vector<int> a ;
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //  int p[200000] ;
  //  return 0 ;
    int n , m ;cin>>n>>m ;
    if( m == 0 ){
        cout<<1<<endl;
        return 0;
    }
    for(int i = 0 ; i< m ; i++){
        int x ; cin>>x  ;
        a.pb(x) ;
    }
    if( n == m ){
        cout<<0<<endl;
        return 0 ;
    }
    a.pb(0);
    a.pb(n+1) ;
    sort( a.begin() , a.end()  ) ;
    int ans = n + 1 ;
  //  invector(a) ;
    for(int i = 1  ; i < a.size() ;i++  ){
        int h = a[i] - a[i-1] -1 ;
        if( h <= 0 ) continue;
        ans = min( ans , h ) ;
     //   debug(ans) ;
    }
    if( ans == n +1  ){
        cout<<-1<<endl;
        return 0 ;
    }
 //   debug(ans) ;
    if( ans == 0 ){
        cout<<ans<<endl; return 0 ;
    }
    int kq = 0;
    for(int i = 1  ; i < a.size() ;i++  ){
        int h = a[i] - a[i-1] -1 ;
        if( h <= 0 ) continue;
        kq = kq + ( h -1 ) / ans + 1 ;
    }
    if( kq == 0 ){
        cout<<-1<<endl;
        return 0 ;
    }
    cout<<kq<<endl;

}
