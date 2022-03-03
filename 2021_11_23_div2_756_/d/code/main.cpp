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
const int N = 2e5 + 10 ;
int a[N] ;
const int M = 30 ;
int sl[ M ] ;
int s[ N ] ;
const int mod = 1e9 + 7 ;
void cong(int &x,  int y){
    x = ( x + y ) % mod;
}
void nhan(int &x,  int y){
    x = ( x * y ) % mod;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n  ; cin>>n ;
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i] ;
        int dem = 0 ;
        while( a[i] % 2 == 0 ){
            dem++;
            a[i] /= 2;
        }
        sl[ dem ]++ ;
    }
    s[0] = 1 ;
    for(int i = 1;  i< N ; i++ ){
        s[i] = 1;
        nhan( s[i] , s[i-1] * 2 ) ;
    }
    int ans = 0 ;
    ans = s[ sl[0] ] -1 ;
    nhan( ans , s[  n - sl[0] ]  ) ;
    int du = n - sl[0] ;
    for(int i = 1;  i< M ; i++ ){
        du -= sl[i] ;
        if(  sl[i] < 2  ) continue;
        int kq = s[ sl[i] -1 ] - 1 ;
        nhan( kq , s[ du ] ) ;
        cong( ans, kq ) ;
    }
    cout<<ans<<endl;
}