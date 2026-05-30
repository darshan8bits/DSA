class Solution {
public:
    bool isValid(string &current){
        stack<char> st;

    for(char c : current){
        if(c == '('){
            st.push('(');
        }
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }

    return st.empty();
    }

    void solve(vector<string> &ans, string &current, int n){
        if(current.size() == 2 * n){
            if(isValid(current)){
                ans.push_back(current);
            }
            return;
        }
        current.push_back('(');
        solve(ans, current, n);
        current.pop_back();
        current.push_back(')');
        solve(ans, current, n);
        current.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        solve(ans, current, n);
        return ans;
    }
};