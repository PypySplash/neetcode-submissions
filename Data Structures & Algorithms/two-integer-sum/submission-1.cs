public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; ; i++) {
            int t = target - nums[i];
            if (dic.ContainsKey(t)) {
                return new int[] {dic[t], i};
            }
            dic[nums[i]] = i;
        }
    }
}
