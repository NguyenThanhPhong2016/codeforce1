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
const int N = 1e5 + 20 ;
vector<ii > kq ;
int par1[N] ;
int par2[N] ;
int n ;
int root1( int x ){
    return par1[x] == x ? x : par1[x] = root1( par1[x] ) ;
}
int root2( int x ){
    return par2[x] == x ? x : par2[x] = root2( par2[x] ) ;
}

void them( int x , int y ){
    kq.pb({x,y}) ;
    par1[ root1(x) ] = root1(y) ;
    par2[ root2(x) ] = root2(y) ;
}

int tk( int id ){
    while( id <=n  ){
        if( root1(1) == root1(id)  ){
            id++;
        }
        else{
            if( root2(1) != root2( id ) ){
                them(id , 1) ;
                id++;
            }
            else{
                return id ;
            }
        }
    }
    return -1 ;
}
int tk1( int id ){
    while( id <=n  ){
        if( root2(1) == root2(id)  ){
            id++;
        }
        else{
            if( root1(1) != root1( id ) ){
                them(id , 1) ;
                return -id ;
            }
            else{
                return id ;
            }
        }
    }
    return 0 ;
}
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m1, m2 ;
    cin>>n>>m1>>m2 ;
    for(int i =0 ; i<= n; i++){
        par1[i] = i ;
        par2[i] = i ;
    }
    for(int i = 0 ; i< m1 ; i++){
        int x, y ; cin>>x>>y ;
        if( x>y ) swap(x,y) ;
        par1[ root1(y) ] = root1( x ) ;
    }
    for(int i = 0 ; i< m2 ; i++){
        int x, y ; cin>>x>>y ;
        if( x>y ) swap(x,y) ;
        par2[ root2(y) ] = root2( x ) ;
    }
    int l = 2 ;
    int r = 2 ;
    while( l <= n && r <=n ){
        int h = tk( l ) ;
     //   debug(h) ;
        if( h==-1 ){
            break ;
        }
        int k = tk1( r );
        if( k < 0 ){
            l = h ;
            r = -k ;
            continue;
        }
       // debug(k) ;
        if( k== 0 ){
            break ;
        }
        them( h , k ) ;
        l = h +1 ;
        r = k + 1 ;
    }
    cout<<kq.size()<<endl;
    for(auto [x,y] : kq){
        cout<<x<<" "<<y<<endl;
    }
}
