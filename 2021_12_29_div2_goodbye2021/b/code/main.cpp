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
const int N = 1e5 + 10 ;
int n ;
string a ;
char x ;
void xuli( int id ){
    //debug(id) ;
    if( id == 0 ){
        cout<<a[id]<<a[id]<<endl;
        return ;
    }
    while( id + 1< n && a[ id+1 ] == x ){
        id++;
    }
    for(int i = 0 ; i <= id ;i++){
        cout<<a[i];
    }
    for(int i = id ; i >= 0 ; i--){
        cout<<a[i];
    }
    cout<<endl;
}
void solve(){
    cin>> n ;
    cin>>a ;
    x = 'z' ;
    if( n == 1 ){
        cout<<a[0]<<a[0]<<endl; return ;
    }
    if( a[0] == a[1] ){
        cout<<a[0]<<a[0]<<endl; return ;
    }
    for( int i = 0 ; i< n ; i++){
        x= min( x,  a[i] ) ;
    }
    //cout<<x<<" "<<a[0]<<endl;
    if( a[0] == x  ){
        cout<<x<<x<<endl;
        return ;
    }
    char y = a[0] ;
    vector< char > ds ;
    for(int i = 0 ; i < n ; i++){
        if(  a[i] <= y ){
            ds.pb( a[i] ) ;
            y= min( a[i] , y ) ;
        }
        else{
            break ;
        }
    }
    for(int i = 0 ; i< ds.size() ; i++ ){
        cout<<ds[i];
    }
    for(int i = ds.size() - 1 ; i >=0 ; i-- ){
        cout<<ds[i] ;
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
