class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        vector<int> leftMin(n), rightMin(n);

        // Build leftMin
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        // Build rightMin
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        int ans = INT_MAX;

        for (int j = 1; j < n - 1; j++) {
            int left = leftMin[j - 1];
            int right = rightMin[j + 1];

            if (left < nums[j] && right < nums[j]) {
                ans = min(ans, left + nums[j] + right);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};