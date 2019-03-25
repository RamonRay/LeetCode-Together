#Stupid Way using stack to record all values 64ms 12.2mb
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root==None:
            return
        record=[]
        queue=[]
        val=[]
        while record or root:
            if root:
                record.append(root)
                root=root.left
            else:
                root=record.pop()
                queue.append(root)
                root=root.right
        for i in queue:
            val.append(i.val)
        valNew=sorted(val)
        wrong1=None
        wrong2=None
        for i in range(len(val)):
            if val[i]!=valNew[i]:
                if wrong1==None:
                    wrong1=i
                else:
                    wrong2=i
                    break
        queue[wrong1].val,queue[wrong2].val=queue[wrong2].val,queue[wrong1].val
        return
#o(1) Space solving iteratively using only 2 pointers recording 75ms 12.3mb
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root==None:
            return
        record=[]
        wrong1=None
        wrong2=None
        prev=None
        while record or root:
            if root:
                record.append(root)
                root=root.left
            else:
                root=record.pop()
                if prev==None:
                    prev=root
                else:
                    if prev.val>root.val:
                        if wrong1==None:
                            wrong1=prev
                            wrong2=root
                        else:
                            wrong2=root
                            break
                    prev=root
                root=root.right
        wrong1.val,wrong2.val=wrong2.val,wrong1.val
#o(1)Space solving recursively using global variatives to indicate wrong nodes 64ms 12.3mb
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        self.wrong1 = self.wrong2 = self.prev = None
        self.findNode(root)
        self.wrong1.val, self.wrong2.val = self.wrong2.val, self.wrong1.val

    def findNode(self, root):
        if root == None:
            return
        self.findNode(root.left)

        if self.prev != None and root.val < self.prev.val:
            if self.wrong1 == None:
                self.wrong1 = self.prev
            self.wrong2 = root
        self.prev = root
        self.findNode(root.right)