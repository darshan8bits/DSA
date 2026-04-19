class Solution {
public:
    bool isMatch(char a, char b){
        if (a == '{' && b == '}') return true;
        if (a == '[' && b == ']') return true;
        if (a == '(' && b == ')') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char c = st.top();
                if(!isMatch(c, s[i])) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
