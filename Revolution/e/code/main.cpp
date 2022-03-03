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
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
const int mod = 1e9 + 7 ;
const int N = 1e5 + 10 ;
int n , k ;
int a[ N ] ;
vector< int >  ds ;
set<int> s ;
int b[N] ;
vector<int> ans  ;
int c[N] ;
int get(int id ){
    return id % n ;
}
void solve1( int x , int root , int sl = 1  ){
    int id = root ;
    for(int i = 1 ; i <= x ; i++){
        id = get( id + sl ) ;
        sl = get( sl * 2 ) ;
        b[ id ]++ ;
        debug(i) ;
        debug(id) ;
    }
}
void xuliroot( int root ,int dem ){
    int root1 = root ;
    int sl = dem ;
    ds.pb( root ) ;
    while( true ){
      //  debug(root1) ;
        root1 = get( root1 + sl ) ;
        sl = get( sl  *  2 ) ;
        if( root1 == root ){
            break ;
        }
        else{
            ds.pb( root1 ) ;
        }
    }
}
int p , q  ;
void xuli( int x , int y , int mod1 ){
    if( y == 1  ){
        p = x / mod1  ;
        q = x % mod1 ;
        return ;
    }
    int h = y / 2 ;
    xuli( x , y / 2 , mod1 ) ;
   // debugp( ii( p , q) ) ;
    p = p * p * mod1 + 2 * p * q + ( q * q ) / mod1 ;
   // debug(p) ;
    p = p % mod ;
    q = ( q * q ) % mod1 ;
    if( y % 2 == 1 ){
        p = p * 2 + ( q * 2 ) / mod1  ;
        p = p % mod ;
        q = (q * 2) % mod1  ;
    }
   // debug( y ) ;
  //  cout<<p<<" "<<q<<endl;
}
void solve(){
    int id = 0 ;
    int sl = 1 ;
    int root = -1 ;
    s.insert( 0 )  ;
    while(   true   ){
        id = get(id + sl ) ;
        sl = get( sl * 2 ) ;
       // debug(id) ;
        if( s.find( id ) != s.end() ){
            root = id ;
            break ;
        }
        s.insert( id ) ;
    }
    id = 0 ;
    sl = 1 ;
  //  debug(root) ;
    int dem = 0 ;
    while( true ){
        dem++ ;
        id = get( id + sl ) ;
        sl = get( sl * 2 ) ;
      //  debug( id ) ;
        if( id == root ){
            break ;
        }
        else{
            b[id]++ ;
        }
    }
    k -= dem ;
  //  debug(root) ;
    xuliroot( root, sl ) ;
    int sz = ds.size() ;
    xuli( 2 , k , sz ) ;
    int h = p ;
    int du = q ;
    if( du != 0 ){
        b[ root ]++  ;
        solve1( du - 1 , root , sl ) ;
    }
    for( int i = 0 ; i < sz; i++ ){
        b[ ds[i] ] += h ;
        b[ ds[i] ]%= mod ;
    }
}
signed main(){
    // srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   // xuli( 2 , 5 , 1 ) ;
  //  cout<<"Pq : "<<p<<" "<<q<<endl;
    cin>>n>>k ;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i] ;
    }
    if( k <= 20 ){
        solve1( 1<<k , 0 ) ;
    }
    else{
        solve() ;
    }
    for(int i = 0 ; i < n ; i++ ){
        c[i] = b[ i ] ;
        c[i] += b[ get(n-i) ] ;
        c[i] %= mod ;
      //  debugp( ii( i ,c[i] ) ) ;
    }
    vector<int > d1 ; vector<int > d2 ;
    d1.resize( n ) ;
    for(int i = 0 ; i < n ; i++){
        d1[ i ] = a[i] ;
    }
    d2.resize( n ) ;
    for(int i = 0 ; i < n ; i++){
        d2[ i ] = c[i] ;
    }
    invector(d1) ; invector(d2) ;
    ans = multiply( d1 , d2 ) ;
 //   invector(ans) ;
    for(int i = 0 ; i< n ;i++){
        int x = 0;
        for(int j = i ; j < ans.size() ; j+= n){
            x += ans[j] ;
            x %= mod ;
        }
        if( x < 0 ) x += mod ;
        cout<<x<<" ";
    }
}
