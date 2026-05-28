class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt(256, 0);
        string s = word;
        for (auto c : word)
            cnt[c]++;
        int ans = 0;
        vector<int> idC(26, -1);
        int n = word.size();
        for (int i = n - 1; i >= 0; i--)
            if (s[i] >= 'A' && s[i] <= 'Z')
                idC[s[i] - 'A'] = i;
        vector<int> idc(26, -1);
        for (int i = 0; i < n; i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                idc[s[i] - 'a'] = i;
        for (char c = 'a', C = 'A'; c <= 'z'; c++, C++){
            if(cnt[c] && cnt[C] && idC[C-'A'] > idc[c-'a']) ans++;
        }
        return ans;
    }
};