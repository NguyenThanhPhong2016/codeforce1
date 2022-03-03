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
vector<ii> p ;
void solve(){
    int n ; cin>>n;
    int s[10] ;
    for(int i = 0 ; i < 10 ; i++) s[i]  = 0 ;
    string a ; cin>>a ;
    for( int i = 0 ; i< n ;i++ ){
        s[ a[i] - '0' ]++ ;
        for(int j = 0 ; j < p.size() ; j++ ){
            if( (int)(a[i] - '0') == p[ j ].fi ){
                cout<<1<<endl;
                cout<<p[j].fi<<endl;
                return ;
            }

        }
    }
    int ok = 0 ;
    for(int i = 2; i< 10 ;i++){
        if( s[i] == 0 ) continue ;
        ok = 1 ;
        if( s[i] % 2 == 0 ){
            int k = i * 10 + i ;
            cout<<2<<endl<<k<<endl;
            return ;
        }
    }
    if( false ){
        cout<<3<<endl<<111<<endl;
        return ;
    }
    for( int i = 0 ; i < n ; i++ ){
        for(int j = i + 1 ; j < n ; j++){
            int k = ( a[i] - '0' ) * 10 + a[j] - '0' ;
            for(int i = 2 ; i < k ; i++){
                if( k % i == 0){
                    cout<<2<<endl<<k<<endl;
                    return;
                }
            }
        }
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    p.pb( {1,0} ) ;
    p.pb( {4,0} ) ;
    p.pb( {6,0} ) ;
    p.pb( {8,0} ) ;
    p.pb( {9,0} ) ;
 //   p.pb( {,0} ) ;
    while(t--){
        solve();
    }
}
