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
const int mod = 1e9 + 7 ;
int power1( int a , int  b){
    if( b == 0  ) return 1 ;
    int c=  b /2 ;
    c = power1( a , c ) % mod ;
    c = ( c * c ) % mod   ;
    if( b % 2 == 1 ) c = (  c  * a )%mod;
    return c ;
}
map< string , int > p ;
vector<int > dske[ 6 ] ;
void capnhat( int &x , int y ){
    x = ( x *y ) % mod;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k ; cin>>k  ;
    int n ; cin>>n ;
    vector< ii > ds ;
    p[ "while" ] = 0;
    p[ "yellow" ] = 5 ;
    p[ "green" ] = 1;
    p[ "blue" ] = 4 ;
    p[ "red" ] = 2 ;
    p[ "orange" ] = 3 ;
    for(int i = 0 ; i < 6 ; i++){
        for( int j = 0 ; j < 6 ; j++ ){
            if( i + j == 6 ) continue;
            dske[i].pb(j) ;
        }
    }
    for(int i = 0;  i< n ; i++){
        int id ; string l ;
        cin>>id>> l ;
        int mau = p[ l ] ;
        ds.pb( ii( id , mau ) );
    }
    sort( ds.begin() , ds.end()  ) ;
    int sl[n] ;
    vector<int > ans( 6 , 1 ) ;
    for(int i = 0 ; i < n ; i++){
        sl[i] = 1;
    }
    int ansb = -1 ;
    int duyet = 1 ;
    duyet <<= k ;
    duyet-- ;
    duyet-- ;
    for(int i = n -1 ; i >= 0 ; i--){
        duyet-- ;
        auto [id , val ] = ds[i] ;
        if( id  ==1 ){
            ansb = ans[ val ] ;
            break ;
        }
        vector<int> kq(6 , 0 );
        kq[ val ] = sl[ i ] ;
        id = id / 2 ;
        while( id >= 1 ){
            if( id == 1 ){
                int x =  0 ;
                for(int i = 0 ; i < 6 ; i++){
                    int x = 0 ;
                    for( auto y : dske[i] ){
                        x += kq[y] ;
                    }
                    if( x == 0  ){
                        cout<<0<<endl;
                    //    debug(i) ;
                        return 0;
                    }
                    capnhat( ans[i] , x ) ;
                }
                break ;
            }
            int id1 = lower_bound( ds.begin() , ds.end() , ii(id,0) ) - ds.begin() ;
            if( id1 != n ){
                if( ds[id1].fi == id ){
                    int val1 = ds[ id1 ].se ;
                    int x = 0 ;
                    for(auto y : dske[val1]){
                        x += kq[y] ;
                    }
                    if( x == 0  ){
                        cout<<0<<endl;
                    //    debug(i) ;
                        return 0;
                    }
                    capnhat( sl[id1] , x ) ;
                    break ;
                }
            }
            duyet-- ;
            vector<int > kq1(6,0) ;
            for(int j = 0; j < 6 ; j++){
                for( auto x : dske[j] ){
                    kq1[j] += kq[x] ;
                }
            }
            kq = kq1 ;
            id = id/2 ;
        }
    }
    debug(duyet) ;
    if( ansb != -1 ) cout<<ansb<<endl;
    else{
        ansb = 0 ;
        for(int i = 0 ; i< 6 ; i++ ){
            ansb += ans[i] ;
        }
        cout<<ansb<<endl;
    }
}
