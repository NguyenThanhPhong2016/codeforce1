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
const int N = 2e5 + 10 ;
int s[N] ;
void upd( int id , int n ,int val ){
    while( id <= n ){
      //  debug(id) ;
        s[id] += val ;
        id += ( id & ( -id ) ) ;
    }
}
int get( int id ){
    int sum = 0 ;
    while( id > 0 ){
      //  cout<<" id 1 : "<<id<<endl;
        sum += s[id] ;
        id -= ( id & ( -id ) ) ;
    }
    return sum ;
}
void solve(){
    int n ; cin>>n ;
    int a[n] ;
    vector<int> a1 ;
    for(int i = 0 ; i<= n ;i++){
        s[i] = 0 ;
    }
    for(int i = 0 ; i< n ; i++){
        cin>>a[i] ;
        a1.pb( a[i] );
    }
    sort( a1.begin() , a1.end()  ) ;
    for(int i = 0 ; i< n ; i++){
        a[i] = lower_bound( a1.begin() , a1.end() , a[i] ) - a1.begin() ;
        a[i]++;
    }
    int kq = 0;
    for(int i = 0 ; i < n ; i++){
        int sl = get( a[i] - 1 ) ;
       // cout<<i<<"  :  "<<i<<" "<<sl<<endl;
        int sl1 = get(  n  ) - get(  a[i] );
        sl = min( sl1 , sl ) ;
        kq += sl ;
        upd( a[i] , n , 1 ) ;
       // debug(kq) ;
    }
    cout<<kq<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
