/*
這題就是需要一個資料結構，能進行 O(1) 時間查找資料結構內的最大值，
同時要可以從右端加入，左端移出，第一個想法是雙端隊列？
但雙端隊列要怎麼 O(1) 找最大值？

-> monotonic queue 單調隊列，存 index ，而只要當前遍歷到的 nums[index] 值大於目前最左端 index 的值，把隊列中的全部元素 pop 掉，只保留當前的 index ，這是為什麼呢？因為前面的 nums[index] 已經不可能成為最大值了

反之若小於，則直接從右端放入隊列
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // 1. 剔除視窗左端過期的元素，需注意這條件 dq 不能為空
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. 維持單調遞減：將右端比 nums[i] 小或相等的元素剔除，需注意這條件 dq 不能為空
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. 將當前 index 加入隊列
            dq.emplace_back(i);

            // 4. 當視窗大小到達 k 時，記錄當前最大值
            if (i >= k - 1) {
                ans.emplace_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
