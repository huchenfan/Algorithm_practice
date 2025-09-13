#include <iostream>
#include <queue>
#include <climits>
#include <cstdlib>

using namespace std;

int reverse(int x) {
    queue<int> queue1;
    long long result = 0;
    int sign = x > 0 ? 1 : -1;
    x = abs(x);
    while (x) {
        queue1.push(x % 10);
        x /= 10;
    }

    while (!queue1.empty()) {
        result = result * 10 + queue1.front();
        queue1.pop();
    }

    result *= sign;

    if (result < INT_MIN || result > INT_MAX) {
        return 0;
    }

    return static_cast<int>(result);
}

int main() {
    cout << reverse() << endl;
    return 0;
}