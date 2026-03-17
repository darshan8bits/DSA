class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n){
            int dig = n % 3;
            if(dig == 2) return false;
            n /= 3;

        }
        return true;
    }
};