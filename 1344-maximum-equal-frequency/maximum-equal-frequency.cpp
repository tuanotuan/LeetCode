class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector < int > a(nums);
        int n = a.size();
        vector < int > cnt(1e5+5,0);
        vector < int > fre(1e5+5,0);
        int mx = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int &x = cnt[a[i]];
            if(x > 0)
            fre[x]--;
            x++;
            fre[x]++;
            mx = max(mx, x);
            if(mx == 1)
            ans = max(ans, i + 1);
            else if(fre[mx] == 1 && fre[mx] * mx + fre[mx - 1] * (mx - 1) == i + 1)
            ans = max(ans, i + 1);
            else if(fre[1] == 1 && fre[mx] * mx + 1 == i + 1)
            ans = max(ans, i + 1);
        }
        return ans;
    }
};