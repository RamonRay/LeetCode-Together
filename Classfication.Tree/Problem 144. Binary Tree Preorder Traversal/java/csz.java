class Solution {
    List<Integer> output = new ArrayList<Integer>();

    public List<Integer> preorderTraversal(TreeNode root) {
        if (root == null) {
            return output;
        }
        output.add(root.val);
        if (root.left != null) {
            preorderTraversal(root.left);
        }
        if (root.right != null) {
            preorderTraversal(root.right);
        }
        return output;
    }
}