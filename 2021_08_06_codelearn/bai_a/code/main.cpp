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

int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int ans = 0 ;
vector<int> a;
void xuli( int l , int r  ){
   // debug(  l   ) ;
   // debug( r );
    if( l >= r ) return ;
    int mid = ( l + r ) / 2 ;
    xuli( l , mid ) ;
    xuli( mid + 1 , r );
    int i = l ; int j = mid + 1 ;
    int p[ r - l + 1 ] ;
    int dem = - 1;
    while( i <= mid && j <= r ){
        dem++;
        if( a[ i ] > a[j] ){
          //  cout<<" i "<<a[i]<<" "<<a[j]<<endl;
            ans = ans +  ( mid - i + 1 ) ;
            p[ dem ] = a[j];
            j++;
        }
        else{
            p[dem] = a[ i ] ;
            i++;
        }
    }
    if( i > mid  ){
        while( j <= r ){
            dem++;
            p[dem] = a[j] ;
            j++;
        }
    }
    else{
        while( i <= mid ){
          //  cout<<"a : "<<a[i]<<endl;
          //  ans = ans + ( r - mid );
          //  debug(ans);
            dem++;
            p[dem] = a[i] ;
            i++;
        }
    }
    for(int k = l ; k <= r ; k++){
        a[k] = p[ k - l ];
    }
}
int countInversions(vector<int> arr)
{
    a = arr;
    xuli( 0 , arr.size() -1 ) ;
    return ans ;
}
signed main(){
     //   srand(time(NULL));ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> p ;
    int n ; cin>> n ;
    for(int i = 0 ; i < n ; i++){
        int x ; cin>>x ;
        p.pb( x );
    //    cout<<p[i]<<endl;
    }
    cout<<countInversions( p );
}
