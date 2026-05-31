#include <bits/stdc++.h>
using namespace std;

int minSteps(vector<int> heights){
    int n = heights.size();
    vector<int> steps(n, 0);
    steps[1] = abs(heights[1] - heights[0]);
    for(int i = 2; i < n; i++){
        int a = abs(heights[i] - heights[i - 1]) + steps[i - 1];
        int b = abs(heights[i] - heights[i - 2]) + steps[i - 2];
        steps[i] = min(a, b);
        
    }
    return steps[n - 1];

}

int main(){
    vector<int> heights = {10, 20, 30, 10};
    cout << minSteps(heights);
    return 0;
}