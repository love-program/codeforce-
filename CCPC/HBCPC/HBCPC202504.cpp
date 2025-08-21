//二分思想
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// 为了防止输出 __int128 时出错，可以自定义一个输出函数
// 大部分现代编译器和在线评测系统支持 __int128
std::ostream& operator<<(std::ostream& os, __int128 val) {
    if (val == 0) return os << "0";
    std::string s = "";
    bool neg = val < 0;
    if (neg) val = -val;
    while (val > 0) {
        s += (val % 10) + '0';
        val /= 10;
    }
    if (neg) s += '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}

int n;
long long k;
std::vector<int> a;
std::vector<__int128> prefix_sum;

// check 函数返回一个 pair: {差值<=D的配对数, 这些配对的差值总和}
std::pair<long long, __int128> check(int D) {
    long long count = 0;
    __int128 total_sum_of_diffs = 0;
    int right = 0;
    for (int left = 0; left < n; ++left) {
        // 移动 right 指针，找到满足条件的上界
        while (right < n && a[right] - a[left] <= D) {
            right++;
        }
        // 对于当前的 left, a[left+1]...a[right-1] 都可以与之配对
        long long num_pairs = right - 1 - left;
        if (num_pairs > 0) {
            count += num_pairs;
            // 计算差值和: (a[left+1] - a[left]) + ... + (a[right-1] - a[left])
            // 等价于 (a[left+1] + ... + a[right-1]) - num_pairs * a[left]
            __int128 sum_of_aj = prefix_sum[right] - prefix_sum[left + 1];
            total_sum_of_diffs += sum_of_aj - (__int128)num_pairs * a[left];
        }
    }
    return {count, total_sum_of_diffs};
}

int main() {
    // 加速输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 必须排序
    std::sort(a.begin(), a.end());

    // 构建前缀和数组，用于在 O(1) 内计算区间和
    prefix_sum.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // 二分查找分界点 D
    int low = 0;
    int high = a[n - 1] - a[0];
    int ans_D = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid).first >= k) {
            ans_D = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 计算最终结果
    // 1. 先把所有差值 < ans_D 的配对全部选上
    std::pair<long long, __int128> result_less = check(ans_D - 1);
    long long count_less = result_less.first;
    __int128 sum_less = result_less.second;

    // 2. 还需要选 k - count_less 个配对，这些配对的差值都是 ans_D
    long long remaining_k = k - count_less;
    __int128 final_answer = sum_less + (__int128)remaining_k * ans_D;

    std::cout << final_answer << std::endl;

    return 0;
}