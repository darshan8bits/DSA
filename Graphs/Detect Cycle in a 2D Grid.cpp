bool dfs(vector<vector<char>> &grid, int curri, int currj, int parenti, int parentj, vector<vector<int>> &vis, char c){
    int m = grid.size();
    int n = grid[0].size();

    vis[curri][currj] = 1;

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    for(int i = 0; i < 4; i++){
        int nx = curri + dx[i];
        int ny = currj + dy[i];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        
        if(grid[nx][ny] != c) continue;

        if(!vis[nx][ny]){
            if(dfs(grid, nx, ny, curri, currj, vis, c)) return true;
        }else{
            if(nx != parenti || ny != parentj) return true;
        }
    }

    return false;
}

bool detectCycleInGrid(vector<vector<char>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j]){
                if(dfs(grid, i, j, -1, -1, vis, grid[i][j])) return true;
            }
        }
    }
    return false;
}