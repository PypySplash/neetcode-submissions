/*
在遍歷數組的同時, 維護兩個訊息:
1. 右端點下標為 i 的最大乘積 f_max[i]
2. 右端點下標為 i 的最小乘積 f_min[i]
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> f_max(n), f_min(n);
        f_max[0] = f_min[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int x = nums[i];
            // 把 x 加到右端点为 i-1 的（乘积最大/最小）子数组后面 or 单独组成一个子数组只有 x 一个元素
            // 比較 3 個以上元素時, 需加大括號 {}
            f_max[i] = max({f_max[i-1] * x, f_min[i-1] * x, x});
            f_min[i] = min({f_max[i-1] * x, f_min[i-1] * x, x});
        }
        return ranges::max(f_max);
    }
};
