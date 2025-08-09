//只考虑右边界，出界的--，随后连加即可
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> ans(n+2);
    while(k--)
    {
        int l,r;
        cin>>l>>r;
        ans[l]++;
        ans[r+1]--;
    }
    for(int i=1;i<=n;i++)
    ans[i]+=ans[i-1];
    sort(ans.begin()+1,ans.end());
    cout<<ans[n/2+1]<<endl;
}