#define all(a) (a).begin(),(a).end()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k == 0){
            unordered_map < int, int > ump;
            for(auto e: nums) ump[e]++;
            int ans = 0;
            uniquev(nums);
            for(auto e: nums) if(ump[e] >= 2) ans++;
            return ans;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector < int > a;
        a.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        if(nums[i] != nums[i-1])
        a.push_back(nums[i]);
        n = a.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int id = lower_bound(a.begin() + i + 1, a.end(), a[i] + k) - a.begin();
            if(id < n && a[id] - a[i] == k) ans++;
        }
        return ans;
    }
};