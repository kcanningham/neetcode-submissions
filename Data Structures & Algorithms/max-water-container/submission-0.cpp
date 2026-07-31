class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        int area = 1;
        int maxx = 0;
        int i = 0, j = n - 1;
        while(i <= j) {
            area = (j - i) * min(heights[i], heights[j]);
            maxx = max(area, maxx);
            if(heights[i] < heights[j]) i++;
            else if(heights[j] < heights[i]) j--;
            else {
                i++, j--;
            }
        }
        return maxx;
    }
};
