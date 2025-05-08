bool check(string st, int l, int r){
    string ts = "";
    for(int i = l; i <= r; i++)
    ts += st[i];
    for(int i = 0; i < (r - l + 1) / 2; i++)
    if(ts[i] != ts[r - l - i])
    return false;
    return true;
}
bool ck(string st){
    for(int i = 0; i < (int)st.size(); i++)
    if(st[i] != st[(int)st.size() - i - 1])
    return false;
    return true;
}
class Solution {
public:
    int longestPalindrome(string s, string t) {
        int n = (int)s.size();
        int m = (int)t.size();
        s = " " + s;
        t = " " + t;
        int ans = 1;
        for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
        if(check(s,i,j))
        ans = max(ans, j - i + 1);
        for(int i = 1; i <= m; i++)
        for(int j = i; j <= m; j++)
        if(check(t,i,j))
        ans = max(ans, j - i + 1);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                for(int k = 1; k <= m; k++){
                    for(int o = k; o <= m; o++){
                        string cc = "";
                        for(int p = i; p <= j; p++)
                        cc += s[p];
                        for(int p = k; p <= o; p++)
                        cc += t[p];
                        if(ck(cc))
                        ans = max(ans, j - i + 1 + o - k + 1);
                    }
                }
            }
        }
        return ans;
    }
};