#include <iostream>
#include <stack>


using namespace std;

class MinStack {
public:

    stack<int> stk;
    stack<int> minStk;

    MinStack() {}

    void push(int val) {
      stk.push(val);
      if(minStk.empty() || minStk.top() >= val){
          minStk.push(val);
      }else{
          minStk.push(minStk.top());
      }
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

};
