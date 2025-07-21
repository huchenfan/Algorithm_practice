#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashItem;

#define HASH_SIZE 1007

HashItem hash[HASH_SIZE];

int hashIndex(int key) {
    /* 哈希线性探测，这是局部探测，不是遍历*/
//  int idx = abs(key) % HASH_SIZE; //处理不了相反数
    int idx = key % HASH_SIZE;
    if (idx < 0) idx += HASH_SIZE;
    while (hash[idx].key != key && hash[idx].value > 0) {
        idx = (idx + 1) % HASH_SIZE;
    }

    return idx;
}


int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *ans = malloc(2 * sizeof *ans);
    *returnSize = 2;

    for (int i = 0; i < HASH_SIZE; i++) {
        hash[i].key = 0;
        hash[i].value = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int idx = hashIndex(need);

        if (hash[idx].key == need && hash[idx].value != i && hash[idx].value >= 0) {
            ans[0] = hash[idx].value;
            ans[1] = i;
            return ans;
        }
        idx = hashIndex(nums[i]);
        hash[idx].key = nums[i];
        hash[idx].value = i;
    }
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