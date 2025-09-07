#include <iostream>
#include <vector>

using namespace std;


int searchInsert(vector<int>& nums, int target) {
   int l = 0;
   int r = nums.size();
   while(l < r){
       int mid = l + (r  - l) / 2;
       if(target <= nums[mid]) {
           r = mid;
       } else{
           l = mid + 1;
       }
   }
    return l;
}


int main(){
    vector<int> vector1 = {3};
    int ans = searchInsert(vector1, 3);
    cout << ans << endl;
    return 0;
}
