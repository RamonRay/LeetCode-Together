#solving iteratively 24ms
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root==None:
            return []
        ans=[]
        record=[root]
        while record:
            tmp=[]
            for i in record:
                tmp.append(i.val)
            ans.append(tmp)
            tmp=[]
            for i in record:
                if i.left!=None:
                    tmp.append(i.left)
                if i.right!=None:
                    tmp.append(i.right)
            record=tmp
        return ans
#solving recursively
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.ans=[]
        self.search(root,0)
        return self.ans
    def search(self,root,level):
        if root==None:
            return
        if len(self.ans)==level:
            self.ans.append([])
        self.ans[level].append(root.val)
        self.search(root.left,level+1)
        self.search(root.right,level+1)