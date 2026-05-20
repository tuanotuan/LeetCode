class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector < int > f(n,1e9);
        f[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = min(n - 1, i + nums[i]); j >= i; j--){
                if(f[j] != 1e9) break;
                f[j] = min(f[j], f[i] + 1);
            }
        }
        return f[n-1];
    }
};