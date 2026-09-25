class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), pre = 1;

        vector<int> suf(n+1, 1);
        for (int i = n-1; i >= 0; i--) {
            suf[i] = suf[i+1] * nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = suf[i+1] * pre;
            pre *= nums[i];
        }
        return ans;
    }
};
