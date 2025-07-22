#include <stdio.h>
#include <string.h>

int romanToInt(const char* s) {
    int val[256] = {0};          // ASCII 表，直接映射字符到数值
    val['I'] = 1;  val['V'] = 5;
    val['X'] = 10; val['L'] = 50;
    val['C'] = 100; val['D'] = 500;
    val['M'] = 1000;

    int res = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && val[s[i]] < val[s[i + 1]])  // i < n-1 , 是为了防止 i+1 超过索引
            res -= val[s[i]];    // 左减右加
        else
            res += val[s[i]];
    }
    return res;
}

int main(void) {
    char s[] = "MCMXCIV";
    printf("%d\n", romanToInt(s)); // 1994
    return 0;
}