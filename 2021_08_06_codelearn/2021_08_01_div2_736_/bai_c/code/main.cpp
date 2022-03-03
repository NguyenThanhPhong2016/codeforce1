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
	inv[n]=pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m  ; cin>>n>>m ;
    int a[ n+1 ];
    int ans = n ;
    for(int i = 1 ; i <= n ;i++) a[i] = 0;
    for(int i = 1 ; i <= m ;i++){
        int u , v ; cin>>u>>v ;
        if( u > v ) swap(u ,v) ;
        a[u]++;
        if( a[u] ==1 ) ans--;
    }
    int q ; cin>>q;
    while( q-- ){
        int t ; cin>>t ;
      //  debug(ans);
        if( t==1 ){
            int u , v ; cin>>u>>v ;
            if( u > v ) swap(u,v);
            a[u]++;
            if( a[u] == 1 ) ans--;
        }
        else if( t ==2 ){
            int u , v ; cin>>u>>v ;
            if( u > v ) swap(u,v);
            a[u]--;
            if( a[u] ==0 ) ans++;
        }
        else{
            cout<<ans<<endl;
        }

    }

}
