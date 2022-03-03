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

int xuli( int x , int id  ){
    return (x>>id)&1 ;
}

signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n ;
    int a[n];
    for(int i = 0 ; i< n ; i++){
        cin>>a[i] ;
    }
    vector<int > b(n , 0) ;
    int ans = 0 ;
    for(int i = 21 ; i >= 0 ; i--){
        map< int , int > ds[2] ;
        int sum = 0 ;
        for(int j = 0 ; j < n ; j++){
            if( xuli( a[j] , i) == 1 ){
                if( j % 2 == 0 ){
                    if( ds[0].find(sum) == ds[0].end() ){
                        ds[0][sum] = j ;
                    }
                    sum ^= b[j] ;
                    if( ds[ 1 ].find( sum ) != ds[1].end() ){
                        int kq = j - ds[1][sum] + 1 ;
                       // debug(j) ;debug( ds[1][sum] );
                        ans = max(ans, kq) ;
                    }
                }
                else{
                    if( ds[1].find(sum) == ds[1].end() ){
                        ds[1][sum] = j ;
                    }
                    sum ^= b[j] ;
                    if( ds[ 0 ].find( sum ) != ds[0].end() ){
                        int kq = j - ds[0][sum] + 1 ;
                        ans = max(ans, kq) ;
                    //    debug(j) ;debug( ds[0][sum] );
                    }
                }
                b[j] ^= 1<<i ;
            }
            else{

                for(int i = 0 ; i < 2;  i++){
                    ds[i].clear() ;
                }
            }
        }
    }
    cout<<ans<<endl;
}
