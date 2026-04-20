class Solution {
public:
    void solve(vector<vector<int>>& land, int row, int col, int& maxRow, int& maxCol){
        int m = land.size();
        int n = land[0].size();

        if(row >= m || col >= n) return;

        if(land[row][col] == 0) return;

        land[row][col] = 0;
        maxRow = max(maxRow, row);
        maxCol = max(maxCol, col);

        solve(land, row + 1, col, maxRow, maxCol);
        solve(land, row, col + 1, maxRow, maxCol);
        
    } 
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] == 1){
                    int maxRow = i, maxCol = j;
                    solve(land, i, j, maxRow, maxCol);
                    ans.push_back({i, j, maxRow, maxCol});
                }
            }
        }
        return ans;
    }
}; 