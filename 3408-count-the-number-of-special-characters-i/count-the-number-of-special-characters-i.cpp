class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector < int > cnt(256,0);
        for(auto c: word)
        cnt[c]++;
        int ans = 0;
        for(char c = 'a', C = 'A'; c <= 'z'; c++, C++)
        if(cnt[c] && cnt[C]) ans++;
        return ans;
    }
};