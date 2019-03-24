class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] temp = new int[m + n];
        int index = 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp[index] = nums1[i];
                i++;
            } else {
                temp[index] = nums2[j];
                j++;
            }
            index++;
        }
        while (i < m) {
            temp[index] = nums1[i];
            i++;
            index++;
        }
        while (j < n) {
            temp[index] = nums2[j];
            j++;
            index++;
        }
        for (int k = 0; k < temp.length; k++) {
            nums1[k] = temp[k];
        }
    }
}