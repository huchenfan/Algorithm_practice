#include <stdio.h>
#include <stdlib.h>


int nextPrime(int n) {
    /*算出2n以后最小的质数*/
    n = (n << 1) | 1;               // 先保证 ≥ 2n+1
    for (int p = n; ; ++p) {
        int ok = 1;
        for (int d = 2; d * d <= p; ++d)
            if (p % d == 0) { ok = 0; break; }
        if (ok) return p;
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int cap = nextPrime(numsSize);
    int *key = malloc(cap * sizeof *key);
    int *value = malloc(cap * sizeof *value);
    char *flag = calloc(cap, 1);
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int idx = (need % cap + cap) % cap;
        while(flag[idx] && key[idx] != need) {
            idx = (idx + 1) % cap;
        }

        if(flag[idx]) {
            int *ans = malloc(2 * sizeof *ans);
            ans[0] = value[idx];
            ans[1] = i;
            free(key);
            free(value);
            free(flag);
            return ans;
        }

        idx = (nums[i] % cap + cap) % cap;
        while (flag[idx] && key[idx] != nums[i]) {
            idx = (idx + 1) % cap;
        }
        key[idx] = nums[i];
        value[idx] = i;
        flag[idx] = 1;

    }
    free(key);
    free(value);
    free(flag);
    return NULL;
}



int main(void) {
    int arr[4] = {0, 4, 3, 0};
    int target = 0;
    int returnSize;
    int *ans = twoSum(arr, 4, target, &returnSize);
    printf("[%d, %d]", ans[0], ans[1]);
    free(ans);
    return 0;
}
