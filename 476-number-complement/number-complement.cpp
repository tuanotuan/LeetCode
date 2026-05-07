class Solution {
public:
    int findComplement(int num) {
        // Nếu num = 0, complement là 1 (dù ràng buộc num >= 1)
        if (num == 0) return 1;

        unsigned int mask = 0;
        int temp = num;

        // Tạo mặt nạ gồm toàn bit 1 có độ dài bằng num
        // Ví dụ: num = 5 (101) -> mask sẽ thành 111 (7)
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XOR num với mask để đảo toàn bộ bit có nghĩa
        return num ^ mask;
    }
};