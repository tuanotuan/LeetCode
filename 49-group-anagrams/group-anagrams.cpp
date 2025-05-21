class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
        return vector < vector < string > >();
        vector < pair < string, int > > v;
        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            v.push_back({s,i});
        }
        sort(v.begin(), v.end());
        vector < vector < int > > ans;
        vector < int > cur;
        for(int i = 0; i < n; i++){
            cur.push_back(v[i].second);
            int j = i + 1;
            while(j < n && v[j].first == v[i].first){
                cur.push_back(v[j].second);
                j++;
            }
            ans.push_back(cur);
            cur.clear();
            i = j - 1;
        }
        for(auto &e: ans){
            for(auto &v: e)
            cout << v << " ";
            cout << endl;
        }
        vector < vector < string > > res;
        for(auto &e: ans){
            vector < string > t;
            for(auto &x: e)
            t.push_back(strs[x]);
            res.push_back(t);
        }
        return res;
    }
};