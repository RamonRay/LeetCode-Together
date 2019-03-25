class Solution {
    public boolean isValidBST(TreeNode root) {
        return check(root, null, null);
    }

    public boolean check(TreeNode root, Integer low, Integer high) {
        if (root == null) {
            return true;
        }
        if (high != null && root.val >= high || low != null && root.val <= low) {
            return false;
        }
        return check(root.left, low, root.val) && check(root.right, root.val, high);
    }
}