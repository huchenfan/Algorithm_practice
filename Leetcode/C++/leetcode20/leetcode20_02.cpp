#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


bool isValid(string s) {
    if (s.size() & 1) return false;
    stack<int> st;
    int map[256] = {0};
    map['('] = 1; map[')'] = -1;
    map['['] = 2; map[']'] = -2;
    map['{'] = 3; map['}'] = -3;

    for (char c : s) {
        int v = map[c];
        if (v > 0) {                // 左括号
            st.push(v);
        } else {                    // 右括号
            if (st.empty() || st.top() != -v) return false;
            st.pop();
        }
    }
    return st.empty();
}