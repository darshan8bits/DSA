#include <bits/stdc++.h>
using namespace std;

void generateSubsequence(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int> &arr){
    if(index >= nums.size()){
        ans.push_back(arr);
        return;
    }
    arr.push_back(nums[index]);
    generateSubsequence(nums, ans, index + 1, arr);
    arr.pop_back();
    generateSubsequence(nums, ans, index + 1, arr);
}

int main(){
    vector<int> nums = {3, 1, 2};
    vector<vector<int>> ans;
    vector<int> arr = {};
    generateSubsequence(nums, ans, 0, arr);
    for(int i = 0; i < ans.size(); i++){
        if(ans[i].empty()){ 
            cout << "NULL" << endl;
            continue;
        }
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
