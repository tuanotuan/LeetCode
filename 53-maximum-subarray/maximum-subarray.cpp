class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -1e9, cur = 0, sum = 0;
        for(auto e: nums){
            sum += e;
            mx = max(mx, sum - cur);
            cur = min(cur, sum);
        }
        return mx;
    }
};