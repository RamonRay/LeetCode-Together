#solving recursively. Claiming global list for storing data. 44 ms.
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        record=[]
        global record
        self.nQueens([],[],[],1,n)
        return record
    def nQueens(self,cols,lcross,rcross,nrow,n):
        for i in xrange(1,n+1):
            if i in cols:
                continue
            if i+nrow in lcross:
                continue
            if i-nrow in rcross:
                continue
            if nrow<n:
                self.nQueens(cols+[i],lcross+[i+nrow],rcross+[i-nrow],nrow+1,n)
            else:
                tmp=self.transform(cols+[i],n)
                record.append(tmp)
    def transform(self,cols,n):
        ans=[]
        for i in xrange(n):
            tmp="."*(cols[i]-1)+"Q"+"."*(n-cols[i])
            ans.append(tmp)
        return ans

