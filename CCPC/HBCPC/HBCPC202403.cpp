//思路让k自增，匹配最紧急的人
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 为了代码简洁，给复杂类型起个别名
// 候选人格式：{r, id}
using Candidate = std::pair<int, int>;
// 定义一个“小顶堆”，r 值最小的候选人会自动排在最前面
using MinHeap = std::priority_queue<Candidate, std::vector<Candidate>, std::greater<Candidate>>;

// 存储每个人的信息
struct Person {
    int id;
    int l, r;
};

int main() {
    // 加快 C++ 的输入输出速度
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        people[i].id = i + 1;
        std::cin >> people[i].l >> people[i].r;
    }

    // 准备工作：按 l 值排序，方便我们按顺序解锁候选人
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.l < b.l;
    });

    MinHeap candidates;         // 候选人池
    std::vector<int> team;      // 最终的队伍
    int person_idx = 0;         // 指向下一个待检查的人

    // 核心循环：k 代表当前游戏人数，从 0 开始尝试增加
    for (int k = 0; k < n; ++k) {
        
        // 步骤 1: 更新候选池
        // 把所有 l <= k 的人都拉入候选池
        while (person_idx < n && people[person_idx].l <= k) {
            candidates.push({people[person_idx].r, people[person_idx].id});
            person_idx++;
        }

        // 步骤 2: 淘汰过期的候选人
        // 有些人虽然在池里，但他们的 r < k，已经不愿加入了，从堆顶丢掉
        while (!candidates.empty() && candidates.top().first < k) {
            candidates.pop();
        }

        // 步骤 3: 寻找最紧急的人
        // 如果池子空了，说明找不到任何人了
        if (candidates.empty()) {
            break; // 结束循环
        }

        // 选出最紧急的（r 最小的）那个人，他就在堆顶
        Candidate chosen_one = candidates.top();
        candidates.pop(); // 从候选池中移除

        team.push_back(chosen_one.second); // 让他加入队伍
    }

    // 输出答案
    std::cout << team.size() << std::endl;
    for (int i = 0; i < team.size(); ++i) {
        std::cout << team[i] << (i == team.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// struct point
// {
//     int id;
//     int x;
//     int y;
//     point(int id=0,int x=0,int y=0):id(id),x(x),y(y){}  
// };
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;cin>>n;
//     vector<point> points;
//     for(int i=1;i<=n;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         points.push_back(point(i,x,y));
//     }
//     sort(points.begin(),points.end(),[](const point &a,const point &b){
//         if(a.x==b.x) return a.y<b.y;
//         return a.x<b.x;
//     });
//     queue<int>ans;
//     int cur=0;
//     for(auto p:points)
//     {
//         if(p.x<=cur&&p.y>=cur)
//         {
//             ans.push(p.id);
//             cur++;
//         }
//     }
//     cout<<cur<<endl;
//     while(!ans.empty())
//     {
//         cout<<ans.front()<<" ";
//         ans.pop();
//     }
// }