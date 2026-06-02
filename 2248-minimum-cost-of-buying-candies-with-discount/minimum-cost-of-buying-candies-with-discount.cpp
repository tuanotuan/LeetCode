class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int sum = 0;
        int cnt = 0, free = 0;
        for(int i = n - 1; i >= 0; i--){
            if(free){
                free = 0;
                continue;
            }
            sum += cost[i];
            cnt++;
            if(cnt == 2){
                free = 1;
                cnt = 0;
            }
        }
        return sum;
    }
};