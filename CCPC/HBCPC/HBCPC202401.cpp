#include <bits/stdc++.h>
using namespace std;
map<char,int> freq;
int main()
{
    string s;
    cin >> s;
    for(char c : s) freq[c]++;
    int ans=0;
    for(int i='a';i<='z';i++ ){
        if(freq.count(i)&&i!='i') 
        ans++; 
    }
    cout << ans << endl;
}