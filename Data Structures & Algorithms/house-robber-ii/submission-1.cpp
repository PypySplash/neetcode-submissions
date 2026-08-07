/*
那就是偷第一間房子的話，最後一間不能偷
不偷第一間的話，最後一間可以偷
*/

class Solution {
    // 198. House Robber 偷下標在 [start, end) 中的房子
    int rob1(vector<int>& nums, int start, int end) {
        // 1. 補上這行保護！無效區間直接回傳 0 (防止 nums=[0] 時 2 >= 0 造成 vector 爆掉)
        if (start >= end) return 0;
        
        int n = end - start;
        vector<int> memo(n, -1);
        // dfs(i) 表示从 nums[0] 到 nums[i] 最多能偷多少
        // dfs(i) 表示處理到子陣列的第 i 個元素 (對應原陣列索引 start + i)
        auto dfs = [&] (this auto&& dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (memo[i] != -1) { // 之前计算过
                return memo[i];
            }
            // 選 or 不選
            return memo[i] = max(dfs(i-1), dfs(i-2) + nums[start + i]);
        };
        return dfs(n-1);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n-1), rob1(nums, 1, n));
    }




};
