class Solution {
public:
    using ll = long long;
    struct SegmentTree{
        int n;
        const ll INF = -1e18;
        vector < ll > st;
        SegmentTree(vector < ll > &a){
            n = a.size();
            st.assign(4 * n, INF);
            build(1,0,n-1,a);
        }
        void build(int id, int l, int r, vector < ll > &a){
            if(l == r){
                st[id] = a[l];
                return;
            }
            int mid = (l+r)/2;
            build(id*2,l,mid,a);
            build(id*2+1,mid+1,r,a);
            st[id] = max(st[id*2],st[id*2+1]);
        }
        ll get(int id, int l, int r, int u, int v){
            if(l > v || r < u) return INF;
            if(u <= l && r <= v) return st[id];
            int mid = (l+r)/2;
            return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
        }
    };
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        const ll INF = -1e18;
        vector < vector < ll > > dp(m + 1, vector < ll > (n + 1, INF));
        for(int i = 0; i <= n; i++)
        dp[0][i] = 0;
        vector < ll > pre(n+1,0);
        for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1] + nums[i-1];
        ll ans = INF;
        for(int c = 1; c <= m; c++){
            vector<ll> val(n + 1, INF);

            for(int j = 0; j <= n; j++) {
                if(dp[c - 1][j] != INF) {
                    val[j] = dp[c - 1][j] - pre[j];
                }
            }

            SegmentTree seg(val);

            for(int i = 1; i <= n; i++) {
                dp[c][i] = dp[c][i - 1];

                int L = i - r;
                int R = i - l;

                ll best = seg.get(1,0,n,L, R);

                if(best != INF) {
                    dp[c][i] = max(dp[c][i], pre[i] + best);
                }

                ans = max(ans, dp[c][i]);
            }
        }
        return ans;
    }
};