// 这个问题的核心难点在于操作次数 k 可以达到 10^9，这是一个巨大的数字。直接模拟 k 次操作是绝对不可能的，一定会超时。因此，我们必须找到一种方法来“跳过”大量的计算，这通常意味着我们要寻找某种模式或循环。
// 核心思想：状态演化与循环检测
// 什么是“状态”？ 在这个问题里，一个“状态”就是数组 a 在某个时刻的完整内容。整个过程就是数组从一个状态 a_0 变换到 a_1，再到 a_2，如此等等。
// 状态是有限的吗？ 虽然数组 a 的可能组合非常多，但它们是有限的。数组的长度是 n，其中的元素值也因为 mex 操作而不会无限增大。在一个有限的状态空间里进行变换，最终必然会发生两件事之一：
// 进入稳定状态（不动点）：数组变换到某个状态后，就再也不变了。例如 ... -> X -> X -> X -> ...。
// 进入一个循环：数组进入一个不断重复的状态序列。例如 ... -> C -> D -> E -> C -> D -> E -> ...。
// 我们的目标：就是找到这个循环。一旦我们找到了循环，我们就不需要再一步步模拟了，而是可以通过数学计算直接跳到第 k 步的状态。
// 例子：假设我们发现数组的变化是这样的：
// A -> B -> C -> D -> C -> D -> ...
// A -> B 是进入循环前的“前序期”（Transient part）。
// C -> D -> C -> ... 是一个长度为 2 的循环。
// 假设循环从第 2 步（状态 C）开始。如果我们想知道第 100 步是什么状态，我们不需要模拟 100 次。我们已经走了 2 步到达 C，还需要走 100 - 2 = 98 步。因为循环长度是 2，98 % 2 = 0，所以我们从 C 开始再走 0 步（在循环内的偏移量），最终状态还是 C。
// 算法步骤：如何实现循环检测
// 这个思路可以用一种经典的方法实现：使用哈希表（在 C++ 中是 std::map）来记录所有见过的状态。
// 数据结构：
// map<vector<long long>, int> seen_states;
// 键 (Key)：一个数组状态（vector<long long>）。
// 值 (Value)：这个状态第一次出现的步数（int）。
// vector<vector<long long>> history;
// 用来按顺序存储从第 0 步开始的每一个数组状态，方便我们找到循环开始时的那个数组。
// 模拟过程：
// 我们开始一个循环，模拟从第 step = 0 到 k 的每一步。在每一步开始时，我们都做一件事：
// 检查当前状态：查看当前的数组 current_a 是否在 seen_states 这个 map 中出现过。
// 如果出现过 (找到循环！)：
// a. 从 seen_states 中取出这个状态第一次出现的步数，记为 start_step。
// b. 当前的步数是 step。这意味着我们找到了一个从 start_step 开始，到 step-1 结束的循环。
// c. 计算循环的长度：cycle_len = step - start_step。
// d. 我们总共要走 k 步，现在已经走了 step 步，还剩下 remaining_k = k - step 步。
// e. 这些剩下的步数将在循环中进行。我们需要知道在循环里具体要走多少步，这通过取模运算得到：offset_in_cycle = remaining_k % cycle_len。
// f. 最终的状态就是循环的起点（第 start_step 个状态）再走 offset_in_cycle 步。我们可以直接从 history 数组中取出这个状态：final_a = history[start_step + offset_in_cycle]。
// g. 计算 final_a 的和，输出结果，然后结束程序。
// 如果没出现过 (这是一个新状态)：
// a. 记录这个新状态和当前步数：seen_states[current_a] = step;。
// b. 将这个状态存入历史记录：history.push_back(current_a);。
// c. 计算下一个状态 next_a，用于下一次循环。
// 特殊情况：
// 如果 k 非常小，我们可能在 k 步之内都找不到一个循环。在这种情况下，我们的 for 循环会正常运行 k 次并结束。此时，current_a 中存储的就是第 k 次操作后的结果，我们直接计算它的和即可。
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

// 辅助函数，执行一次完整的 mexification 操作
// 这个函数的逻辑是正确的，不需要修改
vector<long long> perform_step(int n, const vector<long long>& a) {
    // 数组中的值可能达到 n 或 n+1，所以大小设为 n+2 更安全
    vector<int> counts(n + 2, 0);
    for (long long val : a) {
        if (val <= n + 1) {
            counts[val]++;
        }
    }

    int mex = 0;
    while (mex <= n + 1 && counts[mex] > 0) {
        mex++;
    }

    vector<long long> next_a(n);
    for (int i = 0; i < n; ++i) {
        long long current_val = a[i];
        // 规则：如果一个数小于全局mex且是唯一的，它就保持不变
        if (current_val < mex && current_val <= n + 1 && counts[current_val] == 1) {
            next_a[i] = current_val;
        } else {
            // 否则，它就变成全局mex
            next_a[i] = mex;
        }
    }
    return next_a;
}

// 辅助函数，计算数组和
long long calculate_sum(const vector<long long>& a) {
    long long sum = 0;
    for (long long val : a) {
        sum += val;
    }
    return sum;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == 0) {
        cout << calculate_sum(a) << endl;
        return;
    }

    map<vector<long long>, int> seen_states;
    vector<vector<long long>> history;

    vector<long long> current_a = a;

    // 最多模拟 k 步
    for (int step = 0; step < k; ++step) {
        // 检查是否进入循环
        if (seen_states.count(current_a)) {
            int start_step = seen_states[current_a];
            int cycle_len = step - start_step;
            long long remaining_k = k - step;
            int offset_in_cycle = remaining_k % cycle_len;
            
            // 从历史记录中找到最终状态
            current_a = history[start_step + offset_in_cycle];
            cout << calculate_sum(current_a) << endl;
            return;
        }

        // 记录当前状态
        seen_states[current_a] = step;
        history.push_back(current_a);
        
        // 计算下一步状态
        current_a = perform_step(n, current_a);
    }

    // 如果 k 很小，循环没有被检测到，直接输出 k 次操作后的结果
    cout << calculate_sum(current_a) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}