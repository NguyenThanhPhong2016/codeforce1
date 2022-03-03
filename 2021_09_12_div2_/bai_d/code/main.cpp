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
bool cmp( ii x , ii y   ){

    return x.se < y.se ;
}
bool cmp1( ii x , ii y   ){
    if( x.se != y.se ) return x.se < y.se ;
    return x < y ;
}
bool cmp2( ii x ,ii y){
    if( x.fi != y.fi ) return x < y;
    else{
        return x > y ;
    }
}
const int N = 310 ;
ii a[N*N] ;
int s[N] ;
void add( int id  , int val ){
    while( id < N ){
        s[id] += val;
        id += ( id & (-id) ) ;
    }
}
int get(int id ){
    int sum = 0 ;
    while( id > 0 ){
        sum += s[id] ;
        id -= ( id & (-id) );
    }
    return sum ;
}
int xuli( int l ,int r ,int m  ){
    int sum = 0 ;
    for(int i = 0 ;i < N ; i++){
        s[i] = 0 ;
    }
    ii aa[m+1] ;
    for(int i = l ; i < r ; i++){
        aa[ i - l + 1 ].se = a[ i ].se ;
        aa[ i - l + 1 ].fi = i - l + 1 ;
    }
    sort( aa + 1 , aa + m +1 , cmp1 ) ;
    for(int i = 1; i <= m ; i++){
        int id = aa[i].fi ;
        sum += get(id) ;
        add(id , 1) ;
    }
    return sum ;
}
void solve(){
    int n ,m ; cin>>n>>m ;
    int n1 = n * m ;
    for(int i = 0 ; i< n1 ; i++){
        cin>>a[i].fi;
        a[i].se = i ;
    }
    sort( a , a + n1 ) ;
    int l = 0 ;
    while( l < n1 ){
        int r = l ;
        while( r < n1 && a[r].fi == a[l].fi ) r++;
        sort( a + l , a + r , cmp )  ;
        l = r;
    }
    int ans = 0 ;
    for(int i = 0 ;i < n1 ; i+= m){
        sort( a + i , a + i + m , cmp2 ) ;
        int kq = xuli(  i , i + m ,m  );
     //   debug(kq) ;
        ans += kq;
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
