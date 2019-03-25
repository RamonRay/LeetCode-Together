import java.util.ArrayList;
import java.util.List;
class Solution {

        
    public void recoverTree(TreeNode root) {
        List<TreeNode> treeList = order(root);
        List<Integer> valList = new ArrayList<Integer>();
        for(TreeNode node : treeList){
            valList.add(node.val);
        }
        valList.sort(null);
        for(int i = 0;i<treeList.size();i++){
            treeList.get(i).val = valList.get(i); 
        }
    }
    public List<TreeNode> order(TreeNode root){
        List<TreeNode> temp = new ArrayList<TreeNode>();
        if(root==null){
            return temp;
        }
        temp.addAll(order(root.left));
        temp.add(root);
        temp.addAll(order(root.right));
        return temp;
    }
}