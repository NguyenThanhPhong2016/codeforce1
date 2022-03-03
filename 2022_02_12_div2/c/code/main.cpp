#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 2e5 ;
int a[N] ;
void solve(){
    int ans = 0 ;
    int n ; cin>> n ;
    for(int i = 1 ; i <= n ; i++ ){
        cin>>a[i] ;
    }
    for(int i = 2; i < n ; i++){
        ans += ( a[i] + 1  ) / 2 ;
    }
    if( n == 3 ){
        if( a[ 2 ] % 2 == 0  ){
            cout<<a[2]/2<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return ;
    }
    for(int i = 2 ; i < n ; i++ ){
        if( a[i] % 2 == 0 || a[i] >= 3 ){
            cout<<ans<<endl; return ;
        }
    }
    cout<<-1<<endl ;
}
signed main(){
    srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
