class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        maxLeft[0] = 0;
        maxRight[height.size() - 1] = 0;
        int leftmax = 0;
        int rightmax = 0;
        for(int i = 1; i < height.size(); i++){
            leftmax = max(leftmax, height[i - 1]);
            maxLeft[i] = leftmax;
        }
        for(int i = height.size() - 2; i >= 0; i--){
            rightmax = max(rightmax, height[i + 1]);
            maxRight[i] = rightmax;
        }
        int total = 0;
        for(int i = 0; i < height.size(); i++){
            int m = min(maxRight[i], maxLeft[i]);
            int add = (m - height[i] < 0) ? 0 : m - height[i];
            total += add; 
        }
        return total;
    }
};
