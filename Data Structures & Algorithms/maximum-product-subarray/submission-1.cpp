/*
在遍歷數組的同時, 維護兩個訊息:
1. 右端點下標為 i 的最大乘積 f_max[i]
2. 右端點下標為 i 的最小乘積 f_min[i]
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // dp 優化
        int ans = INT_MIN, f_max = 1, f_min = 1; // 因為乘積所以初始化為 1, 求和則初始化為 0 (53. Maximum Subarray)
        for (int x : nums) {
            int mx = f_max; // 由於兩個變數都會用到 f_max, 故這邊先用暫時變數存起來
            f_max = max({f_max * x, f_min * x, x});
            f_min = min({mx * x, f_min * x, x});
            ans = max(ans, f_max);
        }
        return ans;

        // // dp
        // vector<int> f_max(n), f_min(n);
        // f_max[0] = f_min[0] = nums[0];
        // for (int i = 1; i < n; i++) {
        //     int x = nums[i];
        //     // 把 x 加到右端点为 i-1 的（乘积最大/最小）子数组后面 or 单独组成一个子数组只有 x 一个元素
        //     // 比較 3 個以上元素時, 需加大括號 {}
        //     f_max[i] = max({f_max[i-1] * x, f_min[i-1] * x, x});
        //     f_min[i] = min({f_max[i-1] * x, f_min[i-1] * x, x});
        // }
        // return ranges::max(f_max);
    }
};
