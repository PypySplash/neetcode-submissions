/*
dfs(i) 表示以 nums[i] 结尾的 LIS 長度
枚举子序列的倒数第二个数的下标是 j，如果 nums[j] < nums[i]，那么有 dfs(i) = dfs(j) + 1 
取最大值。

注意 nums[i] 可以单独形成一个长为 1 的子序列。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n);
        auto dfs = [&] (this auto&& dfs, int i) -> int {
            if (memo[i]) {
                return memo[i];
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    memo[i] = max(memo[i], dfs(j));
                }
            }
            memo[i]++;
            return memo[i]; // 加一提到循環外面，表示以 nums[i] 結尾的 LIS 長度 +1
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
