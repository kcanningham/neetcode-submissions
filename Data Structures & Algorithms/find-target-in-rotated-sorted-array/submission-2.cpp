class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; int r = n - 1;
         while(l < r) {
            int mid = l + (r - l)/2;
            if(nums[mid] < nums[r]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        int pivot = l;
        int ans = binarySearch(nums, target, 0, pivot - 1);
        if(ans != -1) return ans;
        return binarySearch(nums, target, pivot, n - 1);
        
    }
};
