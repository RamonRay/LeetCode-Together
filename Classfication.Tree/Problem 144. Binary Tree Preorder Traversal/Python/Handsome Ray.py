# Iteravive using stack 20ms
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        ans = []
        nodes = [root]
        while nodes:
            tmp = nodes.pop()
            if tmp:
                ans.append(tmp.val)
                nodes.append(tmp.right)
                nodes.append(tmp.left)
        return ans
#recursive 20ms
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root==None:
            return []
        ans=[]
        global ans
        def search(node):
            ans.append(node.val)
            if node.left:
                search(node.left)
            if node.right:
                search(node.right)
        search(root)
        return ans