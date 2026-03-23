class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpp1, mpp2;
        for(char c : s){
            mpp1[c]++;
        }
        for(char c : t){
            mpp2[c]++;
        }
        return mpp1 == mpp2;
    }
};
