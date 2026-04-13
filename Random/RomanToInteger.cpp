class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int i = 0;
        int ans = 0;

        while(i < s.size()){
            if(s.size() - i >= 1 && roman[s[i + 1]] > roman[s[i]]){
                int n = roman[s[i + 1]] - roman[s[i]];
                ans += n;
                i+=2;
            }else{
                ans += roman[s[i]];
                i++;
            }
        }
        return ans;
    }
};