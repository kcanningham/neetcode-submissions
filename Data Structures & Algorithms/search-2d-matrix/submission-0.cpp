class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int low = 0; int high = r * c - 1;  //treat 2D matrix as 1D for high & low
        while(low <= high) {
            int mid = low + (high - low)/2;
            int row = mid / c;
            int col = mid % c;
            int midVal = matrix[row][col];

            if(target == midVal) return true;

            else if(target < midVal) {
                high = mid - 1;
            }

            else low = mid + 1;
        }
        return false;
    }
};
