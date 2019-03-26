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
#solving iteratively 28ms
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        ls=[]
        rs=[]
        lp=root.left
        rp=root.right
        while lp or ls:
            if lp and rp:
                if lp.val!=rp.val:
                    return False
                ls.insert(0,lp.left)
                ls.insert(0,lp.right)
                rs.insert(0,rp.right)
                rs.insert(0,rp.left)
                lp=ls.pop()
                rp=rs.pop()
            elif (lp and rp==None) or (lp==None and rp):
                return False
            else:
                lp=ls.pop()
                rp=rs.pop()
        if not (rp or rs):
            return True
        return False