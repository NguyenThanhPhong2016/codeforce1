#include <iostream>

using namespace std;
void ktra(int* a , int *b , int &c ){
    *( ( *a + 1 == 1 ) ? b : a ) = *a ? *b : c ;
    int x = 10 ;
    int y = 0 ;
    cout<< ( x = y ? x : y )<<endl;
    cout<<x<<" "<<y<<endl;
}
int main()
{
    int a  = 1 , b = 2 , c = 0 ;
    ktra( &c , &a , b ) ;
    cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i = -5 ; i < 10 ; i++ ){
        cout<<~i<<endl;
    }
    return 0;

}
