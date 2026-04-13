class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = -1;
        int l = 0, r = matrix.size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[mid][0] <= target){
                R = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        //cout << R << endl;
        if(R == -1) return false;
        l =  0, r = matrix[0].size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(matrix[R][mid] == target) return true;
            if(matrix[R][mid] > target)
            r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};