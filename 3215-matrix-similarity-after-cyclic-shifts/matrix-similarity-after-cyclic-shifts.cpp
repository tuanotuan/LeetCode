class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();    // Số hàng
        int m = mat[0].size(); // Số cột
        
        // Tối ưu: Nếu k là bội của m thì dịch kiểu gì cũng về chỗ cũ
        k %= m;
        if (k == 0) return true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Dù là hàng chẵn (dịch trái) hay hàng lẻ (dịch phải),
                // điều kiện để giống hệt ban đầu là mat[i][j] == mat[i][(j + k) % m]
                if (mat[i][j] != mat[i][(j + k) % m]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};