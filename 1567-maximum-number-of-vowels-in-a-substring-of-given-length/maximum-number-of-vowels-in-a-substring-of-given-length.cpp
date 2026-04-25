class Solution {
public:
    bool ck(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int ans = 0, cur = 0;
        int n = s.size();
        for(int i = 0; i < k; i++)
        if(ck(s[i])) cur++;
        ans = cur;
        for(int i = k; i < n; i++){
            if(ck(s[i])) cur++;
            if(ck(s[i-k])) cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};