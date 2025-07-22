#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0))return false;
    int reverse = 0;
    while(x > reverse){
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    return reverse == x || x == reverse / 10 ;
}


int main(void) {
    int num = 121;
    printf("%s", isPalindrome(num) ? "true": "false");
    return 0;
}