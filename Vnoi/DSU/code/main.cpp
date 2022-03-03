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
struct node{
    int id ;
    vector< int > s ;
};
node a[N] ;
int ans[N];
int ra[N] ;
int n ;
void update( int l , int r  ){
    //debug( l  ) ;debug(r);
   // int l1 = l , r1 = r ;
    l = ra[l];
    r = ra[r];
  //  cout<<"t 2 : "<<endl;debug( l  ) ;debug(r);

    if(  a[l].s.size() < a[r].s.size()  ){
        for(auto x : a[l].s ){
            a[r].s.pb( x );
        }
        a[l].s.clear();
    }
    else{
        int x= a[l].id ;
        a[l].id = a[r].id ;
        a[r].id = x;
        ra[   a[r].id   ] =  r ;
        ra[   a[l].id   ] =  l  ;
        for(auto x : a[r].s ){
            a[l].s.pb( x );
        }
        a[r].s.clear();
    }
}
void  in(){
    for(int i = 1 ; i <= n ; i++){
        cout<<" i : "<<i<<"  : "<<a[i].id<<" : ";
        for(auto x : a[i].s){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<" ra "<<i<<" : "<<ra[i]<<endl;

    }
}
signed main(){
      //  srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q ; cin>>n>>q ;
    for(int i = 1 ; i  <= n ; i++){
        a[i].id = i ;
        a[i].s.pb( i ) ;
        ra[i] = i ;
    }
    while( q-- ){
        int l , r ; cin>>l>>r ;
        update( l , r );
        //in();
    }
    for(int i = 1;  i <= n; i++){
        if(  a[i].s.size() == 0  ) continue;
        for(auto x : a[i].s){
         //   debug(i);debug( x );debug( a[i].id ) ;
            ans[ x ] = a[i].id ;
        }
    }
    for(int i = 1;  i <= n ; i++){
        cout<<ans[i]<<" ";
    }
}
