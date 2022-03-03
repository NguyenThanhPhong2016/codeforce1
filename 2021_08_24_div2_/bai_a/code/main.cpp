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
void solve(){
    int n ;
    cin>>n ;
    ii a[n+1] ;
    for(int i = 1;  i<= n ; i++){
        cin>>a[i].fi ;
        a[i].se = i ;
    }
    int ans = 0 ;
    int dem = 0 ;
    int x = 5 * n * n ;
    for( int i = 1 ; i <= x ; i++ ){
      //  debug(i);
        int ok = 0 ;
        if( i % 2 == 1 ){
            for(int j = 1 ; j < n ;j = j+ 2 ){
                if( a[j] > a[j+1] ){
                    ok = 1;
                    swap( a[j] , a[j + 1] ) ;
                }
            }
        }
        else{
            for(int j = 2 ; j < n ;j = j+ 2 ){
                if( a[j] > a[j+1] ){
                    ok = 1;
                    swap( a[j] , a[j + 1] ) ;
                }
            }
        }
        if( ok == 1 ){
            if( dem == 0 )  ans++;
            else ans+= 2 ;
            dem = 0 ;
        }
        else if( dem ==1 ){
            break ;
        }
        else{
            dem = 1 ;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
