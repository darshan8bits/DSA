class Solution {
public:
    bool isOp(string a){
        return (a == "+" || a == "-" || a == "*" || a == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &i : tokens){
            if(!isOp(i)){
                int n = stoi(i);
                st.push(n);
            }else{
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(i == "+") st.push(first + second);
                if(i == "-") st.push(second - first);
                if(i == "*") st.push(first * second);
                if(i == "/") st.push(second / first);
            }

        }
        return st.top();
    }
};
