static const int MOD = 1000000007;

class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = (int)conversions.size() + 1;
        // 1) Xây đồ thị có hướng (cục bộ, không cần clear lại)
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : conversions) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
        }

        // 2) BFS từ đỉnh 0
        vector<long long> ans(n, 0);
        queue<int> q;
        ans[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                ans[v] = (ans[u] * w) % MOD;
                q.push(v);
            }
        }

        // 3) Chuyển sang vector<int> kết quả
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = (int)ans[i];
        }
        return res;
    }
};