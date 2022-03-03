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
int xuli( char x ){
    if( x == '0' ) return 0 ;
    else return 1;
}
const int N = 1e3 + 10 ;
vector<int> ds ;
vector< vector<int> > kq ;
void solve(){
    int n ; cin>>n ; string a ; cin>>a ;
    kq.clear() ;
    for(int i = 0 ;i < n ;i++){
        if( a[i] != '0' ){
            break ;
        }
        if( i == n -1 ){
            cout<<0<<endl; return  ;
        }
    }
    for(int i = 0 ;i < n ;i++){
        if( a[i] != '1' ){
            break ;
        }
        if( i == n -1 ){
            cout<<0<<endl; return  ;
        }
    }
    while( true ){
        ds.clear() ;
        int l = 0 , r = n-1 ;
        while(  l < r  ){
            while( l < n && a[l] == '0' ){
                l++ ;
            }
            while( r >=0 && a[r] == '1' ){
                r-- ;
            }
            if( l == n || r == 0 || l > r ){
                 break ;
            }
            ds.pb( l ) ;
            ds.pb( r ) ;
            //debugp( ii( l , r ) ) ;
            //swap( a[l] , a[r] ) ;
            l++;r-- ;
        }
        if( ds.size() == 0 ) break ;
        for(int i = 0 ; i < ds.size() ; i = i + 2 ){
            swap( a[ ds[i]  ] , a[ ds[i+1] ] ) ;
        }
        kq.pb( ds ) ;
    }
    cout<<kq.size()<<endl;
    for(auto x : kq){
        cout<<x.size()<<" ";
        sort( x.begin() , x.end() ) ;
        for(auto y : x ){
            cout<<y+1<<" ";
        }
        cout<<endl;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
