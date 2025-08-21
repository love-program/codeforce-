//Trie树，字典树学习
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Trie 树节点
struct TrieNode {
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

// Trie 类
class Trie {
private:
    TrieNode* root;
    long long unique_prefix_count; // 用于统计本质不同前缀（即后缀）的数量

public:
    Trie() {
        root = new TrieNode();
        unique_prefix_count = 0;
    }

    // 向 Trie 树中插入字符串
    void insert(const std::string& s) {
        TrieNode* current = root;
        for (char ch : s) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
                unique_prefix_count++; // 每当创建一个新节点，说明发现了一个新的前缀
            }
            current = current->children[index];
        }
    }

    long long get_count() {
        return unique_prefix_count;
    }

    // 释放内存 (可选，但好习惯)
    ~Trie() {
        // ... 实现一个释放所有节点内存的函数 ...
    }
};

int main() {
    // 提高 IO 效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    Trie trie;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        // 将字符串反转
        std::reverse(s.begin(), s.end());
        // 插入到 Trie 树中
        trie.insert(s);
    }

    std::cout << trie.get_count() << std::endl;

    return 0;
}