class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Bước 1: Tìm điểm gãy (số đầu tiên nhỏ hơn số bên phải nó)
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Nếu tìm thấy điểm gãy (không phải mảng đang giảm dần toàn bộ)
        if (i >= 0) {
            int j = n - 1;
            // Bước 2: Tìm số đầu tiên từ phải sang trái lớn hơn nums[i]
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Bước 3: Đổi chỗ
            swap(nums[i], nums[j]);
        }

        // Bước 4: Lật ngược phần đuôi (từ i + 1 đến hết mảng)
        // Nếu i = -1 (mảng [3, 2, 1]), nó sẽ lật từ 0 đến hết mảng thành [1, 2, 3]
        reverse(nums.begin() + i + 1, nums.end());
    }
};