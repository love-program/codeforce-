// //本题重要学习内容
// 场景一：两个DFS调用 —— “选择”与“不选择”的二元决策
// 当你看到一个DFS函数内部有两个对自身的递归调用时，通常它解决的是组合/子集类问题。
// 在算法的每一步，你只关心一个元素，并对它做出一个二选一的决策。
// 核心思想：对于当前考虑的元素 item[i]，我要么 把它加入我的方案中，要么 不把它加入我的方案中。
// 问题类型：
// 从一堆物品中选出若干个，问能否凑成某个重量（0/1背包问题）。
// 找出集合的所有子集。
// **（你的问题）**从 n 道题中选出若干道题删除/保留。
// 决策树：这种结构形成的决策树是一棵二叉树。每个节点代表对一个元素做决策，它的左子树代表“选择”，右子树代表“不选择”。
// 代码骨架：
// code
// C++
// void dfs(int index, ...){
//     // 终止条件
//     if (index == n) {
//         // ...处理一个完整的方案...
//         return;
//     }

//     // 决策1: 选择/包含 index 号元素
//     // ...做选择（例如，加入列表）...
//     dfs(index + 1, ...); // 基于这个选择，继续处理下一个元素
//     // ...撤销选择（回溯）...

//     // 决策2: 不选择/不包含 index 号元素
//     // ...（通常什么也不做）...
//     dfs(index + 1, ...); // 基于这个选择，继续处理下一个元素
// }
// 你的代码就是这种模式：对于第 u 题，你做出了两个决策，并分别用一个 dfs 调用来探索这两个决策分支的后续所有可能性。
// dfs(u + 1, ...) (在 del.push_back(u) 之后) -> 探索删除第 u 题之后的所有可能。
// dfs(u + 1, ...) (在 del.pop_back() 之后) -> 探索不删除第 u 题之后的所有可能。
// 场景二：一个DFS调用（在循环内）—— “多选一”的决策
// 当你看到一个DFS函数内部是一个 for 循环，循环里只有一个对自身的递归调用时，它通常解决的是排列、路径搜索或填充类问题。
// 在算法的每一步，你需要从多个可用选项中选择一个来填入当前位置。
// 核心思想：对于当前需要填充的位置 pos（或者当前状态），我应该从所有 candidates（候选者）中选择哪一个？
// 问题类型：
// 生成数字/字符的全排列 (e.g., "1, 2, 3" 的所有排列)。
// N皇后问题（在第 k 行，把皇后放在哪一列？）。
// 解数独（在某个空格，填入1-9中的哪个数字？）。
// 在迷宫或图中寻找从起点到终点的路径（在当前节点，下一步走向哪个相邻节点？）。
// 决策树：这种结构形成的决策树是一棵多叉树。每个节点代表一个状态，它的每个子节点代表从当前状态出发，执行一个不同选择后达到的新状态。
// 代码骨架：
// code
// C++
// void dfs(当前状态 or 当前要填充的位置){
//     // 终止条件
//     if (所有位置都已填满){
//         // ...处理一个完整的方案...
//         return;
//     }

//     // 遍历所有可能的选择
//     for (每一个 "候选者" in "可用选择列表") {
//         // 做出选择
//         // ...更新状态（例如，标记候选者为“已使用”）...
        
//         // 基于当前选择，递归地去解决下一个子问题
//         dfs(新状态 or 下一个位置);
        
//         // 撤销选择（回溯），为for循环的下一次迭代做准备
//         // ...恢复状态（例如，标记候选者为“未使用”）...
//     }
// }
// 总结与对比
// 特征	两个DFS调用 (二元决策)	一个DFS调用 (在循环内)
// 核心问题	这个东西，我要还是不要？	这个位置，我该放什么东西？
// 问题模型	组合/子集	排列/填充/路径
// 决策方式	对一个元素做二选一决策	从多个选项中做多选一决策
// 代码结构	两个独立的递归调用	for循环 + 单个递归调用
// 经典例子	0/1背包、找子集	全排列、N皇后、解迷宫

#include<bits/stdc++.h>
using namespace std;

// --- 全局变量 ---
// n: 题目总数, m: 队伍总数
// rkg, rks, rkb: 金银铜排名线
// pg, ps, pb: 金银铜分数线
int n, m;
int rkg, rks, rkb;
int pg, ps, pb;
vector<string> a;       // 存储答题情况
bool found = false;     // solution_found -> found
vector<int> ans;        // final_answer -> ans

// --- 验证函数 ---
// kept: kept_problems (保留的题目列表)
void check(const vector<int>& kept) {
    vector<int> sc(m); // scores -> sc
    for (int i = 0; i < m; ++i) {
        int cur_sc = 0; // current_score -> cur_sc
        for (int p_idx : kept) { // problem_idx -> p_idx
            if (a[i][p_idx - 1] == '1') {
                cur_sc++;
            }
        }
        sc[i] = cur_sc;
    }

    sort(sc.begin(), sc.end(), std::greater<int>());

    if (sc[rkg - 1] == pg && sc[rks - 1] == ps && sc[rkb - 1] == pb) {
        found = true;
        ans = kept;
    }
}

// --- 深度优先搜索 ---
// u: start_index (当前处理的题目)
// target_d: deletions_to_make (目标删除数)
// del: currently_deleted (当前已删除的列表)
void dfs(int u, int target_d, vector<int>& del) {
    if (found) {
        return;
    }

    // 终止条件
    if (del.size() == target_d) {
        vector<int> kept;
        vector<bool> is_del(n + 1, false);
        for (int idx : del) {
            is_del[idx] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (!is_del[i]) {
                kept.push_back(i);
            }
        }
        check(kept);
        return;
    }
    
    // 剪枝
    if (u > n || del.size() + (n - u + 1) < target_d) {
        return;
    }

    // 分支1: 删除第 u 题
    del.push_back(u);
    dfs(u + 1, target_d, del);
    if (found) return;

    // 分支2: 不删除 (回溯)同时还要继续第二个分支
    del.pop_back();
    dfs(u + 1, target_d, del);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    cin >> rkg >> rks >> rkb;
    cin >> pg >> ps >> pb;

    // min_d / max_d: min/max deletions
    int min_d = max(0, n - 13);
    int max_d = n - 10;

    // d_cnt: deletions_to_make
    for (int d_cnt = min_d; d_cnt <= max_d; ++d_cnt) {
        //if (d_cnt < 0) continue; 

        vector<int> del; // currently_deleted -> del
        dfs(1, d_cnt, del);

        if (found) {
            break;
        }
    }

    if (found) {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            // 修复输出格式：最后一个数字后不加空格
            cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}