#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int row, int col, int baserow, int basecol, vector<pair<int, int>> &vec){
    int m = grid.size();
    int n = grid[0].size();

    if(row < 0 || col < 0 || row >= m || col >= n) return;
    if(grid[row][col] == 0) return;

    grid[row][col] = 0;

    vec.push_back({row - baserow, col - basecol});

    dfs(grid, row - 1, col, baserow, basecol, vec);
    dfs(grid, row + 1, col, baserow, basecol, vec);
    dfs(grid, row, col - 1, baserow, basecol, vec);
    dfs(grid, row, col + 1, baserow, basecol, vec);
}

int numberOfDistinctIslands(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    set<vector<pair<int, int>>> st;


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                int baserow = i;
                int basecol = j;
                vector<pair<int, int>> vec;
                dfs(grid, i, j, baserow, basecol, vec);
                st.insert(vec);
            }
        }
    }

    return st.size();
}

