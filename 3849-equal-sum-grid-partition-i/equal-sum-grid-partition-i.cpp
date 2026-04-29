class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;

        // Bước 1: Tính tổng toàn bộ grid
        // Dùng long long để tránh tràn số (overflow)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
            }
        }

        // Nếu tổng lẻ thì không bao giờ chia đôi bằng nhau được
        if (totalSum % 2 != 0) return false;
        long long target = totalSum / 2;

        // Bước 2: Kiểm tra cắt ngang (Horizontal cut)
        // Duyệt qua từng hàng, cộng dồn tổng hàng vào rowSum
        long long currentRowSum = 0;
        for (int i = 0; i < m - 1; ++i) { // m-1 vì mỗi phần phải non-empty
            for (int j = 0; j < n; ++j) {
                currentRowSum += grid[i][j];
            }
            if (currentRowSum == target) return true;
        }

        // Bước 3: Kiểm tra cắt dọc (Vertical cut)
        // Duyệt qua từng cột, cộng dồn tổng cột vào colSum
        long long currentColSum = 0;
        for (int j = 0; j < n - 1; ++j) { // n-1 vì mỗi phần phải non-empty
            for (int i = 0; i < m; ++i) {
                currentColSum += grid[i][j];
            }
            if (currentColSum == target) return true;
        }

        return false;
    }
};