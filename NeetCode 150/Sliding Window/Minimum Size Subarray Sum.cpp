class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minm = INT_MAX;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                minm = min(minm, i - j + 1);
                sum -= nums[j];
                j++;
                
            }
            
        }
        minm = (minm == INT_MAX) ? 0 : minm;
        return minm;
    }
};