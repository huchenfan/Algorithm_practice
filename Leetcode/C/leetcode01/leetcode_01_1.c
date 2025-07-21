#include<stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main(void) {
    int arr[5] = {1, 2, 5, 3, 8};
    int target = 9;
    int returnSize;
    int *ans = twoSum(arr, 5, target, &returnSize);
    printf("[%d, %d]", ans[0], ans[1]);
    free(ans);
    return 0;

}


int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    /* 遍历数组元素，耗时长*/
    int *ans = malloc(2 * sizeof *ans);  // 申请大小为两个int长度的内存空间，用来装答案
    *returnSize = 2; // 表示返回数组大小为2

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return NULL;
}


