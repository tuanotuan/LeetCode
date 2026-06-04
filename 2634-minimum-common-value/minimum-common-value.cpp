class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map < int, int > ump1,ump2;
        for(auto x: nums1) ump1[x]++;
        for(auto x: nums2) ump2[x]++;
        for(auto x: nums1)
        if(ump2.find(x) != ump2.end()) return x;
        return -1;
    }
};