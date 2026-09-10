class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy: 維護一個目前能到達的最遠位置變數 mx_reach
        int mx_reach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > mx_reach) return false;

            mx_reach = max(mx_reach, i + nums[i]);
            if (mx_reach >= n-1) return true;
        }
        
        

        // // dp: O(n^2), O(n)
        // int n = nums.size();
        // vector<bool> arrive(n, false);
        // arrive[0] = true;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (arrive[i]) {
        //         for (int j = i; j <= min(n-1, i + nums[i]); j++) { // j: 目的地
        //             arrive[j] = true;
        //         }
        //     }
        // }
        // return arrive[n-1];
    }
};
