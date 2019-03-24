class shizhchen2_164 {
    public int maximumGap(int[] nums) {
        quickSort(nums);
        if (nums.length < 2) {
            return 0;
        } else {
            int max = Math.abs(nums[1] - nums[0]);
            for (int i = 0; i < nums.length - 1; i++) {
                if (Math.abs(nums[i + 1] - nums[i]) > max) {
                    max = Math.abs(nums[i + 1] - nums[i]);
                }
            }
            return max;
        }
    }

    public void quickSort(int[] nums) {
        partition(nums, 0, nums.length - 1);
    }

    public void partition(int[] nums, int left, int right) {
        if (left < right) {
            int base = nums[left];
            int low = left;
            int high = right;
            while (low < high) {
                while (low < high && base <= nums[high]) {
                    high--;
                }
                nums[low] = nums[high];
                while (low < high && base >= nums[low]) {
                    low++;
                }
                nums[high] = nums[low];
            }
            nums[low] = base;
            partition(nums, left, low);
            partition(nums, low + 1, right);
        }
    }
}