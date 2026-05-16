class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector < vector < bool > > f(n, vector < bool > (n,false));
        for(int i = 0; i < n; i++)
        f[i][i] = true;
        for(int i = 1; i < n; i++)
        if(s[i] == s[i-1])
        f[i-1][i] = true;
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++)
            if(f[i+1][i+len-2] && s[i] == s[i+len-1])
            f[i][i+len-1] = true;
        }
        int mx = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        if(f[i][j]) mx = max(mx, j - i + 1);
        string ans = "";
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        if(f[i][j] && j - i + 1 == mx){
            for(int k = i; k <= j; k++)
            ans += s[k];
            return ans;
        }
        return ans;
    }
};