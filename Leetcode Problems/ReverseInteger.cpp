#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long result = 0;

        while (x != 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            x = x / 10;
        }

        if (result > INT32_MAX || result < INT32_MIN)
            return 0;

        return static_cast<int>(result);
    }
};


int main() {
	Solution sol;
	int x = -32890;
	cout << "Reversed integer: " << sol.reverse(x) << endl;
	return 0;
}