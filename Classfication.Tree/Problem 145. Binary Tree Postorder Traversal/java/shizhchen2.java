import java.util.ArrayList;
import java.util.List;
class Solution {
    List<Integer> output = new ArrayList<Integer>();
    public List<Integer> postorderTraversal(TreeNode root) {
        if(root==null){
            return output;
        }
        if(root.left!=null){
            postorderTraversal(root.left); 
        }
        if(root.right!=null){
            postorderTraversal(root.right);
        }
        output.add(root.val);
        return output;
    }
}