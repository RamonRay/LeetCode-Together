class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum = Math.max(nums[i], sum + nums[i]);
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
}
// reference:https://www.youtube.com/watch?v=7J5rs56JBs8