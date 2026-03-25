class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector < int > ans(n + m);
	int id = 0, i = 0, j = 0;
	while(i < m && j < n){
		if(nums1[i] < nums2[j]){
			ans[id++] = nums1[i++];
		}
		else{
			ans[id++] = nums2[j++];
		}
	}
	while(i < m)
		ans[id++] = nums1[i++];
	while(j < n)
		ans[id++] = nums2[j++];
	nums1.swap(ans);
    }
};