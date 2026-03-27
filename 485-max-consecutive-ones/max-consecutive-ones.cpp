class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, cur = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(i == 0){
                if(nums[i] == 1){
                    cur = 1;
                    mx = max(mx, cur);
                }
            }
            else{
                if(nums[i] == 1){
                    cur++;
                    mx = max(mx, cur);
                }
                else cur = 0;
            }
        }
        return mx;
    }
};