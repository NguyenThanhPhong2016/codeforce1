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
void solve(){
    string a;  cin>>a ;
    string t; cin>>t ;
    vector<char> s ;
    int kt[9] ;
    for(int i = 0 ; i < 9 ; i++){
        kt[ i ] = 0 ;
    }
    for(int i = 0 ; i < a.size() ; i++ ){
        s.pb( a[i] ) ;
        if(  a[i] - 'a' < 9  ){
            kt[ a[i] - 'a' ]++ ;
        }
    }
    sort(s.begin() , s.end() ) ;
    if(  kt[ 1 ] == 0 || kt[0] == 0 || t != "abc" || kt[ 2 ] == 0 ){
        for(int i = 0 ; i< s.size() ; i++ ){
            cout<<s[i];
        }
        cout<<endl;
    }
    else{
        int id = 0 ;
        for(int i = 0 ; i< s.size() ; i++){
            if( s[i] =='a' ){
                cout<<s[i];
            }
            else{
                break ;
            }
        }
        for(int i = 0 ; i< s.size() ; i++){
           // debug(i) ;
            if( s[i] == 'c' ){
                cout<<s[i];
            }
            else{
                if( s[i] == 'a' || s[i] == 'b' ) continue;
                break ;
            }
        }
        for(int i = 0 ; i< s.size() ; i++){
            if( s[i] !='a' && s[i]!='c' ){
                cout<<s[i];
            }
        }
        cout<<endl;
    }

}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
