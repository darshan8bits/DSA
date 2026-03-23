class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int time = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty() && fresh > 0){
            time++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();

                vector<int> dx = {1, -1, 0, 0};
                vector<int> dy = {0, 0, 1, -1};

                int x = front.first;
                int y = front.second;

                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            
            
        }
        if(fresh > 0) return -1;
        return time;
    }
};
