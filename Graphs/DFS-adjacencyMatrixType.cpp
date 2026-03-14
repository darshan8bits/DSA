class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, unordered_map<int, bool> &visited){
        visited[city] = true;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[city][j] == 1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, bool> visited;
        int n = isConnected.size();
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};