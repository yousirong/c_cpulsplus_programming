#include <iostream>
using namespace std;
// #define pi = 3.141592;  -> 매크로선언 중간에 바꿀 수 없고 선언한 곳에서만 변경 가능
int main(){
    const int a =10;
    // const 상수 선언
    cout<< a<<endl;
    // int a = 20; ->에러
    // a =20;  -> 에러
    cout<<a << endl;
    return 0;
}