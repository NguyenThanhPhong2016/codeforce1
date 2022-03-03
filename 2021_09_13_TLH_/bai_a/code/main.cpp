#include<bits/stdc++.h>
using namespace std ;
int main(){
    pair< int,int > a[1010] ;
    int n ; cin>>n ;
    for(int i = 0 ; i< n ; i++){
        cin>>a[i].first>>a[i].second ;
    }
    sort( a, a + n ) ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j< n ; j++){
            int x = abs( a[i].first - a[j].first ) ;
            int t = abs( a[i].second - a[j].second ) ;
            if( x >= t ) ans++;
        }
    }
    cout<<ans<<endl;
}
