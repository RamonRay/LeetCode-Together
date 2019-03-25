#Recursive recording max and min using formal parameter 40ms
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.checkBST(root,None,None)
    def checkBST(self,root,minimum,maximum):
        if root==None:
            return True
        if (minimum==None or root.val>minimum) and(maximum==None or root.val<maximum):
            return self.checkBST(root.left,minimum,root.val) and self.checkBST(root.right,root.val,maximum)
#Using Stack to check if values are in order 40ms
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        record=[]
        prev=None
        while record or root:
            if root:
                record.append(root)
                root=root.left
            else:
                root=record.pop()
                if prev!=None and root.val<=prev:
                    return False
                prev=root.val
                root=root.right
        return True