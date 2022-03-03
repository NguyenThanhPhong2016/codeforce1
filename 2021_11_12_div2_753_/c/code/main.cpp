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
const int N = 1e6 + 10 ;
int sum[ 3 ][N] ;
int sl(  int id , int trai , int phai  ){
    int kq = sum[id][phai] - sum[id][trai] ;
    return kq ;
}
void solve(){
    int n ; cin>>n ;
    string a ; cin>>a ;
    vector< int > ds ;
    a =  ' ' + a ;
    for(int i = 1 ; i <= n ; i++ ){
        if( a[i] == 'a' ){
            ds.pb( i ) ;
        }
    }
  //  invector(ds) ;
    if( ds.size() < 2 ){
        cout<<-1<<endl;
        return ;
    }
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 0 ; j < 3;  j++ ){
            if( j == a[i] - 'a' ){
                sum[j][ i ] = sum[ j ][ i -1 ] + 1 ;
            }
            else{
                sum[j][i] = sum[j][i-1] ;
            }
        }
    }
    int ans = 1e18 ;
    for(int i = 0; i +1 < ds.size() ; i++ ){
        int b1 = sl( 1 , ds[i] , ds[i+1] ) ;
        int c1 = sl( 2 , ds[i] , ds[i+1] ) ;
     //   debug(i) ;
    //    debugp( ii(b1,c1) ) ;
        if( b1 + c1 == 0 ){
            ans = 2 ;
            break ;
        }
        if( b1 + c1 == 1 ){
            ans = min(3ll,ans) ;
        }
        else if( b1 == 1 && c1 == 1 ){
            ans = min( 4ll , ans ) ;
        }
    }
    if( ans != 1e18 ){
        cout<<ans<<endl;
        return ;
    }
    for(int i = 0 ; i + 2 < ds.size() ; i++ ){
        int b1 = sl( 1 , ds[i] , ds[i+1] ) ;
        int c1 = sl( 2 , ds[i] , ds[i+1] ) ;
        int b2 = sl( 1 , ds[i+1] , ds[i+2] ) ;
        int c2 = sl( 2 , ds[i+1] , ds[i+2] ) ;
        if( b1 + c1 == 2 && b2 + c2 == 2 ){
            if( b1 == 2 && c2 == 2 ){
                ans = min(ans , 7ll) ;break ;
            }
            else if( c1 ==2 && b2 == 2 ){
                ans = min( ans , 7ll ) ; break ;
            }
        }
    }
    if( ans == 1e18 ) ans = -1 ;
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
