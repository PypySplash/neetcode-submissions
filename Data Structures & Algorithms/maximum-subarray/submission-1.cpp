class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int prefix_sum = 0, min_prefix = 0, ans = INT_MIN;
        for (int x : nums) {
            prefix_sum += x;
            ans = max(ans, prefix_sum - min_prefix);
            min_prefix = min(min_prefix, prefix_sum);
        }
        return ans;
    }
};
