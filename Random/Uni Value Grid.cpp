class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> res;
        for(auto &it : grid){               
            for(auto &val : it){
                res.push_back(val);
            }
        }
        for(int i = 0; i < res.size(); i++){
            if(res[i] % x != res[0] % x) return -1;
        }
        sort(res.begin(), res.end());
        int median = res[res.size() / 2];
        int operations = 0;
        for(int i = 0; i < res.size(); i++){
            operations += abs(median - res[i]) / x;
        }
        return operations;
    }
};