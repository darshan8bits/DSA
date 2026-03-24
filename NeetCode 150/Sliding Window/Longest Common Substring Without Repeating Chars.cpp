class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxlen = 0;
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            while(st.find(s[i]) != st.end()){
                st.erase(s[j]);
                j++;
            }
            maxlen = max(maxlen, i - j + 1);
            st.insert(s[i]);
        }
        return maxlen;
    }
};
