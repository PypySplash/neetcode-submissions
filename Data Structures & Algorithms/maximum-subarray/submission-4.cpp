/*
方法二：动态规划
定义 f[i] 表示以 nums[i] 结尾的最大子数组和。

分类讨论：

nums[i] 单独组成一个子数组，那么 f[i]=nums[i]。
nums[i] 和前面的子数组拼起来，也就是在以 nums[i−1] 结尾的最大子数组和之后添加 nums[i]，那么 f[i] = f[i−1] + nums[i]。
两种情况取最大值，得

f[i]={ 
- nums[i], i=0
- max(f[i−1],0)+nums[i], i≥1
​
简单地说，如果 nums[i] 左边的子数组元素和是负的，就不用和左边的子数组拼在一起了。

答案为 max(f)。

⚠注意：答案不是 f[n−1]，这仅仅表示以 nums[n−1] 结尾的最大子数组和。或者说 f[n−1] 意味着 nums[n−1] 一定要选，但这不一定正确。
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // dp 優化
        int ans = INT_MIN, f = 0;
        for (int x : nums) {
            f = max(f, 0) + x;
            ans = max(ans, f);
        }
        return ans;

        // // dp
        // vector<int> f(n);
        // f[0] = nums[0];
        // for (int i = 1; i < n; i++) {
        //     f[i] = max(f[i-1], 0) + nums[i];
        // }
        // return ranges::max(f);
        
        // // 前綴和（貪心的點在哪？）
        // // 維護前綴和（不用數組紀錄，用一個變數紀錄即可), 最小前綴和, 以及 ans
        // int prefix_sum = 0, min_prefix = 0, ans = INT_MIN;
        // for (int x : nums) {
        //     // 前綴和加上當前的數
        //     prefix_sum += x;
        //     // 先更新答案，再更新最小前綴和
        //     ans = max(ans, prefix_sum - min_prefix);
        //     min_prefix = min(min_prefix, prefix_sum);
        // }
        // return ans;
    }
};
