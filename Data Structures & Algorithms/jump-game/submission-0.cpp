class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> arrive(n, false);
        arrive[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (arrive[i]) {
                for (int j = i; j <= min(n-1, i + nums[i]); j++) { // j: 目的地
                    arrive[j] = true;
                }
            }
        }
        return arrive[n-1];
    }
};
