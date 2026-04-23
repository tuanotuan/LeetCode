class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1 = {s1[0],s1[2]};
        string t2 = {s1[1],s1[3]};
        string t3 = {s2[0],s2[2]};
        string t4 = {s2[1],s2[3]};
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        sort(t3.begin(),t3.end());
        sort(t4.begin(),t4.end());
        if(t1 == t3 && t2 == t4) return true;
        return false;
    }
};