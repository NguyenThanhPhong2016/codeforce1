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
int minm( int a[] ){
    for(int i =  0 ; i<= 9 ;i++){
        if( a[i] == 0 ) continue;
        return i ;
    }
}
int maxm( int a[] ){
    for(int i =  9 ; i >=0 ;i--){
        if( a[i] == 0 ) continue;
        return i ;
    }
}
bool check(int a[] , int k ){
    int dem = 0 ;
    for(int i = 0 ; i <= 9 ; i++){
        if( a[i] !=0 ) dem++;
      //  cout<<i<<" "<<a[i]<<endl;
    }
   // debug(dem) ; debug(k);
    return (dem == k) ;
}
void solve(){
    string a ; cin>>a ;
    int h[11] ;
    for(int i = 0 ; i<= 10 ; i++) h[i] = 0 ;
    stack< char > ds ;
    int k ; cin>>k ;
    int cnt = 0 ;
    for(int i = 0 ; i< a.size() ; i++){
        if( h[ a[ i ] - '0' ] == 0  ){
            if( cnt < k ){
                cnt++;
                ds.push( a[i] ) ;
                h[ a[i] - '0' ]++;
            }
            else{
                for(int j = 0 ; j <= 9 ; j++){
                    if( h[j] == 0 )continue;
                    if( j > a[i] - '0' ){
                        a[i] = j + '0' ;
                        int value = minm(h) ;
                        if( check( h , k ) == false ) value == 0;
                        for(int p = i + 1 ; p < a.size() ; p++){
                            a[p] = '0' +  value ;
                        }
                        cout<<a<<endl;
                        return;
                    }
                }
                //char k = ds.top()  ;
                for(int u = i - 1 ; u >= 0 ; u--  ){
                    int x= a[u] - '0' ;
                    if(  h[ x ] == 1  ){
                       // debug(x);debug(u);
                        a[u]++;
                        h[x]--;
                        h[x+1]++;
                        int value = minm( h ) ;
                        if( check( h , k ) == false) value = 0 ;
                       // debug(value);
                        for(int p = u + 1 ; p < a.size() ; p++ ){
                          //  debug(p);
                            a[p] = '0' + value ;
                        }
                        cout<<a<<endl; return ;
                    }
                    else{
                        if(  x == maxm(h)  ){
                            h[x]--;
                        }
                        else{
                            int tk = 0 ;
                            for(int l = x + 1 ; l <=  9 ;l++ ){
                                if( h[l] ==0 ) continue;
                                tk = l ;
                                break ;
                            }
                            h[ x ]--;
                            h[tk]++;
                            a[u] = '0' + tk ;
                            int value = minm(h);
                            if( check( h , k ) == false ) value == 0;
                            for(int p = u + 1 ; p < a.size() ; p++ ){
                                a[p] = '0' + value ;
                            }
                            cout<<a<<endl; return ;
                        }
                    }
                }
            }
        }
        else{
            h[ a[i] - '0' ]++;
        }
    }
    cout<<a<<endl;return ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
