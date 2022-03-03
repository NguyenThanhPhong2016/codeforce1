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
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());

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
void invector( vector< int > p ){
    cout<<" in p : ";
    for(auto x : p ){
        cout<<x<<" ";
    }
    cout<<endl;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int mint = 1e12 ;
struct node{
    int l , r ;

};

struct seg{
    int l1 , r1 ;
    ii value1 ;
    ii fake ;
};

const int N = 3e5 + 10  ;
vector< node > a[N] ;
seg s[ 8 * N ] ;
int ans[N] ;
int tvet[ N ] ;
// cac phan tu giong nhau chi lay 1
vector< int > trunglap( vector< int > &p ){
    vector<int > s1 ;
    for(int i =  0 ; i+1 < p.size() ; i++){
        if( p[i] == p[i+1] ) continue ;
        s1.pb( p[i] );
    }
    s1.pb( p[ p.size() - 1 ] ) ;
    return s1 ;
}
int k ;

void down( int v  ){

    s[v*2].value1 = s[v*2+1].value1 = s[v].value1 ;
    s[v*2].fake = s[v*2+1].fake = s[v].value1 ;
}
void update( int v ,  int l , int r , int value , int id  ){
    if( v >= 2 *k  ) return ;
    if(    s[v].l1 > r || s[v].r1 < l     ) return ;
    if( s[v].l1 >= l && s[v].r1 <= r  ){
        s[v].value1 = { value , id };
        s[v].fake = {value , id } ;
        return ;
    }
    if( s[v].fake != ii(0,0) ){
        down( v ) ;
        s[v].fake = {0,0} ;
    }
    update( v * 2 , l , r , value , id  );
    update( v*2 +1 , l , r , value , id ) ;
    s[v].value1 = max( s[v*2].value1 , s[v*2+1].value1 ) ;
}
ii getseg( int v , int l , int r  ){
    if( v >= 2 *k  ) return {-1 , 0} ;
    if(    s[v].l1 > r || s[v].r1 < l     ) return {-1 , 0 };

    if( s[v].l1 >= l && s[v].r1 <= r  ){
        return s[v].value1 ;
    }
    if( s[v].fake != ii(0,0)  ){
        down( v ) ;
        s[v].fake = {0,0} ;
    }
    return max(  getseg( v*2 , l , r  ) , getseg( v*2 + 1 , l ,r )  );
}
signed main(){
  //  cout<<mint<<endl;
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m ; cin>>n>>m ;
    vector<int > s2 ;
    for(int i = 0 ; i< m ; i++ ){
        int x, y ,  z; cin>>x>>y>>z ;
        a[x].pb( { y ,z } ) ;
        s2.pb( y ) ;
        s2.pb( z ) ;
    }
    for(int i = 0 ; i<= n ; i++){
        tvet[i] = i ;
    }
    sort( s2.begin() , s2.end() ) ;
   // s2 = trunglap( s2 );
    __unique(s2);
  //  invector( s2 );
    int nseg = s2.size() ;
    k =1 ;
    while( k < nseg ){
       // debug(k);
        k = k <<1 ;
    }
    for(int i = 0 ; i < k; i++  ){
        if( i >= nseg ){
            s[ i + k ].l1 = s[i+k].r1 = ++mint ;
            s[i+k].value1 = {0,0} ;
            s[i+k].fake = {0,0} ;
            continue;
        }
        s[ i + k ].l1 = s[i+k].r1 = s2[i] ;
        s[i+k].value1 = {0,0}  ;
        s[i+k].fake = {0,0} ;
    }
    for(int i = k -1 ; i >= 1 ; i-- ){
        s[i].l1 = min(  s[2*i].l1 , s[2*i+1].l1  ) ;
        s[i].r1 = max(  s[2*i].r1 , s[2*i+1].r1  ) ;
        s[i].value1 = {0,0}  ;
        s[i].fake = {0,0} ;
    }
    ii kq = {0 , 0} ;
    for(int i = 1 ; i <= n ; i++){
        if( a[i].size() == 0 ) continue;
        ii maxa = {0,0} ;
        for(auto x : a[i]  ){
            ii h = getseg( 1 , x.l , x.r  ) ;
            maxa = max( maxa , h ) ;
        }
        tvet[ i ] = maxa.se ;
        kq = max( kq , { maxa.fi +1 , i }  ) ;
        for(auto x : a[i]  ){
            update( 1 , x.l , x.r , maxa.fi + 1 , i );
        }
    }
    int dem = 0 ;
    int x = kq.se ;
    while( x != 0 ){
      //  debug(x);
        dem++;
        ans[x] = 1;
        x= tvet[x];
    }
    cout<<n-dem<<endl;
     for(int i = 1; i <= n ; i++){
        if( ans[i] == 0 ){
            cout<<i<<" ";
        }
    }
}
