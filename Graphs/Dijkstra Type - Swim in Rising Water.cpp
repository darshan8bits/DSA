class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            if(x == n - 1 && y == n - 1) return time;
            pq.pop();

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                    int newtime = max(grid[nx][ny], time);
                    if(newtime < dist[nx][ny]){
                        dist[nx][ny] = newtime;
                        pq.push({newtime, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};