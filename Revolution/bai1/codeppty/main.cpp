#include <iostream>

using namespace std;

inline int vd(int x , int y ){
    static int a = 10 ;
    return ( x > a || y) ? x - a + y++ : x + y ;
}
int s[] = {2 , 5 , 6 , 1  } ;
int main()
{

}
