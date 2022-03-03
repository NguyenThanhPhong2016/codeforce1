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
const int N = 1e5 + 10 ;
int a[N] ;
int n , m ;
void add( int id , int val ){
    for( ; id <= n ; id += ( id & (-id) ) ){
        a[ id ] += val ;
    }
}
int get( int id ){
    int sum = 0 ;
    for( ; id > 0; id -= ( id & (-id) ) ){
        sum += a[id] ;
    }
    return sum ;
}
signed main(){
      srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        add( i , 1 ) ;
    }
    int sl = n ;
    while( m-- ){
        char p ; cin>>p ;
        if( p == '-' ){
            int x ; cin>>x ;
            add( x , -1) ;
            sl--;
        }
        else{
            int x ; cin>>x ;
            int l = x , r = n + 1 ;
            while( l < r ){
                int mid = ( r + l)>>1 ;
              //  debug(mid) ;
             //   debug( get(mid) - get( l - 1 ) );
                if(  get(mid) - get( l - 1 ) == 0 ){
                    l = mid + 1;
                }
                else{
                    r = mid ;
                }
            }
           // debug(get(l));
            if( l <=n) cout<<l<<endl;
            else cout<<-1<<endl;
        }
    }

}
