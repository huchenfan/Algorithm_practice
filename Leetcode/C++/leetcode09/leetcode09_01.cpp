#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    int x_ = x;
    int result = 0;

    while(x){
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result == x_;
}

int main(){
    cout << isPalindrome(121) << endl;
    return 0;
}