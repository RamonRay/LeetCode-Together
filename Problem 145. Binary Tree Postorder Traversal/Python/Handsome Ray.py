#iterative using stack 24ms
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans=[]
        node=[root]
        while node:
            tmp=node.pop()
            if tmp==None:
                continue
            if tmp.left==None and tmp.right==None:
                ans.append(tmp.val)
            else:
                node.append(tmp)
                node.append(tmp.right)
                node.append(tmp.left)
                tmp.left=None
                tmp.right=None
        return ans
#recursive 20ms
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root==None:
            return []
        ans=[]
        global ans
        def search(node):
            if node.left!=None:
                search(node.left)
            if node.right!=None:
                search(node.right)
            ans.append(node.val)
        search(root)
        return ans