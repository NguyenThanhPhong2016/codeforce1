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
int sum = 0 ;
int l1 , r1 , k1 , n ;
int query( int l , int r ){
    cout<<"? "<<l<<" "<<r<<endl;
    int kq ;
    fflush( stdout ) ;
    cin>>kq;
    return kq ;
}
int xuli( int id , int val ){
    int denta = 1 + 8 * val ;
    int can = sqrt( denta ) ;
    if( can * can != denta ){
        return -1;
    }
    int a = ( 1 + can ) / 2 ;
   // cout<<" ting phai "<<endl;
    int phai = query( id + 1 , n ) ;
    int p = sum - phai - val ;
    int b = p / a ;
    l1 = id - a + 1 ;
    r1 = id + b  +1  ;
    p = sum - ( ( a + b ) * ( a + b - 1) / 2 );
  //  debug( p ) ;debug(sum) ;debug(   ( a + b ) * ( a + b - 1) / 2  ) ;
    denta = 1 + 8 * p ;
    can = sqrt( denta ) ;
    int c = ( 1 + can ) / 2 ;
    k1 = r1 + c - 1 ;
  //  debug(id) ;debug( a ) ;debug( b ) ;debug( c ) ;debug(l1) ; debug(r1) ; debug(k1) ;
    return 1 ;
}
void xuli1( int id , int val , int trai ){
    int denta = 1 + 8 * val ;
    int can = sqrt( denta ) ;
    int a = ( 1 + can ) / 2 ;
    //int trai = query( id + 1 , r ) ;
    int p = sum - trai - val ;
    int b = p / a ;
    k1 = id + a - 1 ;
    r1 = id - b ;
    p = sum - ( a + b) * ( a + b - 1) / 2 ;
    denta = 1 + 8 * p ;
    can = sqrt( denta ) ;
    int c = ( 1 + can ) / 2 ;
    l1 = r1 - c  ;
//    return 1 ;
}
void solve(){
    cin>>n ;
    int l = 1 ; int r = n ;
    sum = query( 1ll , n ) ;
    while( true  ){
        int mid = (l + r) / 2 ;
        int h = query( 1 , mid ) ;
        if( h == 0 ){
            l = mid + 1 ;
        }
        else if( h == sum  ){
            r = mid ;
        }
        else{
            if( mid != 1 ){
                int h1 = query( 1 , mid - 1 ) ;
                if( h1 == h ){
                    mid-- ;
                    h = h1 ;
                }
            }
            int po = xuli( mid , h ) ;
            if( po == -1 ){
                xuli1( mid + 1 , query( mid + 1, n ) , h ) ;
            }
            else{
                int sum1 = query( l1 , r1 -1 ) + query( r1 , k1  ) ;
                if( sum1 != sum ){
                    xuli1( mid + 1 , query( mid + 1 , n  ) , h ) ;
                }
            }
            break ;
        }
    }
    cout<<"! "<<l1<<" "<<r1<<" "<<k1<<endl;
}
signed main(){
//srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
