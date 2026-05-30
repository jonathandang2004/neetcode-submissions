class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = INT_MIN; 
        int h = heights.size();
        int i = 0, j = h - 1;
        while (i < j) {
            area = max(area, (j - i) * min(heights[i], heights[j]));
            if (heights[i] > heights[j]) {
                --j;
            } else {
                ++i;
            }
            // Only move the shorter one, not the taller one? so no look ahead? yeah you know what that actually makes sense, what if i go from 500 to 50, or from 50 to 40, i dont wanna move the 500 one
        }
        return area;
    }
};
