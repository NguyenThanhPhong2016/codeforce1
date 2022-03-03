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
int f( double x ){
    double l = 1;
    for(int i = 1 ; i <= 19 ; i++){
        l *= x;
    }
    return ( l - x * x - x + 1 ) / ( x - 1 ) ;
}
int f1( double x ){
    double l = 1;
    for(int i = 1 ; i <= 19 ; i++){
        l *= x;
    }
    return ( l - x * x - x + 1 ) ;
}
void solve(){
    double l = 0 ;
    double r = 0.99 ;
    while( r - l >= 0.000000001 ){
        double mid = (r + l ) / 2 ;
        if( f( mid ) > 0 ){
            r = mid ;
        }
        else{
            l = mid ;
        }
    }
    cout<<"l : "<<l<<endl;
}
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x ;  cin>>x ;
    cout<<"fx : "<<f1(x)<<endl;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
