class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &e: nums)
        e = e * e;
        sort(nums.begin(), nums.end());
        return nums;
    }
};