#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    long result = 0;

    while(x){
        result = result * 10 + x % 10;
        x /= 10;
    }

    return (result > INT_MIN && result < INT_MAX) ? result : 0;
}

int main(void) {
    int num = -89562;
    int num_ = reverse(num);
    printf("%d", num_);
    return 0;
}