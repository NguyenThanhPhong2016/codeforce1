#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
//#define pb push_back
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
const int inf = 1e18 ;
vector< ii > ds[ N ] ;
int n , m , q ;
bool check[N] ;
int tinh[N][3] ;
void in(){
    cout<<"in : ";
    for(int i = 1 ; i <= n ;i++){
        cout<<tinh[i]<<" ";
    }
    cout<<endl;
}
void dijkstra(){
    priority_queue< ii, vector<ii> , greater< ii > > pri;
    pri.push(  {   0 , n   }  ) ;
    while( !pri.empty() ){
        ii x = pri.top() ;
       // in();
        //debugp(x);
        int u = x.se ;
        pri.pop();
        if( check[u] == true  ){
            continue;
        }
        check[u] = true ;
        for(auto y : ds[u]){
            int v = y.fi ;
            int w = y.se ;
            for(int i = 0 ; i < 3 ; i++){
                int k = tinh[u][i] + w ;
                if( tinh[ v ][k%3] > k ){
                    tinh[ v ][ k%3  ] = k ;
                    pri.push( { tinh[v][k%3] , v } ) ;
                }
            }
        }
    }
}

signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m ;
    for(int i = 0 ; i< m ; i++){
        int u , v , w ;
        cin>>u>>v>>w  ;
        ds[u].push_back(  { v , w}  ) ;
        ds[v].push_back(  { u , w } ) ;
    }
    for(int i = 0 ; i<= n ; i++){
        check[i] = false ;
        tinh[i][0] = inf ;
        tinh[i][1] = inf ;
        tinh[i][2] = inf ;
    }
    check[n] = false ;
    tinh[n][0] = 0 ;
    tinh[n][1] = 0 ;
    tinh[n][2] = 0 ;
    dijkstra();

    // be nhat len dau

    if( tinh[1][0] != inf ){
        cout<<tinh[1][0]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
