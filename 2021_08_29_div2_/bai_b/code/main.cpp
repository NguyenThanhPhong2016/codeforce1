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
const int N = 1e5 + 10  ;
int a[N] ;
int b[N] ;
int c[N] ;
void solve(){
    int n ; cin>>n ;
    int dem[2] ;
    dem[0] = dem[1] = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i] ;
        a[i] = a[i] % 2 ;
        dem[ a[i] ]++;
    }
    int ans = 1e18 ;
    if( dem [0] == dem[1] ){
        int i = 0 , j = 0 ;
        int kq  = 0;
        while(  i < n && j < n  ){
            while( i < n && a[ i ] == 1 ) i++;
            while( j < n && b[ j ] == 1 ) j++;
            if( i == n || j == n ) break ;
            i++;
            j++;
            kq += abs( i-j ) ;
        }
        debug( kq ) ;
        ans = min( kq , ans  );
         i = 0 , j = 0 ;
         kq  = 0;
        while(  i < n && j < n  ){
            while( i < n && a[ i ] == 1 ) i++;
            while( j < n && c[ j ] == 1 ) j++;
            if( i == n || j == n ) break ;
            kq += abs( i-j ) ;
            i++;
            j++;
        }
        debug(kq) ;
        ans = min( kq , ans  );
    }
    else if( dem[0] == dem[1] + 1 ){
        int i = 0 , j = 0 ;
        int kq  = 0;
        while(  i < n && j < n  ){
            while( i < n && a[ i ] == 1 ) i++;
            while( j < n && b[ j ] == 1 ) j++;
            if( i == n || j == n ) break ;
            i++;
            j++;
            kq += abs( i-j ) ;
        }
        ans = min( kq , ans  );
    }
    else if( dem[1] == dem[0] + 1 ){
        int i = 0 , j = 0 ;
        int kq  = 0;
        while(  i < n && j < n  ){
            while( i < n && a[ i ] == 1 ) i++;
            while( j < n && c[ j ] == 1 ) j++;
            if( i == n || j == n ) break ;
            i++;
            j++;
            kq += abs( i-j ) ;
        }
        ans = min( kq , ans  );
    }
    else{
        cout<<-1<<endl;
        return ;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i = 0; i< N ; i++){
        if( i%2 ==0){
            b[i] = 0 ;
            c[ i ] = 1;
        }
        else{
            b[i] = 1 ;
            c[i] = 0 ;
        }
    }
    while(t--){
        solve();
    }
}