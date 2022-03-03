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
int query( int y , int x , int z){
    cout<<"? "<<y<<" "<<z<<" "<<x<<endl ;
    fflush(stdout) ;

    int l ;

    cin>>l ;
    return l ;
}
void in( int x , int y ){
    cout<<"! "<<x<<" "<<y <<endl ;
}
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n): n(n), f(n+1, 0) {}
    void set(int x, int i) {
        for (; i<=n; i += i&(-i)) f[i] = max(f[i], x);
    }
    int get(int i) const {
        int r = 0;
        for (; i>=1; i -= i&(-i)) r = max(r, f[i]);
        return r;
    }
};
map< int ,int > ds ;
void solve(){
    ds.clear() ;
    int kq1 , kq2 ;
    int id1 , id2 ;
    int n ; cin>> n ;
    kq1 = -1 ;
    for(int i = 3 ; i <= n ; i++ ){
        int p = query( 1 , 2 , i ) ;
        if( kq1 < p ){
            kq1 = p ;
            id1 = i ;
        }
        ds[ p ]++ ;
    }
    kq2 = -30 ;
    int o = max( kq1 , kq2 ) ;
    for(auto x : ds ){
        debugp(x) ;
        if( x.se == n - 2  ){
            for(int i = 4 ; i <= n ; i++){
                int l = query( 1 , 3 , i ) ;
                if( l > kq1 ){
                    //    cout<<"chay"<<endl;
                    in( 3 , i ) ;

                    return ;
                }
                if( i == n  ){
                    in( 1  , 2 ) ;
                }
            }
            return ;
        }
    }
    for(int i = 3 ; i <= n ; i++ ){
        if( i == id1 ) continue ;
        int op = query( 1 , id1 , i ) ;
        if( op <= kq1 ) continue ;
        if( kq2 == -30 ){
            kq2 = op ; id2 = i ;
        }
        else if( kq2 < op ){
            kq2 = op ; id2 = i ;
        }
    }
   // cout<<"chay1"<<endl;
    if( kq2 != -30 ){
        in( id1 , id2 ) ;
    }
    else{
        int vex = 4 ;
        if( vex == id1 ) vex = 3 ;

        if( query( vex , id1 , 2 ) == kq1 ){
            in( id1 , 2 ) ;
        }
        else if( query(  vex , id1 , 1 ) == kq1 ){
            in( id1 , 1 ) ;
        }
        else{
            in( 1 , 2 ) ;
        }
    }
}

void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x: a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    }
}

int daycontang( int n , vector<int> a ) {
    ios::sync_with_stdio(false); cin.tie(0);
    compress(a);
    Fenwick bit(n);
    for (int x: a) bit.set(bit.get(x-1) + 1, x);

    return bit.get(n);

}
signed main(){
    int u;cin>>u;
    while(u--  ){
        solve();
    }
}
