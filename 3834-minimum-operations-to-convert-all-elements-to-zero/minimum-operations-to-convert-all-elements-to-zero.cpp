class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        vector < int > v;
        for(auto &x: nums){
            while(v.size() && v.back() > x){
                v.pop_back();
                ans++;
            }
            if(x && (v.size() == 0 || v.back() < x))
            v.push_back(x);
        }
        return ans + v.size();
    }
};