class Solution {
public:
    void backtrack(int id, int cnt, int k, int n, string cur, vector < string > &ans){
        if(id >= n){
            int cost = 0;
            for(int i = 1; i < n; i++)
            if(cur[i] == '1' && cur[i-1] == '1') return;
            for(int i = 0; i < n; i++)
            if(cur[i] == '1') cost += i;
            if(cost <= k) ans.push_back(cur);
            return;
        }
        cur += '0';
        backtrack(id+1,cnt,k,n,cur,ans);
        cur.pop_back();
        cur += '1';
        backtrack(id+1,cnt+1,k,n,cur,ans);
    }
    vector<string> generateValidStrings(int n, int k) {
        vector < string > ans;
        backtrack(0,0,k,n,"",ans);
        return ans;
    }
};