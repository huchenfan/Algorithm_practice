#include <iostream>
#include <string>
#include<vector>
using namespace std;


int romanToInt(string s) {
    vector<int> dict(256, 0);
    dict['I'] = 1;
    dict['V'] = 5;
    dict['X'] = 10;
    dict['L'] = 50;
    dict['C'] = 100;
    dict['D'] = 500;
    dict['M'] = 1000;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int now = dict[s[i]];
        int next = (i + 1 < s.size()) ? dict[s[i + 1]] : 0;
        ans += (now >= next) ? now : -now;
    }
    return ans;
}

int main(){
    string string1 = "LVIII";
    cout << romanToInt(string1) << endl;

    return 0;
}