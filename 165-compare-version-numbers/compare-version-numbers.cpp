class Solution {
public:
    vector < string > parse(string s){
        stringstream ss(s);
        string token;
        vector < string > tokens;
        while(getline(ss,token,'.')){
            if(!token.empty())
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector < string > v1 = parse(version1);
        vector < string > v2 = parse(version2);
        while(v1.size() < v2.size())
        v1.push_back("0");
        while(v1.size() > v2.size())
        v2.push_back("0");
        for(int i = 0; i < v1.size(); i++)
        if(stoi(v1[i]) < stoi(v2[i])) return -1;
        else if(stoi(v1[i]) > stoi(v2[i])) return 1;
        return 0;
    }
};