class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = (int)nums.size();
        int mx = nums[0];
        vector < int > v;
        v.push_back(mx);
        for(int i = 1; i < n; i++)
        if(nums[i] >= mx){
            mx = nums[i];
            v.push_back(mx);
        }
        return (int)v.size();
    }
};