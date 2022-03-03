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
bool kiemtra( int id1 ,int id2 , string &s1 , string &s2  ){
    while( id1 < s1.size() && id2 < s2.size() ){
        if( s1[id1] != s2[id2] ) return false ;
        id1++;
        id2++;
    }
    if( id1 == s1.size() ) return true;
    else return false ;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ; cin>>n;
    pair< int , string > a[n+1] ;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i].se ;
        a[i].fi  = a[i].se.size() ;
    }
    sort( a + 1 , a + n + 1  ) ;
    for(int i = 1 ; i < n ; i++){
        if( a[i].fi == a[i+1].fi ){
            if( a[i].se != a[i].se ){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else{
            string s = a[i+1].se ;
            string s1 = a[i].se ;
            for(int j = 0 ; j < s.size() ; j++ ){
                if( kiemtra(0,j,s1 , s ) == true ){
                    break ;
                }
                if( j + 1== s.size() ){
                    cout<<"NO"<<endl;
                    return 0 ;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i =  1 ; i <=n ; i++){
        cout<<a[i].se<<endl ;
    }
}
