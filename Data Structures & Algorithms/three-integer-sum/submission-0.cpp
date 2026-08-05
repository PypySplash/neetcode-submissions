class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        // 一次找 3 個數，故找到 nums.size() - 2
        for (int i = 0; i < nums.size() - 2; i++) {
            // 因為同樣的數只能貢獻一組解，若數字一樣，繼續跳過往後找
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                long long s = nums[i] + nums[left] + nums[right];
                if (s == 0) {
                    // 找到一個答案，接著繼續找
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 因為同樣的數只能貢獻一組解，若數字一樣，繼續往後找
                    while (left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    // 跳過完同樣的數後，此時的 index 還是在同樣的數，再一個 left++, right--
                    left++;
                    right--;
                }
                else if (s < 0) {
                    left++;
                }
                else { // s > 0
                    right--;
                }
            }
        }
        return ans;
    }
};
