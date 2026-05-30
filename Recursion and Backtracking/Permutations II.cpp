class Solution {
public:
    void solve(vector<int>& nums, vector<int>& taken, set<vector<int>>& ans, vector<int> &current){
        int n = nums.size();
        if(current.size() == n){
            ans.insert(current);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!taken[i]){
                taken[i] = 1;
                current.push_back(nums[i]);
                solve(nums, taken, ans, current);
                current.pop_back();
                taken[i] = 0;
            }
        }


                
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> current;
        vector<int> taken(nums.size(), 0);
        solve(nums, taken, st, current);
        for(auto &it : st){
            ans.push_back(it);
        }
        return ans;
    }
};