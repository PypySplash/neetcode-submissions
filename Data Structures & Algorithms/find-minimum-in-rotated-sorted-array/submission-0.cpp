/*
二分搜中間，只要搜到一個數，小魚他左邊的數，極為答案

左閉右開區間
*/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            // 若 mid 的數 > right - 1 的數，則最小值在右邊
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else { // 反之，在左邊
                right = mid;
            }
        }
        return nums[left];
    }
};
