#solving it recursively 20ms
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return self.compare(p,q)
    def compare(self,p,q):
        if p==None and q==None:
            return True
        if (p==None and q) or (p and q==None):
            return False
        if p.val==q.val:
            return self.compare(p.left,q.left) and self.compare(p.right,q.right)
        else:
            return False