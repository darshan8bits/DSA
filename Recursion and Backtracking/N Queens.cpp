class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board){
        int i = row, j = col;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        j = col;
        while(j >= 0){
            if(board[row][j] == 'Q') return false;
            j--;
        }
        i = row, j = col;
        while(i < board.size() && j >= 0){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isSafe(i, col, board)){
                board[i][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};