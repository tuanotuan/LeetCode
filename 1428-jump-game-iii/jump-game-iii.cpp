class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector < bool > f(n,false);
        vector < bool > vis(n,false);
        f[start] = vis[start] = true;
        queue < int > q;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int v1 = u + arr[u];
            int v2 = u - arr[u];
            if(v1 < n && !vis[v1]){
                f[v1] = vis[v1] = true;
                q.push(v1);
            }
            if(v2 >= 0 && !vis[v2]){
                f[v2] = vis[v2] = true;
                q.push(v2);
            }
        }
        for(int i = 0; i < n; i++)
        if(arr[i] == 0 && f[i]) return true;
        return false;
    }
};