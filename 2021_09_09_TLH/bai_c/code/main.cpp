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
const int N= 2e5 + 10 ;
vector<int> a[N] ;
map<int , ii > ds ;
void in(int i , int x , int j ,int y){
    cout<<"YES"<<endl;
    cout<<i<<" "<<x+1<<endl ;
    cout<<j<<" "<<y+1<<endl ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    int ok = 0 ;
    for(int i = 1 ; i <= n ; i++){
        int cnt ; cin>>cnt ;
        a[i].resize( cnt );
        int sum = 0 ;
        for(int j = 0 ; j < cnt ;j++){
            cin>>a[i][j] ;
            sum += a[i][j] ;
        }
        if( ok == 1 ) continue;
        for(int j = 0 ; j < cnt ; j++){
            if(  ds.find( sum - a[i][j] ) == ds.end()  ){
                ds[sum - a[i][j] ] = ii( i , j ) ;
            }
            else{
                ii l = ds[sum- a[i][j] ] ;
                if( l.fi == i ){
                    continue;
                }
                else{
                    in(  l.fi , l.se , i , j  );
                    ok = 1 ;
                    break ;
                }
            }
        }
    }
    if( ok == 0 ) cout<<"NO"<<endl;
}
