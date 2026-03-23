class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 1;
        for(int num : st){
            if(st.find(num - 1) != st.end()) continue;
            int count = 1; 
            int curr = num;
            while(st.find(curr + 1) != st.end()){
                curr++;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};
