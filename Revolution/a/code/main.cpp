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
void solve(){

}
const int N = 510 ;
vector< vector<int> > ds ;
vector< vector<int> > a;
vector< vector<int> > ans;
int m , n ;
int ra[N] ;
bool cmp( vector<int> &a , vector<int> &b  ){
    for( int i = 0 ; i < n ; i++ ){
        if( a[i] != b[i]  ){
            return a[i] > b[i] ;
        }
    }
    return true ;
}
void upd1(){
    for(int i = 0 ; i < m; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            ans[i][j] = ds[i][j] ;
        }
    }
}
void upd(){
    for(int i = 0 ; i < m; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if( ans[ i ][j] > ds[i][j] ){
                return ;
            }
            if( ans[i][j] < ds[i][j] ){
                upd1() ;
                return ;
            }
        }
    }
}
void in( vector< vector<int> > x   ){
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++ ){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve( int x ){
    if( x != 0 ) swap( a[0] , a[x] ) ;
    for(int i = 0 ; i < n ; i++ ){
        ra[ a[0][ i ] ] = i ;
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++ ){
            ds[ i ][ j ] = a[ i ][  ra[ n - 1 - j] ] ;
        }
    }
    sort( ds.begin() , ds.end() , cmp ) ;
   // in( ds ) ;
    upd() ;
    if( x != 0 ){
        swap( a[0] , a[x] ) ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>> n ;
    a.resize(m) ;
    ds.resize(m) ;
    ans.resize(m) ;
    for( int i = 0 ; i < m ;i++ ){
        a[ i ].resize(n) ;
        ds[i].resize(n) ;
        ans[i].resize(n) ;
        for(int j = 0 ; j < n ; j++){
            cin>>a[i][j] ;
            a[i][j]--;
        }
    }
    for(int i = 0 ; i < m ; i++){
        solve( i ) ;
    }
 //   in(ans) ;
    int q ; cin>>q ;
    while( q-- ){
        int x , y ; cin>>x>>y ; x-- ; y-- ;
        cout<<ans[ x ][ y ]+1<<endl;
    }

}
