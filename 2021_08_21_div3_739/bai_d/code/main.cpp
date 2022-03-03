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
const int maxn = 4e18 ;
vector< string > s;
void xuli(int n ){
    string a = "" ;
    while( n>0 ){
        char x =  '0' + ( n % 10) ;
        a = x + a ;
        n = n / 10 ;
    }
    s.push_back(a) ;
}
int xulichuoi( string bd ,string ss ){
    //int kq = 0 ;
    int i = 0 ; int j = 0 ;
    while( i < bd.size() && j < ss.size() ){
        if( bd[i] == ss[j] ){
            //cout<<bd[i]<<" "<<ss[j]<<endl;
            i++;j++;
        }
        else{
            i++;
        }
    }
  //  debug(j);
    return j  ;
}

void solve(){
    string n ; cin>>n ;
    int kq = 100 ;
    for(int i = 0 ; i < s.size() ; i++){
        int h = xulichuoi( n , s[i] ) ;
       // cout<<"s i "<<s[i]<<endl;debug(h);debug(i);
        if( kq > n.size() + s[i].size() - 2 * h ) kq = n.size() + s[i].size() - 2 * h;
        //debug(kq);
    }
    cout<<kq<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int l = 1 ;
    //cout<<"x"<<endl;
    while( l <= maxn ){
        xuli( l );
        l = l * 2 ;
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
