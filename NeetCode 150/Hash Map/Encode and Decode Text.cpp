class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs.size(); i++){
            int size = strs[i].size();
            ans += to_string(size);
            ans.push_back('#');
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;

    while (i < s.size()) {
        int j = i;

        // Step 1: find '#'
        while (s[j] != '#') {
            j++;
        }

        // Step 2: get length
        int len = stoi(s.substr(i, j - i));

        // Step 3: extract string
        string word = s.substr(j + 1, len);
        ans.push_back(word);

        // Step 4: move pointer
        i = j + 1 + len;
    }

    return ans;
}
};
