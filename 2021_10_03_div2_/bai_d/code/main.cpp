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
const int N = 1e3 +10 ;
vector<int> a[N] ;
int n ;
int kt[N] ;
vector< int  > ds[N] ;
ii ans[N] ;
vector< int > ds1 ;
vector< int > la ;
int dem ;
void dfs( int id , int vt ){
    if(id != 1 && a[id].size() == 1 ){
        la.pb( vt ) ;
    }
    for(auto x : a[id]){
        if( kt[x] == 0 ){
            dem++ ;
            for(auto y : ds[vt] ){
                ds[dem].pb( y ) ;
            }
            ds[dem].pb( x ) ;
            ans[dem] = ii( x , id ) ;
            kt[x] = 1;
            dfs( x , dem ) ;
        }
    }
}
int query( set<int> p ){
    cout<<"? "<<p.size()+1 <<" "<<1<<" ";
    for(auto x : p ){
        cout<<x<<" ";
    }
    fflush(stdout) ;
    int kq ; cin>>kq ;
    return kq ;
}
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n ;
    for(int i = 0 ; i< n - 1;  i++){
        int u ,v ; cin>>u>>v ;
        a[u].pb(v) ;
        a[v].pb(u) ;
    }
    kt[1] = 1;
    dfs(1,0) ;
    set<int > s ;
    for(int i = 2 ; i <= n ; i++){
        s.insert( i ) ;
    }
    int sum = query( s ) ;

    for(int i = 1 ; i <= dem ; i++){
        cout<<"ds "<<i<<" : ";
        for(auto x : ds[i]){
            cout<<x<<" ";
        }
        cout<<endl;
        debugp(ans[i]) ;
    }
    int l = 1, r = n -1 ;
    int dem1 = 0 ;
    int t = 0 ;
    while( true ){
        dem1++;
        if( dem1 == n ){
            exit( t ) ;
        }
     //   debugp( ii(l,r) ) ;
        int mid = (l+ r ) / 2  ;
        s.clear() ;
        debug(mid) ;
        for(auto x : la){
            if( x < l ) continue;
            if( x > mid ) break ;
            for(auto y : ds[x]){
                s.insert( y );
                debug(y) ;
            }
        }
        for(auto x : la){
            if( x >= l ) break ;
            for(auto y : ds[x]){
                s.erase(y);
            }
        }
        int k = query(s) ;
        t = k ;
        if( k == sum ){
            if( l == mid  ){
                cout<<"! "<<ans[mid].fi<<" "<<ans[mid].se<<endl;
                return 0;
            }
            else{
                r = mid  ;
            }
        }
        else{
            l = mid + 1 ;
        }
    }
}
