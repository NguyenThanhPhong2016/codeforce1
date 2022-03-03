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
int a[N] ;
vector< int > b ;
map< int ,int > s ;
const int maxn = 5e6 + 10 ;
vector<int> ds[ maxn ];
int ans ;
int sum ;
int sum1 ;
void xuli( int x ,int val , int kq ){
    debug( x ) ; debug( val ) ; debug( kq ) ; debug( sum1 ) ;debug( ans ) ;
    ans = max( ans , kq + sum1 ) ;
    for( int i = 0 ; i < ds[x].size() ; i++ ){
        if(  val % ds[x][i] == 0  ){
          //  debug( ds[x][i] ) ;
            int p = val / ds[x][i] ; int sl = 0 ;
            if( s.find(p) == s.end() ){
                sl = s[p] ;
            }
            else{
                sl = 0 ;
            }
       //     cout<<"chon "<<ds[x][i]<<endl;
            sum1 -= sl ;
            xuli( x , p , kq + p * sl  ) ;
            sum1 += sl ;
        }
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2 ; i < maxn ; i++){
        if( ds[i].size() != 0 ) continue ;
        for(int j = i  ; j < maxn ; j = j + i){
            ds[j].pb( i ) ;
        }
    }
    cout<<"xong"<<endl;
    int n ; cin>> n ;
    sum = n ;
    cin>>a[0] ;
    int all = a[0] ;
    for(int i = 1 ; i < n ; i++){
        cin>>a[i] ;
        all = gcd( all , a[i] ) ;
    }
    sort( a, a+ n ) ;
    if( all != 1 ){
        for(int i = 0 ; i < n ; i++ ){
            a[i] /= all ;
        }
    }
    for(int i = 0 , dem = 1 ; i < n ; i++ ){
        if(  i == n  - 1 ){
            b.pb( a[i] ) ;
            s[ a[i] ] = dem ;
        }
        else{
            if( a[i] == a[i+1] ){
                dem++;
            }
            else{
                b.pb( a[i] ) ;
                s[ a[i] ] = dem ;
                dem = 1;
            }
        }
    }
    n = b.size() ;
    for(int i = n - 1;i >= 0 ;i-- ){
        sum1 = sum - s[ b[i] ];
        xuli(  b[i] , b[i] , b[i] * s[ b[i] ] ) ;
    }
    cout<<ans<<endl;
}
