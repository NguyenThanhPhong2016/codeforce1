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
int a[N] ;
int x[ N ] ;
vector< ii > duong ;
vector< ii > am ;
int ans1 ;
int x1 ;
int xuli( int a, int b ){
    if( abs(b) % a == 0 ){
        int p = -b / a ;
        return p ;
    }
    else{
        int p = -b / a;
        if( p*a + b >= 0 ){
            return p ;
        }
        else{
            return p + 1;
        }
    }
}
int xuli1(int a, int b){
    if( abs(b) % (-a) == 0 ){
        int p = b / a ;
        return p ;
    }
    else{
        b = -b ;
        a = -a ;
        int p = -b / a;
        if( p * a + b <= 0 ){
            return p ;
        }
        else{
            return p - 1;
        }
    }
}

void xuli3(int l , int r , int dau ){
  //  debug(l ) ; debug(r) ;
    if( r == -1 ){
        return ;
    }
    int kq ;
    if( l == -1 ){
        kq = x[ r ] ;
    }
    else{
        kq = x[r] - x[l] ;
    }
 //   debug(kq) ;
    ans1 = ans1 + x1*kq*dau ;
    if( l == -1  ){
        kq = a[r] ;
    }
    else{
        kq = a[r] - a[l] ;
    }
  //  cout<<"KQ : "<<kq<<endl;
    ans1 = ans1 + kq*dau ;
}
void xuliduong(){
    if( duong.size() == 0 ) return ;
    int id = lower_bound( duong.begin() , duong.end() , ii( x1, 0ll ) ) - duong.begin();
    id-- ;
    int bg ;
    if( id == -1 ){
        bg = -1 ;
    }
    else{
        bg = duong[id].se ;
    }
    xuli3(  -1 , bg , 1 ) ;
    xuli3( bg  , duong[ duong.size() - 1 ].se  , -1 ) ;
}
void xuliam(){
    if( am.size() == 0 ) return ;
    int id = lower_bound( am.begin() , am.end() , ii( x1 , 0ll ) ) - am.begin() ;
    id-- ;
    int bg ;
    if( id == -1 ){
        bg = -1 ;
    }
    else{
        bg = am[id].se ;
    }
    xuli3(  -1 , bg , -1 ) ;
    xuli3( bg  , am[ am.size() - 1 ].se  , 1 ) ;
}
signed main(){
       srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   // int p = (-4) / 3 ;cout<<p<<endl;
    int n ; cin>>n ;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i] ;
    }
    for(int i = 1 ;i  <= n ; i++ ){
        int x ; cin>>x ;
        if( i == 1 ) continue ;
        a[i] -= x ;
    }
    int ooo = a[1] ;
    a[1] = 0 ;
    //x[ 1 ] = 1;
    for(int i = 1 ; i <= n ; i++){
        x[i] = 1 ;
    }
    for(int i = 2 ; i <= n ; i++  ){
        for(int j = i + i ; j <= n ; j+= i ){
            a[ j ] = a[ j ] - a[ i ] ;
            x[ j ] = x[ j ] - x[ i ] ;
        }
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++ ){
        if( x[i] == 0 ){
            ans += abs( a[i] ) ;
        }
        else if( x[i] > 0  ){
            ii tem  ;
            tem.se = i ;
            tem.fi = xuli( x[i] , a[i] ) ;
            duong.pb(tem) ;
        }
        else{
            ii tem ;
            tem.se = i ;
            tem.fi = xuli( x[i] , a[i] ) ;
            am.pb( tem ) ;
        }
    }
    sort( duong.begin() , duong.end()  ) ;
    sort( am.begin() , am.end()  ) ;
    if(  false ){
        for(int i = 0 ; i < duong.size() ; i++ ){
        cout<<i<<" ";
        debugp( duong[i] ) ;
        int id = duong[i].se ;
        debugp( ii( x[ id ] , a[id] ) ) ;
        }
    }
    for( int i = 1 ; i < duong.size() ; i++ ){
        int id = duong[i].se ;
        int rid = duong[i-1].se ;
        x[ id ] += x[rid] ;
        a[ id ] += a[rid] ;
    }
    for( int i = 1 ; i < am.size() ; i++ ){
        int id = am[i].se ;
        int rid = am[i-1].se ;
        x[ id ] += x[rid] ;
        a[ id ] += a[rid] ;
    }
 //   debug(ans) ;
    int q ;cin>>q ;
    while( q-- ){
        ans1 = 0 ;
        cin>>x1 ;
        x1 -= ooo ;
        xuliduong() ;
      //  debug(ans1) ;
        xuliam() ;
        cout<<ans+ans1 <<endl;
    }
}
