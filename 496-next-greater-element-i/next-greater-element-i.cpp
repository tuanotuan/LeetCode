class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector < int > ans(10001,-1);
        for(int i = 0; i < m; i++)
        for(int j = m - 1; j > i; j--)
        if(nums2[j] > nums2[i])
        ans[nums2[i]] = nums2[j];
        vector < int > cc(n,-1);
        for(int i = 0; i < n; i++)
        cc[i] = ans[nums1[i]];
        return cc;
    }
};