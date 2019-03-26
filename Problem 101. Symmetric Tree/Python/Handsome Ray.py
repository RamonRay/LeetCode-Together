#solving recursively 24ms
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.compare(root.left, root.right)

    def compare(self, p, q):
        if p == None and q == None:
            return True
        if (p == None and q) or (p and q == None):
            return False
        if p.val == q.val:
            return self.compare(p.left, q.right) and self.compare(p.right, q.left)
        else:
            return False