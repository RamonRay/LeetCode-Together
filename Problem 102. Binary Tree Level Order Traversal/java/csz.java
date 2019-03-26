import java.util.ArrayList;
import java.util.List;
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelTraversal = new ArrayList<List<Integer>>();
        addElements(levelTraversal,root,0);
        return levelTraversal;
    }
    public void addElements(List<List<Integer>> macroList,TreeNode root,int level){
        if(root==null){
            return;
        }
        if(level>=macroList.size()){
            macroList.add(new ArrayList<Integer>());
        }
        macroList.get(level).add(root.val);
        addElements(macroList,root.left,level+1);
        addElements(macroList,root.right,level+1);
    }    
}