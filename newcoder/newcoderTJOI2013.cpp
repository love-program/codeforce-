#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// 使用当前时间作为随机数生成器的种子，确保每次运行的优先级不同
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Treap 节点定义
struct Node {
    int key;      // 元素的值 (1, 2, ..., N)
    int dp_val;   // 以该元素结尾的LIS长度
    int priority; // 随机优先级，用于维护堆属性
    int count;    // 以该节点为根的子树中的节点总数 (用于按位置分裂)
    int max_dp;   // 以该节点为根的子树中最大的dp_val (增强信息)
    Node *l, *r;

    // 构造函数
    Node(int k, int dp) : 
        key(k), 
        dp_val(dp), 
        priority(rng()), 
        count(1), 
        max_dp(dp), 
        l(nullptr), 
        r(nullptr) {}
};

// 全局变量，指向Treap的根
Node* root = nullptr;

// 获取节点的子树大小，处理空指针情况
int get_count(Node* t) {
    return t ? t->count : 0;
}

// 获取节点的子树中最大的dp值，处理空指针情况
int get_max_dp(Node* t) {
    return t ? t->max_dp : 0;
}

// 更新节点的 count 和 max_dp 值
void update_node(Node* t) {
    if (t) {
        t->count = 1 + get_count(t->l) + get_count(t->r);
        t->max_dp = t->dp_val; // 从自身dp值开始
        if (t->l) t->max_dp = std::max(t->max_dp, get_max_dp(t->l));
        if (t->r) t->max_dp = std::max(t->max_dp, get_max_dp(t->r));
    }
}

// 将树 t 按位置 pos 分裂成两棵树 l 和 r
// l 包含前 pos 个元素，r 包含剩下的元素
void split(Node* t, Node*& l, Node*& r, int pos, int add = 0) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    int current_pos = add + get_count(t->l);
    if (pos <= current_pos) {
        split(t->l, l, t->l, pos, add);
        r = t;
    } else {
        split(t->r, t->r, r, pos, current_pos + 1);
        l = t;
    }
    update_node(t);
}

// 将树 l 和 r 合并成一棵树 t
// 假设 l 中的所有元素在序列中都位于 r 中元素的前面
void merge(Node*& t, Node* l, Node* r) {
    if (!l || !r) {
        t = l ? l : r;
        return;
    }
    if (l->priority > r->priority) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    update_node(t);
}

int main() {
    // 提高C++ IO效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int k = 1; k <= n; ++k) {
        int xk;
        std::cin >> xk;

        Node *left_tree, *right_tree;
        // 1. 按位置 xk 分裂树
        split(root, left_tree, right_tree, xk);

        // 2. 查询 left_tree 中 dp 的最大值
        int max_l = get_max_dp(left_tree);

        // 3. 计算新节点的 dp 值
        int new_dp_val = 1 + max_l;

        // 4. 创建新节点
        Node* new_node = new Node(k, new_dp_val);

        // 5. 合并三部分：(left_tree) + (new_node) + (right_tree)
        merge(root, left_tree, new_node);
        merge(root, root, right_tree);

        // 6. 整棵树的根节点的 max_dp 就是当前序列的LIS长度
        std::cout << get_max_dp(root) << "\n";
    }

    return 0;
}