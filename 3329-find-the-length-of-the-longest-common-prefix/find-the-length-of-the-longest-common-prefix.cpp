class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map < pair < int, int >, bool > ump1,ump2;
        for(auto x: arr1){
            string s = to_string(x);
            int t = 0;
            for(int i = 0; i < s.size(); i++){
                t = t * 10 + (s[i] - '0');
                ump1[make_pair(t,i+1)] = true;
            }
        }

        for(auto x: arr2){
            string s = to_string(x);
            int t = 0;
            for(int i = 0; i < s.size(); i++){
                t = t * 10 + (s[i] - '0');
                ump2[make_pair(t,i+1)] = true;
            }
        }
        int ans = 0;
        for(auto x: ump1){
            if(ump2.find(x.first) != ump2.end())
            ans = max(ans, x.first.second);
        }
        return ans;
    }
};