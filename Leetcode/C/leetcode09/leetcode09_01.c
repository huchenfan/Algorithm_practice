#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    long reverse = 0;    // 用 long,而不是 int，因为 x翻转过来可能会 溢出；
    int x_ = x;
    while(x) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return (reverse == x_) ? true : false;
}

int main(void) {
    int num = -10;
    bool c = isPalindrome(num);
    printf("%s", c ? "true": "false");
    return 0;
}