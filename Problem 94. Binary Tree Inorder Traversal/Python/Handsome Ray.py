#recursivly
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.record=[]
        self.traversal(root)
        return self.record
    def traversal(self,root):
        if root==None:
            return
        self.traversal(root.left)
        self.record.append(root.val)
        self.traversal(root.right)
#iteratively
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        record=[]
        stack=[]
        while root or stack:
            if root:
                stack.append(root)
                root=root.left
            else:
                root=stack.pop()
                record.append(root.val)
                root=root.right
        return record