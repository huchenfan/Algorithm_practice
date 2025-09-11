#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int> &nums, int target) {
   unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        int need = target - nums[i];
        unordered_map<int, int>::iterator pos = mp.find(need);
        if(pos != mp.end()){
            vector<int> vec;
            vec.push_back((*pos).second);
            vec.push_back(i);
            return vec;
        }
        mp.insert({nums[i], i});
    }
    return {};
}


int main(){
    vector<int> vector1{1, 2, 6, 7};
    int target = 8;
    vector<int> ans = twoSum(vector1, target);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}
