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
#solving iteratively 20ms
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        ps = []
        qs = []
        while p or ps:
            if p and q:
                ps.append(p)
                qs.append(q)
                p = p.left
                q = q.left
            elif (p and q == None) or (p == None and q):
                return False
            else:
                p = ps.pop()
                q = qs.pop()
                if p.val != q.val:
                    return False
                p = p.right
                q = q.right
        if qs or q:
            return False
        return True
