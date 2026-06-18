class Solution {
public:
    int getLength(vector<int>& nums) {
        vector < int > a(nums);
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i < n; i++){
            map < int, int > cnt,fre;
            for(int j = i; j < n; j++){
                int x = cnt[a[j]];
                if(x > 0){
                    fre[x]--;
                    if(fre[x] == 0)
                    fre.erase(x);
                }
                cnt[a[j]]++;
                fre[cnt[a[j]]]++;
                int dis = cnt.size();
                if(cnt.size() == 1)
                ans = max(ans, j - i + 1);
                else if(fre.size() == 2){
                    auto itr = fre.begin();
                    int n1 = itr->first;
                    itr++;
                    int n2 = itr->first;
                    if(n1 == 2 * n2 || 2 * n1 == n2)
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};