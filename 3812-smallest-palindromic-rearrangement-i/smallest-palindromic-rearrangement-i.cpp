class Solution {
public:
    string smallestPalindrome(string s) {
        string ans = "";
        int cnt[26];
        for(auto e: s)
        cnt[e-'a']++;
        for(char c = 'a'; c <= 'z'; c++){
            int x = cnt[c-'a'];
            for(int j = 1; j <= x / 2; j++)
            ans += c;
        }
        for(char c = 'a'; c <= 'z'; c++)
        if(cnt[c-'a'] & 1){
            ans += c;
            break;
        }
        for(char c = 'z'; c >= 'a'; c--){
            int x = cnt[c-'a'];
            for(int j = 1; j <= x / 2; j++)
            ans += c;
        }
        return  ans;
    }
};