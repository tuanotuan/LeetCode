const int N = 100005;
int par[N],tplt,sz[N];
int acs(int u){
    if(u == par[u]) return u;
    return par[u] = acs(par[u]);
}
void join(int u, int v){
    int x = acs(u);
    int y = acs(v);
    if(sz[x] < sz[y])
    swap(x,y);
    if(x != y){
        par[y] = x;
        sz[x] += sz[y];
        tplt--;
    }
}
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        tplt = n;
        for(int i = 0; i < n; i++)
        par[i] = i, sz[i] = 1;
        bool ck = true;
        int pre = 0;
        for(int i = 0; i < n; i++){
            if(tplt == 1)
            break;
            int l = pre + 1, r = n - 1, ans = -1;
            while(l <= r){
                int mid = (l+r) / 2;
                if(nums[mid] - nums[i] <= maxDiff){
                    ans = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(ans == -1)
            continue;
            for(int j = pre + 1; j <= ans; j++)
            if(tplt == 1){
                ck = false;
                break;
            }
            else
            join(i,j);
            if(!ck)
            break;
            pre = ans;
        }
        int m = (int)queries.size();
        vector < bool > ans(m);
        int cnt = 0;
        for(auto &e: queries){
            int u = e[0];
            int v = e[1];
            if(acs(u) == acs(v))
            ans[cnt++] = true;
            else ans[cnt++] = false;
        }
        return ans;
    }
};