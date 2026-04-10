class Solution {
public:
    bool isPerfectSquare(int num) {
        // Trường hợp đặc biệt
        if (num < 1) return false;
        if (num == 1) return true;

        // Khởi tạo phạm vi tìm kiếm nhị phân
        long left = 1;
        long right = num;

        while (left <= right) {
            // Tránh tràn số khi cộng left + right
            long mid = left + (right - left) / 2;
            long square = mid * mid;

            if (square == num) {
                // Tìm thấy số thỏa mãn mid * mid = num
                return true;
            } else if (square < num) {
                // Bình phương nhỏ hơn num, cần tìm ở nửa bên phải
                left = mid + 1;
            } else {
                // Bình phương lớn hơn num, cần tìm ở nửa bên trái
                right = mid - 1;
            }
        }

        // Không tìm thấy số nguyên nào có bình phương bằng num
        return false;
    }
};