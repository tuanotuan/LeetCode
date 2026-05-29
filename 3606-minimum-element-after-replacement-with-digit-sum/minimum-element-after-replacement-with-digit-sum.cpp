class Solution {
public:
    int calc(int x){
        int sum = 0;
        while(x > 0){
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        nums[i] = calc(nums[i]);
        return *min_element(nums.begin(), nums.end());
    }
};