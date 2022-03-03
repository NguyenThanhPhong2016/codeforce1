#include <iostream>

using namespace std;

int main()
{
    string a = "";
    for(int i = 0 ; i < 26 ;i++){
        int x ; cin>>x ;x--;
        a += ('a' + x);
    }
    cout<<a<<endl;
}
