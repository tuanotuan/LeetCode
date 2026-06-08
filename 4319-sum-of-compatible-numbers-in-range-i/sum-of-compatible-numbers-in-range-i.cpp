class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        vector < int > ans;
        for(int x = max(1,n - k); x <= n + k; x++)
        if((n & x) == 0) ans.push_back(x);
        return accumulate(ans.begin(), ans.end(), 0);
    }
};