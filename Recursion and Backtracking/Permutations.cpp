class Solution {
public:
    void solve(vector<int>& nums, vector<int>& taken, vector<vector<int>>& ans, vector<int> &current){
        int n = nums.size();
        if(current.size() == n){
            ans.push_back(current);
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> taken(n, 0);
        vector<vector<int>> ans;
        vector<int> current = {};
        solve(nums, taken, ans, current); 
        return ans;
    }
};