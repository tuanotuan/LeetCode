class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector < int > C(n,0);
        for(int i = 0; i < n; i++){
            vector < int > cnta(n+1,0),cntb(n+1,0);
            for(int j = 0; j <= i; j++){
            cnta[A[j]]++;
            cntb[B[j]]++;
            }
            int cnt = 0;
            for(int j = 1; j <= n; j++)
            if(cnta[j] && cntb[j]) cnt++;
            C[i] = cnt;
        }
        return C;
    }
};