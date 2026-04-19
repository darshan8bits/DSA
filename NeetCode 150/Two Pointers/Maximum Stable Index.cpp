class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        if(nums.size() == 0){
            if(k >= 0) return 0;
            else return -1;
        }
        
        vector<int> maxms(nums.size(), nums[0]);
        vector<int> minms(nums.size(), nums[nums.size() - 1]);

        int maxm = nums[0];
        int minm = nums[nums.size() - 1];
        
        for(int i = 1; i < nums.size(); i++){
            maxm = max(maxm, nums[i]);
            maxms[i] = maxm;
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            minm = min(minm, nums[i]);
            minms[i] = minm;
        }

        for(int i = 0; i < nums.size(); i++){
            if(maxms[i] - minms[i] <= k) return i;
        }

        return -1;
    }
};