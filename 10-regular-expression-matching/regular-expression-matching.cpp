class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // DP Table: Khởi tạo toàn bộ là false
        // dp[i][j] mang ý nghĩa: s(0..i-1) có khớp với p(0..j-1) không
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: Hai chuỗi rỗng luôn khớp với nhau
        dp[0][0] = true;
        
        // Base case: Chuỗi s rỗng, nhưng mẫu p chứa các cụm kiểu "a*b*c*"
        // Các cụm này có thể mang nghĩa "xuất hiện 0 lần", nên nó vẫn có thể khớp chuỗi rỗng.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Bắt đầu điền ma trận DP
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                
                // Trường hợp 1: Ký tự bình thường hoặc dấu '.'
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Trường hợp 2: Đụng độ con quái vật '*'
                else if (p[j - 1] == '*') {
                    // Nhánh 1: Coi cụm "X*" xuất hiện 0 lần -> Lùi pattern lại 2 ký tự
                    dp[i][j] = dp[i][j - 2];
                    
                    // Nhánh 2: Nếu ký tự trước '*' khớp với s hiện tại (hoặc là dấu '.')
                    // -> Coi cụm "X*" xuất hiện 1 hoặc nhiều lần -> Giữ nguyên pattern, lùi string lại 1
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};