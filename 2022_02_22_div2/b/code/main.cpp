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
void solve(){
    int n ; cin>> n ;
    if( n == 3 ){
        cout<<3<<" "<<2<<" "<<1<<endl;
        cout<<1<<" "<<3<<" "<<2<<endl;
        cout<<3<<" "<<1<<" "<<2<<endl;
        return ;
    }
    if( n == 5 ){
        cout<<5<<" "<<4<<" "<<3<<" "<<2<<" "<<1<<endl ;
        cout<<4<<" "<<5<<" "<<3<<" "<<2<<" "<<1<<endl ;
        cout<<5<<" "<<4<<" "<<2<<" "<<3<<" "<<1<<endl ;
        cout<<5<<" "<<4<<" "<<3<<" "<<1<<" "<<2<<endl ;
        cout<<5<<" "<<3<<" "<<4<<" "<<2<<" "<<1<<endl ;
        return ;
    }
    int a[ n  + 1 ] ;
    for(int i = n ; i >= 1 ; i--){
        a[i] = n + 1 - i ;
    }
    for(int i = 1;  i<= n ; i++ ){
      //  debug(i) ;
        for(int j = 1 ; j <= n ; j++ ){
            cout<<a[j]<<" ";
        }
        cout<<endl;
        for(int j = n ; j >= 1 ; j--){
            a[j] = n + 1 - j ;
        }
       // debug(i) ;
        for(int j = 0 ; j < 10 ; j++ ){
            if( (i>>j )&1 == 1 ){
                int t = j + 1 ;
            //    debug(t) ;
                swap( a[ t*2 ] , a[t*2 - 1]  ) ;
            }
        }
     //   debug(i) ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
