#include<bits/stdc++.h>
using namespace std;

string checkSwapSort(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    
    if (arr == sortedArr) {
        return "Sorted";
    }
    
    vector<int> diffIndices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] != sortedArr[i]) {
            diffIndices.push_back(i);
        }
    }
    
    if (diffIndices.size() != 2) {
        return "Failed";
    }
    
    int i = diffIndices[0];
    int j = diffIndices[1];
    swap(arr[i], arr[j]);
    
    if (arr == sortedArr) {
        return "Sorted";
    } else {
        return "Failed";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << checkSwapSort(a) << endl;
    return 0;
}
