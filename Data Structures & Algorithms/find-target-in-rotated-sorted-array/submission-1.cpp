/*
如果 target 在數組中，那這題不難，就簡單二分搜
if nums[mid] == target: return mid

else if nums[mid] >= nums[left], 左半邊有序, 檢查 target 是否在範圍內，若在範圍內，在左邊，否則，在右變


else if nums[mid] < nums[left] 等價於 nums[mid] < nums[n-1], 右半邊有序，檢查 target 是否在範圍內，若在範圍內，在右邊，否則，在左邊

那如果 target 不在數組中呢？
回圈結束時，若沒有找到 return -1

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) return mid;

            // 左半邊有序
            if (nums[left] <= nums[mid]) {
                // 再來找 target 是否在有序區間內
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // 右半邊有序
                // 再來找 target 是否在有序區間內
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
