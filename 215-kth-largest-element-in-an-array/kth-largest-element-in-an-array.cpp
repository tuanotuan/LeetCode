class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        // Chọn pivot ngẫu nhiên để tránh worst-case O(N^2) với các mảng đã có thứ tự
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        
        int pivot = nums[right];
        int p = left;
        
        // Phân vùng: Đẩy các số lớn hơn pivot về bên trái
        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        
        // Đưa pivot về đúng vị trí phân ranh giới
        swap(nums[p], nums[right]);
        return p;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int target = k - 1; // Số lớn thứ k sẽ nằm ở index k - 1
        
        while (left <= right) {
            int p = partition(nums, left, right);
            
            if (p == target) {
                return nums[p];
            } else if (p < target) {
                // Đáp án nằm bên phải pivot
                left = p + 1;
            } else {
                // Đáp án nằm bên trái pivot
                right = p - 1;
            }
        }
        
        return -1;
    }
};