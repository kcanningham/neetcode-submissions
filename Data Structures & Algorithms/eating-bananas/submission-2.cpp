class Solution {
public:
    bool check(int m, vector<int>& piles, int h) {
        double time = 0;
        for(int i = 0; i < piles.size(); i++) {
            time += (piles[i] + m - 1)/m;
        }
        if(time <= h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int min_ans = high;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(check(mid, piles, h)) {
                min_ans = mid;
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return min_ans;
    }
};
