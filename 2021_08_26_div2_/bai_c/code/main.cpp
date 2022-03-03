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
void in( int a , int b, int c ,int d ){
    cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
}
void solve(){
    int n ; cin>>n ;
    string a ;
    cin>>a;
    int mid = n / 2  ;
    for(int i = 0 ; i < n ; i++){
        if( a[i] =='0' ){
            if( i == 0 ){
                in( 0 , n - 1 , 1 , n -1 ) ;
                return ;
            }
            if( (i-1 - 0 + 1 ) >= mid  ){
                in( 0 , i , 0 , i -1  ) ;
                return ;
            }
            if(  ( n -1 - ( i+1 ) + 1  ) >= mid  ){
                in( i , n - 1 , i + 1 , n- 1 ) ;
                return ;
            }
        }
    }
    if( n % 2 ==0 )  in( 0 , mid -1 , mid , n -1 ) ;
    else{
        n--;
        mid = n /2 ;
        in( 0 , mid -1 , mid , n -1 ) ;
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
