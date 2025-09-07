#include <iostream>
#include <string>
#include<vector>
using namespace std;

int change(char ch){
    vector<char> dict_char = {'I','V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> dict_int = {1, 5, 10, 50, 100, 500, 1000};
    for(int i = 0; i < dict_char.size(); i++){
        if(ch == dict_char[i]){
            return dict_int[i];
        }
    }
    return 0;
}

int romanToInt(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int now = change(s[i]);
        int next = (i + 1 < s.size()) ? change(s[i + 1]) : 0;
        ans += (now >= next) ? now : -now;
    }
    return ans;
}


int main(){
    string string1 = "LVIII";
    cout << romanToInt(string1) << endl;

    return 0;
}