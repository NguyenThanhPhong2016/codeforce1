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
const int N = 2e5 + 10 ;
const int N1 = 1e6 + 10 ;
int kt[ N1 ] ;
int a[N] ;
void solve(){
    int n ; cin>> n ;
    int e ; cin>> e;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i] ;
        if( a[i] != 1 ){
            if( kt[ a[i] ] == 0 ){
                a[i] = 2;
            }
            else{
                a[i] = -1 ;
            }
        }
    }
    if(  n == e ){
        cout<<0<<endl;
        return ;
    }
    int ans = 0 ;
    for(int i = n ; i > n - e ; i--){
        int dem = 0 ;
        int tich = 1 ;
        vector<int > ds ;
        for(int j = i ; j >= 1 ; j -= e ){
            if( a[j] == -1 ){
                ds.pb( dem ) ;
                dem = 0 ;
               // invector(ds) ;
                for(int k = 0 ; k + 1 < ds.size() ; k++){
                    ans = ans + ( ds[k] + 1 ) * ( ds[k+1] + 1 ) - 1 ;
                }
                ds.clear() ;
                continue ;
            }
            else{
                if( a[j] == 1 ){
                    dem++;
                }
                else{
                    ds.pb( dem ) ;
                    dem= 0 ;
                }
            }
            if( j - e < 1 ){
                ds.pb( dem ) ;
            }
        }
     //   invector(ds) ;
        for(int k = 0 ; k + 1 < ds.size() ; k++){
            ans = ans + ( ds[k] + 1 ) * ( ds[k+1] + 1 ) - 1 ;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2 ;i < N1 ; i++ ){
        if( kt[N1] != 0 ) continue ;
        for(int j = i + i ; j < N1 ; j+= i){
            kt[ j ] = 1;
        }
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
