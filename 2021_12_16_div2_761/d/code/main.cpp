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
int query( int a,  int b,  int c ){
    int kq ;
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    fflush(stdout) ;
    cin>>kq ;
    return 1-  kq ;
}
int l , r ;
const int N = 1e4 + 10 ;
int ans[ N ] ;
int n ;
void xuli1(int a , int b){
    vector<int> ds ;
    int id0 , id1 ;
    id0 = id1= -1 ;
    int dem = 1 ;
    for(int i = 1;  i<= n ; i++ ){
        if( i == a || i == b  ) continue ;
        if(ans[i] == -1 ){
            int h = query( a , b , i ) ;
            ans[ i ] = h ;
        }
        if( ans[ i ] == 0 ){
            id0 = i ;
        }
        else{
          //  debug(i) ;
            dem++ ;
            //debug(dem) ;
            id1 = i ;
        }
    }
    if( ans[a] == -1 ){
        int k = query( id0 , id1 , a ) ;
        ans[ a ] = k ;
    }
    ans[ b ] = 1 - ans[ a ] ;
    cout<<"! "<<dem<<" ";
    for(int i = 1 ; i <= n ; i++ ){
        if( ans[i] == 1 ){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
void xuli2( int a,  int b ){
    ans[ a ] = ans[ b ] = 0 ;
    for(int i = 4;  i <= n ; i += 3 ){
        int h = query( i , i + 1 , i + 2 ) ;
        if( h == 1 ){
            int k = query( i  , i + 1 , a  ) ;
            if( k == 1 ){
                ans[i] = ans[i+1] = 1 ;
                xuli1(  a , i  ) ;
            }
            else{
                k = query( i , i + 2  , a ) ;
                if( k == 1 ){
                    ans[ i ] = ans[ i + 2 ] = 1 ;
                    xuli1( a , i ) ;
                }
                else{
                    ans[ i + 1 ] = ans[ i + 2 ] = 1;
                    xuli1( a , i + 1 ) ;
                }
            }
            return ;
        }
    }
}
void xuli3( int a,  int b ){
    ans[ a ] = ans[ b ] = 1 ;
    for(int i = 4;  i <= n ; i += 3 ){
        int h = query( i , i + 1 , i + 2 ) ;
        if( h == 0 ){
            int k = query( i  , i + 1 , a  ) ;
            if( k == 0 ){
                ans[i] = ans[i+1] = 0 ;
                xuli1(  a , i  ) ;
            }
            else{
                k = query( i , i + 2  , a ) ;
                if( k == 0 ){
                    ans[ i ] = ans[ i + 2 ] = 0 ;
                    xuli1( a , i ) ;
                }
                else{
                    ans[ i + 1 ] = ans[ i + 2 ] = 0;
                    xuli1( a , i + 1 ) ;
                }
            }
            return ;
        }
    }
}
void solve(){
    cin>>n ;
    for(int i = 0 ; i <= n ; i++){
        ans[ i ] = -1 ;
    }
    l = n / 3;
    r = l*2 ;
    int sl[2] ;
    sl[0] = sl[1] = 0 ;
    for(int i =3 ; i <= n ;i++ ){
        int h = query( 1 , 2 , i ) ;
        sl[ h ]++ ;
        if( sl[0] != 0 && sl[1] !=0 ){
            xuli1( 1 , 2  ) ;
            return ;
        }
        else{
            if( sl[ 0 ] >= r ){
                xuli2( 1 , 2 ) ;
                return ;
            }
            else if( sl[ 1 ] >= r ){
                xuli3(  1 , 2  ) ;
                return ;
            }
        }
    }
}
signed main(){
       // srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
