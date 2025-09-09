#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s) {
    if (s.size() % 2 != 0) {
        return false;
    }
    vector<int> dict(256, 0);
    dict['('] = -1;
    dict[')'] = 1;
    dict['['] = -2;
    dict[']'] = 2;
    dict['{'] = -3;
    dict['}'] = 3;

    vector<int> s_int(s.size());
    for (int i = 0; i < s.size(); i++){
        s_int[i] = dict[s[i]];
    }
    for(int q = 0; q < s_int.size(); q++) {
        cout << s_int[q] << " ";
    }
    cout << endl;
    for(int i = 0; i < s_int.size(); i++){
        if(s_int[i] < 0){
            if( i + 1 < s_int.size() && s_int[i] + s_int[i + 1] == 0){
                s_int[i] = 0;
                s_int[i+1] = 0;
                continue;
            }
            for(int j = i + 3; j < s_int.size(); j += 2){
                if(s_int[i] + s_int[j] == 0){

                    s_int[i] = 0;
                    s_int[j] = 0;
                    break;
                }
            }
        }
    }

    for(int q = 0; q < s_int.size(); q++){
        cout << s_int[q]<< " ";
    }
    cout << endl;
    for(int k = 0; k < s_int.size(); k++){
        if(s_int[k] != 0){
            return false;
        }
    }


    return true;
}

int main(){
    string s = "([)]";
    cout << isValid(s) << endl;
    return 0;
}
