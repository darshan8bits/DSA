class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> flatten;
        for(auto &row : grid){
            for(auto &i : row){
                flatten.push_back(i);
            }
        }
        // product except self;
        int s = n * m;
        vector<long long> left(s, 1);
        vector<long long> right(s, 1);

        for(int i = 1; i < s; i++){
            left[i] = (left[i - 1] * flatten[i - 1]) % 12345;
        }
        for(int i = s - 2; i >= 0; i--){
            right[i] = (right[i + 1] * flatten[i + 1]) % 12345;
        }
        long long p = 1;
        for(int i = 0; i < s; i++){

            p = (left[i] * right[i]) % 12345;
            flatten[i] = p;

        }

        //copy back
        
        for(int i = 0; i < s; i++){
            int r = i / n;
            int c = i % n;
            grid[r][c] = flatten[i];
        }

        return grid;
    }
};