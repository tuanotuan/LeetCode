class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector < vector < long long > > sum(n, vector < long long > (m,0));
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0){
                sum[i][j] = grid[i][j];
                continue;
            }
            else if(i == 0)
            sum[i][j] = sum[i][j-1] + grid[i][j];
            else if(j == 0)
            sum[i][j] = sum[i-1][j] + grid[i][j];
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
        }
        for(int i = 0; i < n - 1; i++)
        if(2 * sum[i][m-1] == sum[n-1][m-1]) return true;
        for(int j = 0; j < m - 1; j++)
        if(2 * sum[n-1][j] == sum[n-1][m-1]) return true;
        return false;
    }
};