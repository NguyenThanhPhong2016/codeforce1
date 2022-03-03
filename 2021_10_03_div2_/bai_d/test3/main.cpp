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
const int N = 1e3 + 10 ;
vector<int> td[N] ;
int kt[N] ;
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    vector< ii > a ;
    a.pb( ii(0,0) ) ;
    for(int i = 1 ; i <= n - 1;  i++){
        int u, v ; cin>>u>>v ;
        td[u].pb( v ) ;
        td[v].pb( u ) ;
    }
    queue<int > ds ;
    ds.push(1) ;
    kt[1] = 1 ;
    while( !ds.empty() ){
        auto x = ds.front() ;
        ds.pop() ;
        for(auto y : td[x]){
            if( kt[y] == 1 ) continue;
            ds.push( y ) ;
            kt[y] = 1;
            a.pb( ii( x , y ) ) ;
        }
    }
    int sum ;
    cout<<"? "<<n<<" ";
    for(int i =1 ; i <= n ; i++){
        cout<<i<<" ";
    }
    fflush(stdout) ;
    cin>>sum ;
    int l = 1 , r = n -1 ;
    int dem = 0 ;
    while( true ){
       // debugp( ii(l,r) ) ;
        dem++;
        if( dem == n -1 ){
            exit(l) ;
        }
        if( l == r ){
            cout<<"! "<<a[l].fi<<" "<<a[r].se<<endl;
            return 0;
        }
        int mid = (r + l) / 2 ;
        set<int> s ;
        for(int i = l ; i <= mid ;  i++){
            s.insert( a[i].fi ) ;
            s.insert( a[i].se ) ;
        }
        cout<<"? "<<s.size()<<" ";
        for(auto x : s){
            cout<<x<<" ";
        }
        fflush(stdout) ;
        int val ; cin>>val ;
        if( val == sum ){
            r = mid;
        }
        else{
            l = mid + 1 ;
        }
    }

}
