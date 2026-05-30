class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &current, set<vector<int>> &st){
        int n = nums.size();

        if(index == n){
            st.insert(current);
            return;
        }

        // pick
        current.push_back(nums[index]);
        solve(nums, index + 1, current, st);
        current.pop_back();
        solve(nums, index + 1, current, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> current = {};
        vector<vector<int>> ans;
        solve(nums, 0, current, st);
        for(auto &it : st){
            ans.push_back(it);
        }
        return ans;
    }
};