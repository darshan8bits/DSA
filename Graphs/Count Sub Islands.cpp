class Solution {
public:
    void solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, bool& check){
        int m = grid1.size();
        int n = grid1[0].size();
        if(row >= m || row < 0 || col >= n || col < 0) return;
        if(grid2[row][col] == 0) return;

        if(grid1[row][col] == 0){
            check = false;
            
        }

        grid2[row][col] = 0;
        solve(grid1, grid2, row + 1, col, check);
        solve(grid1, grid2, row, col + 1, check);
        solve(grid1, grid2, row - 1, col, check);
        solve(grid1, grid2, row, col - 1, check);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int c = 0;
        for(int i = 0; i < grid2.size(); i++){
            for(int j = 0; j < grid2[0].size(); j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 1){
                    bool check = true;
                    solve(grid1, grid2, i, j, check);
                    if(check) c++;
                }
            }
        }
        return c;
    }
};