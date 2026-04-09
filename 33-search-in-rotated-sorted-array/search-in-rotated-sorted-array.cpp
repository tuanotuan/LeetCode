class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Dùng công thức này để tránh tràn số (overflow) nếu mảng cực lớn
            int mid = left + (right - left) / 2;

            // Tìm thấy target thì cook luôn
            if (nums[mid] == target) {
                return mid;
            }

            // XÉT TRƯỜNG HỢP 1: Nửa TRÁI đã được sắp xếp chuẩn
            if (nums[left] <= nums[mid]) {
                // Kiểm tra xem target có chui lọt vào cái khe của nửa trái này không?
                if (nums[left] <= target && target < nums[mid]) {
                    // Nếu có, vứt nửa phải đi
                    right = mid - 1;
                } else {
                    // Nếu không, vứt nửa trái đi
                    left = mid + 1;
                }
            } 
            // XÉT TRƯỜNG HỢP 2: Nửa PHẢI đã được sắp xếp chuẩn
            else {
                // Kiểm tra xem target có chui lọt vào cái khe của nửa phải này không?
                if (nums[mid] < target && target <= nums[right]) {
                    // Nếu có, vứt nửa trái đi
                    left = mid + 1;
                } else {
                    // Nếu không, vứt nửa phải đi
                    right = mid - 1;
                }
            }
        }

        // Quét cạn kiệt mảng mà không thấy
        return -1;
    }
};