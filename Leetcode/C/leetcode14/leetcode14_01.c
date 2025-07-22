#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0) return strdup("");
    if(strsSize == 1) return strdup(strs[0]);
    int len = strlen(strs[0]);
    for(int i = 0; i < len; i++){
        char c = strs[0][i];
        for(int j = 1; j < strsSize; j++){
            if(strs[j][i] != c || i == strlen(strs[j])){
                char* ans = malloc(i + 1);
                memcpy(ans, strs[0], i);
                ans[i] = '\0';
                return ans;
            }
        }
    }
    return strdup(strs[0]);
}

int main(void) {
    char* strs[] = {"ad"};
    char* ans = longestCommonPrefix(strs, 1);
    printf("\"%s\"\n", ans);   // 输出 "fl"
    free(ans);
    return 0;
}