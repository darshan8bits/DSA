class Solution {
public:
    int rob2(vector<int>& houses) {
        int n = houses.size();
        vector<int> dp(n, 0);
        dp[0] = houses[0];
    
        for(int i = 1; i < n; i++){ 
            int pick = houses[i];
            if(i > 1) pick += dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& houses) {
    int n = houses.size();

    if(n == 1) return houses[0];

    vector<int> a1 = houses;
    vector<int> a2;

    for(int i = 1; i < n; i++){
        a2.push_back(houses[i]);
    }

    a1.pop_back();

    int ans1 = rob2(a1);
    int ans2 = rob2(a2);

    return max(ans1, ans2);
}
};