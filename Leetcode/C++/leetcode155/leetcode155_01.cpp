#include <iostream>
#include <vector>


using namespace std;

class MinStack {
public:

    vector<int> stk;

    vector<int> minStk;

    MinStack() {}

    void push(int val) {
        stk.push_back(val);
        if(minStk.empty() || minStk.back() >= val){
            minStk.push_back(val);
        }else{
            minStk.push_back(minStk.back());
        }

    }

    void pop() {
        stk.pop_back();
        minStk.pop_back();
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        return minStk.back();
    }


};

int main(){


    return 0;
}
