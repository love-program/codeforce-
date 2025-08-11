// //map+迭代器
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     vector<int> p(n);
//     map<int,int> mp;
//     for(int i=0;i<n;i++)
//     {
//         cin>>p[i];
//         mp[i]=p[i];
//     }
//     string input;
//     cin>>input;
//     int cur=0;
//     bool check=true;
//     auto it=mp.begin();
//     for(int i=0;i<input.size();i++)
//     {
//         it->second--;
//         if(it->second==0)
//         {
            
//         }
//         if(input[i]=='S')
//         {
//             if(check)
//             {
//                 if(it++==mp.end())
//                 {
//                     it=mp.begin();
//                 }
//                 it++;
//             }
//             else
//             {
//                 if(it==mp.begin())
//                 {
//                     it=--mp.end();
//                     mp.end()++;
//                 }
//                 it--;
//             }
//         }
//         if(input[i]=='R')
//         {
//             check=!check;
//         }
//         if(input[i]=='D')
//         {
//             if(check)
//             {
//                 if(it++==mp.end())
//                 {
//                     it=mp.begin();
//                 }
//                 it++;
//             }
//             else
//             {
//                 if(it==mp.begin())
//                 {
//                     it=--mp.end();
//                     mp.end()++;
//                 }
//                 it--;
//             }
//             it->second+=2;
//         }
//         if(check)
//         {
//             if(it++==mp.end())
//             {
//                 it=mp.begin();    
//             }
//            it++;
//         }
//         else
//         {
//             if(it==mp.begin())
//             {
//                 it=--mp.end();
//                 mp.end()++;
//             }
//             it--;
//         }
//     }
// }
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

using namespace std;

// 辅助函数：顺时针移动迭代器，并处理循环（绕圈）
map<int, int>::iterator move_clockwise(map<int, int>::iterator current_it, map<int, int>& m) {
    current_it++;
    if (current_it == m.end()) {
        current_it = m.begin();
    }
    return current_it;
}

// 辅助函数：逆时针移动迭代器，并处理循环（绕圈）
map<int, int>::iterator move_counter_clockwise(map<int, int>::iterator current_it, map<int, int>& m) {
    if (current_it == m.begin()) {
        current_it = --m.end();
    } else {
        current_it--;
    }
    return current_it;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; 
    cin >> n >> k;
    
    vector<int> p(n);
    map<int, int> mp;
    
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        mp[i] = p[i];
    }
    
    string input;
    cin >> input;

    // check 为 true 表示顺时针, false 表示逆时针
    bool check = true;
    
    // it 指向当前出牌的玩家
    auto it = mp.begin();

    for(int i = 0; i < k; i++)
    {
        // 记录当前出牌玩家的迭代器，这很重要
        auto currentPlayerIt = it;
        char card_type = input[i];

        // 1. 当前玩家出牌，手牌减一
        currentPlayerIt->second--;

        // 2. 处理牌的效果，并决定下一位轮到的玩家是谁
        if (card_type == 'R') {
            // R牌：先翻转方向
            check = !check;
            // 下一位玩家是按新方向从当前玩家移动一次
            if (check) { // 新方向是顺时针
                it = move_clockwise(currentPlayerIt, mp);
            } else { // 新方向是逆时针
                it = move_counter_clockwise(currentPlayerIt, mp);
            }
        } else if (card_type == 'S' || card_type == 'D') {
            // S牌和D牌效果相似：都要影响/跳过下一家
            auto targetIt = it; // 先找到目标玩家
            if (check) { // 顺时针
                targetIt = move_clockwise(currentPlayerIt, mp);
            } else { // 逆时针
                targetIt = move_counter_clockwise(currentPlayerIt, mp);
            }

            if (card_type == 'D') {
                targetIt->second += 2; // D牌使目标玩家+2
            }
            
            // 无论是S还是D，都要跳过目标玩家，所以再移动一次找到最终的下家
            if (check) {
                it = move_clockwise(targetIt, mp);
            } else {
                it = move_counter_clockwise(targetIt, mp);
            }
        } else { // C牌 (普通牌)
            // C牌：按当前方向从当前玩家移动一次
            if (check) {
                it = move_clockwise(currentPlayerIt, mp);
            } else {
                it = move_counter_clockwise(currentPlayerIt, mp);
            }
        }
        
        // 3. 处理玩家出局
        // 在确定了下一位玩家 it 之后，再安全地删除出局的玩家
        if (currentPlayerIt->second == 0) {
            mp.erase(currentPlayerIt);
        }
        
        // 如果牌局只剩一人，可以提前结束
        if (mp.size() < 2) {
            break;
        }
    }

    // 4. 输出最终结果
    // 将p向量清零
    for(int i = 0; i < n; i++) {
        p[i] = 0;
    }
    
    // 将map中还在牌局的玩家手牌数更新到p中
    for(auto const& [player_id, cards] : mp) {
        p[player_id] = cards;
    }
    
    // 按1到n的顺序输出
    for(int i = 0; i < n; i++) {
        cout << p[i] << "\n";
    }

    return 0;
}