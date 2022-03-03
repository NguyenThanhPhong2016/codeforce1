
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
const int mod = 1e9 + 7 ;
const int N = 5e5+ 10 ;
int a[N] ;
int sum[N] ;

void cong(int &x , int y ){
    x = ( x + y ) % mod ;
}
void nhan( int & x , int y ){
    x = (  x*y  ) % mod ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ;cin>> n ;
    for(int i = 1  ; i <= n ; i++ ){
        cin>>a[i ] ;
    }
    int ans= 0 ;
    int socach = 1 ;
    sort(  a  + 1 , a + n +1 )  ;
    for(int i = 1 ; i <= n ; i++ ){
        sum[i] = sum[i-1] + a[i] ;
        sum[i] = sum[i] % mod ;
    }
    for(int i = n ; i >= 1 ; i-- ){
        int kq = a[i] *(a[i] - 1) * ( a[i] + 1 ) / 6 ;
        kq %= mod;
        cong( ans , kq) ;
    }
    debug(ans) ;
    int sl = 0 ;
    for(int i = n ; i >=1 ; i--){
     //   debug(i) ;
        if( a[i] % 2 == 1 ){
            int mid = a[i]  / 2;
            nhan( socach , 2 ) ;
            int mid1 = mid*(mid+1) % mod ;
            int kq = mid1 * ( sum[i-1] + sl ) ;
            kq %= mod ;
            debug(kq) ;
            cong(  ans , kq ) ;
            sl+=1 ;
        }
        else{
            int mid = a[i] / 2 ;
            int mid1 = mid*mid % mod ;
            int kq = mid1 * (sum[i-1] + sl )  ;
            kq %= mod ;
            debug(kq) ;
            cong(  ans , kq ) ;
        }
    }
    cout<<ans<<" "<<socach<<endl;

}
