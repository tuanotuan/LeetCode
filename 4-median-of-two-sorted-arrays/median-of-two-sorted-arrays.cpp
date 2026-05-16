class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector < int > ans(n+m,0);
        int i = 0, j = 0, id = 0;
        while(i < n && j < m){
            if(nums1[i] > nums2[j]){
                ans[id++] = nums2[j++];
            }
            else ans[id++] = nums1[i++];
        }
        while(i < n)
        ans[id++] = nums1[i++];
        while(j < m)
        ans[id++] = nums2[j++];
        if((n + m) & 1)
        return ans[(n+m)/2];
        return 1.0 * ((ans[(n+m)/2]) + (ans[(n+m)/2 - 1])) / 2;
    }
};