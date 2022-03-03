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
// priority_queue<int, vector<int>, greater<int> > gquiz;
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
set< string > ds ;
set< string > ds1 ;
void xuli( string x ){

}
string ngc( string x ){
    string l = "" ;
    for(int i = 0 ; i < x.size() ; i++ ){
        l = x[i] + l ;
    }
    return l ;
}
void in(  ){
    cout<<"ds : "<<endl;
    for(auto x : ds ){
        cout<<x<<endl;
    }
}
void solve(){
    int n ; cin>> n ;
    ds.clear() ;
    ds1.clear() ;
    int ok = 0 ;
    for(int i = 0 ; i < n ; i++ ){
      //  in() ;
        string x ; cin>>x ;
        string y = ngc(x) ;
        if( x.size() == 1 ){
            ok = 1 ;
        }
        else if( x.size() == 2 ){
            if( x[0] == x[1] ){
                ok = 1 ;
            }
            else{
                if( ds.find( y ) != ds.end() ){
                    ok = 1 ;
                }
                else if( ds1.find( y ) != ds1.end() ){
                    ok = 1 ;
                }
                else{
                    ds.insert( x ) ;
                }
            }
        }
        else{
            string z = "" ;
            z = z  + x[ 2 ] + x[1] ;
           // cout<<" z : "<<z<<endl;
            if( x[0] == x[2] ){
                ok = 1;
            }
            else{
                if( ds.find( y ) != ds.end() ){
                    ok = 1 ;
                }
                else if( ds.find( z ) != ds.end() ){
                    ok = 1 ;
                }
                else{
                    string t = "" ;
                    t = t  + x[0] + x[1] ;
                    ds.insert( x ) ;
                    ds1.insert(t) ;
                }
            }
        }
    }
    if( ok == 1 ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
