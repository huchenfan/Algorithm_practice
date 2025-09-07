#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int l, int r, int target){
    if(l == r) {return l;}
    int mid = l + (r - l) / 2;
    if(target <= nums[mid]) {
        return search(nums, l, mid, target);
    }
    else{
        return search(nums, mid + 1, r, target);
    }

}

int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int ans = search(nums, l, r, target);
    if(nums.size() == 1){
        return target <= nums[0] ? 0 : 1;
    }
    if(target > nums[ans]) {
        return ans + 1;
    }
    return ans;
}


int main(){
    vector<int> vector1 = {1,2};
    int target =  3;
    int ans = searchInsert(vector1, target);
    cout << ans << endl;
    return 0;
}
