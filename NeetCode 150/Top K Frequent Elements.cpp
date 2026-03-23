class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto it : nums){
            hash[it]++;
        }
        vector<pair<int, int>> pairs;
        for(auto &it : hash){
            pairs.push_back({it.second, it.first});
        }
        sort(pairs.rbegin(), pairs.rend());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pairs[i].second);
        }
        return ans;
    }
};