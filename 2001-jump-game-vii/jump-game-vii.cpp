class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> dp(n, 0);
        vector<int> pref(n, 0);

        dp[0] = 1;
        pref[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                int l = i - maxJump;
                int r = i - minJump;

                l = max(l, 0);

                if (r >= 0) {
                    int cnt = pref[r];
                    if (l > 0) cnt -= pref[l - 1];

                    if (cnt > 0) {
                        dp[i] = 1;
                    }
                }
            }

            pref[i] = pref[i - 1] + dp[i];
        }

        return dp[n - 1];
    }
};