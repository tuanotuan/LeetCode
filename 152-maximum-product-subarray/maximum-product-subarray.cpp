class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0], mx = nums[0], ans = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < 0) swap(mn,mx);
            mx = max(mx * nums[i], nums[i]);
            mn = min(mn * nums[i], nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }
};