class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1, ans = 0;

        while (left < right) {
            int volume = (right - left) * min(heights[right], heights[left]);
            ans = max(ans, volume);
            if (heights[left] <= heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};
