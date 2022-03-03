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
const int N  = 110 ;
int a[N] ;
int n ;
bool kt(){
    int id = n ;
    while( id >= 1 && a[id] == a[n] ){
        id-- ;
    }
    if( id == 0  ){
        return false ;
    }
    else{
        if( a[id] == a[n] - 1  ){
            return true ;
        }
        else{
            return false  ;
        }
    }
}
void solve(){
    cin>> n ;
    a[0] = -1 ;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i] ;
    }
    sort( a +  1 , a + n + 1 ) ;
    int du1 , du2 ;
    du1 = du2 = 0 ;
    for(int i = 1 ; i<= n ;i++){
        if( a[i] % 3 == 1 ){
            du1++ ;
        }
        else if( a[i] % 3 == 2 ){
            du2++ ;
        }
    }
    if( a[ n ] % 3 == 0 ){
        if( du1 == 0 && du2 == 0 ){
            cout<<a[n] / 3 <<endl;
            return ;
        }
        else{
            cout<<a[n] / 3 + 1 <<endl;
            return ;
        }
    }
    if( a[n] % 3 == 1 ){
        if( du2 == 0 ){
            cout<<a[ n ] / 3 + 1 <<endl;
        }
        else{
            if( a[1] == 1 ){
                cout<<a[n] / 3 + 2 <<endl;
            }
            else if( kt() ){
                cout<<a[n] / 3 + 2 <<endl;
            }
            else{
                cout<<a[n] / 3 + 1 <<endl;
            }
        }
    }
    else{
        if( du1 == 0 ){
            cout<<a[n] /3 + 1 <<endl;
        }
        else{

            cout<<a[ n ] / 3 + 2 <<endl;
        }
    }
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
