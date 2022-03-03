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
	inv[n]=power(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
} */
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
const int N = 3e5 + 10 ;
int a[ N ] ;
int b[ N ] ;
int kt[ N ] ;
int duyet[N] ;
int tv[ N ] ;
int p[N] ;
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    for(int i = 1;  i <= n ; i++){
        cin>>a[i] ;
    }
    for(int i = 1 ; i<=n ; i++){
        cin>>b[ i ] ;
    }
    for(int i = 0 ; i <= n ; i++){
        duyet[i] = tv[i] = kt[i] = p[i] = -1 ;
    }
    queue< int > ds ;
    kt[ n ] = 1 ;
    ds.push( n ) ;
    duyet[ n ] = 1;
    while( !ds.empty() ){
        int vt = ds.front() ; ds.pop() ;
      //  debug(vt) ;
        //if( duyet[ vt ] == 1 ) continue ;
        duyet[ vt ] = 1 ;
        for(int i = vt - a[vt] ; i < vt ; i++ ){
            if( i == 0 ){
                tv[ i ] = vt ;
                goto ppp ;
            }
            if( kt[ i ] != -1 ) break ;
            kt[i] = 1 ;
           // debug(i) ;
            if( duyet[ i + b[i] ] != -1 ) continue ;
           // debug(i) ;
            duyet[ i + b[i] ] = 1;
            p[ i + b[i] ] = i ;
            tv[ i + b[i] ] = vt ;
            ds.push( i + b[i] ) ;
           // cout<<" i : "<<i<<endl;
        }
    }
    ppp : ;
    if( tv[0] == -1 ){
        cout<<-1<<endl;
        return 0 ;
    }
    vector<int> kq ;
    int vt = 0 ;
    p[0] = 0 ;
    while( vt != n ){
    //    debug(vt) ;
        kq.pb( p[vt] ) ;
        vt = tv[vt] ;
    }
    cout<<kq.size()<<endl;
    for(int i = kq.size() -1 ; i >=0 ; i--){
        cout<<kq[i]<<" ";
    }
}
