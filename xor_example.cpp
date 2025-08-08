#include <iostream>
#include <vector>
using namespace std;

// 计算数组的异或和
int xorSum(const vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;  // 异或运算
    }
    return res;
}

int main() {
    // Example 1: Find unique number appearing odd times
    vector<int> nums1 = {1, 2, 3, 2, 1};
    cout << "Unique odd count number: " << xorSum(nums1) << endl;

    // Example 2: XOR of two numbers
    int x = 5, y = 7;
    cout << x << " XOR " << y << " = " << (x ^ y) << endl;

    // Example 3: Swap two variables
    int a = 5, b = 7;
    cout << "Before swap: a=" << a << ", b=" << b << endl;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "After swap: a=" << a << ", b=" << b << endl;

    // Example 4: XOR sum of array
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Array XOR sum: " << xorSum(nums2) << endl;

    return 0;
}
