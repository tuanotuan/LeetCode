const int MOD = 1000000007;
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = (int)conversions.size() + 1;
        vector < long long > ans(n);
        vector < pair < int, int > > adj[100005];
        for (auto &e : conversions) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
        }
        ans.resize(n,0);
        ans[0] = 1;
        queue < int > q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto [v,w]: adj[u]){
            ans[v]  = (ans[u] * w) % MOD;
            q.push(v);
            }
        }
        vector < int > res(n);
        for(int i = 0; i < n; i++)
        res[i] = ans[i];
        return res;
    }
};
