class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.begin(), nums1.end());
        for(int it : nums2) {
            nums.push_back(it);
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n % 2 != 0) return nums[n/2.0];
        else {
            return (nums[(n - 1)/2.0] + nums[n/2.0])/2.0;
        }
    }
};
