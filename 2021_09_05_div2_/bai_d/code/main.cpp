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
int nhan[15] ;
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int tong( vector<int > t ){
    int sum = 0 ;
    for(int i = 0 ; i < t.size() ;  i++){
        sum += t[i] ;
    }
    return sum ;
}
int so(vector<int> t){
    int sum = 0 ;
    for(int i = 0 ; i < t.size() ;  i++){
        sum = sum  * 10 + t[i] ;
    }
    return sum ;
}

void solve(){
    int a , n ; cin>>a>>n ;
    stack<int > t ;
    while( a > 0 ){
        t.push( a%10 );
        a = a/ 10 ;
    }
    vector<int > s ;
    while( !t.empty() ){
        s.pb( t.top() );
        t.pop() ;
    }
    //invector(s);
    int n1 = s.size();
    int id = (int )s.size()  ;
    id -= 2 ;
    while( tong( s ) < n ){
        while( s[id] == 0 ) id--;
        s[id]--;
        s[id+1]+= 10 ;
        id = (int )s.size() - 2 ;
    }
   // invector(s);
    int ans[n] ;
    for(int i = 0 ; i < n ; i++){
        ans[i] = 0 ;
    }
    id = 0 ;
    for(int i = n1 - 1 ; i >= 0 ; i--){
        if( s[i] > 0 ){
            if(  id == n -1  ) break ;
            ans[ id ] = nhan[ n1 - 1 - i ] ;
         //   debug(ans[id]);
            s[i]--;
            i++;
            id++ ;
        }
    }
    ans[id] = so( s );
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    nhan[0] = 1;
    for(int i = 1 ; i < 15 ; i++){
        nhan[i] = nhan[i-1] * 10 ;
    }
    while(t--){
        solve();
    }
}
