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

const int mod = 998244353 ;
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
}
int C(int n , int k){
    return ( ( ( fac[ n ] * inv[ n - k ] ) % mod  ) * inv[ k ] ) % mod ;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
map< char , int>  cnt[ 2 ] ;
bool kt( string& p){
    if( p == "BB" || p == "WW" ){
        return true;
    }
    else{
        return false ;
    }
}
bool kt1( string& p){
    if( p == "B?" || p == "??" || p == "BW" || p == "?W" ){
        return true;
    }
    else{
        return false ;
    }
}
bool kt2( string& p){
    if( p == "W?" || p == "??" || p == "?B" || p == "WB" ){
        return true;
    }
    else{
        return false ;
    }
}
int tinh( string& p ){
    if( p == "??" ){
        return 2 ;
    }
    else if( p=="B?" || p == "BW" || p == "W?"  || p == "WB" || p == "?B" || p == "?W" ){
        return 1 ;
    }
    else{
        return 0 ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n  ;
    init( N - 1 ) ;
    int ok = 0 ;
    int ok1 = 0 ;
    int ans = 0 ;

    int sl = 0 ;
    int trai = 0 ;
    int phai = 0 ;

    int bw = 0 ;
    int wb = 0 ;
    int tich = 1 ;
    cnt[ 0 ][ 'B' ] = cnt[ 0 ][ 'W' ] = 0 ;
    cnt[ 1 ][ 'B' ] = cnt[ 1 ][ 'W' ] = 0 ;
    for(int i = 1 ; i <= n ; i++ ){
        string a ; cin>>a ;
        if( kt( a ) ){
            ok = 1 ;
        }
        else{
            ok1++ ;
        }
        if( kt1(a) ){
            bw++;
        }
        if( kt2(a) ){
            wb++;
        }
        tich = tich * tinh( a ) ;
        tich %= mod ;
        if( a[0] == '?' ){
            sl++;
            trai++ ;
        }
        else{
            cnt[ 0 ][ a[0] ]++;
        }
        if( a[1] == '?' ){
            sl++;
            phai++ ;
        }
        else{
            cnt[ 1 ][ a[1] ]++;
        }
    }
    int du1 = ( cnt[ 0 ][ 'B' ] - cnt[ 1 ][ 'W' ] ) ;
  //  debug(du1) ;
    if( du1 < 0 ){
        if( trai < abs( du1 ) ){
            cout<<0<<endl;
            return 0 ;
        }
        else{
            trai -= abs(du1) ;
        }
    }
    else{
        if( phai < du1 ){
            cout<<0<<endl;
            return 0 ;
        }
        else{
            phai -= du1 ;
        }
    }
    int du2 = ( cnt[ 0 ][ 'W' ] - cnt[ 1 ][ 'B' ] ) ;
    if( du2 < 0 ){
        if( trai < abs( du2 ) ){
            cout<<0<<endl;
            return 0 ;
        }
        else{
            trai -= abs(du1) ;
        }
    }
    else{
        if( phai < du2 ){
            cout<<0<<endl;
            return 0 ;
        }
        else{
            phai -= du2 ;
        }
    }
    if( trai != phai ){
        cout<<0<<endl;
        return 0 ;
    }
    if( ok == 1 ){
        cout<<C( sl , trai )<<endl;
    }
    else{
        ans = C( sl , trai ) ;
        if( bw == n ){
            tich--;
        }
        if( wb == n ){
            tich--;
        }
        ans = (ans - tich) % mod  ;
        ans = ( ans + mod  ) % mod ;
        cout<<ans<<endl;
    }
}
