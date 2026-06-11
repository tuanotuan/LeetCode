class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector < int > v;
        while(n > 0){
            int r = n % 2;
            v.push_back(r);
            n /= 2;
        }
        int cnt = 0;
        for(int i = 1; i < v.size(); i++)
        if(v[i] == 1 && v[i-1] == 1) cnt++;
        if(cnt == 1) return true;
        return false; 
    }
};