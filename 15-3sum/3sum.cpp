class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        set < vector < int > > res;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int l = j + 1, r = n - 1;
                int ans = -1, need = -(nums[i] + nums[j]);
                while(l <= r){
                    int mid = (l+r)/2;
                    if(nums[mid] == need){
                        ans = nums[mid];
                        break;
                    }
                    else if(nums[mid] > need)
                    r = mid - 1;
                    else l = mid + 1;
                }
                if(ans != -1)
                res.insert({nums[i],nums[j],ans});
            }
        }
        vector < vector < int > > hi;
        for(auto &e: res)
        hi.push_back(e);
        return hi;
    }
};