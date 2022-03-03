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
// priority_queue<int, vector<int>, greater<int> > gquiz;
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
const int N = 5010 ;
int a[N] ;
int b[ N ] ;
ii c[N] ;
int ans[N] ;
void solve(){
    int n ; cin>> n ;
    int x;  cin>> x ;
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i] ;
    }
    int maxy = -1e18 ;
    for(int i = 1 ; i <= n ; i++ ){
        int sum = 0 ;
        int maxx = -1e18  ;
        ii tem  ;
        for(int j = 0 ; j < i ; j++ ){
            sum += a[j] ;
        }
        maxx = sum ;
        tem = ii( 0 , i - 1 ) ;
        for(int j = i ; j < n; j++ ){
            sum = sum + a[j] - a[ j - i ] ;
            if( sum > maxx ){
                maxx = sum ;
                tem = ii( j - i + 1 , j ) ;
            }
        }
    //    debug(i) ;debugp( tem ) ;
       // debug(maxx) ;
        b[ i ] = maxx ;
        c[ i ] = tem ;
        maxy = max( maxy , b[i] ) ;
    }
    for(int i = n -1  ; i >= 1;  i-- ){
        b[i] = max( b[i] , b[i + 1] ) ;
    }
    ans[0] = b[ 1 ] ;
    for(int i = 1; i  <= n ; i++ ){
        ans[i] = b[i] + x*i ;
    }
    cout<<max(ans[0] , 0ll ) <<" ";
    for(int i = 1 ; i<= n ; i++ ){
        ans[i] = max( ans[ i ] , ans[i-1] ) ;
        ans[i] = max( ans[i] , 0ll ) ;
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
