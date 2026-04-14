class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector < vector < int > > ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int lastr = ans.back()[1];
            if(intervals[i][0] <= lastr)
            ans.back()[1] = max(lastr, intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};