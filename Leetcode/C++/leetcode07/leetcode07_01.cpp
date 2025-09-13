#include <iostream>

using namespace std;

int reverse(int x) {
    long result = 0;

    while(x){
        result = result * 10 + x % 10;
        x /= 10;
    }
    return (result < INT_MAX && result> INT_MIN) ? result : 0;
}

int main(){
    int a = -2147483648;
    cout << reverse(a) << endl;
    return 0;
}