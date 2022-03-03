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
string a  ,b ;
int vt( int id  ){
    int t = a[id] + b[id] - '0' - '0' ;
    if( t == 1 ) return 1 ;
    else if( t == 0 ) return 0 ;
    else return 2 ;
}
void solve(){
    int n ;cin>>n;
    cin>>a>>b;
    int ans = 0 ;
    a = '1' + a + '1' ;
    b = '0' + b + '0';
    int dem = 0 ;
    int so0 = 0 ;
    int so1 = 0 ;
    int kt[n+1] ;

    for(int i = 0; i <= n ; i++){
        kt[i] = 0;
    }
 kt[0] = 1;
    for(int i = 1 ; i <= n + 1 ;i++){
        if(   vt(i) == 1   ){
            ans += 2 ;
            if( kt[i-1] == 0 && vt(i-1) == 0 ) ans+= 1;
            kt[i] = 1 ;
            continue ;
        }
      //  debug(i);
        if( vt(i) == 0 ){
            if( kt[i-1] == 1 ){
            }
            else{
                if( vt(i-1) == 0  ){
                    ans+= 1;
                }
                else{
                    ans+= 2 ;
                    kt[i] = 1 ;
                }
            }
        }
        else{
            if( kt[i-1] == 1 ){
            }
            else{
                if( vt(i-1) == 0  ){
                    ans+= 2;
                    kt[i] = 1;
                }
                else{
                    ans+= 0 ;
                }
            }
        }
    //    debug(ans) ;
    }
    cout<<ans - 2 <<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
