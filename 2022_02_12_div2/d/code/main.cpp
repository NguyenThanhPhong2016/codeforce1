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
const int L = 2e4+10 ;
int kt[ L+10 ] ;
const int N = 1110 ;
int a[N] ;
int b[N] ;
void solve(){
    int n ; cin>> n ;
    vector<int> ds ;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i] ;
    }
    for(int i = 1 ; i <= n ; i++){
        cin>>b[i] ;
    }
    int sum = 0 ;
    for(int i = 1 ; i<= n ; i++){
        if(a[i] < b[i] ){
            swap( a[i] , b[i] ) ;
        }
        sum += a[i] - b[ i ] ;
    }
    // reset
    for(int i = 1 ; i<= sum; i++){
        kt[i] = 0 ;
    }
    int ans = 0 ;
    kt[0 ] = 1;
    for( int i = 1 ; i <= n ; i++ ){
        for(int j = sum ; j >=0  ; j-- ){
            if( kt[j] != 0 ){
                int t = a[i] - b[i] ;
                if(  kt[ j+t ] == 0 ){
                    kt[ j+t ] = i ;
                }
            }
        }
    }
    int  mid = sum / 2 ;
    while( kt[ mid ] == 0 ){
        mid-- ;
    }
    while( mid != 0 ){
        swap( a[ kt[mid] ] , b[ kt[mid] ]  ) ;
        mid   = mid  - b[ kt[mid] ] + a[ kt[mid] ] ;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = i+1;  j <= n ; j++){
            ans += ( a[i] + a[j] )*(a[i] + a[ j ] ) ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = i+1 ;  j <=n ; j++){
            ans += ( b[i] + b[j] )*(b[i] + b[ j ] ) ;
        }
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
