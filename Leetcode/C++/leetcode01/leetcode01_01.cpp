#include <iostream>
#include <vector>

using namespace std;

int nextPrime(int n){
    n = 2 * n;
    for (int p = n; ; p++){
        int ok = 1;
        for(int i = 2; i * i <= p; i++){
            if (p % i == 0) { ok = 0; break; }

        }
        if (ok) return p;
    }
}

vector<int> twoSum(vector<int> &nums, int target) {
    int numSize = nums.size();
    int cap = nextPrime(numSize);
    vector<int> index(cap), value(cap);
    vector<char> flag(cap, 0);          // �� char �͹���

    for (int i = 0; i < numSize; ++i) { // i ������
        int need = target - nums[i];
        int idx = (need % cap + cap) % cap;

        while (flag[idx] && value[idx] != need)
            idx = (idx + 1) % cap;

        if (flag[idx])                  // �ҵ�����
            return {index[idx], i};     // ֱ�ӷ����±�

        // ���뵱ǰԪ��
        idx = (nums[i] % cap + cap) % cap;
        while (flag[idx] && value[idx] != nums[i])
            idx = (idx + 1) % cap;

        index[idx] = i;
        value[idx] = nums[i];
        flag[idx] = 1;
    }
    return {};                          // �޽�
}

void printVector(vector<int> &v){

    for(vector<int>::iterator it  = v.begin(); it != v.end(); it++){
        cout << *it << " ";

    }

    cout << endl;
}

int main(){
    vector<int> vector1, ans;
    vector1 = {1,2,3,4};
    printVector(vector1);

    ans = twoSum(vector1, 7);
    printVector(ans);
    return 0;
}












