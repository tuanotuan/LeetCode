class Solution {
public:
    bool check(string &s, int k){
        unordered_map < char, int > ump;
        int distinct = 0, mx = 0;
        for(int i = 0; i < k; i++){
            ump[s[i]]++;
            if(ump[s[i]] == 1) distinct++;
        }
        mx = max(mx, distinct);
        for(int i = k; i < s.size(); i++){
            ump[s[i-k]]--;
            if(ump[s[i-k]] == 0) distinct--;
            ump[s[i]]++;
            if(ump[s[i]] == 1) distinct++;
            mx = max(mx, distinct);
        }
        return mx == k;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 1, r = n, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(s,mid)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};