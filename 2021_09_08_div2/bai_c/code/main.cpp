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

const int mod = 998244353  ;
const int N = 5e5 + 10  ;
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
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int tinh( int n , int k ){
    int kq = fac[n] * inv[n-k] ;
    kq = kq % mod;
    kq = kq * inv[k] ;kq = kq % mod;
    kq = kq * fac[k-1] ;kq = kq % mod;
    kq = kq * fac[ n - k ] ; kq = kq % mod;

   // debug(kq);
    return kq ;
}
void solve(){
    int n ; cin>>n ;
    int a[n+1];
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    sort( a + 1 , a + n + 1  ) ;
    if( a[n] - a[ n -1 ] > 1 ){
        //debug(a[n]);
        cout<<0<<endl;
        return ;
    }
    int val = a[n-1] ;
    if( a[n] == a[n-1] ){
      //  cout<<"sia"<<endl;
        cout<<fac[n]<<endl;
        return ;
    }
    int dem = 0 ;
    for(int i = 1 ; i <=n ;i++){
        if( a[i] == val ){
            dem++;
        }
    }
    int ans = fac[n] ;
    //ans = ( ans - fac[n-1]  + mod) % mod ;
   // debug(ans);
    ans = ( ans - tinh( n  , dem +1 ) + mod ) % mod ;
    cout<<ans<<endl;
}
signed main(){
       srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(N-1) ;
    int t;cin>>t;
    while(t--){
        solve();
    }
}
