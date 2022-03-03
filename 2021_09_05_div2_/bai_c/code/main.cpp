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
void invector( vector< int > &p ){
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
int s[40] ;
int xuli( string a1 , int n  ){
    if( n == 0 ) return 1 ;
    vector<int> a(n) ;
 //   cout<<"a1 : "<<a1<<endl;
    int ans = 0 ;
    for(int i = 0 ; i< n ; i++){
        a[i] = a1[i] - '0' ;
    }
    for(int val = 0 ; val < ( 1<<(n-1) ) ; val++ ){
        vector<int > b = a ;
        int ok = 1 ;
        for( int i = 0 ; i < n - 1  ; i++ ){
            if( (val>>( n - 2  - i ) & 1 ) == 1 ){
                if( b[i] > 0 ){
                    b[i]--;
                    b[i+1] += 10 ;
                }
                else{
                    ok = 0 ;
                    break;
                }
            }
        }
      //  debug(val) ;
        if( ok == 0  ) continue ;
        int kq = 1;
        for(int i = 0 ; i < n ; i++ ){
            kq *= s [b[i] ] ;
        }
        ans += kq ;
     //   invector( b );
    }
    return ans ;
}
void solve(){
    string a ; cin>>a ;
   // cout<<a<<endl;
    int n = a.size() ;
    string b[2] ;
    b[0] = b[1] = "" ;
    for(int i = 0 ; i < n ; i++){
     //   debug(a[i] - '0');
        b[ i%2 ] += a[i] ;
    }
  //  debug(b[0]) ;debug( b[1] ) ;
    int c[2] ;
    for(int i = 0 ; i < 2 ; i++){
        c[i] = xuli( b[i] , b[i].size() ) ;
    }
    // debug(c[0]) ;debug( c[1] ) ;
    cout<<c[0]*c[1]  - 2<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    s[0] = 1 ;
    for( int i = 0 ; i< 40 ; i++ ){
        if( i<=9 ){
            s[i] = i + 1 ;
        }
        else if( i<= 18 ){
            int h = i - 9 ;
            s[i] = 9 - h + 1 ;
        }
        else{
            s[i] = 0 ;
        }
    }
    while(t--){
        solve();
    }
}
