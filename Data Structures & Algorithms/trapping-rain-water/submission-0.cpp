class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if(n == 0) return 0;
        vector<int> prefix_max(n);
        vector<int> suffix_max(n);

        prefix_max[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        suffix_max[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }

        for(auto it : prefix_max) {
            cout<<it<<" ";
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res += min(prefix_max[i], suffix_max[i]) - height[i];
        }    
        return res;
    }
};
